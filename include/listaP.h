#ifndef LISTAP_H
#define LISTAP_H
#include "../include/musicas.h"
typedef struct listaP ListaP;
#include <stdio.h>
#include "listaU.h"

/**
 * @brief Inicia uma lista de playlists
 * @return Lista de playlists já iniciada
 */
ListaP* iniciaListaPlay();

/**
 * @brief Insere uma plalist na lista de playlists
 * @param l - Lista a qual vai ser adicionada a playlist
 * @param play - Playlist que será adicionada
 */
void insereListaPlay(ListaP* l, Playlist* play);

/**
 * @brief Procura uma playlist dentro da lista de playlists
 * @param l - Lista na qual será procurada a playlist
 * @param chave - String usada como referência para encontrar a playlist na lista
 * @return Struct playlist que estava sendo procurada
 */
Playlist* procuraPlayLista(ListaP* l, char* chave);

/**
 * @brief Imprime a lista de playlists
 * @param l - Lista que será printada
 */
void imprimeListaPlay(FILE* arq,ListaP* l);

/**
 * @brief Cria as playlists refatoradas e adiciona as músicas nelas
 * @param l - Lista de playlists que armazenará as playlists refatoradas
 * @param musica - Musica que será adicionada na playlist refatorada
 * @return 0 caso a playlist já exista e 1 caso contrário 
 */
int comparaPlaylist(ListaP* l, tMusica* musica);

/**
 * @brief 
 * @param 
 * @return 
 */
ListaP* leArquivosPlaylist(void* usuario);

/**
 * @brief Cria a playlist refatorada
 * @param usuario Struct usuario
 * @param l lista de playlist do usuario
 */
void criaEDrefatorada(Usuario* usuario, ListaP* l);

/**
 * @brief - Libera a memória da lista de playlists
 * @param l - Lista que terá a memória liberada
 */
void destroiListaPlay(ListaP* l);

/**
 * @brief Compara o nome das playlists de dois usuários e caso sejam iguais chama uma função para identificar quantas músicas iguais existem entre as playlists
 * @param p1 - Lista de playlists do usuário 1 que será usada na comparação
 * @param p2 - Lista de playlists do usuário 2 que será usada na comparação
 * @return Quantidade de músicas similares entre todas as playlists dos usuários
 */
int buscaPlaySimilaridades(ListaP* p1, ListaP* p2);

void imprimePastaListaPlay(char* caminho, ListaP* l);

#endif