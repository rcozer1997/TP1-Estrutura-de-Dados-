#include "../include/playlists.h"
#include "../include/listaM.h"
#include "../include/musicas.h"
#include "../include/usuarios.h"
#include "../include/listaP.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct playlist
{
    char *nome;     
    ListaM* listaMusica; 
};

Playlist* inicializaPlaylist(char* nome)
{   
    Playlist* play = (Playlist*)malloc(sizeof(Playlist));
    play->nome = strdup(nome);
    play->listaMusica = iniciaListaMusicas();
        return play;
}

char* retornaNomePlay(Playlist* p)
{
        return p->nome;

}

void imprimePlaylist(FILE* arq, Playlist* p)
{   
    fprintf(arq,"%s;", p->nome);
   

}

void adicionaMusica(Playlist* p, tMusica* musica)
{
    insereListaMusica(p->listaMusica, musica);

}

ListaM* retornaListaMusica(Playlist* p){
  return p->listaMusica;
}

void imprimePastaPlay(char* caminho, Playlist* p)   
{ 
    char* stringAux = malloc(sizeof(char)*(strlen(caminho)+strlen(p->nome)+1));
    strcpy(stringAux,caminho);
    strcat(stringAux, p->nome); 

    FILE* arq = fopen(stringAux, "w");
    imprimeListaMusicas(arq, p->listaMusica);
    free(stringAux);
    fclose(arq);
}

void destroiPlaylist(Playlist* p){
  free(p->nome);
  destroiListaMusicas(p->listaMusica);
  free(p);
}
