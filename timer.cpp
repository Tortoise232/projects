#include <iostream>
#include<time.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

int main()
{
    char storeKey;
    int startingTime = time(NULL);
    int switchForBreak = 0;
    int passedTime;

    while(1)
    {
        if(kbhit())
                {
                    storeKey = getch();
                    switchForBreak = atoi(&storeKey);
                }
        if(switchForBreak == 0)
            {
                system("cls");
                passedTime = time(NULL) - startingTime;
                cout<<passedTime;
            }

    }
    return 0;
}
