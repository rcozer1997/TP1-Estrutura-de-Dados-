#ifndef MUSICAS_H
#define MUSICAS_H

#include <stdio.h>

typedef struct Musica tMusica;

/**
 * @brief Separa o nome da banda e da música
 * @param linha - String que contém "nome da banda - nome da música"
 * @return Struct tMusica com o nome da banda e da música separados
 */
tMusica* iniciaMusica(char* linha);

/**
 * @brief Retorna o nome da banda da struct música
 * @param musica - Struct que tem o nome da banda desejado
 * @return Nome da banda
 */
char* retornaBanda(tMusica* musica);

/**
 * @brief Imprime a struc música
 * @param musica - Struct música que terá suas informações printadas
 * @param
 */
void imprimeMusica(FILE* arq, tMusica* musica);

/**
 * @brief Retorna o nome da música
 * @param musica - Struct que tem o nome da música desejado
 * @return Nome da música
 */
char* retornaNomeMusica(tMusica* musica);

/**
 * @brief Libera a memoria armazenada das musicas
 * @param m - struct da musica 
 */
void destroiMusica(tMusica* m);

#endif