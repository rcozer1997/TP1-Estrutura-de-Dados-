#ifndef Playlist_h
#define Playlist_h

#include "../include/musicas.h"
#include "../include/usuarios.h"
#include "../include/listaM.h"

typedef struct playlist Playlist;

/**
 * @brief Inicia uma struct playlist
 * @pre O nome de uma playlist
 * @param nome - Nome da playlist
 * @return Struct playlist já iniciada
 * @post Alocar na memória e inicializar uma playlist
 */
Playlist* inicializaPlaylist(char* nome);

/**
 * @brief Retorna o nome da playlist
 * @pre Struct de playlist armazenada
 * @param p - Struct que tem o nome da playlist
 * @return Nome da playlist
 * @post Retornar o nome de uma playlist
 */
char* retornaNomePlay(Playlist* p);

/**
 * @brief Imprime as informações da playlist
 * @pre Struct de playlist armazenada e o diretorio do arquivo played_refatorada.txt
 * @param p - Playlist que será printada
 * @post Imprimir a playlist refatorada no arquivo played_refatorada.txt
 */
void imprimePlaylist(FILE* arq,Playlist* p);

/**
 * @brief Libera a memória da playlist
 * @pre A struct armazenada da playlist de um usuario
 * @param p - Playlist que terá a memória liberada
 * @post Liberar a memoria armazenada de uma playlist
 */
void destroiPlaylist(Playlist* p);

/**
 * @brief Adiciona uma música na playlist
 * @pre As structs armazenadas de uma musica e da playlist de um usuário
 * @param p - Playlist que receberá a música
 * @param musica - Musica que será adicionada na playlist
 * @post Adicionar uma musica à uma playlist, caso ela já não esteja adicionada
 */
void adicionaMusica(Playlist* p, tMusica* musica);

/**
 * @brief Retorna a lista de músicas de uma playlist
 * @pre Uma struct playlist 
 * @param p - Playlist que possui a lista de músicas desejada
 * @return Lista de músicas desejada
 * @post Retornar uma lista de musicas
 */
ListaM* retornaListaMusica(Playlist* p);

/**
 * @brief Adiciona os arquivos de playlist nas pastas
 * @pre Uma struct playlist e um diretório da pasta onde será salva a playlist
 * @param p - Playlist que possui a lista de músicas desejada
 * @param caminho - Diretório onde será salva a playlist
 * @post  Playlists, separadas por bandas, nas pastas dos respectivos usuarios
 */
void imprimePastaPlay(char* caminho, Playlist* p);

#endif