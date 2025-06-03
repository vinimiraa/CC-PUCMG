class CelulaDupla
{
    public int elemento;
    public CelulaDupla prox, ant;

    public CelulaDupla ( ) {
        this(0);
    } // end CelulaDupla ( )

    public CelulaDupla ( int elemento )
    {
        this.elemento = elemento;
        this.prox = null;
        this.ant = null;
    } // end CelulaDupla ( )
} // end class CelulaDupla

public class ListaDupla 
{
    CelulaDupla primeiro;
    CelulaDupla ultimo;

    public ListaDupla ( )
    {
        primeiro = new CelulaDupla ( );
        ultimo = primeiro;
    } // end ListaDupla ( )

    public void inserir_inicio ( int x )
    {
        CelulaDupla tmp = new CelulaDupla( x );
        tmp.ant = primeiro;
        tmp.prox = primeiro.prox;
        primeiro.prox = tmp;
        if( primeiro == ultimo ) {
            ultimo = tmp;
        } else {
            tmp.prox.ant = tmp;
        } // end if
        tmp = null;
    } // end inserir_inicio ( )

    public void inserir_fim ( int x )
    {
        ultimo.prox = new CelulaDupla( x );
        ultimo.prox.ant = ultimo;
        ultimo = ultimo.prox;
    } // end inserir_fim ( )

    public int remover_inicio ( ) throws Exception
    {
        if( primeiro == ultimo ) {
            throw new Exception ( "[REMOVER] ERRO: Lista Vazia!" );
        } // end if
        CelulaDupla tmp = primeiro;
        primeiro = primeiro.prox;
        int resp = primeiro.elemento;
        tmp.prox = primeiro.ant = null;
        tmp = null;
        return ( resp );
    } // end remover_inicio ( )

    public int remover_fim ( ) throws Exception
    {
        if( primeiro == ultimo ) {
            throw new Exception ( "[REMOVER] ERRO: Lista Vazia!" );
        } // end if
        int resp = ultimo.elemento;
        ultimo = ultimo.ant;
        ultimo.prox.ant = null;
        ultimo.prox = null;
        return ( resp );
    } // end remover_fim ( )

    public void mostrar ( )
    {
        System.out.print( "[ " );
        for( CelulaDupla i = primeiro.prox; i != null; i = i.prox ) {
            System.out.print( i.elemento + " " );
        } // end for
        System.out.println( "]" );
    } // end mostrar ( )

    public void mostrar_inverso ( )
    {
        System.out.print( "[ " );
        for( CelulaDupla i = ultimo; i != primeiro; i = i.ant ) {
            System.out.print( i.elemento + " " );
        } // end for
        System.out.println( "]" );
    } // end mostrar_inverso ( )

    public boolean pesquisar ( int x )
    {
        boolean resp = false;
        for( CelulaDupla i = primeiro.prox; i != null; i = i.prox )
        {
            if( i.elemento == x )
            {
                resp = true;
                i = ultimo;
            } // end if
        } // end for
        return ( resp );
    } // end pesquisar ( )

} // end class ListaDupla
