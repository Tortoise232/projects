#include <iostream>
#include<windows.h>
#include<stdio.h>
#include<time.h>
int k=32;
int a[100][100];
FILE *g,*f;
char z;
using namespace std;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void culoare(int k,char x)
{SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), k);
  cout<<x;
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void detCol() // determina culoarea pe care o va avea charul
{int color;
    color=rand()%7+1;
    switch(color)
 {case 1: k=4;
  break;
  case 2: k=12;
  break;
  case 3: k=14;
  break;
  case 4: k=10;
  break;
  case 5: k=9;
  break;
  case 6: k=13;
  break;
  case 7: k=5;
  break;}
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), k);

}

void inima(int a[60][60])
{for(int i=1;i<=60;i++)
  for(int j=1;j<=60;j++)
    a[i][j]=0;
 a[8][40]=a[39][7]=a[38][6]=
 a[37][7]=a[36][8]=a[35][9]=
 a[35][10]=a[36][11]=a[37][12]=
 a[38][13]=a[39][14]=a[40][15]=
 a[41][14]=a[42][13]=a[43][12]=
 a[44][11]=a[45][10]=a[45][9]=
 a[44][8]=a[43][7]=a[42][6]=
 a[41][7]=1;

for(int i=1;i<=60;i++)
{for(int j=1;j<=60;j++)
  if(a[j][i]==1)
    {gotoxy(j,i);
    z=rand()%125+63;
    srand(z+time(NULL));
    cout<<z;}

gotoxy(0,0);
  }
}

void inimioara(int a[60][60])
{for(int i=1;i<=60;i++)
  for(int j=1;j<=60;j++)
    a[i][j]=0;


a[40][9]=a[39][8]=a[38][7]=
a[37][8]=a[36][9]=a[36][10]=
a[37][11]=a[38][12]=a[39][13]=
a[40][14]=a[41][13]=a[42][12]=
a[43][11]=a[44][10]=a[44][9]=
a[43][8]=a[42][7]=a[41][8]=1;

for(int i=1;i<=60;i++)
{for(int j=1;j<=60;j++)
  if(a[j][i]==1)
    {gotoxy(j,i);
    z=rand()%125+63;
    srand(z+time(NULL));
    cout<<z;}}
gotoxy(0,0);
    }

void inimoi(int a[60][60])
{for(int i=1;i<=60;i++)
  for(int j=1;j<=60;j++)
    a[i][j]=0;
a[38][5]=a[37][6]=a[36][7]=a[35][8]=a[43][6]=a[44][7]=a[45][8]=a[39][6]=a[41][6]=
a[40][6]=a[39][5]=a[38][5]=a[38][5]=a[41][5]=
a[37][5]=a[36][6]=a[35][7]=
a[34][8]=a[34][9]=a[34][10]=
a[35][11]=a[36][12]=a[37][13]=
a[38][14]=a[39][15]=a[40][16]=
a[40][17]=a[41][15]=a[42][14]=
a[43][13]=a[44][12]=a[45][11]=
a[46][10]=a[46][9]=a[46][8]=
a[45][7]=a[44][6]=a[43][5]=
a[42][5]=a[44][6]=1;


for(int i=1;i<=60;i++)
{for(int j=1;j<=60;j++)
  if(a[j][i]==1)
    {gotoxy(j,i);

    z=rand()%125+63;
    srand(z+time(NULL));
    cout<<z;}}
gotoxy(0,0);
    }

void inima_c(int a[60][60])
{for(int i=1;i<=60;i++)
  for(int j=1;j<=60;j++)
    a[i][j]=0;
    detCol();
 a[8][40]=a[39][7]=a[38][6]=
 a[37][7]=a[36][8]=a[35][9]=
 a[35][10]=a[36][11]=a[37][12]=
 a[38][13]=a[39][14]=a[40][15]=
 a[41][14]=a[42][13]=a[43][12]=
 a[44][11]=a[45][10]=a[45][9]=
 a[44][8]=a[43][7]=a[42][6]=
 a[41][7]=1;

for(int i=1;i<=60;i++)
{for(int j=1;j<=60;j++)
  if(a[j][i]==1)
    {gotoxy(j,i);
    z=rand()%125+63;
    srand(z+time(NULL));
    cout<<z;}

gotoxy(0,0);
  }
}

void inimioara_c(int a[60][60])
{for(int i=1;i<=60;i++)
  for(int j=1;j<=60;j++)
    a[i][j]=0;

detCol();
a[40][9]=a[39][8]=a[38][7]=
a[37][8]=a[36][9]=a[36][10]=
a[37][11]=a[38][12]=a[39][13]=
a[40][14]=a[41][13]=a[42][12]=
a[43][11]=a[44][10]=a[44][9]=
a[43][8]=a[42][7]=a[41][8]=1;

for(int i=1;i<=60;i++)
{for(int j=1;j<=60;j++)
  if(a[j][i]==1)
    {gotoxy(j,i);
    srand(time(NULL));
    z=rand()%125+63;
    srand(z);
    cout<<z;}}
gotoxy(0,0);

    }

void inimoi_c(int a[60][60])
{for(int i=1;i<=60;i++)
  for(int j=1;j<=60;j++)
    a[i][j]=0;
detCol();
a[38][5]=a[37][6]=a[36][7]=a[35][8]=a[43][6]=a[44][7]=a[45][8]=a[39][6]=a[41][6]=
a[40][6]=a[39][5]=a[38][5]=a[38][5]=a[41][5]=
a[37][5]=a[36][6]=a[35][7]=
a[34][8]=a[34][9]=a[34][10]=
a[35][11]=a[36][12]=a[37][13]=
a[38][14]=a[39][15]=a[40][16]=
a[40][17]=a[41][15]=a[42][14]=
a[43][13]=a[44][12]=a[45][11]=
a[46][10]=a[46][9]=a[46][8]=
a[45][7]=a[44][6]=a[43][5]=
a[42][5]=a[44][6]=1;


for(int i=1;i<=60;i++)
{for(int j=1;j<=60;j++)
  if(a[j][i]==1)
    {gotoxy(j,i);
    cout<<" ";}}
gotoxy(0,0);
    }

void text()
{char a[1000]="Draga mea Luiza, iti multumesc ca ai ramas cu mine atata timp, si iti urez un digital si calduros la multi ani din partea mea. Sper sa ai parte de toate experientele pe care ti le-ai propus, sa ajungi unde vrei sa fii si sa fii ceea ce vrei sa fii. Minunata. Te iubesc. De foarte mult timp, si sper sa fiu alaturi de tine in continuare. Ok. Gata cu urarile, daca ai stat pana aici inseamna ca deja te-ai plictisit de urari. La multi ani! Hah, ce teapa ti-am dat, ei? Oricum, repede au mai trecut 18 ani. Nici nu stiu cand, daca stau sa ma gandesc bine. De fapt, daca stau sa ma gandesc bine, au trecut din 1997 si pana acum. Nu e greu calculul. Te iubesc. Te iubesc. Te iubesc. Traieste asa cum simti, atunci cand simti, si oricat de morocanos as parea, iti urez tot binele din lume. Tot tot tot, pentru tine. Pentru ca meriti! Si acum, la piessse de rezistences.................";
 for(int i=0;i<=1000;i++)
 {cout<<a[i];
  Sleep(100);
 }
}
void wave(int a[60][60])
{for(int i=1;i<=60;i++)
  for(int j=1;j<=60;j++)
    if(j>38)
    {if(i<=10)
     if(a[j][i]==1)
      {if(a[j-1][i]==0)
        {gotoxy(j-1,i);
         cout<<"o";}
        if(a[j-1][i-1]==0)
        {gotoxy(j-1,i-1);
         cout<<"o";}
        if(a[j-1][i+1]==0)
        {gotoxy(j-1,i+1);
         cout<<"o";}
        if(a[j][i+1]==0)
        {gotoxy(j,i+1);
         cout<<"o";}
        if(a[j+1][i+1]==0)
        {gotoxy(j+1,i+1);
         cout<<"o";}
}}}
void k2(int &k)
{k-=10;}
void k1(int &k)
{k+=10;}




void heartbeat(int a[60][60])
//tweaked from the original
{int sleepPeriod = 60;
    inimioara(a);
  Sleep(sleepPeriod);
  inima(a);
  Sleep(sleepPeriod/3);
  inimoi(a);
  Sleep(sleepPeriod);
  inimoi_c(a);
  inimioara(a);
  inima(a);
  Sleep(sleepPeriod/3);
  inima_c(a);
  inimioara(a);
  Sleep(sleepPeriod);
  inima(a);
  Sleep(sleepPeriod/50);
   inima_c(a);
    srand(time(NULL));
    z = rand()%100+1;

}

int main()
{int x=0;int a[60][60];

 system("cls");
 while(1)
  {heartbeat(a);
   if(k==32)
    k2(k);
   else
    k1(k);}
 return 0;}

