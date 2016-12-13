#include<iostream>
#include<windows.h>
#include<time.h>
using namespace std;
int a[100][100];
int color;
int srand1 = 1;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void randomSpawn()
{srand(time(NULL)+srand1);
 srand1++;
 int x,y;
     do{ x = rand()%25+0; }while( x<=0 || x>=25 );
     do{ y = rand()%70+0; }while( y<=0 || y>=70 );
     a[x][y]=1;
 }



int detCol(int &k) // determina culoarea pe care o va avea charul
{switch(color)
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

  color=rand()%7+1;
}
/*void selectPoint(int &x,int &y) //selecteaza pozitie
{for(int i=0;i<=100;++i)
  for(int j=0;j<=100;++j)
    if(a[i][j]==2)
     {x=i;
      y=j;} */

/* ~~~~~~~~~~~~~~~~~~~~~BROKEN AS FUCK~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int orientare() //misca tot catre pozitii nevoite
{int c,b; // pozitie tintita de fiecare entitate
  for(int i=0;i<=100;++i)
  for(int j=0;j<=100;++j)
  {if(a[i][j]==1)
   {selectPoint(c,b);
   if(i>c&&a[i-1][j]!=1)
    {a[i-1][j]=1;
     a[i][j]=0;}
   else
    {if(i<c&&a[i+1][j]!=1)
   {a[i+1][j]=1;
    a[i][j]=0;}
   else
    {if(j<b&&a[i][j+1]!=1)
   {a[i][j+1]=1;
    a[i][j]=0;}
    else
    if(j>b&&a[i][j-1]!=1)
    {a[i][j-1]=1;
     a[i][j]=0;}}}}
    }
}
   ~~~~~~~~~~~~~~~~~~~~~BROKEN AS FUCK~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
int mover(int pozi, int pozj, int x, int y, int a[][100])
//supposed to delete the value from pozi and pozj (in the matrix) and move it to x,y
{int tempX = 0,tempY = 0;
    if(pozi<1|| pozj<1||pozi>50||pozj>50)
        return 0;
    if(pozi < x)
        tempX = pozi + 1;
    if(pozi > x)
        tempX = pozi - 1;
    if(pozj <y)
        tempY = pozj + 1;
    if(pozj >y)
        tempY = pozj - 1;
    if(pozi == x && pozj == y)
        return 0;
a[tempX][tempY] = 2;
a[pozi][pozj] = 0;
return 0;
}

int show()
{char z;int k;
 for(int i=0;i<=100;++i)
  for(int j=0;j<=100;++j)
    if(a[i][j] == 1)
     {
        gotoxy(j,i);
        z=rand()%125+63;
        detCol(k);
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), k);
        cout<<z;
        mover(i,j,10,10,a);

    }

}

int main()
{
while(1)
{ // getting somewhere, maybe?

 randomSpawn();
 a[1][1] = 1; //this holds the generation together, for some reason (lol)
 Sleep(1);
 show();
for(int i = 0; i <=100; i ++)
    for(int j = 0; j<=100; j++)
    if(a[i][j] == 1)
        {
            gotoxy(j,i);
            cout<<" ";
            a[i][j] = 0;
        }
for(int i = 0 ;i <= 100 ; i ++)
    for (int j =0 ;j <= 100 ; j++)
        if(a[i][j] == 2)
            a[i][j] = 1;

 //orientare();
}}
