#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "trunfo.h"
#include "menu.h"

int feedback;

int main() {

    LimpaTela();

    int opcao;
    int tamanho = 0;
    
    FILE* binorcsv = fopen("cartas.bin", "rb");
    if(binorcsv == NULL){
        tamanho = ContaLinhas("cartas.csv");
        printf("Tamanho CSV: %i\n", tamanho);
    }else{
        tamanho = getFileSize("cartas.bin")/sizeof(CARTA);
        printf("Tamanho Bin: %i\n", tamanho);
    }

    CARTA* cartas = (CARTA*) malloc (tamanho * sizeof(CARTA));
    if(cartas == NULL){
        perror("Erro ao alocar memória!\n");
        exit(1);
    }

    SalvaCartas(cartas, tamanho); // SALVA AS CARTAS NA VARIAVEL

    do{ 
        printf("Cadastro de Cartas!\n");
        printf("1- Inserir cartas\n");
        printf("2- Listar cartas\n");
        printf("3- Pesquisar cartas\n");
        printf("4- Alterar cartas\n");
        printf("5- Excluir cartas\n");
        printf("6- Exportar para CSV\n");
        printf("0 - Sair do programa\n");
        printf("Opcao: ");

        scanf("%i", &opcao);
        setbuf(stdin, NULL);

        switch (opcao){
        case 1:
            LimpaTela();
            InserirCartas(&cartas, &tamanho) ;
            break;
        case 2: 
            LimpaTela();
            ListaCartas(cartas, tamanho);
            break;
        case 3:
            LimpaTela();
            PesquisarCartas(cartas, tamanho);
            break;
        case 4:
            LimpaTela();
            AlterarCartas(cartas, tamanho);
            break;
        case 5:
            LimpaTela();
            RemoverCartas(cartas, &tamanho);
            break;
        case 6:
            LimpaTela();
            ExportaCSV(cartas, tamanho);
            break;
        case 0:
            LimpaTela();
            printf("Finalizando programa!\nObrigado pela preferência!\n");
            printf("Deixe um feedback (0 a 10)!\n");
            printf("Feedback: ");
            scanf("%i", &feedback);
            printf("Muito obrigado! Até logo...\n\n");
            SalvaBinario(cartas, tamanho);
            break;
        default:
            LimpaTela();
            printf("Nenhum valor válido foi digitado!\n");
            break;
        }
    } while (opcao != 0);
    
    free(cartas);
    fclose(binorcsv);

    return 0;
}