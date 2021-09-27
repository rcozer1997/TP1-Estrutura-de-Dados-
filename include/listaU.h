#ifndef LISTAU_H
#define LISTAU_H

typedef struct listaU ListaU;

#include "usuarios.h"

/**
 * @brief Inicia uma lista de usuários
 * @return Lista de usuários já iniciada
 */
ListaU* iniciaListaUsuario();

/**
 * @brief Insere um usuário na lista de usuários
 * @param l - Lista a qual vai ser adicionada o usuário
 * @param usu - Usuario que será inserido na lista
 */
void insereListaUsuario(ListaU* l, Usuario* usu);

/**
 * @brief Imprime a lista de usuários
 * @param l - Lista que será printada
 */
void imprimeListaUsu(ListaU* l);

/**
 * @brief Libera a memória da lista de usuários
 * @param l - Lista que terá a memória liberada
 */
void destroiListaUsuario(ListaU* l);

/**
 * @brief Procura um usuário na lista de usuários
 * @param l - Lista de usuários na qual será procurado o usuário
 * @param chave - String usada como referência para encontrar o usuário na lista
 * @return Struct usuário que estava sendo procurada
 */
Usuario* buscaUsuario(ListaU* l, char* chave);

/**
 * @brief 
 * @param l - Lista de usuários na qual será procurado o usuário
 * @param chave - String usada como referência para encontrar o usuário na lista
 * @return Struct usuário que estava sendo procurada
 */
void imprimeUsuPasta(ListaU* l);

#endif