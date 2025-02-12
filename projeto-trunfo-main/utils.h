#ifndef UTILS_H
#define UTILS_H

// Funções de Manipulação de Strings
void LeString(char string[], int tamanho);

// Funções de Utilidade Geral
void LimpaTela();

// Funções de Manipulação de Vetores
void OrdenaporDecrescente(int numeros[], int tamanhovetor);
void OrdenaporCrescente(int numeros[], int tamanhovetor);

// Funções de Manipulação de Arquivos
long getFileSize(const char *filename);

#endif //UTILS.H
