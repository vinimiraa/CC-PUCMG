import java.util.Random;

public class Geracao extends Log
{
    protected int [] arranjo; 
    protected int    tamanho;
    
    public Geracao ( )
    {
        this.arranjo  = null;
        this.tamanho = -1;
    } // end Geracao ( )

    public Geracao ( int tamanho )
    {
        if( tamanho > 0 )
        {
            this.arranjo = new int[ tamanho ];
            this.tamanho = tamanho;
        } // end if
    } // end Geracao ( )

    public void preencher_crescente ( ) 
    {
        for( int i = 0; i < this.tamanho; i++ )
        {
            arranjo[i] = i;
        } // end for
    } // end preencher_crescente ( )

    public void preencher_decrescente ( ) 
    {
        for( int i = 0; i < this.tamanho; i++ )
        {
            arranjo[i] = tamanho - 1- i;
        } // end for
    } // end preencher_decrescente ( )

    public void preencher_aleatorio ( )
    {
        Random random = new Random ( 0 ); 
        for( int i = 0; i < this.tamanho; i++ )
        {
            arranjo[i] = random.nextInt() % 101;
        } // end for
    } // end preencher_aleatorio ( )

    public void mostrar ( int k ) 
    {
		System.out.print( "[ " );
		for( int i = 0; i < k; i++ ) 
        {
			System.out.print( "("+arranjo[i]+") " );
		} // end for
		System.out.println( "]" );
	} // end mostrar ( )

    public void mostrar (  ) 
    {
		System.out.print( "[ " );
		for( int i = 0; i < this.tamanho; i++ ) 
        {
			System.out.print( "("+arranjo[i]+") " );
		} // end for
		System.out.println( "]" );
	} // end mostrar ( )

    public void swap ( int i, int j ) 
    {
		int temp = arranjo[i];
		arranjo[i] = arranjo[j];
		arranjo[j] = temp;
    } // end swap ( )
    
    public boolean isSort ( )
    {
        boolean resp = true;
        for( int i = 1; i < this.tamanho; i++ ) 
        {
            if( arranjo[i] < arranjo[i-1] ) 
            {
                i = tamanho;
                resp = false;
            } // end if
        } // end for
        return ( resp );
    } // end isSort ( )

    public void sort ( ) { 

    } // end sort ( )

    public void sort ( Log log ) {

    } // end sort ( )

} // end class Geracao
