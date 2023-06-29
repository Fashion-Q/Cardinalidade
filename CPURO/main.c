#include <stdio.h>
#include <conio2.h>
#include "structs.c"
char passos[10];
int teste = 0;
#include "prototipos.c"
#include "interface.c"
#include <time.h>
char *alfabeto;//26 letras
infoCard *somaTotalCard;
int boo = 1;
#include "funcoes.c"

int main(){
    char control = 0;
    strcpy(passos,"Ligado");
    alfabeto = inicializa();
    card *cardinalidade = NULL;
    //cardinalidade = exemploCard();
    do{
        control = getch();
        if(control == 49){//1
            if(boo){
                boo = 0;
                strcpy(passos,"Desligado");
            }
            else{
                boo = 1;
                strcpy(passos,"Ligado");
            }
        }
        else if(control == 50){//2
            //cardinalidade = escolhaVetorAleatorio(cardinalidade);
            cardinalidade = exemploCard2();
        }
        else if(control == 51){//3
            int *alphaIndices = (int*)malloc(tamanhoCardinalidade(cardinalidade)*sizeof(int));
            for(int i=0;i<tamanhoCardinalidade(cardinalidade);i++){
                alphaIndices[i] = i;
            }
            mostrarVetores(cardinalidade,alphaIndices,1);
        }
        else if(control == 52){//4
            if(cardinalidade != NULL){
                fazerInterseccao(cardinalidade);
            }
            else{
                printf("\nPreencha vetores! Pressione alguma tecla...\n");
                getch();
            }
        }
        else if(control == 53){//5
                if(cardinalidade != NULL){
                    cardinalidade = destroiCardinalidade(cardinalidade);
                    printf("Vetores limpado. Pressione alguam tecla...");
                    getch();
                }
                else{
                    printf("A lista de vetore(s) esta vazia. Pressione alguma tecla...");
                    getch();
                }
        }
        menu();
    }while(control != 27);

    //free(alfabeto);
    cardinalidade = destroiCardinalidade(cardinalidade);
    free(alfabeto);
    return 0;
}


