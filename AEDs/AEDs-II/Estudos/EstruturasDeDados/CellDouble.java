public class CellDouble 
{
    // ---------------------------------------- Atributos

    public int data;
    public CellDouble left;  // link para a célula anterior
    public CellDouble right; // link para a próxima célula

    // ---------------------------------------- Construtores

    CellDouble ( )
    {
        this.data = 0;
        this.left = this.right = null;
    } // end CellDouble ( )
    
    CellDouble ( int value )
    {
        this.data = value;
        this.left = this.right = null;
    } // end CellDouble ( )
} // end class 
