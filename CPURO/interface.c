#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio2.h>
#include <windows.h>

void menu(){
    clrscr();
    printf("1   - Mostrar passo-a-passo? >>> %s <<<\n",passos);
    printf("2   - Escolher vetor aleatorio\n");
    printf("3   - Mostrar vetores\n");
    printf("4   - Fazer interseccao\n");
    printf("5   - Limpar lista de vetores\n");
    printf("ESC - Encerrar\n");
}

void vetorAleatorio(){
    clrscr();
    printf(" - Pressione \"R\" para gerar vetore(s) aleatorio(s)\n - ENTER para adicionar\n - ESC para voltar #####\n");
}

char* inicializa(){
    hidecursorr();
    char* alf = (char*)malloc(26 * sizeof(char));
    int n=0;
    for(int i = 65;i<91;i++){
        alf[i-65] = i;
    }

    menu();
    return alf;
}

void finaliza(){

}

void hidecursorr()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
