// Acest program ar trebui sa indeplineasca rolul de afisare, management si calcul aritmetic al sumelor de bani pe care le detin
// Another baby of mine, lel.
#include <iostream>
#include<windows.h>
#include<stdio.h>
using namespace std;
FILE *f;


typedef struct{
int col; // culoarea chestiei, desi inutila.
char name[100];
float suma; //suma de bani, de castigat sau de cheltuit
char data[11]; // data de tip zz/ll/aaaa
}task;
task t[1000];

void color(int k) // colorare text, yey
{SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), k);}
void stergere_carnet()
{int i=1,a; // i este contorul taskurilor
 float suma;
 f=fopen("carnet.txt","r");
 while(!feof(f))
 {fscanf(f,"\n%s %f %s",&t[i].name,&t[i].suma,&t[i].data);
  i++;}
  fclose(f);
  cout<<"A cata insemnare in carnet doriti a fi stearsa (numerotarea se face de sus in jos): ";cin>>a;
  for(a;a<1000;a++)
  {t[a].col=t[a+1].col;
   strcpy(t[a].name,t[a+1].name);
   strcpy(t[a].data,t[a+1].data);
   t[a].suma=t[a+1].suma;
  }
  t[1000].col=0;
  t[1000].suma=0;
  strcpy(t[1000].name,"NULL");
  strcpy(t[1000].data,"NULL");
  i--;
  f=fopen("carnet.txt","w");
 for(int j=1;j<i;j++) // rescrie informatia in fisier
    fprintf(f,"\n%s %f %s",t[j].name,t[j].suma,t[j].data);
 fclose(f);
}

void afisare_venit() // afiseaza suma actuala de bani pe care o detin
{float suma;
 f=fopen("venit.txt","r");
 fscanf(f,"%f",&suma);
 fclose(f);
 color(14);
 cout<<"Venitul tau actual: "<<suma<<"\n";
 color(7);
 f=fopen("venit.txt","w");
 fprintf(f,"%f",suma); //rescrie suma in fisier
 fclose(f);
}

void afisare_carnet() //
{int i=1; // i este contorul taskurilor
 f=fopen("carnet.txt","r");
 while(!feof(f))
 {fscanf(f,"\n%s %f %s",&t[i].name,&t[i].suma,&t[i].data);
  if(t[i].suma>0)
    color(2);
  else
    color(4);
  cout<<"\n"<<t[i].name<<" "<<t[i].suma<<" "<<t[i].data;
    color(7);
  i++;
  }
  cout<<"\n";
 fclose(f);
 f=fopen("carnet.txt","w");
 for(int j=1;j<i;j++) // rescrie informatia in fisier
    fprintf(f,"\n%s %f %s",t[j].name,t[j].suma,t[j].data);
 fclose(f);
}

void inscriere_carnet()
{int i=1; // i este contorul taskurilor
 float suma;
 f=fopen("carnet.txt","r");
 while(!feof(f))
 {fscanf(f,"\n%s %f %s",&t[i].name,&t[i].suma,&t[i].data);
  i++;}
 cout<<"Denumirea inscrierii in carnet: ";
 cin>>t[i].name;
 cout<<"Specificati suma (+ pentru bani primiti, - pentru bani consumati): ";
 cin>>t[i].suma;
 cout<<"Specificati data curenta (zz.ll.aaaa): ";
 cin>>t[i].data;

 fclose(f);
 f=fopen("venit.txt","r");
  fscanf(f,"%f",&suma);
 suma+=t[i].suma;
 fclose(f);
 f=fopen("venit.txt","w");
 fprintf(f,"%f",suma);
 fclose(f);
 i++;
 cout<<"\n";
 f=fopen("carnet.txt","w");
 for(int j=1;j<i;j++) // rescrie informatia in fisier
    fprintf(f,"\n%s %f %s",t[j].name,t[j].suma,t[j].data);
 fclose(f);
}

void afisare_task() // subprogram pentru afisat o lista cu lucruri ce trebuie cumparate, facute
{int i=1; // i este contorul taskurilor
 f=fopen("date.txt","r");
 while(!feof(f))
 {fscanf(f,"\n%s %d",&t[i].name, &t[i].col);
  color(t[i].col);
  cout<<"\n"<<t[i].name;
  color(7);
  i++;
  }
  cout<<"\n";
 fclose(f);
 f=fopen("date.txt","w");
 for(int j=1;j<i;j++) // rescrie informatia in fisier
    fprintf(f,"\n%s %d",t[j].name,t[j].col);
 fclose(f);
}

int comenzi()
{char x[100];
 while(1){
gets(x);
 if(strstr(x,"biban"))
  cout<<"Nu sunt biban,boss!\n";
 if(strstr(x,"prieten"))
  cout<<"Nu sunt prietenul tau, frate!\n";
 if(strstr(x,"frate"))
  cout<<"Nu sunt fratele tau, tati!\n";
 if(strstr(x,"tata")||strstr(x,"tati"))
  cout<<"Nu's tactu, bibane!\n";
 if(strstr(x,"te rog")||strstr(x,"multumesc"))
  cout<<"Cu cea mai mare placere\n";
 if(strstr(x,"suma")||strstr(x,"bani")||strstr(x,"venit")||strstr(x,"bistari")||strstr(x,"verzisori"))
  afisare_venit();
 if(strstr(x,"carnetel")||strstr(x,"carnet"))
    if(strstr(x,"inscriere"))
      inscriere_carnet();
    else
      if(strstr(x,"sterge"))
        stergere_carnet();
      else
        afisare_carnet();
 if(strstr(x,"curata")||strstr(x,"clean"))
  system("cls");
 if(strstr(x,"task")||strstr(x,"notari")||strstr(x,"scop"))
  afisare_task();
 if(strstr(x,"shutdown"))
  return 0;}
}

int main()
{ comenzi();
 return 0;}
