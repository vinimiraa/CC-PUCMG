#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <wchar.h>   
#include <locale.h>  

// ---------------------------------- Struct

typedef struct tm Date;

typedef struct s_Personagem
{
    char*   id              ; 
    char*   name            ; 
    char*   alternateNames  ;
    char*   house           ; 
    char*   ancestry        ; 
    char*   species         ; 
    char*   patronus        ; 
    bool    hogwartsStaff   ;  
    bool    hogwartsStudent ;  
    char*   actorName       ; 
    bool    alive           ;
    char*   alternateActors ; 
    char*   dateOfBirth     ; 
    int     yearOfBirth     ; 
    char*   eyeColour       ; 
    char*   gender          ; 
    char*   hairColour      ; 
    bool    wizard          ; 
} Personagem;

// ---------------------------------- Funções

/**
 *  "Construtor"
*/
void newPersonagem ( Personagem* personagem,
                  char* id             , char*  name       , char* alternateNames, char* house          , 
                  char* ancestry       , char*  species    , char*   patronus     , bool  hogwartsStaff  ,
                  bool  hogwartsStudent, char* actorName  , bool    alive        , char* alternateActors, 
                  char*  dateOfBirth    , int    yearOfBirth, char*   eyeColour    , char* gender         , 
                  char* hairColour     , bool wizard )
{
    if( personagem != NULL )
    {
        personagem->id               = id              ;                             
        personagem->name             = name            ;                         
        personagem->alternateNames   = alternateNames  ;                 
        personagem->house            = house           ;                           
        personagem->ancestry         = ancestry        ;                     
        personagem->species          = species         ;                       
        personagem->patronus         = patronus        ;                     
        personagem->hogwartsStaff    = hogwartsStaff   ;                   
        personagem->hogwartsStudent  = hogwartsStudent ;               
        personagem->actorName        = actorName       ;                       
        personagem->alive            = alive           ;                           
        personagem->alternateActors  = alternateActors ;               
        personagem->dateOfBirth      = dateOfBirth     ;                   
        personagem->yearOfBirth      = yearOfBirth     ;                   
        personagem->eyeColour        = eyeColour       ;                       
        personagem->gender           = gender          ;                         
        personagem->hairColour       = hairColour      ;                     
        personagem->wizard           = wizard          ;                         
    } // end if
} // end personagem

/**
 *  Função para imprimir um personagem.
*/
void imprimir ( Personagem* personagem )
{
    printf( "[%s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %d ## %s ## %s ## %s ## %s]\n",
            personagem->id,
            personagem->name,
            personagem->alternateNames,
            personagem->house,
            personagem->ancestry,
            personagem->species,
            personagem->patronus,
            personagem->hogwartsStaff ? "true" : "false",
            personagem->hogwartsStudent ? "true" : "false",
            personagem->actorName,
            personagem->alive ? "true" : "false",
            personagem->dateOfBirth,
            personagem->yearOfBirth,
            personagem->eyeColour,
            personagem->gender,
            personagem->hairColour,
            personagem->wizard ? "true" : "false" ); 
} // end imprimir ( )

void tratamento( char** atributos, char* linha )
{
    if( linha[0] == '\0' ) 
    {
        for( int x = 0; x < 18; x = x + 1 ) {
            atributos[x] = "[]";
        } // end for
    } 
    else 
    {
        // atributos[0] = strtok( linha, ";" );
        char* token = strtok( linha, ";" );
        for( int x = 0; x < 18; x = x + 1 ) 
        {
            if( token == NULL ) {
                atributos[x] = "[]";
            }
            else {
                atributos[x] = token;
            } // end if
            token = strtok( NULL, ";" );
        } // end for
    } // end if
} // end tratamento

/**
 *  Função para os personagens de um arquivo.
*/
Personagem* ler(Personagem* personagem, char* filename, char* id_procurado) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("\nERROR: File Not Found.\n");
    } else {
        char line[500];
        bool idFound = false;

        // Pula a linha de cabeçalho
        fgets(line, sizeof(line), file);

        // Processa as demais linhas
        while (fgets(line, sizeof(line), file) != NULL && !idFound) {
            char *atributos[18];
            int index = 0;
            char *token = strtok(line, ";");

            while (token != NULL) {
                
                atributos[index++] = strdup(token);
                token = strtok(NULL, ";");
            }
        char aux[500] = {0};
        int j = 0;
        for (int i = 0; i < strlen(atributos[2]); i++) {
            if (atributos[2][i] == '[') {
                aux[j] = '{';
            } else if (atributos[2][i] == ']') {
                aux[j] = '}';
            } else if (atributos[2][i] == '\'') {
                continue; 
            } else {
                aux[j] = atributos[2][i];
            }
            j++; 
        }
        aux[j] = '\0'; 

        free(atributos[2]); 
        atributos[2] = strdup(aux);

            if (index == 18 && strcmp(atributos[0], id_procurado) == 0) {
                printf("0 - %s\n",atributos[0]);
                newPersonagem(personagem,
                              atributos[0], atributos[1], atributos[2], atributos[3],
                              atributos[4], atributos[5], atributos[6],
                              strcmp(atributos[7], "true") == 0,
                              strcmp(atributos[8], "true") == 0,
                              atributos[9], strcmp(atributos[10], "true") == 0,
                              atributos[11], atributos[12],
                              atoi(atributos[13]), atributos[14], atributos[15],
                              atributos[16], strcmp(atributos[17], "true") == 0);
                idFound = true;
                return personagem;
            }

            // Libera memória alocada para atributos
            for (int x = 0; x < index; x++) {
                free(atributos[x]);
            }
        }
        fclose(file);
    }
}

/**
 *  Funcao Principal.
*/
int main ( void )
{
    setlocale(LC_CTYPE, "UTF-8"); // setCharset

    Personagem* perso = (Personagem*) malloc ( 1 * sizeof(Personagem) );
    char* filename = "tmp/characters.csv"; 
    char id[81];
    // char* filename = "C:\\Users\\vinic\\Desktop\\AEDs-II\\TPs\\TP02\\characters.csv"; 

    scanf( "%s", id ); getchar( );

    while( strcmp( id,"FIM" ) != 0 )
    {
        perso = ler( perso, filename, id );
        imprimir( perso );
        scanf( "%s", id ); getchar( );
    } // end while

    free( perso );
    perso = NULL;
    return ( 0 );
} // end main