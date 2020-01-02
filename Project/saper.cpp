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

//----–екурсивна€ функци€------------------------------------------------------------------------------------------------------
void func(int x, int y){
   IMAGE * bitmap=loadBMP("Resurses/Kletka.jpg");
   putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
   pole_zero[x][y]=0;
   for (int i=x-1; i<x+2; i++){
      for (int j=y-1; j<y+2; j++){
         if ((i>=0 && i<N) && (j>=0 && j<N)){
            if (pole_zero[i][j]==9 ) func(i,j);
            else if (pole_zero[i][j]==1){
                IMAGE * bitmap=loadBMP("Resurses/Kletka1.jpg");
               putimage((j+1)*50,(i+1)*50, bitmap, COPY_PUT);
            }
            else if (pole_zero[i][j]==2){
                IMAGE * bitmap=loadBMP("Resurses/Kletka2.jpg");
               putimage((j+1)*50,(i+1)*50, bitmap, COPY_PUT);
            }
            else if (pole_zero[i][j]==3){
               IMAGE * bitmap=loadBMP("Resurses/Kletka3.jpg");
               putimage((j+1)*50,(i+1)*50, bitmap, COPY_PUT);
            }
            else if (pole_zero[i][j]==4){
                IMAGE * bitmap=loadBMP("Resurses/Kletka4.jpg");
               putimage((j+1)*50,(i+1)*50, bitmap, COPY_PUT);
            }
            else if (pole_zero[i][j]==5){
                IMAGE * bitmap=loadBMP("Resurses/Kletka5.jpg");
               putimage((j+1)*50,(i+1)*50, bitmap, COPY_PUT);
            }
            else if (pole_zero[i][j]==6){
                IMAGE * bitmap=loadBMP("Resurses/Kletka6.jpg");
               putimage((j+1)*50,(i+1)*50, bitmap, COPY_PUT);
            }
            else if (pole_zero[i][j]==7){
                IMAGE * bitmap=loadBMP("Resurses/Kletka7.jpg");
               putimage((j+1)*50,(i+1)*50, bitmap, COPY_PUT);
            }
            else if (pole_zero[i][j]==8){
               IMAGE * bitmap=loadBMP("Resurses/Kletka8.jpg");
               putimage((j+1)*50,(i+1)*50, bitmap, COPY_PUT);
            }
         }
      }
   }
}

