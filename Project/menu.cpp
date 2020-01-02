#include <iostream>
#include <windows.h>
#include "graphics.h"
#include "saper.h"
#include <time.h>
using namespace std;


const int N = 16;//--------------------------------поле NxN
bool pole_mine[N][N];//-------------------------поле с минами
bool pole_flag[N][N];//--------------------------поле с флажками
int pole_zero[N][N];
int kol_mine=40;//--------------------------------колличество мин

void matr(){
   for (int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         pole_mine[i][j]=0;
         pole_flag[i][j]=0;
         pole_zero[i][j]=0;
      }//заполнили массивы
   }
}




//-----заполнение массивов минами и цифрами----------------------------------------------------------------------------
void zapol(int  kol_mine){
   int a,b;
   srand((unsigned int)time(NULL));//дл€ нового рандома
   for(int i=0; i<kol_mine;){
      int x = rand()%N;
      int y = rand()%N;
      if(pole_mine[x][y]==0){
         pole_mine[x][y]=1;//присваиваем €чейке мину
         pole_zero[x][y]=-1;
         i++;
      }
   }
}


