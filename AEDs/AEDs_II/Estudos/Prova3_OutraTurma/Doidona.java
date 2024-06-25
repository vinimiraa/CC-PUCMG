/* class Doidona1
{
    int [] t1;
    int [] t2;
    int tamT1;
    int tamT2;

    final int NULO = -1;

    int hashT1 ( int x ) {
        return ( x % tamT1 );
    }

    int hashT2 ( int x ) {
        return ( x % tamT2 );
    } 

    int rehashT2 ( int x ) {
        return ( ++x % tamT2 );
    }

    int hashT3 ( int x ) {
        return ( x % 2 );
    }

    void inserir ( int x )
    {
        int pos = hashT1(x);
        if ( t1[pos] == NULO ) {
            t1[pos] = x;
        } 
        else 
        {
            pos = hashT2(x);
            if ( t2[pos] == NULO ) {
                t2[pos] = x;
            } 
            else if ( t2[pos] != NULO ) 
            {
                pos = rehashT2(x);
                if ( t2[pos] == NULO ) {
                    t2[pos] = x;
                } 
                else 
                {
                    pos = hashT3(x);
                    if ( pos == 0 ) {
                        lista.inserir(x);
                    } else if ( pos == 1 ) {
                        arvore.inserir(x);
                    } else {
                        System.out.println("ERRO");
                    } // end if
                } // end if
            } // end if
        } // end if
    } // end if
} // end class Doidona1

class Doidona2 
{
    int [] t1;
    int [] t2;
    int [] t3;
    int tamT1;
    int tamT2;
    int tamT3;
    final int NULO = 0xFFFFFFF7;

    int hashT1 ( int x ) {
        return Math.abs( x % tamT1 );
    } 

    int hashT2 ( int x ) {
        return Math.abs( x % tamT2 );
    } 
    
    int hashT3 ( int x ) {
        return Math.abs( x % tamT3 );
    } 

    void inserir ( int x )
    {
        if( x == NULO ) {
            // msg erro
        } 
        else 
        {
            int pos = hashT1(x);
            if( t1[pos] == NULO ) {
                t1[pos] = x;
            } 
            else
            {
                pos = hashVirtual(x);
                if( pos == 0 )
                {
                    pos = hashT2(x);
                    if( t2[pos] == NULO ) {
                        t2[pos] = x;
                    } 
                    else {
                        arvore.inserir(x);
                    } // end if
                }
                else if ( pos == 1 )
                {
                    pos = hashT3(x);
                    if( t3[pos] == NULO ) {
                        t3[pos] = x;
                    } else if( t3[pos] != NULO ) {
                        pos = rehashT3(x);
                        if( t3[pos] == NULO ) {
                            t3[pos] = x;
                        } else {
                            lista.inserir(x);
                        } // end if
                    } else {
                        // msg erro
                    } // end if
                } else {
                    // msg erro
                } // end if
            } // end if
        } // end if
    } // end inserir ( )

    boolean pesquisar ( int x )
    {
        boolean result = false;
        if( x == NULO ) {
            result = false;
        } 
        else 
        {
            int pos = hashT1(x);
            if( t1[pos] == x ) {
                result = true;
            } 
            else
            {
                pos = hashVirtual(x);
                if( pos == 0 )
                {
                    pos = hashT2(x);
                    if( t2[pos] == x ) {
                        result = true;
                    } 
                    else {
                        result = arvore.pesquisar(x);
                    } // end if
                }
                else if ( pos == 1 )
                {
                    pos = hashT3(x);
                    if( t3[pos] == x ) {
                        result = true;
                    } 
                    else 
                    {
                        pos = rehashT3(x);
                        if( t3[pos] == x ) {
                            result = true;
                        } else {
                            result = lista.pesquisar(x);
                        } // end if
                    } // end if
                } // end if
            } // end if
        } // end if
        return ( result );
    } // end pesquisar ( )

} // end class Doidona2
 */