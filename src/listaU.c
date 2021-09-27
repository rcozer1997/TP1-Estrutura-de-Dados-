#include "../include/listaU.h"

#include <stdio.h>

typedef struct celUsu CelulaUsu;

struct celUsu {
  Usuario* usu;
  CelulaUsu* prox;
};

struct listaU{
  CelulaUsu* prim;
  CelulaUsu* ult;
};

ListaU* iniciaListaUsuario()
{
  ListaU* usuario = (ListaU*)malloc(sizeof(ListaU));
  usuario->prim = NULL;
  usuario->ult = NULL;

  return usuario;
}


void insereListaUsuario(ListaU* l, Usuario* usuario)
{
  CelulaUsu* nova = (CelulaUsu*)malloc(sizeof(CelulaUsu));
   nova->usu = usuario;
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



void imprimeListaUsu(ListaU* l){
  CelulaUsu* p;
  FILE *arq = fopen("data/played_refatorada.txt","w");

  for(p = l->prim; p != NULL; p = p->prox){
    imprimeUsu(arq, p->usu);
    fprintf(arq, "\n");
  }
  fclose(arq);
}

Usuario* buscaUsuario(ListaU* l, char* chave)
{
    CelulaUsu* p;

  for(p = l->prim; p != NULL; p = p->prox){
    if(strcmp(retornaNomeUsuario(p->usu), chave) == 0){
      return p->usu;
    }
  }
  
}

void imprimeUsuPasta(ListaU* l){
  CelulaUsu* p;


  for(p = l->prim; p != NULL; p = p->prox){
      criaPasta(p->usu);
  }
}

void destroiListaUsuario(ListaU* l){
  CelulaUsu* p = l->prim;
  CelulaUsu* t;

  while(p != NULL){
    t = p->prox;
    destroiUsuario(p->usu);
    free(p);
    p = t;
  }
  free(l);
}