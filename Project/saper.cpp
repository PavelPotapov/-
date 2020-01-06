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
   srand((unsigned int)time(NULL));//для нового рандома
   for(int i=0; i<kol_mine;){
      int x = rand()%N;
      int y = rand()%N;
      if(pole_mine[x][y]==0){
         pole_mine[x][y]=1;//присваиваем ячейке мину
         pole_zero[x][y]=-1;
         i++;
      }
   }
}

//----Рекурсивная функция------------------------------------------------------------------------------------------------------
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
//-----ход (попал или не попал, прорисовывание картинки)-------------------------------
bool shot(int x, int y, int a, int b){
   if (y>=17 && y<=22 && x>=12 && x<=16) return false;
   else if (x>15 || x<0 || y<0 || y>15) return true;//проверка на границы поля
   else if (mousebuttons()==1 ){//для ЛКМ
      if (pole_mine[x][y]==1) {
         for (int i=0; i<N; i++){//------------отображает все мины------
            for(int j=0; j<N; j++){
               if (pole_mine[i][j]==1){
                  a=(i+1)*50;
                  b=(j+1)*50;
                  IMAGE * bitmap=loadBMP("Resurses/KletkaM.jpg");
                  putimage(b,a, bitmap, COPY_PUT);
               }
            }
         }
         IMAGE * bitmap=loadBMP("Resurses/Proigral.jpg");
         putimage(875,105, bitmap, COPY_PUT);
         getch();
         return false;   //  если попал в мину
      }
      if (pole_zero[x][y]==9) func(x,y);
      else if (pole_zero[x][y]==1){
          IMAGE * bitmap=loadBMP("Resurses/Kletka1.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
      }
      else if (pole_zero[x][y]==2){
          IMAGE * bitmap=loadBMP("Resurses/Kletka2.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
      }
      else if (pole_zero[x][y]==3){
         IMAGE * bitmap=loadBMP("Resurses/Kletka3.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
      }
      else if (pole_zero[x][y]==4){
          IMAGE * bitmap=loadBMP("Resurses/Kletka4.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
      }
      else if (pole_zero[x][y]==5){
          IMAGE * bitmap=loadBMP("Resurses/Kletka5.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
      }
      else if (pole_zero[x][y]==6){
          IMAGE * bitmap=loadBMP("Resurses/Kletka6.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
      }
      else if (pole_zero[x][y]==7){
          IMAGE * bitmap=loadBMP("Resurses/Kletka7.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
      }
      else if (pole_zero[x][y]==8){
         IMAGE * bitmap=loadBMP("Resurses/Kletka8.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
      }
   }  
   else if (mousebuttons()==2 ){//для ПКМ
      if (pole_flag[x][y]==0){
         IMAGE * bitmap=loadBMP("Resurses/Kletka11.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
         pole_flag[x][y]=1;
         if (pole_flag[x][y]==pole_mine[x][y]) kol_mine-=1;
      }
      else if (pole_flag[x][y]==1){
         IMAGE * bitmap=loadBMP("Resurses/Kletka10.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
         pole_flag[x][y]=0;
         if (pole_mine[x][y]==1) kol_mine+=1;
      }
   }
   return true;
}

//-------выход--------------------------------------------------------------------------


