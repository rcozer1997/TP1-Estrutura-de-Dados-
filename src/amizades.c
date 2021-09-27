#include "../include/amizades.h"
#include "../include/listaA.h"
#include "../include/usuarios.h"

struct amizade{
  char* nome;
};

char* retornaNomeAmizade(Amizade* a){
  return a->nome;
}

void imprimeAmizade(Amizade* a){
  printf("%s\n", a->nome);
}


void criaAmizade(ListaU* u){
    FILE *arquivoAmizade = fopen("data/amizade.txt","r");
  if (arquivoAmizade == NULL){
    printf("Problemas na abertura do arquivo\n");
    exit(1);
  }
  int check = 0;
  char linha[100];
  ListaA* a = iniciaListaAmizades();

  fgets(linha, 100, arquivoAmizade);
  while(fgets(linha, 100, arquivoAmizade)){
    Amizade* amizade = (Amizade*)malloc(sizeof(Amizade));
    amizade->nome  = strdup(strtok(linha, "\n"));
    insereListaAmizade(a, amizade);
  }
  
  identificaSimilaridades(a, u);
  destroiListaAmizade(a);
  fclose(arquivoAmizade);
}

void destroiAmizade(Amizade* a)
{
  free(a->nome);
  free(a);
}
