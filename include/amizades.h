#ifndef Amizade_h
#define Amizade_h

#include "../include/usuarios.h"


typedef struct amizade Amizade;

/**
 * @brief Retorna a linha com o nome dos amigos
 * @param a - struct amizade usada para conseguir a string
 * @return string com os nomes dos amigos
 */
char* retornaNomeAmizade(Amizade* a);

/**
 * @brief Imprime a struct amizade
 * @param a - Struct a ser printada
 */
void imprimeAmizade(Amizade* a);

/**
 * @brief Função que é responsável por ler e armazenar as amizades presentes no amizade.txt e também por chamar função que identifica as similaridades
 * @param u - Lista de usuários que será usada para comparar os nomes das amizades com os dos usuários
 */
void criaAmizade(ListaU* u);

/**
 * @brief Imprime no arquivo as amizades e as similaridades
 * @param amiz - arquivo o qual será criado e onde será escrito
 * @param pessoa - nome da primeira pessoa da amizade
 * @param amigo - nome da segunda pessoa da amizade
 * @param cont - contador de similaridades
 */
void imprimeAmizades(char* pessoa, char* amigo, int cont);

/**
 * @brief Libera a memoria das amizades
 * @param a - struct de amizade
 **/
 void destroiAmizade(Amizade* a);

#endif