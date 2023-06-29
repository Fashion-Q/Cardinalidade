card* getCard(int *n, int tam){
    card *aux = (card*)malloc(sizeof(card));
    aux->tam = tam;
    aux->boo = (int*)malloc(tam * sizeof(int));
    aux->n = (int*)malloc(tam*sizeof(int));
    memcpy(aux->n, n, tam * sizeof(int));
    //aux->n = n;
    aux->prox = NULL;
    for(int i=0;i<tam;i++){
        aux->boo[i]=1;
    }
    for(int i=0;i<tam;i++){
        for(int j=i+1;j<tam;j++){
            if(aux->n[i]==aux->n[j]){
                aux->boo[j] = 0;
            }
        }
    }
    return aux;
}

card* exemploCard(){
    //memcpy(vetor, (int[]){1,2,3,4,5}, 5 * sizeof(int));
    card *cardinalidade;
    cardinalidade = getCard((int[]){1,7,11,2,5,8,5,5},8);
    card *aux = cardinalidade;
    aux->prox = getCard((int[]){1, 2, 4, 18, 5, 11, 6},7);
    aux->prox->prox = getCard((int[]){18, 19, 1, 2, 7},5);
    aux->prox->prox->prox = getCard((int[]){1, 3, 8, 10},4);
    aux->prox->prox->prox->prox = getCard((int[]){1,1,1,1},4);
    aux->prox->prox->prox->prox->prox = getCard((int[]){1,1,1,1,3,5},6);
    aux->prox->prox->prox->prox->prox->prox = getCard((int[]){1,1,1,3,5},5);
    //aux->prox = getCard((int[]){},5);


    return cardinalidade;
}

card* exemploCard2(){
    //memcpy(vetor, (int[]){1,2,3,4,5}, 5 * sizeof(int));
    card *cardinalidade;
    cardinalidade = getCard((int[]){5,5,1,2},4);
    card *aux = cardinalidade;
    aux->prox = getCard((int[]){5, 0, 0, 3},4);
    aux->prox->prox = getCard((int[]){5, 5,5,5},4);/*
    aux->prox->prox->prox = getCard((int[]){89, 51, 12},3);
    aux->prox->prox->prox->prox = getCard((int[]){68},1);
    aux->prox->prox->prox->prox->prox = getCard((int[]){6},1);
    aux->prox->prox->prox->prox->prox->prox = getCard((int[]){78},1);*/


    return cardinalidade;
}

void mostrarVetores(card *cardinalidade, int *indices, int boo){
    clrscr();

    printf("\n### VETORES ###\n\n");
    card *aux = cardinalidade;
    int alpha = 0;
    while(aux != NULL){
        printf("%c [",alfabeto[indices[alpha]]);
        for(int i=0;i<aux->tam;i++){
            printf("%d",aux->n[i]);
            if(i+1<aux->tam)printf(",");
        }printf("] Tamanho do vetor: (%d)\n",aux->tam);
        //printf("????? %d \n",aux->tam);
        /*printf("%c [",alfabeto[indices[alpha]]);
        for(int i=0;i<aux->tam;i++){
            printf("%d",aux->boo[i]);
            //getch();
            if(i+1<aux->tam)printf(",");
        }printf("]\n\n");*/
        aux = aux->prox;
        alpha++;
    }
    if(boo){
    printf("\n### PRESSIONE QUALQUER TECLA PARA SAIR ###\n");
    getch();
    }else{
    printf("\n");
    }
}

int tamanhoCardinalidade(card* cardinalidade){
    card* aux = cardinalidade;
    int tam = 0;
    while(aux){
        aux=aux->prox;
        tam++;
    }
    return tam;
}

void printVetor(int *v, int tam){
    for(int i=0;i<tam;i++){
        printf("[%d] ",v[i]);
    }printf("\n");
}

card *getIndices(card* cardinalidade, int *indices, int k){
    card* interseccao = NULL;
    for(int i=0;i<k;i++){
        card*aux = cardinalidade;
        for(int j=0;j<indices[i];j++){
            aux=aux->prox;
        }
        card *aux2 = getCard(aux->n,aux->tam);
        if(interseccao == NULL){
            interseccao = aux2;
        }
        else{
            card*aux3 = interseccao;
            while(aux3->prox != NULL){
                aux3 = aux3->prox;
            }
            aux3->prox = aux2;
        }
    }
    return interseccao;
}

char *getStringCardinalidade(int* n, int tam){
    char* str = (char*)malloc(((tam*2)+3) * sizeof(char));
    str[0] = 'n';
    str[1] = '(';
    int j = 2;
    for(int i=0;i<tam;i++){
        str[j++] = alfabeto[n[i]];
        str[j++] = '+';
    }j--;
    str[j++]=')';
    str[j] = '\0';
    return str;
}

int pesquisarInterseccao(int n, card *aux){
    if(!aux){
        return 1;
    }
    for(int i=0;i<aux->tam;i++){
        if(aux->n[i] == n){
            return pesquisarInterseccao(n,aux->prox);
        }
    }
    return 0;
}

void somaCardinalidade(card* interseccao, int* indices, int tam){
    infoCard *soma = (infoCard*)malloc(sizeof(infoCard));
    soma->n=0;
    soma->str = getStringCardinalidade(indices,tam);
    soma->prox = NULL;

    for(int i=0;i<interseccao->tam;i++){
        card *aux = interseccao;
        if(interseccao->boo[i] == 0){
            continue;
        }
        if(pesquisarInterseccao(interseccao->n[i],aux->prox)){
            soma->n++;
        }
    }
    if(tam % 2 == 0){
        soma->n = soma->n * -1;
    }
    if(boo)
        printf("Interseccao: %s\ncardinalidade: [%d]\n\n",soma->str,soma->n);
    if(somaTotalCard == NULL){
        somaTotalCard = soma;
    }else{
        infoCard *auxInfo = somaTotalCard;
        while(auxInfo->prox != NULL){
            auxInfo = auxInfo->prox;
        }
        auxInfo->prox = soma;
    }
}

int *novoIndice(int *indices,int tamIndices,int tamCard,int profundidade){
    if(tamIndices-1 < 0){
        return indices;
    }
    indices[tamIndices-1]++;
    indices[tamIndices] = indices[tamIndices-1]+1;
    if(indices[tamIndices-1]+profundidade>=tamCard){
        indices = novoIndice(indices, tamIndices-1,tamCard,profundidade+1);
        indices[tamIndices] = indices[tamIndices-1]+1;
    }
    return indices;
}

int somarCardinalidadeTotal(){
    infoCard *aux = somaTotalCard;
    int somaTotal = 0;printf("[");
    while(aux != NULL){
        somaTotal+=aux->n;
        printf("%d",aux->n);
        aux = aux->prox;
        if(aux){
            printf(",");
        }
    }printf("]\n");
    return somaTotal;
}

void fazerInterseccao(card* cardinalidade){
    clrscr();
    {
        int tam = tamanhoCardinalidade(cardinalidade);
        int mostrarVetoresAntesDaInterseccao[tam];
        for(int i=0;i<tam;i++){
            mostrarVetoresAntesDaInterseccao[i]=i;
        }
        mostrarVetores(cardinalidade,mostrarVetoresAntesDaInterseccao,0);
    }
    for(int k=1;k<=tamanhoCardinalidade(cardinalidade);k++){
        int *indices = (int*)malloc(k*sizeof(int));
        for(int i=0;i<k;i++){
            indices[i] = i;
        }
        for(int m=indices[0];m<=tamanhoCardinalidade(cardinalidade)-k;){
            //int test[]={1,2,3};
            //card *interseccao = getIndices(cardinalidade,test,3);
            //somaCardinalidade(interseccao,test,3);
            card *interseccao = getIndices(cardinalidade,indices,k);
            somaCardinalidade(interseccao,indices,k);
            if(k == tamanhoCardinalidade(cardinalidade)){
                break;
            }
            indices[k-1]++;
            if(indices[k-1]>=tamanhoCardinalidade(cardinalidade)){
                indices = novoIndice(indices,k-1,tamanhoCardinalidade(cardinalidade),1);
            }
            interseccao = destroiCardinalidade(interseccao);
            m = indices[0];
        }
        free(indices);
    }
    int somaTotal = somarCardinalidadeTotal();
    printf("\n###### Cardinalidade total: [%d] ######\n",somaTotal);
    printf("Pressione alguma tecla para voltar ao Menu...");
    destroiInfoSoma();
    teste++;
    int consumirBuffer = 0;
    while(kbhit())consumirBuffer = getch();
    getch();
}


card *destroiCardinalidade(card* cardinalidade){
    card *aux;
    while(cardinalidade != NULL){
        aux = cardinalidade;
        cardinalidade = cardinalidade->prox;
        free(aux);
    }
    return cardinalidade;
}

void destroiInfoSoma(){
    infoCard *aux;
    while(somaTotalCard != NULL){
        aux = somaTotalCard;
        somaTotalCard = somaTotalCard->prox;
        free(aux);
    }
}

card *escolhaVetorAleatorio(card *cardinalidade){
    int *vet = NULL;
    int tamVetor;
    int control = 0;
    srand(time(NULL));
    //r = 114 || 82
    do{
        vetorAleatorio();
        int tamanhoCard = tamanhoCardinalidade(cardinalidade);
        printf(" - Tamanho da cardinalidade precisa ser < 27: [%d]\n\n",tamanhoCard);
        if(tamanhoCardinalidade(cardinalidade) > 25){
            printf("O limite de vetores eh 26! Pressione alguma tecla...");
            getch();
            return cardinalidade;
        }
        if(vet == NULL){
            printf("Vetor: [ ]");
        }
        else
        {
            printf("Vetor: ");
            printVetor(vet,tamVetor);
        }
        control = getch();

        if(control == 82 || control == 114){
            tamVetor = 0;
            while((tamVetor < 3))tamVetor = rand()%16;
            if(vet != NULL)free(vet);
            vet = (int*)malloc(tamVetor * sizeof(int));

            for(int i=0;i<tamVetor;i++){
                vet[i] = rand()%15 + 1;
            }
        }
        else if(control == 13){
            if(vet == NULL){
                control = 1;
            }
            else if(cardinalidade == NULL){
                cardinalidade = getCard(vet,tamVetor);
                printf("Adicionado! Pressione alguma tecla...");
                free(vet);
                vet = NULL;
                control = getch();
                control = 13;
            }
            else{
                card *aux = cardinalidade;
                while(aux->prox != NULL){
                    aux=aux->prox;
                }aux->prox = getCard(vet,tamVetor);
                printf("Adicionado! Pressione alguma tecla...");
                free(vet);
                vet = NULL;
                control = getch();
                control = 13;
            }
        }
    }while(control != 27);
    return cardinalidade;
}
