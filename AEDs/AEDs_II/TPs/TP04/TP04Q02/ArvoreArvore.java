/*
 *  -------------------------- Documentacao
 *  
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  TP04Q02 - 23 / 06 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : javac ArvoreArvore.java
 *       Windows: javac ArvoreArvore.java
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : java ArvoreArvore
 *       Windows: java ArvoreArvore
 *   
*/

import java.time.LocalDate;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.time.format.DateTimeFormatter;

/**
 *  Classe No : Nó da Árvore Binária
 */
class No 
{
    public int year; // Conteudo do no.
    public No esq, dir;  // Filhos da esq e dir.
    public No2 outro; // referencia para outra arvore

    public No (int year) {
        this(year, null, null, null);
    } // end No ( )

    public No (int year, No esq, No dir, No2 outro) {
        this.year = year;
        this.esq = esq;
        this.dir = dir;
        this.outro = outro;
    } // end No ( )
} // end class No

class No2
{
    public String name;
    public No2 esq, dir;

    public No2 (String name) {
        this(name, null, null);
    } // end No2 ( )

    public No2 (String name, No2 esq, No2 dir) {
        this.name = name;
        this.esq = esq;
        this.dir = dir;
    } // end No2 ( )
} // end class No2 

/**
 *  Classe ArvoreBinaria : ArvoreArvore Binaria de Pesquisa
 */
class ArvoreBinaria 
{
	private No raiz; // Raiz da arvore.

	public ArvoreBinaria ( ) {
		raiz = null;
        try {
            inserir(7);
            inserir(3);
            inserir(11);
            inserir(1);
            inserir(5);
            inserir(9);
            inserir(13);
            inserir(0);
            inserir(2);
            inserir(4);
            inserir(6);
            inserir(8);
            inserir(10);
            inserir(12);
            inserir(14);
        } catch (Exception e) {
            System.err.println( e.getMessage( ) );
        }
	} // end ArvoreBinaria ( )

    /* INSERIR OS NUMEROS NA PRIMEIRA ARVORE */
    private void inserir (int x) throws Exception {
		raiz = inserir(x, raiz);
	} // end inserir ( )

	private No inserir (int x, No i) throws Exception {
		if (i == null) {
            i = new No(x);
        } else if (x < i.year) {
            i.esq = inserir(x, i.esq);
        } else if (x > i.year) {
            i.dir = inserir(x, i.dir);
        } else {
            throw new Exception("Erro ao inserir!");
        } // end if
		return ( i );
	} // end inserir ( )

    /* INSERIR OS PERSONAGENS NA ARVORE */
    public void inserir (Personagem x) throws Exception {
        raiz = inserir(x, raiz);
    } // end inserir ( )

    private No inserir (Personagem x, No i) throws Exception {
        int ano = x.getYearOfBirth() % 15;
        if( i == null ) {
            System.err.println("erro inserir perso");
        } else if( ano < i.year ) {
            i.esq = inserir(x, i.esq);
        } else if( ano > i.year ) {
            i.dir = inserir(x, i.dir);
        } else {
            i.outro = inserir(x.getName(), i.outro);
        } // end if
        return ( i );
    } // end inserir ( )

	private No2 inserir (String x, No2 i) throws Exception {
		if (i == null) {
            i = new No2(x);
        } else if (x.compareTo(i.name) < 0) {
            i.esq = inserir(x, i.esq);
        } else if (x.compareTo(i.name) > 0) {
            i.dir = inserir(x, i.dir);
        } else {
            throw new Exception("Erro ao inserir na segunda arvore!");
        } // end if
		return ( i );
	} // end inserir ( )

	public boolean pesquisar (Personagem x, Log log) {
        System.out.print( " => raiz ");
		return ( pesquisar(x, raiz, log) );
	} // end pesquisar ( )

	private boolean pesquisar (Personagem x, No i, Log log) {
        boolean resp;
        int ano = x.getYearOfBirth() % 15;
		if (i == null) {
            resp = false;
            log.incrementarComp( );
        } else if ( ano == i.year ) {
            log.incrementarComp( );
            resp = pesquisar( x.getName(), i.outro, log);
        } else if ( ano < i.year ) {
            log.incrementarComp( );
            System.out.print( "ESQ " );
            resp = pesquisar(x, i.esq, log);
        } else {
            System.out.print( "DIR " );
            resp = pesquisar(x, i.dir, log);
        } // end if
        return ( resp );
	} // end pesquisar ( )

    private boolean pesquisar (String x, No2 i, Log log) {
        boolean resp;
        if (i == null) {
            log.incrementarComp();
            resp = false;
        } else if (x.equals(i.name)) {
            log.incrementarComp();
            resp = true;
        } else if (x.compareTo(i.name) < 0) {
            log.incrementarComp();
            System.out.print( "->esq " );
            resp = pesquisar( x, i.esq, log);
        } else {
            System.out.print( "->dir " );
            resp = pesquisar( x, i.dir, log);
        } // end if
        return ( resp );
    } // end pesquisar ( )

} // end class ArvoreBinaria ( )

/**
 *  Classe Log : Analise de Complexidade
 */
class Log 
{
    protected int comparacoes;
    protected int movimentacoes;
    protected double tempo;
    protected String fileName;
    
    Log( ) {
        this.comparacoes = -1;
        this.movimentacoes = -1;
        this.tempo = -1.0; 
        this.fileName = null;
    } // end Log ( )

    Log( String fileName )
    {
        this.comparacoes = -1;
        this.movimentacoes = -1;
        this.tempo = -1.0; 
        this.fileName = fileName;
    } // end Log ( )

    int    getComp ( ) { return ( this.comparacoes   ); }
    int    getMov  ( ) { return ( this.movimentacoes ); }
    double getTime ( ) { return ( this.tempo         ); }
    
    void   setComp ( int    comp ) { this.comparacoes   = comp; }
    void   setMov  ( int    mov  ) { this.movimentacoes = mov ; }
    void   setTime ( double time ) { this.tempo         = time; }

    public void incrementarComp( ) { this.comparacoes++  ; }
    public void incrementarMov ( ) { this.movimentacoes++; }

    public void registro( )
    {
        try {
            FileWriter writer = new FileWriter(this.fileName);
            writer.write( "812839\t" + "Comparacoes: "+getComp()+"\t" + "Movimentacoes: "+getMov()+"\t" 
            + "Tempo de Execucao (ms): "+getTime()+"\n" );
            writer.close();
        } // end try 
        catch( Exception e ) {
            System.out.println( "Erro ao escrever o log no arquivo: " + e.getMessage( ) );
        } // end catch
    } // end registro ( )
    
} // end class Log

/**
 *  Classe Personagem : Modelo Personagem de Harry Potter
 */
class Personagem 
{
    // ---------------------------------- Atributos

    /**
     *  Atributos privados.
     */
    private String    id              ; 
    private String    name            ; 
    private String[]  alternateNames  ; 
    private String    house           ; 
    private String    ancestry        ; 
    private String    species         ; 
    private String    patronus        ; 
    private Boolean   hogwartsStaff   ;  
    private Boolean   hogwartsStudent ;  
    private String    actorName       ; 
    private Boolean   alive           ;
    private String[]  alternateActors ;
    private LocalDate dateOfBirth     ; 
    private int       yearOfBirth     ; 
    private String    eyeColour       ; 
    private String    gender          ; 
    private String    hairColour      ; 
    private Boolean   wizard          ; 

    // ---------------------------------- Construtores

    /**
     *  Construtor Padrao.
     *  Inicializando todos os atributos com "0".
     */
    Personagem ( )
    {
        this.id              = ""    ;              
        this.name            = ""    ;            
        this.alternateNames  = null  ; 
        this.house           = ""    ;           
        this.ancestry        = ""    ;        
        this.species         = ""    ;         
        this.patronus        = ""    ;        
        this.hogwartsStaff   = false ;   
        this.hogwartsStudent = false ; 
        this.actorName       = ""    ;       
        this.alive           = false ;
        this.alternateActors = null  ;           
        this.dateOfBirth     = LocalDate.of(-1, 1, 1);
        this.yearOfBirth     = -1    ;     
        this.eyeColour       = ""    ;       
        this.gender          = ""    ;          
        this.hairColour      = ""    ;      
        this.wizard          = false ;          
    } // Personagem ( )

    /**
     *  Construtor Alternativo.
     *  Inicializando todos os atributos com os valores passados.
     */
    Personagem ( String    id         , String  name         , String[]  alternateNames , 
                 String    house      , String  ancestry     , String    species        , 
                 String    patronus   , Boolean hogwartsStaff, Boolean   hogwartsStudent, 
                 String    actorName  , Boolean alive        , String[]  alternateActors,
                 LocalDate dateOfBirth, int     yearOfBirth  , String    eyeColour      , 
                 String    gender     , String  hairColour   , Boolean   wizard )
    {
        this.id              = id              ;
        this.name            = name            ;
        this.alternateNames  = alternateNames  ;
        this.house           = house           ;
        this.ancestry        = ancestry        ;
        this.species         = species         ;
        this.patronus        = patronus        ;
        this.hogwartsStaff   = hogwartsStaff   ;
        this.hogwartsStudent = hogwartsStudent ;
        this.actorName       = actorName       ;
        this.alive           = alive           ;
        this.alternateActors = alternateActors ;
        this.dateOfBirth     = dateOfBirth     ;
        this.yearOfBirth     = yearOfBirth     ;
        this.eyeColour       = eyeColour       ;
        this.gender          = gender          ;
        this.hairColour      = hairColour      ;
        this.wizard          = wizard          ;
    } // end Personagem ( )

    // ---------------------------------- Metodos GET

    public String    getId              ( ) { return ( this.id              ); }
    public String    getName            ( ) { return ( this.name            ); }
    public String[]  getAlternateNames  ( ) { return ( this.alternateNames  ); }
    public String    getHouse           ( ) { return ( this.house           ); }
    public String    getAncestry        ( ) { return ( this.ancestry        ); }
    public String    getSpecies         ( ) { return ( this.species         ); }
    public String    getPatronus        ( ) { return ( this.patronus        ); }
    public Boolean   getHogwartsStaff   ( ) { return ( this.hogwartsStaff   ); }
    public Boolean   getHogwartsStudent ( ) { return ( this.hogwartsStudent ); }
    public String    getActorName       ( ) { return ( this.actorName       ); }
    public Boolean   getAlive           ( ) { return ( this.alive           ); }
    public String[]  getAlternateActors ( ) { return ( this.alternateActors ); }
    public LocalDate getDateOfBirth     ( ) { return ( this.dateOfBirth     ); }
    public int       getYearOfBirth     ( ) { return ( this.yearOfBirth     ); }
    public String    getEyeColour       ( ) { return ( this.eyeColour       ); }
    public String    getGender          ( ) { return ( this.gender          ); }
    public String    getHairColour      ( ) { return ( this.hairColour      ); }
    public Boolean   getWizard          ( ) { return ( this.wizard          ); }
    
    // ---------------------------------- Metodos SET
    
    public void setId              ( String    id              ) { this.id              = id              ; }
    public void setName            ( String    name            ) { this.name            = name            ; }
    public void setAlternateNames  ( String[]  alternateNames  ) { this.alternateNames  = alternateNames  ; } 
    public void setHouse           ( String    house           ) { this.house           = house           ; }
    public void setAncestry        ( String    ancestry        ) { this.ancestry        = ancestry        ; }
    public void setSpecies         ( String    species         ) { this.species         = species         ; }
    public void setPatronus        ( String    patronus        ) { this.patronus        = patronus        ; }
    public void setHogwartsStaff   ( Boolean   hogwartsStaff   ) { this.hogwartsStaff   = hogwartsStaff   ; }
    public void setHogwartsStudent ( Boolean   hogwartsStudent ) { this.hogwartsStudent = hogwartsStudent ; }
    public void setActorName       ( String    actorName       ) { this.actorName       = actorName       ; }
    public void setAlive           ( Boolean   alive           ) { this.alive           = alive           ; }
    public void setAlternateActors ( String[]  alternateActors ) { this.alternateActors = alternateActors ; }
    public void setDateOfBirth     ( LocalDate dateOfBirth     ) { this.dateOfBirth     = dateOfBirth     ; }
    public void setYearOfBirth     ( int       yearOfBirth     ) { this.yearOfBirth     = yearOfBirth     ; }
    public void setEyeColour       ( String    eyeColour       ) { this.eyeColour       = eyeColour       ; }
    public void setGender          ( String    gender          ) { this.gender          = gender          ; }
    public void setHairColour      ( String    hairColour      ) { this.hairColour      = hairColour      ; }
    public void setWizard          ( Boolean   wizard          ) { this.wizard          = wizard          ; }
    
    public void set(String    id         , String  name         , String[] alternateNames , 
                    String    house      , String  ancestry     , String   species        , 
                    String    patronus   , Boolean hogwartsStaff, Boolean  hogwartsStudent, 
                    String    actorName  , Boolean alive        , String[] alternateActors,
                    LocalDate dateOfBirth, int     yearOfBirth  , String   eyeColour      , 
                    String    gender     , String  hairColour   , Boolean  wizard)
    {
        setId              ( id              );
        setName            ( name            );
        setAlternateNames  ( alternateNames  );
        setHouse           ( house           );
        setAncestry        ( ancestry        );
        setSpecies         ( species         );
        setPatronus        ( patronus        );
        setHogwartsStaff   ( hogwartsStaff   );
        setHogwartsStudent ( hogwartsStudent );
        setActorName       ( actorName       );
        setAlive           ( alive           );
        setAlternateActors ( alternateActors );
        setDateOfBirth     ( dateOfBirth     );
        setYearOfBirth     ( yearOfBirth     );
        setEyeColour       ( eyeColour       );
        setGender          ( gender          );
        setHairColour      ( hairColour      );
        setWizard          ( wizard          );
    } // end set ( )
    
    // ---------------------------------- Metodos Úteis

    public String[] tratamentoArrayString ( String str ) 
    {  
        String [] array = null;
        if( str == null ) {
            array = null;
        }
        else
        {
            String tratada = "";
            for( int x = 0; x < str.length( ); x = x + 1 )
            {
                if( str.charAt(x) == '[' ) {
                    tratada = tratada + '{';
                } else if( str.charAt(x) == ']' ) {
                    tratada = tratada + '}';
                } else if ( str.charAt(x) == '\'' ) {
                    tratada = tratada + "";
                } else {
                    tratada = tratada + str.charAt(x);
                } // end if
            } // end for
            array = tratada.split( "," );
        } // end if
        return ( array );
    } // tratamentoArrayString ( )

    public LocalDate tratamentoDate ( String str ) 
    {        
        return ( LocalDate.parse( str, DateTimeFormatter.ofPattern("dd-M-yyyy") ) );
    } // end tratamentoDate ( )

    public Boolean tratamentoBool( String str )
    {
        if( str.equals("VERDADEIRO") || str.equals("true") || str.equals("1") )
            return ( true );
        else
            return ( false );
    } // tratamentoBool ( )

    public int tratamentoInt( String str ) {
        return ( Integer.parseInt( str ) );
    } // tratamentoInt ( )

    public String altNamesToString ( ) 
    {
        String result = "";
        if( alternateNames == null ) {
            result = "{}";
        }
        else
        {
            for( int x = 0; x < this.alternateNames.length; x++ )
            {
                if( x < this.alternateNames.length-1 ) {
                    result = result + this.alternateNames[x] + ",";
                }
                else {        
                    result = result + this.alternateNames[x];
                }
            } // end for
        } // end if
        return( result );
    } // end altNamesToString ( )

    public String dateBirthToString ( )
    {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");
        String date = this.dateOfBirth.format(formatter);
        return ( date );
    } // end dateBirthToString ( )
    
    // ---------------------------------- Metodos Gerais

    /**
     *  Funcao para verificar se a entrada e' igual a "FIM" 
     *  @param s - String
     *  @return true se fim, false caso contrario.
     */
    public static boolean isFim( String s )
    {
        boolean result = false;
        if( s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M' )
        {
            result = true;
        } // end if
        return ( result );
    } // end isFim ( )

    /**
     *  Metodo para retornar os atributos de um objeto em forma de string. 
     */
    @Override
    public String toString( ) 
    {
        String toString = "";
        toString =  getId         ( ) + " ## " + getName         ( ) + " ## " + altNamesToString  ( ) + " ## " + 
                    getHouse      ( ) + " ## " + getAncestry     ( ) + " ## " + getSpecies        ( ) + " ## " + 
                    getPatronus   ( ) + " ## " + getHogwartsStaff( ) + " ## " + getHogwartsStudent( ) + " ## " + 
                    getActorName  ( ) + " ## " + getAlive        ( ) + " ## " + dateBirthToString ( ) + " ## " + 
                    getYearOfBirth( ) + " ## " + getEyeColour    ( ) + " ## " + getGender         ( ) + " ## " + 
                    getHairColour ( ) + " ## " + getWizard       ( ); 
		return ( toString );
	} // end toString ( )

    /**
     *  Metodo para clonar o personagem.
     *  @return Clone do Personagem.
     */
    public Personagem clone ( )
    {
        Personagem clone = new Personagem( );
        clone.setId             ( getId              ( ) );       
        clone.setName           ( getName            ( ) );         
        clone.setAlternateNames ( getAlternateNames  ( ) );  
        clone.setHouse          ( getHouse           ( ) );           
        clone.setAncestry       ( getAncestry        ( ) );        
        clone.setSpecies        ( getSpecies         ( ) );         
        clone.setPatronus       ( getPatronus        ( ) );        
        clone.setHogwartsStaff  ( getHogwartsStaff   ( ) );   
        clone.setHogwartsStudent( getHogwartsStudent ( ) );
        clone.setActorName      ( getActorName       ( ) );       
        clone.setAlive          ( getAlive           ( ) );           
        clone.setDateOfBirth    ( getDateOfBirth     ( ) );     
        clone.setYearOfBirth    ( getYearOfBirth     ( ) );     
        clone.setEyeColour      ( getEyeColour       ( ) );       
        clone.setGender         ( getGender          ( ) );          
        clone.setHairColour     ( getHairColour      ( ) );      
        clone.setWizard         ( getWizard          ( ) );
        return ( clone );
    } // clone ( )

    /**
     *  Metodo para imprimir personagem.
     */
    public void imprimir ( )
    {
        System.out.println( "[" + toString( ) + "]" );
    } // end imprimir ( )

    /**
     *  Metodo para imprimir personagem.
     */
    public void imprimir ( int x )
    {
        System.out.println( "[" + x + " ## " + toString( ) + "]" );
    } // end imprimir ( )

    /**
     *  Metodo para ler atributos dos personagem do arquivo.
     */
    public Personagem ler ( String id )
    {
        Personagem perso = new Personagem( );
        String path = "/tmp/characters.csv";
        // path = "C:\\Users\\vinic\\Desktop\\CC-PUCMG\\AEDs\\AEDs_II\\TPs\\TP04\\characters.csv";
        try 
        { 
            File file = new File( path );
            Scanner scan = new Scanner( file );
            
            scan.nextLine( ); // Ignorar o cabeçalho do arquivo
            
            boolean found = false;
            while( scan.hasNextLine() && !found )
            {
                String input = scan.nextLine( );
                if( id.equals( input.substring( 0, input.indexOf( ";" ) ) ) )
                {
                    found = true;
                    String [] atributos = input.split( ";" );
                    perso.set(  atributos[0], atributos[1], tratamentoArrayString(atributos[2]),
                                atributos[3], atributos[4], atributos[5], atributos[6],
                                tratamentoBool(atributos[7]), tratamentoBool(atributos[8]), atributos[9], 
                                tratamentoBool(atributos[10]), tratamentoArrayString(atributos[11]),
                                tratamentoDate(atributos[12]) , tratamentoInt(atributos[13]),
                                atributos[14],atributos[15], atributos[16], tratamentoBool(atributos[17])  );
                } // end if
            } // end while

            if( !found ) {
                System.out.println( "Character Not Found." );
            } // end if

            scan.close( );
        } // end try
        catch( FileNotFoundException e ) {
            System.out.println( "ERROR: File Not Found." );
        } // end catch
        return ( perso );
    } // end ler ( )

    public static Personagem findPerso ( Personagem [ ] personagens, int tam, String nome )
    {
        Personagem found = new Personagem( );
        for( int i = 0; i < tam; i = i +1 )
        {
            if( personagens[i].getName( ).equals(nome) ) {
                // System.out.println( "p["+i+"] = " + personagens[i].getName() + " nome = " + nome );
                found = personagens[i];
                i = tam;
            } // end if
        } // end for
        return ( found );
    } // end findPerso ( )
    
} // end class Personagem

/**
 * Classe ArvoreArvore : Teste
 */
public class ArvoreArvore extends Personagem
{
    public static void main ( String [] args ) throws Exception
    {
        Scanner scan = new Scanner( System.in );
        
        Personagem [] array = new Personagem[100];
        Log log = new Log( "812839_arvoreArvore.txt" );
        Personagem perso = new Personagem( );
        ArvoreBinaria arvore = new ArvoreBinaria( );

        String input = scan.nextLine( );
        int tam = 0;
        while( !isFim( input ) )
        {
            Personagem lido = perso.ler( input );
            arvore.inserir( lido );
            array[tam++] = lido;
            input = scan.nextLine( );
        } // end while

        long startTime = System.nanoTime();
        String name = scan.nextLine( );
        while( !isFim( name ) )
        {
            Personagem outro = findPerso( array, tam, name );
            System.out.print( name );
            Boolean found = arvore.pesquisar( outro, log );
            if ( found ) {
                System.out.println( "SIM" );
            } else {
                System.out.println( "NAO" );
            } // end if
            name = scan.nextLine( );
        } // end while
        long endTime = System.nanoTime();
        long totalTime = endTime - startTime;
        double time = totalTime / 1_000_000.0;
        log.setTime( time );
        log.registro( );
        scan.close( );
    } // end main ( )

} // end class ArvoreArvore
