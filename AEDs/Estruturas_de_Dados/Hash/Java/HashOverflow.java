public class HashOverflow 
{
    private int tabela[];
    private int tamTabela;
    private int tamReserva;
    private int tamTotal;
    private int numReserva;
    private final int NULO = 0xFFFFFF77;

    public HashOverflow ( int tamanho, int tamReserva ) 
    {
        if( tamanho > 0 && tamReserva > 0 )
        {
            this.tamTabela = tamanho;
            this.tamReserva = tamReserva;
            this.tamTotal = this.tamTabela + this.tamReserva;
            this.tabela = new int[this.tamTotal];
            for( int i = 0; i < this.tamTotal; i++ ) {
                this.tabela[i] = NULO;
            } // end for
            this.numReserva = 0;
        } // end if
    } // end HashOverflow ( )

    public int hash ( int elemento ) {
        return ( elemento % this.tamTabela );
    } // end hash ( )

    public boolean inserir ( int elemento ) 
    {
        boolean resp = false;
        int index = hash( elemento );
        if ( tabela[index] == NULO ) {
            tabela[index] = elemento;
            resp = true;
        } else {
            if( numReserva < tamReserva )
            {
                tabela[tamTabela + numReserva] = elemento;
                numReserva++;
                resp = true;
            } // end if
        } // end if
        return ( resp );
    } // end inserir ( )

    public boolean pesquisar ( int elemento ) 
    {
        boolean resp = false;
        int index = hash( elemento );
        if ( tabela[index] == elemento ) {
            resp = true;
        } else {
            for( int i = 0; i < tamReserva; i++ )
            {
                if( tabela[tamTabela+i] == elemento )
                {
                    resp = true;
                    i = tamReserva;
                } // end if
            } // end for
        } // end if
        return ( resp );
    } // end pesquisar ( )

    public boolean remover ( int elemento ) 
    {
        boolean resp = false;
        int index = hash( elemento );
        if ( tabela[index] == elemento ) {
            tabela[index] = NULO;
            resp = true;
        } else {
            for( int i = tamTabela; i < tamTotal; i++ )
            {
                if( tabela[i] == elemento )
                {
                    tabela[i] = NULO;
                    resp = true;
                    i = tamTotal;
                } // end if
            } // end for
        } // end if
        return ( resp );
    } // end remover ( )
    
} // end class HashOverflow
