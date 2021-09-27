
#include "../include/playlists.h"
#include "../include/listaM.h"
#include "../include/usuarios.h"
#include "../include/musicas.h"
#include "../include/listaU.h"
#include "../include/amizades.h"
#include "../include/listaA.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct usuario{
  char* nome;
  int quant;
  ListaP* listaPlay;
};




void imprimeUsu(FILE* arq, Usuario* usu)
{     
       fprintf(arq,"%s;%d;", usu->nome, usu->quant);
        
        imprimeListaPlay(arq, usu->listaPlay);
  
}

void inicializaPlayED(){
  
  Playlist* play; 

  FILE *arquivoPlaylist = fopen("data/playlists.txt","r");
  if (arquivoPlaylist == NULL)
  {
    printf("Problemas na abertura do arquivo\n");
    exit(1);
  }

  char linha[100];
  ListaU* u = iniciaListaUsuario();

  while(fgets(linha, 100, arquivoPlaylist))
  {
    Usuario* usuario = (Usuario*)malloc(sizeof(Usuario));
    usuario->nome  = strdup(strtok(linha, ";"));
    usuario->quant = atoi(strtok(NULL, ";"));
    usuario->listaPlay = iniciaListaPlay(); 
    int i;
    for(i = 0 ; i < usuario->quant ; i++)
    {   
    play = inicializaPlaylist(strtok(NULL, ";\n"));

      
      insereListaPlay(usuario->listaPlay, play); //insere a playlist na lista
    }
    usuario->listaPlay = leArquivosPlaylist(usuario);

    insereListaUsuario(u, usuario); //insere o usuario na lista

    
  }
  imprimeListaUsu(u);
  criaAmizade(u);
  imprimeUsuPasta(u);
  fclose(arquivoPlaylist);
  
  destroiListaUsuario(u);
  
} 


ListaP* retornaListaPlay(Usuario* usuario)
{
      return usuario->listaPlay;

}

void alteraQtdPlaylist(Usuario* usuario, int qtd)
{
    usuario->quant = qtd;

}

char* retornaNomeUsuario(Usuario* usuario)
{
  return usuario->nome;
}



void criaPasta(Usuario* usuario)
{ 
  char* stringAux;
  stringAux = malloc(sizeof(char)*(strlen(usuario->nome)+strlen("data/")+2));
  strcpy(stringAux,"data/");
  strcat(stringAux, usuario->nome); 
  strcat(stringAux, "/"); 
  mkdir(stringAux, 0777);
  imprimePastaListaPlay(stringAux, usuario->listaPlay);
  free(stringAux);


}

void destroiUsuario(Usuario* u){
  free(u->nome);
  destroiListaPlay(u->listaPlay);

  free(u);
}

