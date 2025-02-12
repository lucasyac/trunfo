#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "trunfo.h"

int ContaLinhas(const char* nomearquivo){

    FILE* arquivos = fopen(nomearquivo, "r+");
    if(arquivos == NULL){
        perror("Erro ao abrir arquivo para leitura!\n");
        exit(1);
    }

    int c;
    int tamanho = 0;
    while((c = getc(arquivos)) != EOF){
        if(c == '\n'){
            tamanho++; // verifica o número de linhas do arquivo
        }
    } tamanho++;
    
    fclose(arquivos);
    return tamanho;
} // Conta linhas do programa

void SalvaCartas(CARTA* cartas, int tamanho){
    
    FILE* arquivobin = fopen("cartas.bin", "rb");
    if(arquivobin == NULL){
        printf("Abrindo arquivo csv!\n\n");
        FILE* arquivocsv = fopen("cartas.csv", "r");
        if (arquivocsv == NULL) {
            perror("Erro ao ler arquivo CSV!\n");
            exit(1);
        }

        for (int i = 0; i < tamanho; i++) {
            char resultadoTipo[20];

            // Leitura dos dados do arquivo CSV
            if (fscanf(arquivocsv, " %[^,], %c, %d, %d, %d, %d, %d[^\n]",
                    cartas[i].nome,
                    &cartas[i].letra,
                    &cartas[i].numero,
                    &cartas[i].dri,
                    &cartas[i].def,
                    &cartas[i].fis,
                    &cartas[i].pas,
                    resultadoTipo) != 7) {
                fprintf(stderr, "Erro ao ler dados do arquivo CSV %d\n", i + 1);
                break; // Termina o loop se achar erro na leitura
            }
        }
    }
}

void ListaCartas(CARTA* cartas, int tamanho){

    for(int i = 0; i < tamanho; i++){
        printf("Atleta %d: ", cartas[i].codigo);
        printf("%c, ", cartas[i].letra);
        printf("%s, ", cartas[i].nome);
        printf("%d, ", cartas[i].numero);
        printf("%d, ", cartas[i].dri);
        printf("%d, ", cartas[i].def);
        printf("%d, ", cartas[i].fis);
        printf("%d, ", cartas[i].pas);

        for (int i = 0; i < tamanho; i++){            
            cartas[i].codigo = i + 1;
        }

        printf("\n");
    }
}

void SalvaBinario(CARTA* cartas, int tamanho){

    FILE *cartasFile;

        cartasFile = fopen("cartas.bin", "wb");
        if(cartasFile == NULL){
            perror("Erro ao criar arquivo binário \"cartas.bin\" !\n");
            exit(1);
        }

        fwrite(cartas, sizeof(CARTA), tamanho, cartasFile);
        printf("Todas as informações foram transferidas com sucesso no arquivo \"cartas.bin\"!\n");

    fclose(cartasFile);
}