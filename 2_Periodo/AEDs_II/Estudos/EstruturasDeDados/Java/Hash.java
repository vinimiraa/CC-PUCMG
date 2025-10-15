public class Hash 
{
    int tabela[];
    int m;
    final int NULO = -1;

    public Hash ( ) {
        this(13);
    }

    public Hash (int m) 
    {
        this.m = m;
        this.tabela = new int[this.m];
        for (int i = 0; i < m; i++) {
            tabela[i] = NULO;
        }
    }

    public int h (int elemento) {
        return elemento % m;
    }

    public int reh (int elemento) {
        return ++elemento % m;
    }

    public boolean inserir (int elemento) 
    {
        boolean resp = false;
        if (elemento != NULO) {
            int pos = h(elemento);
            if (tabela[pos] == NULO) {
                tabela[pos] = elemento;
                resp = true;
            } else {
                pos = reh(elemento);
                if (tabela[pos] == NULO) {
                    tabela[pos] = elemento;
                    resp = true;
                }
            }
        }
        return (resp);
    }

    public boolean pesquisar (int elemento) 
    {
        boolean resp = false;
        int pos = h(elemento);
        if (tabela[pos] == elemento) {
            resp = true;
        } else if (tabela[pos] != NULO) {
            pos = reh(elemento);
            if (tabela[pos] == elemento) {
                resp = true;
            }
        }
        return (resp);
    }

    public boolean remover (int elemento) 
    {
        boolean resp = false;
        int pos = h(elemento);
        if (tabela[pos] == elemento) {
            tabela[pos] = NULO;
            reh(pos);
            resp = true;
        } else if (tabela[pos] != NULO) {
            pos = reh(elemento);
            if (tabela[pos] == elemento) {
                tabela[pos] = NULO;
                reh(pos);
                resp = true;
            }
        }
        return (resp);
    }
} // end class Hash 