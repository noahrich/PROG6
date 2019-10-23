//---------------------------------------------------------------------------
// File name:   robot100.cpp
// Assign ID:   PROG6
// Due Date:    MARCH 5, 2019
//
// Purpose:     Write a program to simulate the movement of a robot on a
//             2-dimensional grid (0,0) to (10,10). Simple 1-step 
//             moves are supported: L (left), R (right), U (up) and D (down)
//
// Author:      nrichardson Noah Richardson
//
//---------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
#include  <stdlib.h>
using namespace std;
int main()
{
   char command;
   int x=0;
   int y=0;
   int valid =0;
   int invalid =0;
   int badcmd =0 ;
   bool active = false; 
   ifstream inF("robot100.cmds");
    //true when robot started
    cout << endl;
    cout << endl;

    do
    {
    inF >> command;
    switch(command)
    {
        case 'T': 
            active = false;
            cout << endl;
            cout << "TERMINATED AT POSITION" << " (" << x << "," << y << ")" << endl;
            cout << endl;
            break;
        case 'S':
            active = true;
            cout << "ROBOT TRACKER" << endl;
            cout << "=============" << endl; 
            cout << "STARTED AT POSITION" << "(0,0)" << endl;
            break;
        case 'R':
            if(active == true)
            {
            cout << "RIGHT ";
            x++;
                if(x == 11)
                {
                    cout << "BAD MOVE TO " << "(" << x << ", " << y << ")" << endl;
                    x--;
                    invalid++;
                }else{
                    valid++;
                }
            }
            break;
        case 'U':
            if(active == true)
            {
            cout << "UP ";
            y++;
                if(y == 11)
                {
                    cout << "BAD MOVE TO " << "(" << x << ", " << y << ")" << endl;
                    y--;
                    invalid++;
                }else{
                    valid++;
                }
            }
            break;
        case 'D':
            if(active == true)
            {
            cout << "DOWN ";
            y--;
                if(y == -1)
                {
                    cout << "BAD MOVE TO " << "(" << x << ", " << y << ")" << endl;
                    y++;
                    invalid++;
                }else{
                    valid++;
                }
                }
                
            
            break;
        case 'L':
            if(active == true)
            {
            cout << "LEFT ";
            x--;
                if(x == -1)
                {
                    cout << "BAD MOVE TO " << "(" << x << ", " << y << ")" << endl;
                    x++;
                    invalid++;
                }else{
                    valid++;
                }
            }
            break;
        
        case 'W':
            if(active == true)
            {
            cout << endl;
            cout << "POS = " << "(" << x << "," << y << ")" << endl;
            }
            break;
        default:  cout << endl << "BAD COMMAND '" << command << "' IGNORED." << endl;
            badcmd++;
            break;
    }
}

    
            while (command != 'T');
        
        cout << "  " << valid << " VALID MOVES " << endl;
        cout << endl;
        cout << "  " << invalid << " BAD MOVES " << endl;
        cout << endl;
        cout << "  " << badcmd << " BAD COMMANDS " << endl;
        cout << endl;
        cout << endl;
        cout << "(c) 2019, nrichardson Noah Richardson" << endl;
        cout << endl;
    return 0;
}


