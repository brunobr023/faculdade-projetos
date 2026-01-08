package un2aula2;

import javax.management.RuntimeErrorException;

public class Pilha{

    int elementos[];
    int topo;


    public Pilha(){
        elementos = new int[4];
        topo = -1;
    }

    public void push(int e){
        topo++;
        elementos[topo] = e;
    }


    public int pop(){
        int e = 0;

        if (isEmpty()) {
            System.out.println("Pilha vazia");
        }else{

            e = elementos[topo];
            topo--;

        }
        return e;
    }
    public boolean isEmpty(){
        if (topo == -1) {
            return true;
        }
        return false;
    }

    public boolean isFull(){
        return (topo == elementos.length -1);
    }

    public int top(){
        if (isEmpty()) {
            throw new RuntimeException("PILHA VAZIA");

        }
        return elementos[topo];

    }
} 