#include <stdio.h>
#include <string.h>
int main(){
    //Definindo variaveis da nave
    char continuacao[5];
    float tanqueCombustivel = 100;
    int rotaViagem = 1; // 1 = OK  || 0 = N OK
    int condiClimatica = 1; // 1 = OK || 0 = N OK

    //Iniciando o "Suporte"
    printf("Bem vindo ao suporte automático da nave CicComp.\n Por favor aguarde a inicialização do sistema....");
    printf("\n\n\n\n Certo! Tudo carregado.\n");
    scanf("%4s", continuacao);
    
    //tanque de combustivel
    printf("Iniciando suporte..........\n");
    printf("O quanto o tanque de combustível está nuo momento? Eu visualizei que está em %1.f\n", tanqueCombustivel);
    scanf("%f", &tanqueCombustivel); 
    if (tanqueCombustivel < 20){
        printf("Alerta! o combustivel está abaixo do recomendado, iniciando procedimento de economia.........\n");
    }else{
        printf("Seu combustivel está dentro dos conformes!\n\n\n");
    }
    
    //Orientação da nave
    printf("Seguindo, por favor verifique se as cordenadas definidas: -3042Y 22300Z -21033X\n Estão corretas? \n");
    printf("Digite 1 para SIM ou Digite 0 para NÃO.\n) ");
    scanf("%d", &rotaViagem);
    if(rotaViagem == 0){
        printf("Fora de rota....\n Recalculando rota.......\nPronto!!!\n\n");
    }else{
        printf("Ok tudo certo! Prosseguindo para a ultima verificação!!!");
    }

    //Tempestades Solares
    printf("Ultima configuração, há tempestades solares proximas?\n ");
    printf("Digite 1 para  SIM ou Digite 0 para Não.\n) ");
    scanf("%d", &condiClimatica);
    if (condiClimatica == 0){
        printf("Ativando Protocolo de Proteção contra tempestades.....\n Pronto!");
    }else{
        printf("Mantendo desativado o sistema de proteção contra tempestades.\n");
    }
    printf("Fim da verificação do sistema!\n\n\n\n\n");

    return 0;
}