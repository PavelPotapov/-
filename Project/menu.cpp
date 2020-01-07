#include <iostream>
#include <windows.h>
#include "graphics.h"
#include "saper.h"
#include <time.h>

using namespace std;

const int N = 16;//--------------------------------���� NxN
bool pole_mine[N][N];//-------------------------���� � ������
bool pole_flag[N][N];//--------------------------���� � ��������
int pole_zero[N][N];
int kol_mine=40;//--------------------------------����������� ���

void matr(){
   for (int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         pole_mine[i][j]=0;
         pole_flag[i][j]=0;
         pole_zero[i][j]=0;
      }//��������� �������
   }
}




//-----���������� �������� ������ � �������----------------------------------------------------------------------------
void zapol(int  kol_mine){
   int a,b;
   srand((unsigned int)time(NULL));//��� ������ �������
   for(int i=0; i<kol_mine;){
      int x = rand()%N;
      int y = rand()%N;
      if(pole_mine[x][y]==0){
         pole_mine[x][y]=1;//����������� ������ ����
         pole_zero[x][y]=-1;
         i++;
      }
   }
}



// -------------------��������------------------------------------------------------------------
void func(int x, int y){
   IMAGE * bitmap=loadBMP("Kletka.jpg");
   putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
   pole_zero[x][y]=0;
   for (int i=x-1; i<x+2; i++){
      for (int j=y-1; j<y+2; j++){
         if ((i>=0 && i<N) && (j>=0 && j<N)){
            if (pole_zero[i][j]==9 ) func(i,j);
            else if (pole_zero[i][j]==1){
                IMAGE * bitmap=loadBMP("Kletka1.jpg");
               putimage((j+1)*50,(i+1)*50, bitmap, COPY_PUT);
            }
            else if (pole_zero[i][j]==2){
                IMAGE * bitmap=loadBMP("Kletka2.jpg");
               putimage((j+1)*50,(i+1)*50, bitmap, COPY_PUT);
            }
            else if (pole_zero[i][j]==3){
               IMAGE * bitmap=loadBMP("Kletka3.jpg");
               putimage((j+1)*50,(i+1)*50, bitmap, COPY_PUT);
            }
            else if (pole_zero[i][j]==4){
                IMAGE * bitmap=loadBMP("Kletka4.jpg");
               putimage((j+1)*50,(i+1)*50, bitmap, COPY_PUT);
            }
            else if (pole_zero[i][j]==5){
                IMAGE * bitmap=loadBMP("Kletka5.jpg");
               putimage((j+1)*50,(i+1)*50, bitmap, COPY_PUT);
            }
            else if (pole_zero[i][j]==6){
                IMAGE * bitmap=loadBMP("Kletka6.jpg");
               putimage((j+1)*50,(i+1)*50, bitmap, COPY_PUT);
            }
            else if (pole_zero[i][j]==7){
                IMAGE * bitmap=loadBMP("Kletka7.jpg");
               putimage((j+1)*50,(i+1)*50, bitmap, COPY_PUT);
            }
            else if (pole_zero[i][j]==8){
               IMAGE * bitmap=loadBMP("Kletka8.jpg");
               putimage((j+1)*50,(i+1)*50, bitmap, COPY_PUT);
            }
         }
      }
   }
}



//------------------���� � �������---------------------------------------------------------
void pole_cifr(){
   int z;
   for (int x=0; x<N; x++){
      for(int y=0; y<N; y++){
         z=0;
         if (pole_zero[x][y] != -1){
            for (int i=x-1; i<=x+1 && i<N; i++){//�������� �� �������� ����
               for (int j=y-1; j<=y+1 && j<N; j++){
                  if(i>=0 && j>=0){
                     if (pole_zero[i][j]==-1) z++; 
                  }
               }
            }
            pole_zero[x][y]=z;
            if (pole_zero[x][y]==0) pole_zero[x][y]=9;
         } 
      }
   }
}



//-----��� (����� ��� �� �����, �������������� ��������)-------------------------------
bool shot(int x, int y, int a, int b){
   if (y>=17 && y<=22 && x>=12 && x<=16) return false;
   else if (x>15 || x<0 || y<0 || y>15) return true;//�������� �� ������� ����
   else if (mousebuttons()==1 ){//��� ���
      if (pole_mine[x][y]==1) {
         for (int i=0; i<N; i++){//------------���������� ��� ����------
            for(int j=0; j<N; j++){
               if (pole_mine[i][j]==1){
                  a=(i+1)*50;
                  b=(j+1)*50;
                  IMAGE * bitmap=loadBMP("KletkaM.jpg");
                  putimage(b,a, bitmap, COPY_PUT);
               }
            }
         }
         IMAGE * bitmap=loadBMP("Proigral.jpg");
         putimage(875,105, bitmap, COPY_PUT);
         getch();
         return false;   //  ���� ����� � ����
      }
      if (pole_zero[x][y]==9) func(x,y);
      else if (pole_zero[x][y]==1){
          IMAGE * bitmap=loadBMP("Kletka1.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
      }
      else if (pole_zero[x][y]==2){
          IMAGE * bitmap=loadBMP("Kletka2.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
      }
      else if (pole_zero[x][y]==3){
         IMAGE * bitmap=loadBMP("Kletka3.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
      }
      else if (pole_zero[x][y]==4){
          IMAGE * bitmap=loadBMP("Kletka4.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
      }
      else if (pole_zero[x][y]==5){
          IMAGE * bitmap=loadBMP("Kletka5.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
      }
      else if (pole_zero[x][y]==6){
          IMAGE * bitmap=loadBMP("Kletka6.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
      }
      else if (pole_zero[x][y]==7){
          IMAGE * bitmap=loadBMP("Kletka7.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
      }
      else if (pole_zero[x][y]==8){
         IMAGE * bitmap=loadBMP("Kletka8.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
      }
   }  
   else if (mousebuttons()==2 ){//��� ���
      if (pole_flag[x][y]==0){
         IMAGE * bitmap=loadBMP("Kletka11.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
         pole_flag[x][y]=1;
         if (pole_flag[x][y]==pole_mine[x][y]) kol_mine-=1;
      }
      else if (pole_flag[x][y]==1){
         IMAGE * bitmap=loadBMP("Kletka10.jpg");
         putimage((y+1)*50,(x+1)*50, bitmap, COPY_PUT);
         pole_flag[x][y]=0;
         if (pole_mine[x][y]==1) kol_mine+=1;
      }
   }
   return true;
}

//-------�����--------------------------------------------------------------------------



//---------����---------------------------------------------------------------------------------------
void game(){
   kol_mine=40;
   IMAGE * bitmap=loadBMP("Fon.jpg");
   putimage(0,0, bitmap, COPY_PUT);
   matr();//    ���� ��������
   zapol(kol_mine);// ������������� ��� �� ����
   pole_cifr();// ������������� ���� ����� ���
   
   int x, y, a, b;
   do{
      delay(200);
      if (kol_mine==0) {
         IMAGE * bitmap=loadBMP("Pobeda.jpg");
         putimage(870,0, bitmap, COPY_PUT);
         getch();
         break;
      }
      while(mousebuttons()!=1 && mousebuttons()!=2){
         y=(mousex()/50)-1; //50=900/18 � tabl()
         x=(mousey()/50)-1;
      }
   }while(shot(x,y,a,b));
}

bool exit(int a, int b){
   if (a>833 && a<1231 && b>677 && b<825) return false;
   return true;
}

bool next(int a, int b){
   if (a>833 && a<1231 && b>479 && b<625) return false;
   else if (a>833 && a<1231 && b>677 && b<825) return false;
   return true;
}


   
   
int main(){
   int x=1300, y=900, a, b, kol_mine, u;
   initwindow(x,y);
   do{
      IMAGE * bitmap=loadBMP("MENU1.jpg");
      putimage(0,0, bitmap, COPY_PUT);
      delay(200);
      while (mousebuttons()!=1){
         a=mousex();
         b=mousey();
      }
      if ((b>75 && b<224) && (a>833 && a<1229)) game();
      
      else if ((b>476 && b<625) && (a>833 && a<1229)){
         IMAGE * bitmap=loadBMP("Spravka.jpg");
         putimage(0,0, bitmap, COPY_PUT);
         delay(200);
         do{
            while (mousebuttons()!=1){
               a=mousex();
               b=mousey();
            }
         }while(next(a,b));
      }
      else if ((b>276 && b<425) && (a>833 && a<1229)){
         IMAGE * bitmap=loadBMP("Pomosh.jpg");
         putimage(0,0, bitmap, COPY_PUT);
         delay(200);
         do{
            while (mousebuttons()!=1){
               a=mousex();
               b=mousey();
            }
         }while(next(a,b));
      }
   }while(exit(a,b));
   return 0;
}
