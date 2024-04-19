/*
 *  ----------------------------------------------------------------------------
 *  Biblioteca Matrix em C++ - "matrix.hpp"
 *  ----------------------------------------------------------------------------
 *  Copyright (c) 2023, Vinicius MIranda de Araujo
 *  Todos os direitos reservados.
 *  
 *  Este código fonte é propriedade exclusiva de Vinicius Miranda de Araujo e não pode ser
 *  copiado, modificado, distribuído, ou sublicenciado por qualquer outra pessoa
 *  sem autorização expressa por escrito do autor. O uso deste código está
 *  sujeito aos termos e condições estabelecidos no contrato de licença, se fornecido,
 *  ou, na ausência de tal contrato, pelos termos padrão da Licença MIT.
 *  ----------------------------------------------------------------------------
*/

#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

// ---------------------------------- Lista de Dependências

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>

using std::cin;      // para entrada
using std::cout;     // para saida
using std::endl;     // para mudar de linha
using std::setw;     // para definir espacamento
using std::string;   // para cadeia de caracteres
using std::ifstream; // para ler    arquivo
using std::ofstream; // para gravar arquivo

// ---------------------------------- Classe

template <typename T>
class Matrix
{
private:
    /**
     *  Atributos
    */
    int   row;
    int   col;
    T   **data;

public:
    /**
     *  Construtor Padrão 
    */
    Matrix( void )
    {
        this->row = 0;
        this->col = 0;
        data = nullptr;
    } // end Matrix ( )

    /**
     *  Construtor Alternativo
    */
    Matrix( int row, int col )
    {
        bool OK = true;

        if( row > 0 && col > 0 )
        {
            this->row = row;
            this->col = col;

            data =  new T *[row];
            if( data != nullptr )
            {
                for( int x = 0; x < row; x = x + 1 )
                {
                    data[x] = new T[col];
                    OK = OK && (data[x] != nullptr);
                } // end for
                if (!OK)
                {
                    data = nullptr;
                } // end if
            } // end if
        } // end if
    } // end Matrix ( )

    /**
     *  Destrutor
    */
    ~Matrix()
    {
        if (data != nullptr)
        {
            for (int x = 0; x < row; x = x + 1)
            {
                delete (data[x]);
            } // end for
            delete (data);
            data = nullptr;
        } // end if
    } // end ~Matrix ( )

    /**
     *  Método para pegar o número de linhas.
     *  @return Número de Linhas.
    */
    int getRow( )
    {
        return ( this->row );
    } // end getRow( )

    /**
     *  Método para pegar o número de colunas.
     *  @return Número de Colunas.
    */
    int getCol( )
    {
        return ( this->col );
    } // end getCol ( )

    /**
     *  Método para pegar o valor de um lugar específico da matriz.
     *  @return Número na linha e coluna passada.
     *  @param row Linha
     *  @param col Coluna
    */
    T get( int row, int col )
    {
        T value = 0;

        if ( row < 0 || row >= this->row || col < 0 || col >= this->column )
        {
            cout << "\nERROR: Invalid position.\n";
        }
        else
        {
            value = data[row][col];
        } // end if

        return (value);
    } // end get ( )

    /**
     *  Método para atribuir um valor ao número de linhas.
     *  @param row Número de linhas.
    */
    void setRow( int row )
    {
        if( row >= 0 )
        {
            this->row = row;
        } // end if
    } // end setRow ( )

    /**
     *  Método para atribuir um valor ao número de colunas.
     *  @param col Número de colunas.
    */
    void setCol( int col )
    {
        if( col >= 0 )
        {
            this->col = col;
        } // end if
    } // end setCol ( )

    /**
     *  Método para atribuir um valor em um lugar específico da matriz.
     *  @param row Linha.
     *  @param col Coluna.
     *  @param value Valor a ser atribuido na linha e coluna.
    */
    void set( int row, int col, T value )
    {
        if( row >= 0 && col >= 0 )
        {
            this->data[row][col] = value;
        } // end if
    } // end set ( )

    /**
     *  Método para mostrar a matriz na tela.
    */
    void print( )
    {
        cout << endl;
        for (int x = 0; x < row; x = x + 1)
        {
            for (int y = 0; y < col; y = y + 1)
            {
                cout << data[x][y] << "\t";
            } // end for
            cout << endl;
        } // end for
        cout << endl;
    } // end print ( )

    /**
     *  Método para ler os dados de uma matriz.
    */
    void read( )
    {
        cout << endl;
        for (int x = 0; x < row; x = x + 1)
        {
            for (int y = 0; y < col; y = y + 1)
            {
                cout << setw(2) << x << ", "
                    << setw(2) << y << " : ";
                cin >> data[x][y];
            } // end for
        }     // end for
        cout << endl;
    } // end read ( )

    /**
     *  Método para gravar no arquivo uma matriz.
     *  @param fileName Nome do arquivo.
    */
    void fprint( string fileName )
    {
        ofstream afile;

        afile.open(fileName);
        afile << row << endl;
        afile << col << endl;

        for (int x = 0; x < row; x = x + 1)
        {
            for (int y = 0; y < col; y = y + 1)
            {
                afile << data[x][y] << endl;
            } // end for
        } // end for

        afile.close();
    } // end fprint ( )

    /**
     *  Método para ler do arquivo uma matriz.
     *  @param fileName Nome do arquivo.
    */
    void fread( string fileName )
    {
        ifstream afile;
        int m = 0;
        int n = 0;

        afile.open(fileName);
        afile >> m;
        afile >> n;

        if (m <= 0 || n <= 0)
        {
            cout << "\nERROR: Invalid dimensions for matrix.\n" << endl;
        }
        else
        {
            this->row = m;
            this->col = n;

            data = new T *[row];
            for (int x = 0; x < row; x = x + 1)
            {
                data[x] = new T[col];
            } // end for

            for (int x = 0; x < row; x = x + 1)
            {
                for (int y = 0; y < col; y = y + 1)
                {
                    afile >> data[x][y];
                } // end for
            } // end for
        } // end if

        afile.close();
    } // end fread ( )

    /**
     *  Método para fazer a transposição de uma matriz.
     *  @return Matriz transposta.
    */
    Matrix<T> transpose( )
    {
        static Matrix<T> result( 1, 1 );
        int x = 0;
        int y = 0;

        if ( row == 0 || col == 0 )
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            result.row = this->col;
            result.col = this->row;
            result.data = new T *[result.row];

            for ( x = 0; x < result.row; x = x + 1 ) 
            {
                result.data[x] = new T[result.col];
            } // end for

            for ( x = 0; x < result.row; x = x + 1 )
            {
                for ( y = 0; y < result.col; y = y + 1 )
                {
                    result.data[x][y] = this->data[y][x];
                } // end for
            } // end for
        } // end if

        return ( result );
    } // end transpose ( )

    /**
     *  Método para fazer a transposição de uma matriz.
     *  @return Matriz transposta.
     *  @param other Matriz;
    */
    Matrix<T> transpose( const Matrix<T> &other )
    {
        static Matrix<T> result( 1, 1 );
        int x = 0;
        int y = 0;

        if ( other.row == 0 || other.col == 0 )
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            result.row = other.col;
            result.col = other.row;
            result.data = new T *[result.row];

            for ( x = 0; x < result.row; x = x + 1 ) 
            {
                result.data[x] = new T[result.col];
            } // end for

            for ( x = 0; x < result.row; x = x + 1 )
            {
                for ( y = 0; y < result.col; y = y + 1 )
                {
                    result.data[x][y] = other.data[y][x];
                } // end for
            } // end for
        } // end if

        return ( result );
    } // end transpose ( )

    /**
     *  Método para multiplicar cada elemento da matriz por uma constante.
     *  @return Matriz resultante.
     *  @param k Constante.
    */
    Matrix<T> scalar( T k )
    {
        Matrix<T> result( this->rows, this->columns );
        int x = 0;
        int y = 0;

        for( x = 0; x < result.rows; x = x + 1 )
        {
            for( y = 0; y < result.columns; y = y + 1 )
            {
                // result.set( x, y, this->get( x, y ) * k) ;
                result.data[x][y] = this->data[x][y] * k;
            } // end for
        } // end for

        return ( result );
    } // end scalar ( )

    /**
     *  Método para fazer a soma entre duas matrizes.
     *  add_Matrix ( )
     *  @return Matriz resultante da soma.
    */
    Matrix<T> &operator+( const Matrix<T> &other ) 
    {
        static Matrix<T> result( 1, 1 );
        int x = 0;
        int y = 0;

        if ( other.row == 0 || row != other.row ||
            other.col == 0 || col != other.col )
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            result.row = row;
            result.col = other.col;
            result.data = new T *[result.row];

            for ( int x = 0; x < result.row; x = x + 1 ) 
            {
                result.data[x] = new T[result.col];
            } // end for

            for ( int x = 0; x < result.row; x = x + 1 )
            {
                for ( int y = 0; y < result.col; y = y + 1 )
                {
                    result.data[x][y] = data[x][y] + other.data[x][y];
                } // end for
            } // end for
        } // end if

        return ( result );
    } // end operator+ ( )

    /**
     *  Método para fazer a diferença entre duas matrizes.
     *  diff_Matrix ( )
     *  @return Matriz resultante da diferença.
    */
    Matrix<T> &operator-( const Matrix<T> &other ) 
    {
        static Matrix<T> result( 1, 1 );
        int x = 0;
        int y = 0;

        if ( other.row == 0 || row != other.row ||
            other.col == 0 || col != other.col )
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            result.row = row;
            result.col = other.col;
            result.data = new T *[result.row];

            for ( int x = 0; x < result.row; x = x + 1 ) 
            {
                result.data[x] = new T[result.col];
            } // end for

            for ( int x = 0; x < result.row; x = x + 1 )
            {
                for ( int y = 0; y < result.col; y = y + 1 )
                {
                    result.data[x][y] = data[x][y] - other.data[x][y];
                } // end for
            } // end for
        } // end if

        return ( result );
    } // end operator- ( )

    /**
     *  Método para fazer o produto entre duas matrizes.
     *  product_Matrix ( )
     *  @return Matriz resultante do produto.
    */
    Matrix<T> &operator*(const Matrix<T> &other)
    {
        static Matrix<T> result( 1, 1 );
        int x = 0;
        int y = 0;
        int z = 0;
        int sum = 0;

        if ( row <= 0 || col == 0 ||
            other.row <= 0 || other.col == 0 ||
            col != other.row )
        {
            cout << endl << "ERROR: Invalid data." << endl;
            result.data[0][0] = 0;
        }
        else
        {
            result.row = row;
            result.col = other.col;
            result.data = new T *[result.row];

            for ( int x = 0; x < result.row; x = x + 1 )
            {
                result.data[x] = new T[result.col];
            } // end for

            for ( x = 0; x < result.row; x = x + 1 )
            {
                for ( y = 0; y < result.col; y = y + 1 )
                {
                    sum = 0;
                    for ( z = 0; z < col; z = z + 1 )
                    {
                        sum = sum + data[x][z] * other.data[z][y];
                    } // end for
                    result.data[x][y] = sum;
                } // end for
            } // end for
        } // end if

        return (result);
    } // end operator* ( )

    /**
     *  Método para igualar(copiar) uma matriz.
     *  cpy_Matrix ( )
     *  @return Matriz copiada.
    */
    Matrix<T> &operator=(const Matrix<T> &other)
    {
        if (other.row == 0 || other.col == 0)
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            this->row = other.row;
            this->col = other.col;
            this->data = new T *[row];

            for (int x = 0; x < row; x = x + 1)
            {
                this->data[x] = new T[col];
            } // end for

            for (int x = 0; x < this->row; x = x + 1)
            {
                for (int y = 0; y < this->col; y = y + 1)
                {
                    data[x][y] = other.data[x][y];
                } // end for
            } // end for
        } // end if

        return (*this);
    } // end operator= ( )

    /**
     *  Método para fazer a diferença entre duas matrizes.
     *  compare_Matrix ( )
     *  @return true: se iguais; false: caso contrário.
    */
    bool &operator!=(const Matrix<T> &other)
    {
        bool result = false;
        int x = 0;
        int y = 0;

        if (other.row == 0 || row != other.row ||
            other.col == 0 || col != other.col)
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            x = 0;
            while (x < row && !result)
            {
                y = 0;
                while (y < col && !result)
                {
                    result = (data[x][y] != other.data[x][y]);
                    y = y + 1;
                } // end while
                x = x + 1;
            } // end while
        } // end if

        return (result);
    } // end operator!= ( )

    /**
     *  Método para fazer a igualdade entre duas matrizes.
     *  compare_Matrix ( )
     *  @return true: se iguais; false: caso contrário.
    */
    bool &operator== (const Matrix<T> &other)
    {
        bool result = true;
        int x = 0;
        int y = 0;

        if (other.row == 0 || row != other.row ||
            other.col == 0 || col != other.col)
        {
            result = false;
        }
        else
        {
            x = 0;
            while ( x < row )
            {
                y = 0;
                while ( y < col )
                {
                    if ( data[x][y] != other.data[x][y] )
                    {
                        result = false;
                    }
                    y = y + 1;
                } // end while
                x = x + 1;
            } // end while
        } // end if

        return (result);
    } // end operator== ( )

}; // end class

// ---------------------------------- Fim
#endif
