#include<stdio.h>
#include<stdlib.h>

char tabuleiro[3][3];

void inicializa_tabuleiro(){
    int l, c;
    for(l=0; l<3; l++){
        for(c=0; c<3; c++){
            tabuleiro[l][c] = '-';
        }
    }
}

void imprime_tabuleiro(){
    int l, c;

    printf("\n");
    printf("  TABULEIRO  \n");
    printf("  0   1   2  \n");
    printf("=============\n");
    for(l=0; l<3; l++){
        for(c=0; c<3; c++){
            printf("| %c ",tabuleiro[l][c]);
        }
        printf("| %d", l);
        printf("\n");
    }
    printf("=============\n");
    printf("\n");
}

void jogada(char jogador){
    int l, c;

    printf("Jogador '%c'\n", jogador);
    do{
        printf("Digite a posicao da linha: ");
        scanf("%d", &l);
        if(l < 0 || l > 2){
            printf("Posicao invalida. Informe novamente.\n");
        }
    }while(l < 0 || l > 2);

    do{
        printf("Digite a posicao da coluna: ");
        scanf("%d", &c);
        if(l < 0 || l > 2){
            printf("Posicao invalida. Informe novamente.\n");
        }
    }while(c < 0 || c > 2);

    if(tabuleiro[l][c] == '-'){
        tabuleiro[l][c] = jogador;
    }else{
        printf("\nPosicao ocupada. Digite novamente.\n\n");
        jogada(jogador);
    }
}

void verifica_vencedor(char jogador){
    int l, c, cont;

    // Valida as linhas
    for(l=0; l<3; l++){
        cont = 0;
        for(c=0; c<3; c++){
            if(tabuleiro[l][c] == jogador){
                cont++;
            }
        }
        if(cont == 3){
            printf("Parabens! '%c' ganhou!\n", jogador);
            exit (0);
        }
    }

    // Valida as colunas
    for(c=0; c<3; c++){
        cont = 0;
        for(l=0; l<3; l++){
            if(tabuleiro[l][c] == jogador){
                cont++;
            }
        }
        if(cont == 3){
            printf("Parabens! '%c' ganhou!\n", jogador);
            exit (0);
        }
    }

    // Valida a diagonal principal
    cont = 0;
    for(l=0; l<3; l++){
        for(c=0; c<3; c++){
            if(l == c && tabuleiro[l][c] == jogador){
                cont++;
            }
        }
        if(cont == 3){
            printf("Parabens! '%c' ganhou!\n", jogador);
            exit (0);
        }
    }

    // Valida a diagonal secundaria
    cont = 0;
    for(l=0; l<3; l++){
        for(c=0; c<3; c++){
            if(l + c == 2 && tabuleiro[l][c] == jogador){
                cont++;
            }
        }
        if(cont == 3){
            printf("Parabens! '%c' ganhou!\n", jogador);
            exit (0);
        }
    }
}

int main(){
    int cont;

    inicializa_tabuleiro();
    imprime_tabuleiro();

    for(cont=1; cont<=9; cont++){
        if(cont % 2 == 0){ // Vez do 'O'
            jogada('O');
            imprime_tabuleiro();
            if(cont >= 5){
                verifica_vencedor('O');
            }
        }else{ // Vez do 'X'
            jogada('X');
            imprime_tabuleiro();
            if(cont >= 5){
                verifica_vencedor('X');
            }
        }
    }

    return 0;
}