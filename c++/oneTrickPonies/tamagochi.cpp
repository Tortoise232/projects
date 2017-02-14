#include <iostream>
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include <conio.h>
FILE *f;
//ADD THE FILE TAMA.TXT SO THAT THE GAME CAN RUN
struct entiti {
int id; // 0 pentru nimicuri, 1 pentru entitati, 2 pentru mancare
int x,y;
int hp;
int colour;};
entiti a[100];
int k; //folosit pentru random

using namespace std;
int x,y,hunger;// pozitia tomo, x coloana si y linie

void clean()
{for(int i=2;i<=100;i++)
  a[i].id=a[i].hp=a[i].x=a[i].y=0;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void death(int i)
{gotoxy(a[i].x,a[i].y);
a[i].id=a[i].x=a[i].y=0;
}
void food(int i)
{srand(time(NULL));
 a[i].x=rand()%50+1;
 srand(time(NULL)+42);
 a[i].y=rand()%20+1;
 gotoxy(x,y);
 cout<<"f";
 a[i].id=2;
 a[i].hp=1;
}

void creep(int i)
{srand(time(NULL));
 a[i].x=rand()%50+1;
 srand(k);
 k++;
 a[i].y=rand()%20+1;
 a[i].colour=(rand()%170+1);
 a[i].id=1;
 a[i].hp=rand()%9+1;
}

void culoare(int k,char x)
{SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), k);
  cout<<x;
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void afisare(int i) // afisare tomo la pozitia x,y
{gotoxy(a[i].x,a[i].y);
 if(a[i].id==1)
 {if(i==1)
   culoare(32,' ');
   else
    {SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), a[i].colour);
    cout<<a[i].hp;
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}}
 else
  cout<<"f";
 gotoxy(60,0);
 cout<<"HUNGER:"<<a[1].hp;
 if(a[1].hp<10)
 {gotoxy(68,0);
 cout<<" ";}
}
void eat(int i,int j) //i mananca pe j
{gotoxy(a[j].x,a[j].y);
 cout<<" ";
 a[j].id=0;
 a[i].hp+=a[j].hp;
 a[j].hp=0;
 a[j].x=a[j].y=0;
}

int eat_check(int i,int j)//1 pentru i mananca j, -1 pentru j mananca i
{if((a[j].id==2||a[i].hp>=a[j].hp)&&a[j].id!=0&&a[i].id==1)
  return 1;
 if((a[i].id==2||a[j].hp>=a[i].hp)&&a[j].id==1&&a[i].id!=0)
   return -1;
 return 0;
}

void check()
{for(int i=1;i<=100;i++)
  for(int j=1;j<=100;j++)
    if(a[i].x==a[j].x&&i!=j)
     {if(a[i].y==a[j].y+1||a[i].y==a[j].y||a[i].y==a[j].y-1)
       {if(eat_check(i,j)==1)
        eat(i,j);
       if(eat_check(i,j)==-1)
        {eat(j,i);}
     }}
    else
     if(a[i].y==a[j].y&&i!=j)
     {if(a[i].x==a[j].x+1||a[i].x==a[j].x||a[i].x==a[j].x-1)
       {if(eat_check(i,j)==1)
        eat(i,j);
       if(eat_check(i,j)==-1)
        eat(j,i);
     }

}}
void init(int &x,int &y,int &hunger) // initializare cu pozitie,hp, ...
{
 f=fopen("tama.txt","r");
 fscanf(f,"%d %d\n%d",&x,&y,&hunger);
 fclose(f);
 a[1].id=1;
}
void print(int x,int y,int hunger) //printeaza ultima pozitie a lui tomo
{ f=fopen("tama.txt","w");
 fprintf(f,"%d %d\n%d",x,y,hunger);
 fclose(f);
}


void movement(int &x,int &y,char z) //misca tomo in functie de characterul folosit (wasd)
{
 if(z=='a'&&x>0)
  {x--;
   gotoxy(x+1,y);
    cout<<" ";}
 if(z=='d'&&x<50)
  {x++;
   gotoxy(x-1,y);
    cout<<" ";}
 if(z=='w'&&y>0)
  {y--;
   gotoxy(x,y+1);
    cout<<" ";}
 if(z=='s'&&y<20)
  {y++;
  gotoxy(x,y-1);
    cout<<" ";}
}

void roaming(int &x,int &y)
{int c;
 srand(k);
 k++;
 c=rand()%4+1;
 switch(c){
    case 1:
    movement(x,y,'a'); break;
    case 2:
    movement(x,y,'w');break;
    case 3:
    movement(x,y,'d');break;
    case 4:
    movement(x,y,'s');break;
    default:
    movement(x,y,'w');break;}

}

void target(int tg,int id) //calculeaza miscarea catre obiectivul tintit, tg- cel tintit, id- cel care il urmareste
{if(abs(a[tg].x-a[id].x)>=abs(a[tg].y-a[id].y))
   {if(a[tg].x>a[id].x)
    movement(a[id].x,a[id].y,'d');
     else
    movement(a[id].x,a[id].y,'a');
    }
  else
  {if(a[tg].y>a[id].y)
    movement(a[id].x,a[id].y,'s');
    else
    movement(a[id].x,a[id].y,'w');
  }

}

void ai_hunt(int &x,int &y,int id) //face o entitate "id" sa se miste intr-o directie, catre mancare viabila
{ int mind,pozmind; //mind= minimul distantei dintre entitatea "id" si entitatea tintita, pozmind pozitia sa;
  int v[100];
  for(int j=1;j<=100;j++)
    v[j]=0;
 for(int j=1;j<=100;j++)
  {if(j!=id)
  {if(a[j].hp<a[id].hp||a[j].id==2)
   v[j]+=abs(a[id].x-a[j].x)+abs(a[id].y-a[j].y);}
  else v[j]=3200;} // ca entitatea sa nu se tinteasca singura, calculeaza ca este foarte departe de ea insasi.
  mind=v[1];
  for(int i=1;i<=100;i++)
    if(mind>v[i])
     {mind=v[i];
      pozmind=i;}
 if(pozmind!=3200&&pozmind!=0)
 target(pozmind,id);
 else
roaming(x,y);
}


void food_mult(int j,int x,int y)
{int ok=1;
 roaming(a[j].x,a[j].y);
  while(a[j].id!=0&&ok)
    {j++;
     if(j==100)
     {ok=0;}
    }
if(ok){
  a[j].id=2;
  a[j].hp=1;
  a[j].x=x;
  a[j].y=y;}
  if(j>=100)
    j=1;}


void loop(char &b,int &hunger)
{int i=1,j=1;
 while(b!='0'&&hunger>0)
  {
   if(kbhit())
   {b=getch();
   if(b=='f')
   {while(a[j].id!=0)
    j++;
  food(j);
  if(j>=100)
    j=1;
}
    movement(a[1].x,a[1].y,b);}
if(i%150==0)
 for(k=1;k<=100;k++)
{if(a[k].id==2)
 food_mult(k,a[k].x,a[k].y);
}
 for(int k=1;k<=100;k++)
    {if(a[k].id!=0)
      afisare(k);}
 check();
 gotoxy(0,0);
 if(i%100==0)
    { {while(a[j].id!=0) // cauta un loc de entitate gol si spawneaza un creep;
        j++;
       creep(j);

      if(j>=100)
        j=1;
      }
       for(int k=1;k<=100;k++)
        if(a[k].id==1)
        {if(a[k].hp>0)
         {if(a[j].hp>=10)
        a[j].hp=9;
        ai_hunt(a[k].x,a[k].y,k);
          a[k].hp--;}
        }
    }
 if(i%100==0)
 {while(a[j].id!=0) // cauta un loc de entitate gol si spawneaza mancare
    j++;
  food(j);
  if(j>=100)
    j=1;
  i=1;
  }
    i++;}
  }

int main()
{ char b;
  k=time(NULL);
  clean();
  init(a[1].x,a[1].y,a[1].hp);
  loop(b,a[1].hp);
  system("cls");
  if(a[1].hp<=0)
  {cout<<"Dude, you just killed tomo. You fucking prick.\nTomo was beautiful.";
  cout<<"\nResurecting tomo in:";
  for(int i1=5;i1>=1;i1--)
  {cout<<i1<<" ";
   Sleep(1000);
  }
   print(10,10,5);}
   else
    print(a[1].x,a[1].y,a[1].hp);

    return 0;
}
