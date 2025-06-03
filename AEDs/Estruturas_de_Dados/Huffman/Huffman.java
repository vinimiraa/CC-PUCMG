import java.io.ByteArrayOutputStream;
import java.util.HashMap;
import java.util.PriorityQueue;

class HuffmanNode implements Comparable<HuffmanNode> 
{
    byte b;
    int frequencia;
    HuffmanNode esquerdo, direito;

    public HuffmanNode( byte b, int f ) 
    {
        this.b = b;
        this.frequencia = f;
        esquerdo = direito = null;
    } // HuffmanNode ( )

    @Override
    public int compareTo( HuffmanNode o ) {
        return this.frequencia - o.frequencia;
    } // compareTo ( )
} // class HuffmanNode

public class Huffman 
{

    public static HashMap<Byte, String> codifica( byte[] sequencia ) 
    {
        HashMap<Byte, Integer> mapaDeFrequencias = new HashMap<>();
        for( byte c : sequencia ) {
            mapaDeFrequencias.put(c, mapaDeFrequencias.getOrDefault(c, 0) + 1);
        } // for

        PriorityQueue<HuffmanNode> pq = new PriorityQueue<>();
        for( Byte b : mapaDeFrequencias.keySet() ) {
            pq.add(new HuffmanNode(b, mapaDeFrequencias.get(b)));
        } // for

        while( pq.size() > 1 ) 
        {
            HuffmanNode esquerdo = pq.poll();
            HuffmanNode direito = pq.poll();

            HuffmanNode pai = new HuffmanNode((byte)0, esquerdo.frequencia + direito.frequencia);
            pai.esquerdo = esquerdo;
            pai.direito = direito;

            pq.add(pai);
        } // while

        HuffmanNode raiz = pq.poll();
        HashMap<Byte, String> codigos = new HashMap<>();
        constroiCodigos(raiz, "", codigos);

        return codigos;
    } // codifica ( )

    private static void constroiCodigos( HuffmanNode no, String codigo, HashMap<Byte, String> codigos ) 
    {
        if (no == null) {
            return;
        } // if

        if (no.b != 0) {
            codigos.put(no.b, codigo);
        } // if

        constroiCodigos(no.esquerdo, codigo + "0", codigos);
        constroiCodigos(no.direito, codigo + "1", codigos);
    } // constroiCodigos ( )

    // Versão buscando na tabela de códigos.
    public static byte[] decodifica(  String sequenciaCodificada, HashMap<Byte, String> codigos ) 
    {
        ByteArrayOutputStream sequenciaDecodificada = new ByteArrayOutputStream();
        StringBuilder codigoAtual = new StringBuilder();

        for( int i = 0; i < sequenciaCodificada.length(); i++ ) 
        {
            codigoAtual.append(sequenciaCodificada.charAt(i));
            for( byte b : codigos.keySet( ) ) 
            {
                if( codigos.get(b).equals(codigoAtual.toString()) ) 
                {
                    sequenciaDecodificada.write(b);
                    codigoAtual = new StringBuilder();
                    break;
                } // if
            } // for
        } // for
        return sequenciaDecodificada.toByteArray();
    } // decodifica ( )

    public static void main( String[] args ) 
    {
        String frase = "O sabiá não sabia que o sábio sabia que o sabiá não sabia assobiar.";
        System.out.println("Frase original: " + frase);

        HashMap<Byte, String> codigos = codifica(frase.getBytes());
        System.out.println("Códigos: " + codigos);

        // Codificação
        VetorDeBits sequenciaCodificada = new VetorDeBits();
        int i = 0;
        for( byte b : frase.getBytes( ) ) 
        {
            String codigo = codigos.get(b);
            for( char c : codigo.toCharArray()) 
            {
                if( c=='0' ) {
                    sequenciaCodificada.clear(i++);
                } else {
                    sequenciaCodificada.set(i++);            
                } // if
            } // for
        } // for
        byte[] vb = sequenciaCodificada.toByteArray();
        System.out.println("\n"+sequenciaCodificada);
        System.out.println("Tamanho original: "+frase.getBytes().length+" bytes");
        System.out.println("Tamanho compactado: "+vb.length+" bytes");

        // Decodificação
        VetorDeBits sequenciaCodificada2 = new VetorDeBits(vb);
        System.out.println("\nFrase decodificada: " + (new String(decodifica(sequenciaCodificada2.toString(), codigos))));
    } // main ( )

} // Huffman
