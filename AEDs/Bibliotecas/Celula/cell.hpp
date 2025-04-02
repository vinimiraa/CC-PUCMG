/*
 *  ----------------------------------------------------------------------------
 *  Biblioteca de Celula em C++ - "cell.hpp"
 *  ----------------------------------------------------------------------------
*/

// ---------------------------------- Lista de Dependências

#ifndef __CELL_HPP__
#define __CELL_HPP__

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;

// ---------------------------------- Classe

template <typename T>
class Cell
{
    protected:
        /**
         *  Atributos
        */
        T     value;
        Cell *right;
        Cell *left ;
    
    public:
        /**
         *  Default Constructor.
         *  Construtor Padrão.  
        */
        Cell( void )
        {
            this->value = 0;
            this->left  = nullptr;
            this->right = nullptr;
        } // end Cell ( ) 

        /**
         *  Alternative Constructor.
         *  Construtor Alternativo.
        */
        Cell( T value )
        {
            this->value = value;
            this->left  = nullptr;
            this->right = nullptr;
        } // end Cell ( )

        /**
         *  Alternative Constructor.
         *  Construtor Alternativo.
        */
        Cell( T value, Cell* left, Cell* right )
        {
            this->value = value;
            this->left  = left ;
            this->right = right;
        } // end Cell ( )

        /**
         *  Method to change the value.
         *  Método para mudar o valor.
        */
        void set_value( T value )
        {
            this->value = value;
        } // end set_value ( )

        /**
         *  Method to access the value.
         *  Método para acessar o valor.
        */
        T get_value( void )
        {
            return ( this->value );
        } // end get_value ( )

        /**
         *  Method to link the left side.
         *  Método para linkar o lado esquerdo.
        */
        void set_left( Cell* link   )
        {
            this->left = link;
        } // end set_left ( )

        /**
         *  Method to access the link on the left.
         *  Método para acessar o link do lado esquerdo.
        */
        Cell* get_left( void )
        {
            Cell* link = nullptr;
            link = this->left;
            return ( link );
        } // end get_left ( )

        /**
         *  Method to link the right side.
         *  Método para linkar o lado direito.
        */
        void set_right( Cell* link   )
        {
            this->right = link;
        } // end set_rigth ( )

        /**
         *  Method to access the link on the right.
         *  Método para acessar o link do lado direito.
        */
        Cell* get_right( void )
        {
            Cell* link = nullptr;
            link = this->right;
            return ( link );
        } // end get_right ( )

        /**
         *  Method for connecting a cell.
         *  Método para conectar uma célula.
        */
        void connect( Cell* second )
        {
            if( second )
            {
                second->set_left( this );
                this->set_right( second );
            } // end if
        } // end connect ( )

        /**
         *  Method to disconnect a cell.
         *  Método para desconectar uma célula.
        */
        void disconnect( Cell* second )
        {
            if( this->get_right( ) == second )
            {
                second->set_left( nullptr );
                this->set_right( nullptr );
            } // end if
        } // end disconnect ( )

        /**
         *  Method to show cells on the right side.
         *  Método para mostrar as células do lado direito.
        */
        void rprint( void )
        {
            Cell* tmp = this; 
            if( !tmp )           
            {
                cout << "[]";
            }
            else
            {
                while( tmp )
                {
                    cout << tmp->get_value( ) << setw( 3 );
                    tmp = tmp->get_right( ); 
                } // end while
            } // end if
            cout << endl;
        } // end rprint ( )

        /**
         *  Method to show cells on the left side.
         *  Método para mostrar as células do lado esquerdo.
        */
        void lprint( void )
        {
            Cell* tmp = this; 
            if( !tmp )           
            {
                cout << "[]";
            }
            else
            {
                while( tmp )
                {
                    cout << tmp->get_value( ) << setw( 3 );
                    tmp = tmp->get_left( ); 
                } // end while
            } // end if
            cout << endl;
        } // end 

        /**
         *  Method to obtain the number of cells.
         *  Método para obter a quantidade de células.
        */
        int tamanho( void )
        {
            Cell* tmp    = this;
            int   tamanho = 0;
            while( tmp )
            {
                tamanho = tamanho + 1;
                tmp    = tmp->get_right( );
            } // end while
            return ( tamanho );
        } // end Cell:tamanho ( )

        /**
         *  Method to insert new cell at the end.
         *  Método para inserir nova célula no final.
        */
        Cell* push_back( T value )
        {
            Cell* tmp  = new Cell( value );
            Cell* back = this;
            if( back && tmp )
            {
                while( back->right != nullptr )
                {
                    back = back->get_right( );
                } // end while
                back->connect( tmp );
                back = tmp;
            } // end if
            return ( back );
        } // end push_back ( )

        /**
         *  Method to remove cell from end.
         *  Método para remover célula do final.
        */
        Cell* pop_back( void )
        {
            Cell* back = nullptr;
            Cell* last = nullptr;
            back = this;
            last = this;
            while( back->right ) 
            {
                last = back;
                back = back->right;
            } // end while	
            if( last != back )
            {
                last->disconnect( back );
            } // end if
            return ( back );
        } // end pop_back ( )

        /**
         *  Method to insert a cell at the beginning.
         *  Método para inserir uma célula no inicio.
        */
        Cell* push_front( T value )
        {
            Cell* tmp = new intCell ( 0 );
            if( tmp )
            {
                tmp->set_left( this->get_left( ) );
                tmp->set_right( this->get_right( ) );
                tmp->set_value( this->get_value( ) );
                this->set_value( value );
                this->connect( tmp   );
            } // end if
            return ( this );
        } // end push_front ( )

        /**
         *  Method to remove cell from the beginning.
         *  Método para remover célula do inicio.
        */
        Cell* pop_front( void )
        {
            int value = 0;
            Cell* tmp = nullptr;
            if ( this->get_right( ) )
            {
                value = this->get_value( );
                tmp   = this->get_right( );
                this->set_right( tmp->get_right( ) );

                if( tmp->get_right( ) )
                    tmp->get_right( )->set_left( this );

                this->set_value( tmp->get_value( ) );
                tmp->set_value( value );

                if( tmp->get_right( ) )
                    tmp->disconnect( tmp->get_right( ) );
                else
                    this->set_right( nullptr );
            } // end if
            return ( tmp );
        } // end Cell:pop_front ( )

        /**
         *  Method to get the contents of a cell at a certain position.
         *  Método para obter o conteúdo de uma célula em certa posição.
        */
        T at( unsigned int index )
        {
            int value = 0;
            int x     = 0;
            Cell* cursor = this;
            if ( 0 <= index && index < this->inttamanho( ) )
            {
                x = index;
                while ( x > 0 )
                {
                    cursor = cursor->get_right( );
                    x = x - 1;
                } // end while
                value = cursor->get_value( );
            } // end if
            return ( value );
        } // end Cell:at ( )

        /**
         *  Method for exchanging cell contents.
         *  Método para trocar conteúdos de células.
        */
        void swap( Cell* second )
        {
            int value = 0;
            if ( second )
            {
                value  = this->get_value( );
                this->set_value( second->get_value( ) );
                second->set_value( value );
            } // end if
        } // end Cell:swap ( )

}; // end class

// ---------------------------------- Fim
#endif
