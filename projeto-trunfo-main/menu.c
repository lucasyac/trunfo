#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"
#include "trunfo.h"
#include "menu.h"

void InserirCartas(CARTA** cartas, int* tamanho) {
    int chooseoption;

    printf("Você deseja adicionar uma nova carta?\n");
    do {
        printf("1 - Sim!\n");
        printf("2 - Não\n");
        printf("Opcao: ");
        scanf("%i", &chooseoption);
        setbuf(stdin, NULL);
        if (chooseoption > 2 || chooseoption < 1) {
            printf("Digite uma opção válida!\n");
        }
    } while (chooseoption > 2 || chooseoption < 1);

    if (chooseoption == 1){
        while (1) {
            (*tamanho)++;
            *cartas = (CARTA*)realloc(*cartas, (*tamanho) * sizeof(CARTA));
            if (*cartas == NULL) {
                perror("Erro ao realocar vetor das cartas!\n");
                exit(1);
            } else {
                printf("Vetor das cartas realocado para %i\n", *tamanho);
            }
            printf("Digite o nome do(a) atleta %i (\"fim\") para terminar!\n", *tamanho);
            printf("Nome: ");
            LeString((*cartas)[*tamanho - 1].nome, 29);
            if (strcmp((*cartas)[*tamanho - 1].nome, "fim") == 0) {
                (*tamanho)--;
                *cartas = (CARTA*)realloc(*cartas, (*tamanho) * sizeof(CARTA));
                if (*cartas == NULL) {
                    perror("Erro ao realocar vetor da carta!\n");
                    exit(1);
                } else {
                    printf("Vetor de cartas realocado para %i!\n", *tamanho);
                    printf("Retornando...\n");
                    return;
                }
            } else {
                do {
                    printf("A, B, C, D\n");
                    printf("Digite a letra da carta do(a) \"%s\": ", (*cartas)[*tamanho - 1].nome);
                    scanf(" %c", &(*cartas)[*tamanho - 1].letra);
                    setbuf(stdin, NULL);
                    if (tolower((*cartas)[*tamanho - 1].letra) != 'a' && tolower((*cartas)[*tamanho - 1].letra) != 'b' && tolower((*cartas)[*tamanho - 1].letra) != 'c' && tolower((*cartas)[*tamanho - 1].letra) != 'd') {
                        printf("Digite uma letra válida!\n");
                    }
                } while (tolower((*cartas)[*tamanho - 1].letra) != 'a' && tolower((*cartas)[*tamanho - 1].letra) != 'b' && tolower((*cartas)[*tamanho - 1].letra) != 'c' && tolower((*cartas)[*tamanho - 1].letra) != 'd');
                (*cartas)[*tamanho - 1].letra = toupper((*cartas)[*tamanho - 1].letra);

                printf("Escolha o numero do(a) atleta \"%s\"!\n", (*cartas)[*tamanho - 1].nome);
                do{
                    scanf("%d", &(*cartas)[*tamanho - 1].numero);
                }while((*cartas)[*tamanho - 1].numero < 1 || (*cartas)[*tamanho - 1].numero > 8);

                printf("Escolha o numero de drible do(a) atleta \"%s\"!\n", (*cartas)[*tamanho - 1].nome);
                do{
                    scanf("%d", &(*cartas)[*tamanho - 1].dri);
                }while((*cartas)[*tamanho - 1].dri < 0 || (*cartas)[*tamanho - 1].dri > 10);

                (*cartas)[*tamanho - 1].codigo = *tamanho; 

                printf("Escolha o numero de defesa do(a) atleta \"%s\"!\n", (*cartas)[*tamanho - 1].nome);
                do{
                    scanf("%d", &(*cartas)[*tamanho - 1].def);
                }while((*cartas)[*tamanho - 1].def < 0 || (*cartas)[*tamanho - 1].def > 10);

                printf("Escolha o numero de fisico do(a) atleta \"%s\"!\n", (*cartas)[*tamanho - 1].nome);
                do{
                    scanf("%d", &(*cartas)[*tamanho - 1].fis);
                }while((*cartas)[*tamanho - 1].fis < 0 || (*cartas)[*tamanho - 1].fis > 10);

                printf("Escolha o numero de passe do(a) atleta \"%s\"!\n", (*cartas)[*tamanho - 1].nome);
                do{
                    scanf("%d", &(*cartas)[*tamanho - 1].pas);
                }while((*cartas)[*tamanho - 1].pas < 0 || (*cartas)[*tamanho - 1].pas > 10);
            }
        }

        printf("Carta adicionada com sucesso!\n");
    } else if(chooseoption == 2) {
        printf("Ok! retornando...\n");
        return;
    }
}

void PesquisarCartas(CARTA* cartas, int tamanho){
    char buscaNome[30];
    printf("Digite o nome do atleta a ser buscado: ");
    LeString(buscaNome, 29);
    printf("\n");

    int encontrado = 0;
    for (int i = 0; i < tamanho; i++){
        if(strcasecmp(buscaNome, cartas[i].nome) == 0){
            printf("Carta encontrada!\n");
            printf("Nome: %s\n", cartas[i].nome);
            printf("Letra: %c\n", cartas[i].letra);
            printf("Numero: %d\n", cartas[i].numero);
            printf("Drible: %d\n", cartas[i].dri);
            printf("Defesa: %d\n", cartas[i].def);
            printf("Fisico: %d\n", cartas[i].fis);
            printf("Passe: %d\n", cartas[i].pas);
            printf("Codigo: %i\n", cartas[i].codigo);

            encontrado = 1;
        }
    }

    if(!encontrado){
        printf("Carta não encontrada.\n");
    }
}

void AlterarCartas(CARTA* cartas, int tamanho){
    int jogadorEncontrado = 0;
    int maisdeumAtleta = 0;
    int option;
    int codigoatleta;

    char buscaNome[30];
    printf("Alterar dados dos atletas!\n");
    printf("Busca(Nome): ");
    LeString(buscaNome, 29);

    // Inicialização de jogadorrepetido
    CARTA* jogadorrepetido = NULL;

    for(int j = 0; j < tamanho; j++){
        if(strcasecmp(buscaNome, cartas[j].nome) == 0){
            jogadorEncontrado = 1;
            maisdeumAtleta++;

            // Realocando memória para armazenar os jogadores repetidos
            jogadorrepetido = (CARTA*)realloc(jogadorrepetido, maisdeumAtleta * sizeof(CARTA));
            if(jogadorrepetido == NULL){
                perror("Erro ao realocar memória!\n");
                exit(1);
            }
            jogadorrepetido[maisdeumAtleta - 1] = cartas[j];
        }
    }

    // Libera a memória alocada
    free(jogadorrepetido);

    if(!jogadorEncontrado){
        printf("Carta não encontrada!\n");
    }
}

void RemoverCartas(CARTA* cartas, int* tamanho){
    int posicao;

    do{
        printf("Escolha a linha a ser removida (%i-%i): ", 1, *tamanho);
        scanf("%i", &posicao);
    } while(posicao < 1 || posicao > *tamanho);

    posicao--; // Reajusta para mexer nas tabelas

    for(int i = posicao; i < *tamanho - 1; i++){
        cartas[i] = cartas[i + 1]; // CARTAS NA POSIÇÂO I VIRA CARTAS NA POSIÇÃO I + 1
        cartas[i].codigo--; // AJUSTA CODIGO DO ATLETA
    }

    (*tamanho)--;

    cartas = realloc(cartas, *tamanho * sizeof(CARTA)); 
    if (cartas == NULL && *tamanho > 0){
        perror("Erro ao realocar memória!\n");
        exit(1);
    }

    printf("Vetor de cartas realocado para %i!\n", *tamanho);
    printf("Linha %i removida com sucesso!\n", posicao + 1);
}

void ExportaCSV(CARTA* cartas, int tamanho){

    int opcao;

    FILE* archivecsv;

    archivecsv = fopen("cartas.csv", "r");
    if(archivecsv == NULL){
        perror("Erro ao ler arquivo csv!\n");
        exit(1);
    }else{
        printf("O arquivo cartas.csv já existe!\n");
        do{
            printf("1- Sobrescrever dados\n2- Retornar ao menu!\n");
            printf("Opcao: ");
            scanf("%i", &opcao);
            setbuf(stdin, NULL);
        }while(opcao < 1 || opcao > 2);

        if(opcao == 1){
            archivecsv = fopen("cartas.csv", "w");
            if(archivecsv == NULL){
                perror("Erro ao alocar memória!\n");
                exit(1);
            }
            printf("Exportando dados para arquivo \"cartas.csv\"!\n");


            for (int i = 0; i < tamanho; i++){
                fprintf(archivecsv, "%s,%c,%d,%d,%d,%d,%d\n",
                    cartas[i].nome,
                    cartas[i].letra,
                    cartas[i].numero,
                    cartas[i].dri,
                    cartas[i].def,
                    cartas[i].fis,
                    cartas[i].pas
                );
            }
        } else if(opcao == 2){
            printf("Ok! Retornando...\n");
            return;
        }
    }

    printf("Os dados foram salvos com sucesso em \"cartas.csv\"!\n");
    fclose(archivecsv);
}
