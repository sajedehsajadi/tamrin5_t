#include <conio.h>
#include <iostream>
#include <cstdlib>   
#include <chrono>
#include <stdlib.h>  
int rang(int x);
int player = 0;
using namespace std;
char safhe[3][3]{ {'_','_','_'},
                  {'_','_','_'}
                 ,{'_','_','_'} };
void safhe_bazi()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << safhe[i][j] << "\t";
        cout << "\n";
    }
}
bool shart_barande(char ch) {
    return ((safhe[0][0] == ch && safhe[0][1] == ch && safhe[0][2] == ch) ||
        (safhe[1][0] == ch && safhe[1][1] == ch && safhe[1][2] == ch) ||
        (safhe[2][0] == ch && safhe[2][1] == ch && safhe[2][2] == ch) ||
        (safhe[0][0] == ch && safhe[1][0] == ch && safhe[2][0] == ch) ||
        (safhe[0][1] == ch && safhe[1][1] == ch && safhe[2][1] == ch) ||
        (safhe[0][2] == ch && safhe[1][2] == ch && safhe[2][2] == ch) ||
        (safhe[0][0] == ch && safhe[1][1] == ch && safhe[2][2] == ch) ||
        (safhe[0][2] == ch && safhe[1][1] == ch && safhe[2][0] == ch));
}
int rang(int x) {

    if (x == 1)
        system("color 05");
    if (x == 2)
        system("color 03");

    return 1;
}
bool fullboard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (safhe[i][j] != ' ')
                return false;


}


int main()
{
    auto start = chrono::steady_clock::now();
    system("color 06");

    while (true)
    {

        safhe_bazi();
        int row, column;
        cout << "Player 1: ";
        while (true)
        {

            rang(1);
            cout << "\nEnter the row(0-2) and column(0-2) :";
            cin >> row >> column;
            if (0 <= row && row <= 2 && 0 <= column && column <= 2)
            {

                if (safhe[row][column] == '_')
                {

                   safhe[row][column] = 'x' ;
                    break;
                    rang(2);
                }

                else
                    cout << "is not empty";
            }
            else
                cout << "out of range";

        }
        if (shart_barande('x'))
        {
            cout << "player 1 bord\n";
            safhe_bazi();
                break;
        }
        else if (fullboard() && !(shart_barande('X') || shart_barande('O')))
        {
            cout << "mosavi\n";
            safhe_bazi();
            break;
        }


        while (true)
        {
            rang(2);
            safhe_bazi();
            cout << "Player 2: ";
            cout << "\nEnter the row(0-2) and column(0-2) :";
            cin >> row>>column;
            if (0 <= row && row <= 2 && 0 <= column && column <= 2)
            {

                if (safhe[row][column] == '_')
                {
                    safhe[row][column] = 'o';
                    break;
                    rang(1);
                }
                else
                    cout << "is not empty\n";
            }
            else
                cout << "out of range\n";

        }
        if (shart_barande('o'))
        {
            cout << "player 2 bord\n";
            safhe_bazi();
            break;
        }
        else if (fullboard() && !(shart_barande('X') || shart_barande('O')))
        {
            cout << "mosavi\n";
            safhe_bazi();
            break;
        }

    }

    auto end = chrono::steady_clock::now();
    cout << "time: "<< chrono::duration_cast<chrono::seconds>(end - start).count()<< " sec";

}
