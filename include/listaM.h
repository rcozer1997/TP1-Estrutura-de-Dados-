#ifndef LISTAM_H
#define LISTAM_H

#include "../include/musicas.h"

typedef struct listaM ListaM;

/**
 * @brief Inicia uma lista de músicas
 * @return Lista de músicas já iniciada
 */
ListaM* iniciaListaMusicas();

/**
 * @brief Insere uma música na lista de músicas
 * @param l - Lista a qual vai ser adicionada a música
 * @param musica - Musica que será adicionada na lista
 */
void insereListaMusica(ListaM* l, tMusica* musica);

/**
 * @brief Imprime a lista de músicas
 * @param l - Lista que será printada
 */
void imprimeListaMusicas(FILE* arq, ListaM* l);//

/**
 * @brief Libera a memória da lista de músicas
 * @param l - Lista que terá o espaço liberado
 */
void destroiListaMusicas(ListaM* l);

/**
 * @brief Imprime as musicas nos arquivos de playlist dentro das pastas
 * @param l - lista de músicas
 */
void imprimeListaPlayArq(ListaM* l);

/**
 * @brief Compara a quantidade de músicas iguais em duas playlists
 * @param m1 - Uma das listas de músicas que será usada na comparação
 * @param m2 - A outra lista que será usada na comparação
 * @return contador com o número de músicas iguais nas duas playlists
 */
int buscaMusicasSimilares(ListaM* m1, ListaM* m2);

#endif