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


