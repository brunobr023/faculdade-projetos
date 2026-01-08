/* 
    Pra corrigir e ser exibido caracteres especiais como o acento no "Olá mundo":

    nclua a biblioteca #include <locale.h>
    Depois dentro do main: setlocale(LC_ALL, "Portuguese");

    Em seguida: CRTL+Shift+P - Change File Encoding - Save Witch Encoding - Wetern Iso 8859-1

    Vai resolver! 
 */
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Olá mundo!\n");
    return 0;
}