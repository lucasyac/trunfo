#ifndef MENU_H
#define MENU_H
#include "trunfo.h"

void InserirCartas(CARTA** cartas, int* tamanho); // INSERE ATLETA NOVO

void PesquisarCartas(CARTA* cartas, int tamanho); // PESQUISA ATLETA

void AlterarCartas(CARTA* cartas, int tamanho); // ALTERA DADOS DO ATLETA

void RemoverCartas(CARTA* cartas, int* tamanho); // DELETA UMA LINHA

void ExportaCSV(CARTA* cartas, int tamanho); // EXPORTA PARA ARQUIVO CSV

#endif //FUNCOES.H