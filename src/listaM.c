#include "../include/listaM.h"
#include "../include/playlists.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct celMus CelulaMus;

struct celMus {
  tMusica* musica;
  CelulaMus* prox;
};

struct listaM{
  CelulaMus* prim;
  CelulaMus* ult;
};

ListaM* iniciaListaMusicas()
{
  ListaM* musica = (ListaM*)malloc(sizeof(ListaM));
  musica->prim = NULL;
  musica->ult = NULL;

  return musica;
}

void insereListaMusica(ListaM* l, tMusica* musica)
{
  CelulaMus* nova = (CelulaMus*)malloc(sizeof(CelulaMus));
   nova->musica = musica;
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

void imprimeListaMusicas(FILE* arq, ListaM* l)
{
     CelulaMus* p;

  for(p = l->prim; p != NULL; p = p->prox){
    imprimeMusica(arq, p->musica);
  }

}

int buscaMusicasSimilares(ListaM* m1, ListaM* m2){
  CelulaMus* p;
  CelulaMus* pa;
  int cont = 0;

  for(p = m1->prim; p != NULL; p = p->prox){
    for(pa = m2->prim; pa != NULL; pa = pa->prox){
      if(strcmp(retornaNomeMusica(p->musica) ,retornaNomeMusica(pa->musica)) == 0){
        cont++;
        break;
      }
    }
  }
  return cont;
}
void destroiListaMusicas(ListaM* l){
  CelulaMus* p = l->prim;
  CelulaMus* t;

  while(p != NULL){
    t = p->prox;
    destroiMusica(p->musica);
    free(p);
    p = t;
  }
  free(l);
}




