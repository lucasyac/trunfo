#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void LeString(char string[], int tamanho){
    fgets(string, tamanho, stdin);
    string[strcspn(string, "\n")] = '\0';
    setbuf(stdin, NULL);
} // LEITURA DE STRINGS DO USUARIO

void LimpaTela(){
    #ifdef _WIN32 
        system("cls");
    #else 
        system("clear");
    #endif
} // LIMPAR TELA DO CONSOLE

void OrdenaporDecrescente(int numeros[], int tamanhovetor) {
    int temp;

    for (int i = 0; i < tamanhovetor; i++){
        for (int j = i+1; j < tamanhovetor; j++){
            if (numeros[i] < numeros[j]){
                temp = numeros[i];
                numeros[i] = numeros[j]; 
                numeros[j] = temp; 
            } // IF
        } // FOR 
    } // FOR 
} // ORDENAR QUALQUER VETOR EM ORDEM DESCRESCENTE

void OrdenaporCrescente(int numeros[], int tamanhovetor) {
    int temp;

    for (int i = 0; i < tamanhovetor; i++){
        for (int j = i+1; j < tamanhovetor; j++){
            if (numeros[i] > numeros[j]){
                temp = numeros[i]; 
                numeros[i] = numeros[j]; 
                numeros[j] = temp; 
            } // IF
        } // FOR 
    } // FOR 
} // ORDENAR QUALQUER VETOR EM ORDEM CRESCENTE

long getFileSize(const char *filename) {
    FILE *arquivo = fopen(filename, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo!");
        exit(1);
    }

    fseek(arquivo, 0, SEEK_END); // PULA PARA O FIM DO ARQUIVO
    long tamanho = ftell(arquivo); // LÊ O INDICADOR DE POSIÇÃO(EM BYTES);

    fclose(arquivo);

    return tamanho;
}