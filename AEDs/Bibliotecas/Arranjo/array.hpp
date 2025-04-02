/*
 *  ----------------------------------------------------------------------------
 *  Biblioteca de Arranjos em C++ - "arranjo.hpp"
 *  ----------------------------------------------------------------------------
*/

// ---------------------------------- Lista de Dependências

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::ifstream;
using std::ofstream;
using std::string;

// ---------------------------------- Definições Úteis

#ifndef __arranjo_HPP__
#define __arranjo_HPP__

// ---------------------------------- Protótipo da Classe

template <typename T>
class arranjo
{
private:
    /**
     *  Atributos
    */
    int size;
    T  *data;
    T   optional;
    int ix  ;

public:
    /**
     *  Construtor padrão.
    */
    arranjo ( void )
    {
        this->size = 0;
        this->data = nullptr;
        this->ix = -1;
    } // end arranjo ( )

    /**
     *  Construtor Alternativo.
    */
    arranjo ( int size )
    {
        this->size = 0;
        this->data = nullptr;
        this->ix = -1;
        if( size > 0 )
        {
            this->size = size;
            this->data = new T [ size ];
            this->ix = 0;
        } // end if
    } // end arranjo ( )

    /**
     *  Construtor Alternativo.
    */
    arranjo ( int size, T optional )
    {
        this->size = 0;
        this->data = nullptr;
        this->ix = -1;
        if( size > 0 )
        {
            this->size = size;
            this->data = new T [ size ];
            for( this->ix = 0; this->ix < size; this->ix = this->ix + 1 )
            {
                this->data[this->ix] = optional;
            } // end for
            this->ix = 0;
        } // end if
    } // end arranjo ( )

    /**
     *  Inserir o tamanho do arranjo.
    */
    void set_size( int size )
    {
        if( size > 0 )
        {
            this->size = size;
        } // end if
    } // end set_size ( )

    /**
     *  Acessar o tamanho do arranjo.
     *  @return tamanho do arranjo.
    */
    int get_size( void )
    {
        int value = 0;
        value = this->size;
        return ( value );
    } // end get_size( );

    /**
     *  Inserir um valor em uma posição específica.
    */
    void set( int index, T value )
    {
        if( 0 <= index && index < this->size )
        {
            this->data[index] = value;
        } // end if
    } // end set ( )

    /**
     *  Acessar um valor em uma posição específica.
     *  @return valor na posição.
    */
    T get( int index )
    {
        T value = optional;
        if( 0 <= index && index < this->size )
        {
            value = this->data[index];
        }
        return ( value );
    } // end get ( )

    /**
     *  Mostrar na saída padrão os dados do arranjo.
    */
    void print( void )
    {
        cout << endl;
        for( this->ix = 0; this->ix < this->size; this->ix = this->ix + 1 )
        {
            cout << setw( 3 ) << this->ix << " : " << setw( 3 ) 
                << this->data[this->ix] << endl; 
        } // end for
        cout << endl;
    } // end print ( )

    /**
     *  Ler da entrada padrão os dados do arranjo.
    */
    void read( void )
    {
        cout << endl; 
        for( this->ix = 0; this->ix < this->size; this->ix = this->ix + 1 ) 
        { 
            cout << setw( 3 ) << this->ix << " : "; 
            cin >> data[ this->ix ]; 
        } // end for 
        cout << endl;
    } // end read ( )

    /**
     *  Gravar em um arquivo os dados do arranjo;
    */
    void fprint( string filename )
    {
        ofstream afile;
        afile.open( filename ); 
        afile << this->size << endl; 
        for( this->ix = 0; this->ix < this->size; this->ix = this->ix + 1 ) 
        { 
            afile << this->data[ this->ix ] << endl; 
        } // end for 
        afile.close( ); 
    } // end fprint ( )

    /**
     *  Ler os dados de um arquivo e armazená-los no arranjo.
    */
    void fread( string filename )
    {
        ifstream afile;
        int n = 0; 
        afile.open ( filename ); 
        afile >> n; 
        if( n <= 0 ) 
        { 
            cout << "\n[ERRO]: Invalid size.\n" << endl; 
        } 
        else 
        { 
            this->size  = n; 
            this->data = new T [ n ]; 
            for( this->ix = 0; this->ix < this->size; this->ix = this->ix + 1 ) 
            { 
                afile >> data[ this->ix ]; 
            } // end for 
        } // end if 
        afile.close( ); 
    } // end fread ( )

    /**
     *  Ordenar o arranjo em ordem crescente.
    */
    void sort_up( void )
    {
        int x = 0, y = 0;
        T value = optional;
        for ( x = 1; x < this->size; x = x+1 )
        {
            for ( y = 1; y < this->size; y = y+1 )
            {
                if ( get ( y-1 ) > get ( y ) )
                {
                    value = get ( y );
                    set ( y, get ( y-1 ) );
                    set ( y-1, value );
                } // end if
            } // end for
        } // end for
    } // end sort_up ( )

    /**
     *  Sobrecarga do operardor de igualdade.
     *  Copiar um arranjo para outro arranjo.
    */
    arranjo<T>& operator=( const arranjo <T> other ) 
    { 
        if ( other.size <= 0 ) 
        { 
            cout << "\n[ERROR]: Missing data.\n" << endl; 
        } 
        else 
        { 
            this->size = other.size; 
            this->data = new T [ other.size ]; 
            for ( this->ix = 0; this->ix < this->size; this->ix = this->ix + 1 ) 
            { 
                data [ this->ix ] = other.data [ this->ix ]; 
            } // end for 
        } // end if 
        return ( *this ); 
    } // end operator= ( )

}; // end class

// ---------------------------------- Fim
#endif
