/*******************************************************************************************************************************************
University: Addis Ababa Science and Technology University
Made by: Nahom Habtamu Debalkie     ID: ETS0505/12  Sec: E  Date made: 23/12/2013 E.C. or 29/08/2021 G.C.
********************************************************************************************************************************************
Use of this library
-------------------
This header library function can be used to make the menu be chosen using the UP, DOWN and ENTER keyboard keys.

How to Use
----------
1. Copy this header file the same folder as your .cpp file
2. Include this header file in your .cpp file using ---- #include"arrowMenu.h"
3. The function returns an 'int' data type and has 3 parameters 'string array', 'int' and 'string' with default value
4. Create an array with 'string' data type and initialize it
5. In the array, the first array element(0th index) should be the title of the menu displayed which is NOT a selectable menu item
6. The other array elements are selectable, starting from index 1 to your desired number of menu elements
    eg. string menuArray[] = {"\tMain Menu", "1. Continue", "2. New Game", "3. Exit"};
7.

********************************************************************************************************************************************/
#include<conio.h>
#include<iostream>
using namespace std;
//ASCII CODES
//up-72 down-80 left-75 right-77 enter-13
int counter=1;
void display(string menu[], int counter, int arrayMenuSize, string menuPointer)
{
    cout<<menu[0]<<endl;
    for(int i = 1; i<arrayMenuSize; i++)
    {
        if(i == counter)
        {
            cout<<menuPointer<<"  "<<menu[i]<<endl;
        }
        else
            cout<<"  "<<menu[i]<<endl;
    }
}
int arrowMenu(string arrayMenu[], int arrayMenuSizeA, string menuPointer = "->")
{
    int arrayMenuSize = arrayMenuSizeA + 1;
    int c;
    display(arrayMenu, counter, arrayMenuSize, menuPointer);
    while(1)
    {
        c=0;
        c = getch();
        if(c==72 || c==80 || c==13)
        {
            switch(c)
            {
            case 72:    //up arrow
                --counter;
                break;
            case 80:    //down arrow
                ++counter;
                break;
            case 13:
                return counter;
            }
            system("cls");
            if(counter >= 1 && counter <= arrayMenuSize-1)
            {
                display(arrayMenu, counter, arrayMenuSize, menuPointer);
            }
            else if(counter < 1)
            {
                counter = arrayMenuSize-1;
                display(arrayMenu, counter, arrayMenuSize, menuPointer);
            }
            else if(counter > arrayMenuSize-1)
            {
                counter = 1;
                display(arrayMenu, counter, arrayMenuSize, menuPointer);
            }
        }
    }
}
