#include <stdio.h>
#include <stdlib.h> //malloc
#include <time.h> //rand

#define LINHAS 3
#define COLUNAS 4

// Protótipos das Funções 
void preencher_v1(int lin, int col, int* matriz);
void imprimir_matriz_v1(int lin, int col, int* matriz);
void mostrar_soma_linhas_v1(int lin, int col, int* matriz);
void mostrar_soma_colunas_v1(int lin, int col, int* matriz);

void preencher_v2(int lin, int col, int** matriz);
void imprimir_matriz_v2(int lin, int col, int** matriz);
void mostrar_soma_linhas_v2(int lin, int col, int** matriz);
void mostrar_soma_colunas_v2(int lin, int col, int** matriz);


void processar_matriz_estatica(int matriz[LINHAS][COLUNAS]);
void processar_matriz_dinamica_1(int* matriz);
void processar_matriz_dinamica_2(int** matriz);
void processar_matriz_dinamica_3(int** matriz);


int main() {
    srand(time(NULL)); //Inicializa o gerador de números aleatórios
    printf("Matrizes em C (1 Estática e 3 Dinâmicas)\n\n");

    // Método 1: Estático 
    int matriz_estatica[LINHAS][COLUNAS];
    processar_matriz_estatica(matriz_estatica);

    // Método 2: Dinâmico V1 
    int* matriz_din_v1 = (int *) malloc(LINHAS * COLUNAS * sizeof(int));
    if (matriz_din_v1 != NULL) {
        processar_matriz_dinamica_1(matriz_din_v1);
        free(matriz_din_v1);
    }
     printf("--------------------------------------------------\n\n");

    // Método 3: Dinâmico V2 
    int** matriz_din_v2 = (int **) malloc(LINHAS * sizeof(int *));
    if (matriz_din_v2 != NULL) {
        for (int i = 0; i < LINHAS; i++) {
            matriz_din_v2[i] = (int *) malloc(COLUNAS * sizeof(int));
        }
        processar_matriz_dinamica_2(matriz_din_v2);
        for (int i = 0; i < LINHAS; i++) { free(matriz_din_v2[i]); }
        free(matriz_din_v2);
    }
     printf("--------------------------------------------------\n\n");

    // Método 4: Dinâmico V3 
    int** matriz_din_v3 = (int **) malloc(LINHAS * sizeof(int *));
    int* bloco_dados = (int *) malloc(LINHAS * COLUNAS * sizeof(int));
    if (matriz_din_v3 != NULL && bloco_dados != NULL) {
        for (int i = 0; i < LINHAS; i++) {
            matriz_din_v3[i] = bloco_dados + i * COLUNAS;
        }
        processar_matriz_dinamica_3(matriz_din_v3);
        free(bloco_dados);
        free(matriz_din_v3);
    }
     printf("--------------------------------------------------\n\n");

    return 0;
}


void processar_matriz_estatica(int matriz[LINHAS][COLUNAS]) {
    printf("1. Metodo Estatico\n");
    int *ponteiros_para_linhas[LINHAS];
    for(int i = 0; i < LINHAS; i++){
        ponteiros_para_linhas[i] = matriz[i];
    }
    
    preencher_v2(LINHAS, COLUNAS, ponteiros_para_linhas);
    imprimir_matriz_v2(LINHAS, COLUNAS, ponteiros_para_linhas);
    mostrar_soma_linhas_v2(LINHAS, COLUNAS, ponteiros_para_linhas);
    mostrar_soma_colunas_v2(LINHAS, COLUNAS, ponteiros_para_linhas);
    printf("--------------------------------------------------\n\n");
}

void processar_matriz_dinamica_1(int* matriz) {
    printf("2. Metodo Dinamico 1:Bloco Unico 1D\n");
    preencher_v1(LINHAS, COLUNAS, matriz);
    imprimir_matriz_v1(LINHAS, COLUNAS, matriz);
    mostrar_soma_linhas_v1(LINHAS, COLUNAS, matriz);
    mostrar_soma_colunas_v1(LINHAS, COLUNAS, matriz);
}

void processar_matriz_dinamica_2(int** matriz) {
    printf("3. Metodo Dinamico 2:Vetor de Ponteiros\n");
    preencher_v2(LINHAS, COLUNAS, matriz);
    imprimir_matriz_v2(LINHAS, COLUNAS, matriz);
    mostrar_soma_linhas_v2(LINHAS, COLUNAS, matriz);
    mostrar_soma_colunas_v2(LINHAS, COLUNAS, matriz);
}

void processar_matriz_dinamica_3(int** matriz) {
    printf("4. Metodo Dinamico 3 :Bloco Unico com Indirecao\n");
    preencher_v2(LINHAS, COLUNAS, matriz);
    imprimir_matriz_v2(LINHAS, COLUNAS, matriz);
    mostrar_soma_linhas_v2(LINHAS, COLUNAS, matriz);
    mostrar_soma_colunas_v2(LINHAS, COLUNAS, matriz);
}


// Funções Versão 1 (para int*) 
void preencher_v1(int lin, int col, int* matriz) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            matriz[(i * col) + j] = rand() % 100;
        }
    }
}

void imprimir_matriz_v1(int lin, int col, int* matriz) {
    printf("Matriz gerada:\n");
    for (int i = 0; i < lin; i++) {
        printf("  [ ");
        for (int j = 0; j < col; j++) {
            printf("%2d ", matriz[(i * col) + j]);
        }
        printf("]\n");
    }
}

void mostrar_soma_linhas_v1(int lin, int col, int* matriz) {
    printf("Soma das Linhas:\n");
    for (int i = 0; i < lin; i++) {
        int soma = 0;
        for (int j = 0; j < col; j++) {
            soma += matriz[(i * col) + j];
        }
        printf("  Linha %d: %d\n", i, soma);
    }
}

void mostrar_soma_colunas_v1(int lin, int col, int* matriz) {
    printf("Soma das Colunas:\n");
    for (int j = 0; j < col; j++) {
        int soma = 0;
        for (int i = 0; i < lin; i++) {
            soma += matriz[(i * col) + j];
        }
        printf("  Coluna %d: %d\n", j, soma);
    }
}

// Funções Versão 2 (para int**) 
void preencher_v2(int lin, int col, int** matriz) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            matriz[i][j] = rand() % 100;
        }
    }
}

void imprimir_matriz_v2(int lin, int col, int** matriz) {
    printf("Matriz gerada:\n");
    for (int i = 0; i < lin; i++) {
        printf("  [ ");
        for (int j = 0; j < col; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("]\n");
    }
}

void mostrar_soma_linhas_v2(int lin, int col, int** matriz) {
    printf("Soma das Linhas:\n");
    for (int i = 0; i < lin; i++) {
        int soma = 0;
        for (int j = 0; j < col; j++) {
            soma += matriz[i][j];
        }
        printf("  Linha %d: %d\n", i, soma);
    }
}

void mostrar_soma_colunas_v2(int lin, int col, int** matriz) {
    printf("Soma das Colunas:\n");
    for (int j = 0; j < col; j++) {
        int soma = 0;
        for (int i = 0; i < lin; i++) {
            soma += matriz[i][j];
        }
        printf("  Coluna %d: %d\n", j, soma);
    }
}