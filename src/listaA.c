#include "../include/listaA.h"
#include "../include/listaP.h"
#include "../include/amizades.h"
#include "../include/usuarios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celAm CelulaAm;

struct celAm{
  Amizade* amizade;
  CelulaAm* prox;
};

struct listaA{
  CelulaAm* prim;
  CelulaAm* ult;
};

ListaA* iniciaListaAmizades(){
  ListaA* amizade = (ListaA*)malloc(sizeof(ListaA));
  amizade->prim = NULL;
  amizade->ult = NULL;

  return amizade;
}

void insereListaAmizade(ListaA* l, Amizade* amizade)
{
  CelulaAm* nova = (CelulaAm*)malloc(sizeof(CelulaAm));
  nova->amizade = amizade;
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

void imprimeListaAmizade(ListaA* l)
{
     CelulaAm* p;

  for(p = l->prim; p != NULL; p = p->prox){
    imprimeAmizade(p->amizade);
  }
}

void identificaSimilaridades(ListaA* a, ListaU* u){

  FILE *amiz = fopen("data/similaridades.txt","w");

  CelulaAm* p;
  char* nome_pessoa;
  char* nome_amigo;
  Usuario* pessoa;
  Usuario* amigo;
  int cont;

  for(p = a->prim; p != NULL; p = p->prox){
    nome_pessoa = strtok(retornaNomeAmizade(p->amizade), ";");
    nome_amigo = strtok(NULL, "\n");
    pessoa = buscaUsuario(u, nome_pessoa);
    amigo = buscaUsuario(u, nome_amigo);
    cont = buscaPlaySimilaridades(retornaListaPlay(pessoa), retornaListaPlay(amigo));
    imprimeSimilaridadesArq(amiz, nome_pessoa, nome_amigo, cont);
  }
  fclose(amiz);
}



void imprimeSimilaridadesArq(FILE* amiz, char* pessoa, char* amigo, int cont){
  
    fprintf(amiz,"%s;%s;%d\n", pessoa, amigo, cont);
    
}

void destroiListaAmizade(ListaA* l)
{
  CelulaAm* p = l->prim;
  CelulaAm* t;

  while(p != NULL){
    t = p->prox;
    destroiAmizade(p->amizade);
    free(p);
    p = t;
  }
  free(l);
}