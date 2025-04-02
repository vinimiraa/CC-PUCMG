public class ElementoLista implements Comparable<ElementoLista>, Cloneable 
{    
    private int id;
    private float frequencia;

    public ElementoLista( int i, float f ) 
    {
        this.id = i;
        this.frequencia = f;
    } // ElementoLista ( )

    public int getId( ) {
        return id;
    } // getId ( )

    public void setId( int id ) {
        this.id = id;
    } // setId ( )

    public float getFrequencia( ) {
        return frequencia;
    } // getFrequencia ( )

    public void setFrequencia( float frequencia ) {
        this.frequencia = frequencia;
    } // setFrequencia ( )

    @Override
    public String toString( ) {
        return "("+this.id+";"+this.frequencia+")";
    } // toString ( )

    @Override
    public ElementoLista clone( )
    {
        try {
            return (ElementoLista) super.clone();
        } 
        catch( CloneNotSupportedException e ) 
        {
            // Tratamento de exceção se a clonagem falhar
            e.printStackTrace();
            return null;
        } // try-catch
    } // clone ( )

    @Override
    public int compareTo( ElementoLista outro ) {
        return Integer.compare(this.id, outro.id);
    } // compareTo ( )
} // ElementoLista
