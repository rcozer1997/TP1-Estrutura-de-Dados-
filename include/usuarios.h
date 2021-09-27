#ifndef USUARIOS_H
#define USUARIOS_H

typedef struct usuario Usuario;
typedef struct playlist Playlist;

#include "../include/listaU.h"
#include "../include/listaP.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Imprime a struct usuário e suas playlists na played_refatorada.txt
 * @pre A struct de um usuario já alocada na memória e o diretorio do arquivo played_refatorada.txt
 * @param usu - Struct que será printada
 * @post Um arquivo played_refatorada com os dados de todos os usuarios
 */
void imprimeUsu(FILE* arq,Usuario* usu);

/**
 * @brief Responsável por ler o arquivo playlist.txt e armazenar as informações de cada usuário e também chamar a função responsável pelas similaridades
 * @pre   
 * @post Inicializar o programa 
 **/

void inicializaPlayED();

/**
 * @brief Retorna a lista de Playlists
 * @pre A struct de um usuario já alocada na memória
 * @param usuario - Usuario que possui a lista de playlists a ser retornada
 * @return Lista Playlists do usuário
 * @post Retornar a lista de playlist de um usuario
 */
ListaP* retornaListaPlay(Usuario* usuario);

/**
 * @brief Altera a quantidade de playlists que o usuário tem
 * @pre A struct de um usuario já alocada na memória e a quantidade de playlists de um usuario
 * @param usuario - Struct usuário que terá a quantidade de playlists alterada
 * @param qtd - Nova quantidade de playlists do usuário
 * @post Alterar a quantidade de playlists para a quantidade de playlists pós refatoração
 */
void alteraQtdPlaylist(Usuario* usuario, int qtd);

/**
 * @brief Retorna o nome do usuário
 * @pre A struct de um usuario já alocada na memória
 * @param usuario - Struct usuário que terá o nome retornado
 * @return Nome do usuário
 * @post Retornar o nome de um usuário 
 */
char* retornaNomeUsuario(Usuario* usuario);

/**
 * @brief Libera a memória armazenada do usuário
 * @pre A struct de um usuario já alocada na memória
 * @param u - Struct usuário 
 * @post A memoria da struct usuario liberada
 */
void destroiUsuario(Usuario* u);

/**
 * @brief Cria as pastas para os usuários
 * @pre A struct de um usuario já alocada na memoria 
 * @param usuario - Struct usuário 
 * @post Uma pasta para o usuario
 */
void criaPasta(Usuario* usuario);

#endif