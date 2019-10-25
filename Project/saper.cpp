#include <iostream>
#include <time.h>
#include <windows.h>
#include "graphics.h"

using namespace std;


bool exit(int a, int b){
   if (a>833 && a<1231 && b>677 && b<825) return false;
   return true;
}

bool next(int a, int b){
   if (a>833 && a<1231 && b>479 && b<625) return false;
   else if (a>833 && a<1231 && b>677 && b<825) return false;
   return true;
}

//Игра
void game(){
   IMAGE * bitmap=loadBMP("Fon.jpg");
   putimage(0,0, bitmap, COPY_PUT);
   int a,b;
   do{
      while (mousebuttons()!=1){
         a=mousex();
         b=mousey();
      }
   }while(exit(a,b));
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
      if ((b>75 && b<224) && (a>833 && a<1229)) game();//Игра
      
      else if ((b>476 && b<625) && (a>833 && a<1229)){//Справка
         
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
      else if ((b>276 && b<425) && (a>833 && a<1229)){//Помощь
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
