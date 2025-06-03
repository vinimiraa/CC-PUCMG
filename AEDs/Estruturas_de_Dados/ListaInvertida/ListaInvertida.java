/**
 *  LISTA INVERTIDA
 *  String chave, int dado
 *  
 *  Os nomes dos métodos foram mantidos em inglês
 *  apenas para manter a coerência com o resto da
 *  disciplina:
 *  - boolean create(String chave, int dado)
 *  - int[] read(int chave)
 *  - boolean delete(String chave, int dado)
 *  
 *  Implementado pelo Prof. Marcos Kutova
 *  v1.0 - 2020
 */

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;

public class ListaInvertida {

    String nomeArquivoDicionario;
    String nomeArquivoBlocos;
    RandomAccessFile arqDicionario;
    RandomAccessFile arqBlocos;
    int quantidadeDadosPorBloco;

    class Bloco {

        short quantidade;          // quantidade de dados presentes na lista
        short quantidadeMaxima;    // quantidade máxima de dados que a lista pode conter
        ElementoLista[] elementos; // sequência de dados armazenados no bloco
        long proximo;              // ponteiro para o bloco sequinte da mesma chave
        short bytesPorBloco;       // size fixo do cesto em bytes

        public Bloco( int qtdmax ) throws Exception 
        {
            quantidade = 0;
            quantidadeMaxima = (short) qtdmax;
            elementos = new ElementoLista[quantidadeMaxima];
            proximo = -1;
            bytesPorBloco = (short) (2 + (4 + 4) * quantidadeMaxima + 8); // 4 do INT e 4 do FLOAT
        } // Bloco ( )

        public byte[] toByteArray( ) throws IOException 
        {
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            DataOutputStream dos = new DataOutputStream(baos);
        
            dos.writeShort(quantidade);
            int i = 0;
            while( i < quantidade ) 
            {
                dos.writeInt(elementos[i].getId());
                dos.writeFloat(elementos[i].getFrequencia());
                i++;
            } // while
            while( i < quantidadeMaxima ) 
            {
                dos.writeInt(-1);
                dos.writeFloat(-1);
                i++;
            } // while
            dos.writeLong(proximo);
        
            return baos.toByteArray();
        } // toByteArray ( )

        public void fromByteArray( byte[] ba ) throws IOException 
        {
            ByteArrayInputStream bais = new ByteArrayInputStream(ba);
            DataInputStream dis = new DataInputStream(bais);
        
            quantidade = dis.readShort();
            int i = 0;
            while( i < quantidadeMaxima ) 
            {
                elementos[i] = new ElementoLista(dis.readInt(), dis.readFloat());
                i++;
            } // while
            proximo = dis.readLong();
        } // fromByteArray ( )

        // Insere um valor no bloco
        public boolean create( ElementoLista e ) 
        {
            if( full( ) ) {
                return false;
            } // if
            int i = quantidade - 1;
            while( i >= 0 && e.getId() < elementos[i].getId() ) 
            {
                elementos[i + 1] = elementos[i];
                i--;
            } // while
            i++;
            elementos[i] = e.clone();
            quantidade++;
            return true;
        } // create ( )

        // Lê um valor no bloco
        public boolean test( int id ) 
        {
            if( empty( ) ) {
                return false;
            } // if
            int i = 0;
            while( i < quantidade && id > elementos[i].getId() ) {
                i++;
            } // while
            if( i < quantidade && id == elementos[i].getId() ) {
                return true;
            } else {
                return false;
            } // if
        } // test ( )

        // Remove um valor do bloco
        public boolean delete( int id ) 
        {
            if( empty( ) ) {
                return false;
            } // if
            int i = 0;
            while( i < quantidade && id > elementos[i].getId() ) {
                i++;
            } // while
            if( id == elementos[i].getId() ) 
            {
                while( i < quantidade - 1 ) 
                {
                    elementos[i] = elementos[i + 1];
                    i++;
                } // while
                quantidade--;
                return true;
            } else {
                return false;
            } // if
        } // delete ( ) 

        public ElementoLista last( ) {
            return elementos[quantidade - 1];
        } // last ( )

        public ElementoLista[] list( ) 
        {
            ElementoLista[] lista = new ElementoLista[quantidade];
            for( int i = 0; i < quantidade; i++ ) {
                lista[i] = elementos[i].clone();
            } // for
            return lista;
        } // list ( )

        public boolean empty( ) {
            return quantidade == 0;
        } // empty ( )

        public boolean full( ) {
            return quantidade == quantidadeMaxima;
        } // full ( )

        public String toString( ) 
        {
            String s = "\nQuantidade: " + quantidade + "\n| ";
            int i = 0;
            while( i < quantidade ) 
            {
                s += elementos[i] + " | ";
                i++;
            } // while
            while( i < quantidadeMaxima ) 
            {
                s += "- | ";
                i++;
            } // while
            return s;
        } // toString ( )

        public long next( ) {
            return proximo;
        } // next ( )

        public void setNext( long p ) {
            proximo = p;
        } // setNext ( )

        public int size( ) {
            return bytesPorBloco;
        } // size ( )
    } // Bloco

    public ListaInvertida( int n, String nd, String nc ) throws Exception 
    {
        quantidadeDadosPorBloco = n;
        nomeArquivoDicionario = nd;
        nomeArquivoBlocos = nc;

        arqDicionario = new RandomAccessFile(nomeArquivoDicionario, "rw");
        if( arqDicionario.length() < 4 ) 
        { 
            // cabeçalho do arquivo com número de entidades
            arqDicionario.seek(0);
            arqDicionario.writeInt(0);
        } // if
        arqBlocos = new RandomAccessFile(nomeArquivoBlocos, "rw");
    } // ListaInvertida ( )

    // Incrementa o número de entidades
    public void incrementaEntidades( ) throws Exception 
    {
        arqDicionario.seek(0);
        int n = arqDicionario.readInt();
        arqDicionario.seek(0);
        arqDicionario.writeInt(n + 1);
    } // incrementaEntidades ( )

    // Decrementa o número de entidades
    public void decrementaEntidades( ) throws Exception 
    {
        arqDicionario.seek(0);
        int n = arqDicionario.readInt();
        arqDicionario.seek(0);
        arqDicionario.writeInt(n - 1);
    } // decrementaEntidades ( )

    // Retorna o número de entidades
    public int numeroEntidades( ) throws Exception 
    {
        arqDicionario.seek(0);
        return arqDicionario.readInt();
    } // numeroEntidades ( )

    // Insere um dado na lista da chave de forma NÃO ORDENADA
    public boolean create( String c, ElementoLista e ) throws Exception 
    {
        // Percorre toda a lista testando se já não existe
        // o dado associado a essa chave
        ElementoLista[] lista = read(c);
        for( int i = 0; i < lista.length; i++ ) {
            if( lista[i].getId() == e.getId() ) {
                return false;
            } // if
        } // for

        String chave = "";
        long endereco = -1;
        boolean jaExiste = false;

        // localiza a chave no dicionário
        arqDicionario.seek(4);
        while( arqDicionario.getFilePointer() != arqDicionario.length() ) 
        {
            chave = arqDicionario.readUTF();
            endereco = arqDicionario.readLong();
            if( chave.compareTo(c) == 0 ) 
            {
                jaExiste = true;
                break;
            } // if
        } // while

        // Se não encontrou, cria um novo bloco para essa chave
        if( !jaExiste ) 
        {
            // Cria um novo bloco
            Bloco b = new Bloco(quantidadeDadosPorBloco);
            endereco = arqBlocos.length();
            arqBlocos.seek(endereco);
            arqBlocos.write(b.toByteArray());

            // Insere a nova chave no dicionário
            arqDicionario.seek(arqDicionario.length());
            arqDicionario.writeUTF(c);
            arqDicionario.writeLong(endereco);
        } // if

        // Cria um laço para percorrer todos os blocos encadeados nesse endereço
        Bloco b = new Bloco(quantidadeDadosPorBloco);
        byte[] bd;
        while( endereco != -1 ) 
        {
            long proximo = -1;

            // Carrega o bloco
            arqBlocos.seek(endereco);
            bd = new byte[b.size()];
            arqBlocos.read(bd);
            b.fromByteArray(bd);

            // Testa se o dado cabe nesse bloco
            if( !b.full( ) ) {
                b.create(e);
            } 
            else 
            {
                // Avança para o próximo bloco
                proximo = b.next();
                if( proximo == -1 ) 
                {
                    // Se não existir um novo bloco, cria esse novo bloco
                    Bloco b1 = new Bloco(quantidadeDadosPorBloco);
                    proximo = arqBlocos.length();
                    arqBlocos.seek(proximo);
                    arqBlocos.write(b1.toByteArray());

                    // Atualiza o ponteiro do bloco anterior
                    b.setNext(proximo);
                } // if
            } // if

            // Atualiza o bloco atual
            arqBlocos.seek(endereco);
            arqBlocos.write(b.toByteArray());
            endereco = proximo;
        } // while
        return true;
    } // create ( )

    // Retorna a lista de dados de uma determinada chave
    public ElementoLista[] read( String c ) throws Exception 
    {
        ArrayList<ElementoLista> lista = new ArrayList<>();

        String chave = "";
        long endereco = -1;
        boolean jaExiste = false;

        // localiza a chave no dicionário
        arqDicionario.seek(4);
        while( arqDicionario.getFilePointer() != arqDicionario.length() ) 
        {
            chave = arqDicionario.readUTF();
            endereco = arqDicionario.readLong();
            if( chave.compareTo(c) == 0 ) 
            {
                jaExiste = true;
                break;
            } // if
        } // while

        if( !jaExiste ) {
            return new ElementoLista[0];
        } // if

        // Cria um laço para percorrer todos os blocos encadeados nesse endereço
        Bloco b = new Bloco(quantidadeDadosPorBloco);
        byte[] bd;
        while( endereco != -1 ) 
        {
            // Carrega o bloco
            arqBlocos.seek(endereco);
            bd = new byte[b.size()];
            arqBlocos.read(bd);
            b.fromByteArray(bd);

            // Acrescenta cada valor à lista
            ElementoLista[] lb = b.list();
            for( int i = 0; i < lb.length; i++ ) {
                lista.add(lb[i]);
            } // for

            // Avança para o próximo bloco
            endereco = b.next();
        } // while

        // Constrói o vetor de respostas
        lista.sort( null );
        ElementoLista[] resposta = new ElementoLista[lista.size()];
        for( int j = 0; j < lista.size(); j++ ) {
            resposta[j] = (ElementoLista) lista.get(j);
        } // for

        return resposta;
    } // read ( )

    // Remove o dado de uma chave (mas não apaga a chave nem apaga blocos)
    public boolean delete( String c, int id ) throws Exception 
    {
        String chave = "";
        long endereco = -1;
        boolean jaExiste = false;

        // localiza a chave no dicionário
        arqDicionario.seek(4);
        while( arqDicionario.getFilePointer() != arqDicionario.length() ) 
        {
            chave = arqDicionario.readUTF();
            endereco = arqDicionario.readLong();
            if( chave.compareTo(c) == 0 ) 
            {
                jaExiste = true;
                break;
            } // if
        } // while
        
        if( !jaExiste ) {
            return false;
        } // if

        // Cria um laço para percorrer todos os blocos encadeados nesse endereço
        Bloco b = new Bloco(quantidadeDadosPorBloco);
        byte[] bd;
        while( endereco != -1 ) 
        {
            // Carrega o bloco
            arqBlocos.seek(endereco);
            bd = new byte[b.size()];
            arqBlocos.read(bd);
            b.fromByteArray(bd);

            // Testa se o valor está neste bloco e sai do laço
            if( b.test(id) ) 
            {
                b.delete(id);
                arqBlocos.seek(endereco);
                arqBlocos.write(b.toByteArray());
                return true;
            } // if

            // Avança para o próximo bloco
            endereco = b.next();
        } // while

        // chave não encontrada
        return false;
    } // delete ( )

    public void print( ) throws Exception 
    {
        System.out.println("\nLISTAS INVERTIDAS:");

        // Percorre todas as chaves
        arqDicionario.seek(4);
        while( arqDicionario.getFilePointer() != arqDicionario.length() ) 
        {

            String chave = arqDicionario.readUTF();
            long endereco = arqDicionario.readLong();

            // Percorre a lista desta chave
            ArrayList<ElementoLista> lista = new ArrayList<>();
            Bloco b = new Bloco(quantidadeDadosPorBloco);
            byte[] bd;
            while( endereco != -1 ) 
            {
                // Carrega o bloco
                arqBlocos.seek(endereco);
                bd = new byte[b.size()];
                arqBlocos.read(bd);
                b.fromByteArray(bd);

                // Acrescenta cada valor à lista
                ElementoLista[] lb = b.list();
                for( int i = 0; i < lb.length; i++ ) {
                    lista.add(lb[i]);
                } // for

                // Avança para o próximo bloco
                endereco = b.next();
            } // while

            // Imprime a chave e sua lista
            System.out.print(chave + ": ");
            lista.sort(null);
            for( int j = 0; j < lista.size(); j++ ) {
                System.out.print(lista.get(j) + " ");
            } // for
            System.out.println();
        } // while
    } // print ( )
    
} // ListaInvertida