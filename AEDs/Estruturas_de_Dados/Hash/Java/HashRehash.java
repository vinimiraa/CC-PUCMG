public class HashRehash 
{
    private int tabela[];
    private int tamTabela;
    private final int NULO = 0xFFFFFF77;

    public HashRehash ( int tamanho ) 
    {
        if( tamanho > 0 )
        {
            this.tamTabela = tamanho;
            this.tabela = new int[this.tamTabela];
            for( int i = 0; i < this.tamTabela; i++ ) {
                this.tabela[i] = NULO;
            } // end for
        } // end if
    } // end HashRehash ( )

    public int hash ( int elemento ) {
        return ( elemento % this.tamTabela );
    } // end hash ( )

    public int rehash ( int elemento ) {
        return ( ++elemento % this.tamTabela );
    } // end rehash ( )

    public boolean inserir ( int elemento ) 
    {
        boolean resp = false;
        int index = hash( elemento );
        if ( tabela[index] == NULO ) {
            tabela[index] = elemento;
            resp = true;
        } else {
            index = rehash( elemento );
            if ( tabela[index] == NULO ) {
                tabela[index] = elemento;
                resp = true;
            } // end if
        }// end if
        return ( resp );
    } // end inserir ( )

    public boolean pesquisar ( int elemento ) 
    {
        boolean resp = false;
        int index = hash( elemento );
        if ( tabela[index] == elemento ) {
            resp = true;
        } else {
            index = rehash( elemento );
            if ( tabela[index] == elemento ) {
                resp = true;
            } // end if
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
            index = rehash( elemento );
            if ( tabela[index] == elemento ) {
                tabela[index] = NULO;
                resp = true;
            } // end if   
        }// end if
        return ( resp );
    } // end remover ( )
    
} // end class HashRehash
