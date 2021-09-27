#include "../include/musicas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Musica {
    char* banda;
    char* nome;

};

tMusica* iniciaMusica(char* linha)
{
    char* stringAux;
    stringAux = strtok(linha, "-");
    stringAux[strlen(stringAux) - 1] = '\0';
    tMusica* musica = malloc(sizeof(tMusica));

    musica->banda = strdup(stringAux);

     stringAux = strtok(NULL, "\n");

    musica->nome = strdup(stringAux+1);

        return musica;

}   

char* retornaBanda(tMusica* musica)
{

    return musica->banda;
    
}

void imprimeMusica(FILE* arq, tMusica* musica)
{   
    fprintf(arq,"%s - %s\n", musica->banda, musica->nome);

}

char* retornaNomeMusica(tMusica* musica){
  return musica->nome;
}

void destroiMusica(tMusica* m){
  free(m->banda);
  free(m->nome);
  free(m);
}