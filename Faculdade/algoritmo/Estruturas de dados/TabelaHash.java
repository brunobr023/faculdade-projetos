import java.util.LinkedList;

public class TabelaHash{

    private int capacidade;
    private LinkedList<Elemento>[] tabela;

    //construtor da tabelaHash
    public TabelaHash(int capacidade){
        this.capacidade = capacidade;
        this.tabela = new LinkedList[capacidade];
    }

    //Função de espalhamento simples
    private int calcularHash(String chave){
        return chave.length() % capacidade;
    }

    //metodo para inserir um elemento
    public void inserir(String chave, String valor){
        int indice = calcularHash(chave);
        if (tabela[indice] == null) {
            tabela[indice] = new LinkedList<>();

        }
        tabela[indice].add(new Elemento(chave, valor));
    }

    //Metodo para pesquisar um elemento na tabela HASH
    public String pesquisar(String chave){
        int indice = calcularHash(chave);
        LinkedList<Elemento> lista = tabela[indice];
        if(lista != null){
            for(Elemento elemento : lista){
                if (elemento.getChave().equals(chave)) {
                    return elemento.getValor();
                }
            }
        }
        return null; //Retorna null se não encontrado 
    }

    // Classe interna do elemento - Ela estár representando um par chave-valor
    private class Elemento {
        private String chave;
        private String valor;
        

        public Elemento(String chave, String valor){
            this.chave = chave;
            this.valor = valor;
        }

        public String getChave(){
            return chave;
        }
        
        public String getValor(){
            return valor;
        }
    }


    public static void main(String[] args) {
        
        TabelaHash tabela = new TabelaHash(10);


        
        tabela.inserir("chave1", "valor1");   
        tabela.inserir("chave2", "valor2");
        tabela.inserir("chave3", "valor3");
        
        System.out.println(tabela.pesquisar("chave1")); //SAIDA VALOR 1
        System.out.println(tabela.pesquisar("chave2")); //SAIDA VALOR 2
        System.out.println(tabela.pesquisar("chave4")); //SAIDA VALOR NULL
    }
}