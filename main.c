/* 
Insira uma descrição do problema
*/
#include <stdio.h>
#include "libs/libbmp.h"
#include "libs/imghelpers.h"

int main(){
  //Utilize apenas imagens .bmp com o formato 24 (true color)
  // converta em: https://online-converting.com/image/convert2bmp/
  bmp_img img;
  char filename[] = "lenna.bmp";
  printf("\n");
  IMG_TAM t = pegarTamanho(filename);
  int l = t.qtdLinhas,c = t.qtdColunas;
  int R[l][c];
  int G[l][c];
  int B[l][c];
  carregaImagem(t,R,G,B,filename);
  

  // manipule sua imagem aqui. 


  // Borda preta e clareamento
  
  for(int i = 0; i < l; i++){
    for(int j = 0; j < c; j++){

      //Faz a matriz receber 0 no rgb nas bordas até 20
      if(i < 20 || j < 20 || i > c-20 || j > l-20){

        R[i][j] = 0;
        G[i][j] = 0;
        B[i][j] = 0;
        
      }

      //Faz o rgb receber mais 50 quando i <= j, clareando a imagem
      if(i <= j ) {
         R[i][j] += 50 ;
         G[i][j] += 50;
         B[i][j] += 50;
      }
    }
      printf("\n");
  }
  
//Inversão da imagem

  //Matriz auxiliar
  int auxR[l][c];
  int auxG[l][c];
  int auxB[l][c];
  
  for(int i = 0;i < c; i++){
  
   // Variavel auxiliar para decréscimo (inicia em l-1 para igualar 'l' ao valor do for)
   int aux = l - 1;
    
    for(int j = 0; j < l; j++){
      //Final da matriz auxiliar recebe o inicio da principal
      auxR[i][aux] = R[i][j];
      auxG[i][aux] = G[i][j];
      auxB[i][aux] = B[i][j];

      //Decréscimo da auxiliar
      aux--;
    }
  }

  //Principal recebe auxiliar invertida
  for(int i = 0;i < l; i++){
    for(int j = 0;j < c; j++){
      R[i][j] = auxR[i][j];
      G[i][j] = auxG[i][j];
      B[i][j] = auxB[i][j];
    }
  }


  salvaImagem(t,R,G,B,"saida.bmp");
  mostrarNoReplit("saida.bmp");
  return 0;
}