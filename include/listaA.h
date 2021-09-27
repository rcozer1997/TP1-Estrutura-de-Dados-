#ifndef LISTAA_H
#define LISTAA_H

typedef struct listaA ListaA;

#include "listaU.h"
#include "amizades.h"

/**
 * @brief Inicia uma lista de amizades
 * @return Lista de amizades já iniciada
 */
ListaA* iniciaListaAmizades();

/**
 * @brief insere uma struct amizade na lista de amizades
 * @param l - Lista a qual vai ser adicionada a struct
 * @param amizade - struct a ser adicionada
 */
void insereListaAmizade(ListaA* l, Amizade* amizade);

/**
 * @brief Imprime a lista de amizades
 * @param l - Lista que será printada
 */
void imprimeListaAmizade(ListaA* l);

/**
 * @brief Função que compara os nomes da lista de amizades com os usuários na lista de usuário e chama a função de comparação de playlists
 * @param a - Lista de amizades que será usada na comparação
 * @param u - Lista de usuários que será usada na comparação
 */
void identificaSimilaridades(ListaA* a, ListaU* u);

/**
 * @brief Imprime as similaridades de gosto musical no arquivo similaridades
 * @param amiz - diretorio do arquivo
 * @param pessoa - nome a ser impresso da primeira pessoa da amizade  
 * @param amigo - nome a ser impresso da segunda pessoa da amizade 
 * @param cont - variavel contador de similaridades entre os amigos
 */
void imprimeSimilaridadesArq(FILE* amiz, char* pessoa, char* amigo, int cont);

/**
 * @brief Libera a memoria armazenada da lista de amizades
 * @param l - Lista de amizades que será usada na comparação
 */
void destroiListaAmizade(ListaA* l);

#endif