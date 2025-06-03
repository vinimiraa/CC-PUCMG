class Celula 
{
    public int elemento; // Elemento inserido na celula.
    public Celula prox; // Aponta a celula prox.

    public Celula ( ) {
        this(0);
    } // end Celula ( )

    public Celula ( int elemento ) 
    {
        this.elemento = elemento;
        this.prox = null;
    } // end Celula ( )
} // end class Celula

class Lista 
{
    Celula primeiro;
    Celula ultimo;

    public Lista ( )
    {
        primeiro = new Celula ( );
        ultimo = primeiro;
    } // end Lista ( )

    public void inserir_inicio ( int x )
    {
        Celula tmp = new Celula( x );
        tmp.prox = primeiro.prox;
        primeiro.prox = tmp;
        if( primeiro == ultimo ) {
            ultimo = tmp;
        } // end if
        tmp = null;
    } // end inserir_inicio ( )

    public void inserir_fim ( int x )
    {
        ultimo.prox = new Celula( x );
        ultimo = ultimo.prox;
    } // end inserir_fim ( )

    public int remover_inicio ( ) throws Exception
    {
        if( primeiro == ultimo ) {
            throw new Exception ( "[REMOVER_INICIO] ERRO: Lista Vazia!" );
        } // end if
        Celula tmp = primeiro;
        primeiro = primeiro.prox;
        int resp = primeiro.elemento;
        tmp.prox = null;
        tmp = null;
        return ( resp );
    } // end remover_inicio ( )

    public int remover_fim ( ) throws Exception
    {
        if( primeiro == ultimo ) {
            throw new Exception ( "[REMOVER_FIM] ERRO: Lista Vazia!" );
        } // end if
        Celula i;
        for ( i = primeiro; i.prox != ultimo; i = i.prox );
        int resp = ultimo.elemento;
        ultimo = i;
        i = ultimo.prox = null;
        return ( resp );
    } // end remover_fim ( )

    public void inserir ( int x, int index ) throws Exception 
    {
        int tamanho = tamanho();
        if( index < 0 || index > tamanho ) {
            throw new Exception( "[INSERIR] ERRO: Posicao Invalida!" );
        } else if( index == 0 ) {
            inserir_inicio(x);
        } else if( index == tamanho ) {
            inserir_fim(x);
        } 
        else 
        {
            Celula i = primeiro;
            for( int j = 0; j < index; j++, i = i.prox );
            Celula tmp = new Celula(x);
            tmp.prox = i.prox;
            i.prox = tmp;
            tmp = i = null;
        } // end if
    } // end inserir ( )

    public int remover ( int index ) throws Exception 
    {
        int resp = 0xFFFFFF7;
        int tamanho = tamanho();

        if( primeiro == ultimo ) {
            throw new Exception( "[REMOVER] ERRO: Lista Vazia!" );
        } else if( index < 0 || index >= tamanho ) {
            throw new Exception( "[REMOVER] ERRO: Posicao Invalida!" );
        } else if( index == 0 ) {
            resp = remover_inicio( );
        } else if( index == tamanho - 1 ) {
            resp = remover_fim( );
        } 
        else 
        {
            Celula i = primeiro;
            for( int j = 0; j < index; j++, i = i.prox );
            Celula tmp = i.prox;
            resp = tmp.elemento;
            i.prox = tmp.prox;
            tmp.prox = null;
            i = tmp = null;
        } // end if
        return ( resp );
    } // end remover ( )

    public void mostrar ( )
    {
        System.out.println( "[" );
        for ( Celula i = primeiro.prox; i != null; i = i.prox ) {
            System.out.print ( " " + i.elemento );
        } // end for
        System.out.println( " ]" );
    } // end mostrar ( )

    public boolean pesquisar ( int x )
    {
        boolean resp = false;
        for( Celula i = primeiro.prox; i != null; i = i.prox )
        {
            if( i.elemento == x )
            {
                resp = true;
                i = ultimo;
            } // end if
        } // end for
        return ( resp );
    } // end pesquisar ( )

    public int tamanho ( )
    {
        int tamanho = 0;
        for( Celula i = primeiro; i != ultimo; i = i.prox, tamanho++ );
        return ( tamanho );
    } // end tamanho ( )
} // end class Lista

public class HashLista
{
    private Lista tabela[];
    private int tamTabela;
    private final int NULO = 0xFFFFFF77;

    public HashLista ( int tamanho ) 
    {
        if( tamanho > 0 )
        {
            this.tamTabela = tamanho;
            this.tabela = new Lista[this.tamTabela];
            for( int i = 0; i < this.tamTabela; i++ ) {
                this.tabela[i] = new Lista( );
            } // end for
        } // end if
    } // end HashLista ( )

    public int hash ( int elemento ) {
        return ( elemento % this.tamTabela );
    } // end hash ( )

    public void inserir ( int elemento ) 
    {
        int index = hash( elemento );
        tabela[index].inserir_fim( elemento );
    } // end inserir ( )

    public boolean pesquisar ( int elemento ) 
    {
        boolean resp = false;
        int index = hash( elemento );
        resp = tabela[index].pesquisar( elemento );
        return ( resp );
    } // end pesquisar ( )

    public int remover ( int elemento ) throws Exception
    {
        int resp = NULO;
        int index = hash( elemento );
        if( pesquisar( elemento ) == false ) {
            throw new Exception( "[REMOVER] ERRO: Elemento nao encontrado!" );
        } else {
            resp = tabela[index].remover( elemento );
        } // end if
        return ( resp );
    } // end remover ( )
} // end class HashLista
