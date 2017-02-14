 #include<iostream>
 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
 #include<windows.h>
 #include<conio.h>
 int v[20];int i=0; int k=0; char x;int w[20];int scor=0;int j=0;int contor=0;
int v1[20],v2[20];int ucheck=1;int ucount=2;int debugextra2a_check=0;int debugextra2b_check=0;
int v3[20];
void rotireS()
{w[1]=v[4];w[5]=v[3];w[9]=v[2];w[13]=v[1];
 w[2]=v[8];w[6]=v[7];w[10]=v[6];w[14]=v[5];
 w[3]=v[12];w[7]=v[11];w[11]=v[10];w[15]=v[9];
 w[4]=v[16];w[8]=v[15];w[12]=v[14];w[16]=v[13];
 for(i=1;i<=16;i++)
   v[i]=w[i];}



void rotireD()
{w[1]=v[13];w[5]=v[14];w[9]=v[15];w[13]=v[16];
 w[2]=v[9];w[6]=v[10];w[10]=v[11];w[14]=v[12];
 w[3]=v[5];w[7]=v[6];w[11]=v[7];w[15]=v[8];
 w[4]=v[1];w[8]=v[2];w[12]=v[3];w[16]=v[4];
 for(i=1;i<=16;i++)
    v[i]=w[i];}


void afisareJ()
{std::cout<<"\n";
std::cout<<"____________________";
std::cout<<"\n";
for(i=1;i<=4;i++)
 {std::cout<<"|";
  if(v[i]==0)
    std::cout<<"    ";
  else
    if(v[i]>=1000)
   std::cout<<v[i]<<" ";
  else
    if(v[i]<1000&&v[i]>=100)
     std::cout<<" "<<v[i];
    else
        if(v[i]<100&&v[i]>=10)
        std::cout<<" "<<v[i]<<" ";
    else
        if(v[i]<10)
        std::cout<<"  "<<v[i]<<" ";}std::cout<<"|";
std::cout<<"\n";
std::cout<<"____________________";
std::cout<<"\n";
for(i=5;i<=8;i++)
  {std::cout<<"|";
  if(v[i]==0)
    std::cout<<"    ";
  else
    if(v[i]>=1000)
   std::cout<<v[i]<<" ";
  else
    if(v[i]<1000&&v[i]>=100)
     std::cout<<" "<<v[i];
    else
        if(v[i]<100&&v[i]>=10)
        std::cout<<" "<<v[i]<<" ";
    else
        if(v[i]<10)
        std::cout<<"  "<<v[i]<<" ";}
std::cout<<"|";
std::cout<<"\n";
std::cout<<"____________________";
std::cout<<"\n";
for(i=9;i<=12;i++)
   {std::cout<<"|";
    if(v[i]==0)
    std::cout<<"    ";
  else
    if(v[i]>=1000)
   std::cout<<v[i]<<" ";
  else
    if(v[i]<1000&&v[i]>=100)
     std::cout<<" "<<v[i];
    else
        if(v[i]<100&&v[i]>=10)
        std::cout<<" "<<v[i]<<" ";
    else
        if(v[i]<10)
        std::cout<<"  "<<v[i]<<" ";}
std::cout<<"|";
std::cout<<"\n";
std::cout<<"____________________";
std::cout<<"\n";
for(i=13;i<=16;i++)
   {std::cout<<"|";
     if(v[i]==0)
    std::cout<<"    ";
  else
    if(v[i]>=1000)
   std::cout<<v[i]<<" ";
  else
    if(v[i]<1000&&v[i]>=100)
     std::cout<<" "<<v[i];
    else
        if(v[i]<100&&v[i]>=10)
        std::cout<<" "<<v[i]<<" ";
    else
        if(v[i]<10)
        std::cout<<"  "<<v[i]<<" ";}
        std::cout<<"\n";
        std::cout<<"____________________";
        std::cout<<"|";}

 void extra2()
 {int contor_extra1=0;int contor_extra2=0;
 int k=0;int l=0;unsigned y,var3;
 for(i=1;i<=16;i++)
  if(v[i]==0)
    k++;
  else
    contor_extra1++; //contor pentru elementele vectorului inainte de adaugarea propriuzisa a 2-ului
 srand(time(NULL));
 var3=rand()%k;
 for(i=1;i<=16;i++)
  if(v[i]==0)
  {l++;
   if(l==var3)
    v[i]=2;}
  for(i=1;i<=16;i++)
    if(v[i]!=0)
       contor_extra2++; // contor pentru elementele vectorului dupa adaugarea propriu-zisa
    if(contor_extra2==contor_extra1)
  {afisareJ();std::cout<<"\nLoading...";
    Sleep(1000); //intarziere pentru a evita crashul determinat de srand-ul dependent de TIME(NULL)
    system("cls");
    extra2();} //re-apelare pentru rezolvarea 2-urilor lipsa
    }




 void startJ()
 { for(i=1;i<=16;i++)
     v[i]=0;
     std::cout<<"\nAceasta versiune a jocului 2048 se afla in starea 0.5 ALPHA";
     std::cout<<"\n\nCOMENZILE FOLOSITE SUNT: W A S D\n\nPENTRU A INCEPE, TASTEAZA 1\n\nPENTRU A IESI DIN PROGRAM, TASTEAZA 0 DUPA INITIERE\n\n";
     extra2();
     extra2();

     int pornire;
     std::cin>>pornire;
     system("cls");
     afisareJ();
 }

void clash()
{int aux=0,check=1;
for(k=1;k<=4;k++)
for(i=1;i<=4;i++)
 if(v[i]==0)
   for(j=i;j<=3;j++)
 {aux=v[j];
  v[j]=v[j+1];
  v[j+1]=aux;}
   for(i=1;i<=4;i++)
    if(v[i]==v[i+1]&&v[i]==v[i+2]&&v[i]==v[i+3]&&v[i]!=0)
{v[i]=2*v[i+1];scor+=v[i];
 v[i+1]=2*v[i+2];scor+=v[i+1];
 v[i+2]=v[i+3]=0;check=0;}
else
if(v[i]==v[i+1]&&v[i]==v[i+2]&&v[i+3]!=v[i]&&v[i]!=0&&v[i+3]!=0)
{v[i]=2*v[i+1];scor+=v[i];
 v[i+1]=v[i+2];v[i+2]=v[i+3];
 v[i+3]=0;check=0;}
else
if(v[i]==v[i+1]&&v[i]!=v[i+2]&&v[i]!=0&&v[i+2]!=0&&v[i+3]!=0)
 {v[i]=2*v[i+1];scor+=v[i];
  v[i+1]=v[i+2];v[i+2]=v[i+3];v[i+3]=0;check=0;}
else
if(v[i]!=v[i+1]&&v[i+2]==v[i+3]&&v[i+2]!=v[i+1]&&v[i+2]!=0&&v[i+1]!=0&&v[i]!=0)
  {v[i+2]=2*v[i+3];scor+=v[i+2];
   v[i+3]=0;check=0;}
else
if(v[i]!=v[i+1]&&v[i+1]==v[i+2]&&v[i]!=0&&v[i+1]!=0&&v[i+3]!=0)
  {v[i+1]=2*v[i+2];scor+=v[i+1];
   v[i+2]=v[i+3];
   v[i+3]=0;check=0;}
else
if(v[i]!=v[i+1]&&v[i+1]!=v[i+2]&&v[i+2]!=v[i+3]&&v[i]!=0&&v[i+1]!=0&&v[i+2]!=0&&v[i+3]!=0)
  {v[i]=v[i];
   check=0;}
else
{for(i=1;i<=4;i++)
    if(check)
    if(v[i]==v[i+1])
{v[i]=2*v[i+1];scor+=v[i];
 for(j=i+1;j<=4;j++)
    v[j]=v[j+1];
    v[4]=0;
    check=0;
} check=1;

for(k=1;k<=4;k++)
for(i=5;i<=8;i++)
 if(v[i]==0)
   for(j=i;j<=7;j++)
 {aux=v[j];
  v[j]=v[j+1];
  v[j+1]=aux;}
for(i=5;i<=8;i++)
    if(check)
    if(v[i]==v[i+1])
{v[i]=2*v[i+1];scor+=v[i];
 for(j=i+1;j<=8;j++)
    v[j]=v[j+1];
    v[8]=0;
    check=0;
} check=1;

for(k=1;k<=4;k++)
for(i=9;i<=12;i++)
 if(v[i]==0)
   for(j=i;j<=11;j++)
 {aux=v[j];
  v[j]=v[j+1];
  v[j+1]=aux;}
for(i=9;i<=12;i++)
    if(check)
    if(v[i]==v[i+1])
{v[i]=2*v[i+1];scor+=v[i];
 for(j=i+1;j<=12;j++)
    v[j]=v[j+1];
    v[12]=0;
    check=0;
} check=1;

for(k=1;k<=4;k++)
for(i=13;i<=16;i++)
 if(v[i]==0)
   for(j=i;j<=15;j++)
 {aux=v[j];
  v[j]=v[j+1];
  v[j+1]=aux;}
for(i=13;i<=16;i++)
    if(check)
    if(v[i]==v[i+1])
{v[i]=2*v[i+1];scor+=v[i];
 for(j=i+1;j<=16;j++)
    v[j]=v[j+1];
    v[16]=0;
    check=0;
} check=1;}}

void movecheck1(int v3[])
{
for(i=1;i<=16;i++)
  v3[i]=v[i];//salveaza vectorul inaintea adaugarii de 2.
}


int movecheck2(int v3[])
{int ok2=1;
 for(i=1;i<=16;i++)
  if(v[i]!=v3[i])
     ok2=0;
  if(ok2)
    return 1; // nu s-A SCHIMBAT NICI O VALOARE
  else
    return 0; //s-a schimbat una sau mai multe valori
}


void mutareJ()
{movecheck1(v3);
 if(x=='a')
  clash();
 if(x=='w')
  {rotireS();
   clash();
   rotireD();}
 if(x=='d')
 {rotireS();rotireS();
   clash();
   rotireD();rotireD();}
  if(x=='s')
  {rotireS();rotireS();rotireS();
  clash();
  rotireD();rotireD();rotireD();}
   system("cls");
  std::cout<<"\n";
  if(!movecheck2(v3))
    {extra2();}
  afisareJ();
  std::cout<<"\n\n\n"<<"SCORUL TAU= "<<scor;


}

void checkJ(char &x)
{int var=0;
 for(i=1;i<=16;i++)
 if(v[i]==0)
  var++;
  if(var==1)
    {x=NULL;
    system("cls");
    std::cout<<"\nAI PIERDUT\n\nSCORUL TAU ESTE:"<<scor<<"\n\n\n(acum apasa 0)";
    x=getch();
    system("cls");
    }}

void session()
{while(x!='0')
 { mutareJ();
  std::cout<<"\n\n\n";
  Sleep(100);
  x=getch();
  checkJ(x);
  }
}
int main()
{int checker=1;
 startJ();
  x=getch();

  session();

 return 0;}


