#ifndef TRUNFO_H
#define TRUNFO_H

typedef struct{
    char nome[50];
    char letra;
    int numero, dri, def, fis, pas;
    int codigo;
} CARTA; // 

// Funções de Manipulação de Arquivos
int ContaLinhas(const char* arquivo);

void SalvaCartas(CARTA* cartas, int tamanho);

void ListaCartas(CARTA* cartas, int tamanho);

void SalvaBinario(CARTA* cartas, int tamanho);

#endif //TRUNFO.H
