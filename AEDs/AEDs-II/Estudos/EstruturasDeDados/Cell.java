public class Cell 
{
    // ---------------------------------------- Atributos

    public int data;
    public Cell link; // link para a próxima célula

    // ---------------------------------------- Construtores

    Cell ( )
    {
        this.data = 0;
        this.link = null;
    } // end Cell ( )

    Cell ( int value )
    {
        this.data = value;
        this.link = null;
    } // end Cell ( )
} // end class
