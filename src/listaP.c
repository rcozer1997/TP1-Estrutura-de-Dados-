#include "../include/listaP.h"
#include "../include/musicas.h"
#include "../include/playlists.h"
#include "../include/usuarios.h"

#include <stdio.h>

typedef struct celPlay CelulaPlay;

struct celPlay {
  Playlist* playlist; 
  CelulaPlay* prox;
};

struct listaP{
  CelulaPlay* prim;
  CelulaPlay* ult;
};

ListaP* iniciaListaPlay(){
  ListaP* playlist = (ListaP*)malloc(sizeof(ListaP));
  playlist->prim = NULL;
  playlist->ult = NULL;

  return playlist;
}

void insereListaPlay(ListaP* l, Playlist* play){
  CelulaPlay* nova = (CelulaPlay*)malloc(sizeof(CelulaPlay));
  nova->playlist = play;
  nova->prox = NULL;

  if(l->prim == NULL)
  {
    l->prim = nova;
  }

  if(l->ult != NULL)
  {
    l->ult->prox = nova;
  }

  l->ult = nova;
}



void imprimeListaPlay(FILE* arq, ListaP* l){
 
  CelulaPlay* p;

  for(p = l->prim; p != NULL; p = p->prox){
    imprimePlaylist(arq, p->playlist);
  }
}

void imprimePastaListaPlay(char* caminho, ListaP* l){
  
  CelulaPlay* p;

  for(p = l->prim; p != NULL; p = p->prox){
    imprimePastaPlay(caminho, p->playlist);
  }
}



ListaP* leArquivosPlaylist(void* usuario)
{   
  ListaP* play = retornaListaPlay(usuario);
  int qtd = 0;
  FILE *arquivoPlaylist;
  ListaP* refatorada = iniciaListaPlay();
    char *stringAux;
    CelulaPlay* p;
  for(p = play->prim; p != NULL; p = p->prox)
  {
stringAux = malloc(sizeof(char)*(strlen(retornaNomePlay(p->playlist))+strlen("data/ ")));
strcpy(stringAux,"data/");
strcat(stringAux, retornaNomePlay(p->playlist));  
     arquivoPlaylist = fopen(stringAux,"r");
        if (arquivoPlaylist == NULL) 
          {
          printf("Problemas na abertura do arquivo\n");
          exit(1);
          }
  char linha[100];
  while(fgets(linha, 100, arquivoPlaylist)){
   tMusica* musica = iniciaMusica(linha);
   qtd+= comparaPlaylist(refatorada, musica);

}
  fclose(arquivoPlaylist);
  free(stringAux);
  }     
    alteraQtdPlaylist(usuario,qtd);
      destroiListaPlay(play);
        return refatorada;
}

int comparaPlaylist(ListaP* l, tMusica* musica)
{   
    char* banda = retornaBanda(musica);
    int tam = strlen(banda);

     CelulaPlay* p;

  for(p = l->prim; p != NULL; p = p->prox)
  {
    if(strncmp(retornaNomePlay(p->playlist),banda,tam) == 0)
    {
      
       adicionaMusica(p->playlist, musica);
        return 0;
    }
      
  }
    char* stringAux = malloc(sizeof(char)*(strlen(banda)+strlen(".txt ")));
    strcpy(stringAux, banda);
    strcat(stringAux, ".txt"); 
    Playlist* playlist = inicializaPlaylist(stringAux);
      adicionaMusica(playlist, musica);
      insereListaPlay(l, playlist);

      free(stringAux);
      return 1;
}

int buscaPlaySimilaridades(ListaP* p1, ListaP* p2){
  CelulaPlay* p;
  CelulaPlay* pa;
  int cont = 0;

  for(p = p1->prim; p != NULL; p = p->prox){
    for(pa = p2->prim; pa != NULL; pa = pa->prox){
      if(strcmp(retornaNomePlay(p->playlist) ,retornaNomePlay(pa->playlist)) == 0){
        cont += buscaMusicasSimilares(retornaListaMusica(p->playlist), retornaListaMusica(pa->playlist));
      }
    }  
  }
  return cont;
} 

void destroiListaPlay(ListaP* l){
  CelulaPlay* p = l->prim;
  CelulaPlay* t;

  while(p != NULL){
    t = p->prox;
    destroiPlaylist(p->playlist);
    free(p);
    p = t;
  }
  free(l);
}

  


 