package un2aula3;

public class fila {
    private int[] valores;
    private int primeiro;
    private int ultimo;
    private int total;


    public fila() {
        valores = new int[10];
        primeiro = 0;
        ultimo = 0;
        total = 0;
    }

    public void inserir(int elemnto){
        valores[ultimo] = elemnto;
        ultimo = ultimo++;
        total++;
    }

    public int remover(){
        int elemento = valores[primeiro];
        //primeiro++;
        total--;
        return elemento;
    }
    public boolean isEmpty(){
        return (total == 0);
    }
    public boolean isFull(){
        return (total == valores.length);
    }
}
