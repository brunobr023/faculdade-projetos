public class Televisao{

    String marca;
    boolean ligada;
    int canal;
    int volume;
    String Local;

    public Televisao(){
    }

    public void ligar(){
        ligada = true;
        System.out.println("A TV " + marca + " está ligada no Local " + Local + ".");
    }

    public void desligar(){
        ligada = false;
        System.out.println("A TV " + marca + " foi desligada no Local " + Local + ".");
    }

    public void defineMarca(String nomeMarca){
        marca = nomeMarca;
        System.out.println("Marca definida: "+ marca);
    }

    public void local(String plocal){

        System.out.println("Local definido:" + Local);
    }
    public void aumentarVolume(){
        if(ligada){
            volume++;
            System.out.println("Marca:" +marca+": volume definido para " +volume);
        }
        else{
            System.out.println("Ligue a TV" + marca);

        }
        
    }
    // public void defineCanal(int pcanal){
    //     if(ligada){
    //         canal = pcanal;
    //         System.out.println("Marca:" +marca+": volume definido para " +volume)
    //     }
    //     else{
    //         System.out.println("Ligue a TV" + marca)
            
    //     }
        
    // }

}