public class P01Q01
{
    public static void main( String[] args ) 
    {
        int N = 0;
        int M = 0;
        String[] linguaTraducao; // lingua da traducao e traducao para felix natal
        String[] nomeLingua;     // nome da crianca e lingua nativa da crianca

        // ler quantidade de traducoes
        do
        {
            N = MyIO.readInt();
        } while( N < 0 && 100 < N );

        linguaTraducao = new String[N*2];

        // ler lingua e traducao
        for( int x = 0; x < (N*2); x = x + 2 )
        {
            linguaTraducao[x] = MyIO.readLine();
            linguaTraducao[x+1] = MyIO.readLine();
        } // end for

        // ler quantidade de criancas
        do {
            M = MyIO.readInt();
        } while( M < 0 && 100 < M );

        nomeLingua = new String[M*2];

        // ler nome e lingua nativa
        for( int x = 0; x < (M*2); x = x + 2 )
        {
            nomeLingua[x] = MyIO.readLine();
            nomeLingua[x+1] = MyIO.readLine();
        } // end for

        // verificar quais lingua e lingua nativa sao iguais
        for( int x = 0; x < (M*2); x = x + 2 )
        {
            String nativa = nomeLingua[x+1];
            String nome = nomeLingua[x];
            for( int y = 0; y < (N*2); y = y + 2 )
            {
                String lingua = linguaTraducao[y];
                String traducao = linguaTraducao[y+1];
                if( nativa.equals(lingua) )
                {
                    MyIO.println( nome );
                    MyIO.println( traducao );
                    MyIO.println("");
                } // end if
            } //  end for
        } // end for
    } // end main ( )
    
} // end class ( )