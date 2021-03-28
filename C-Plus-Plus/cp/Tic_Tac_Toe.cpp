//Tic Tac toe is a fun way to learn matrix 
#include <iostream>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
using namespace std;

//functions 
void board();// this is the tic tac toe board
int addmark(char);//This function will mark the 'X' and 'O' in the empty matrix.
int check(char);//This is a logic function , which will check winning condition


//creating empty matrix
char matrix[3][3] = {{' ',' ',' ',},
                     {' ',' ', ' ',},
                     {' ', ' ', ' '}};

int turn = 1;
int input;
int main()
{   
    system("color 70");
    string p1, p2;

    //imput the two player name
    cout << "kindly Enter your name before start! " << endl;
    cout << "player 1 name: ";
    cin >> p1;
    cout << "player 2 name: ";
    cin >> p2;

    char mark;
    for (int i = 1; i <= 9; i++)
    {
        system("cls");
      
        // matrix_prient();
        board();
        if (turn)

            cout << "player " << p1 << " turn and mark 'O' " << endl;
        else
            cout << "player " << p2 << " turn and mark 'X' " << endl;

            

        cout << "enter your number (from 1 to 9) matrix: ";
        cin >> input;

        //if invalid input
        while (input > 9 || input < 1)
        {
            cout << "invalid input! \n plz Re-Enter the input: ";
            cin >> input;
        }

        if (turn)
            mark = 'O';
        else
            mark = 'X';

        int invalid = addmark(mark);
        if (invalid==0)
        {
            i--;
            continue;
        }

       //if check function return true means won condition of the player 
        int won = check(mark);

        if (won)
        {
            system("cls");
            board();
            if (turn)
                cout << "\t\t\t************* player 1 (" << p1 << ") won the game ************" << endl;
            else
                cout << "\t\t\t************* player 2 (" << p2 << ") won the game ************" << endl;
            break;
        }

        //if whole matrix filled but no one won,that means game drow
        if (i == 9)
        {
            system("cls");
            board();
            cout << "\t\t\t******** match is drow ************\n";
            cout << "play next round!" << endl;
        }

        turn = !turn;
    }

    sleep(500);
    return 0;
}

// this is the tic tac toe board
void board()
{
    cout << "   "<< "   |   " << "   |   " << endl;
    cout << "   "<< matrix[0][0] << "  |   " << matrix[0][1] << "  |   " << matrix[0][2] << endl;
    cout << "   "<< "   |   " << "   |   " << endl;
    cout << "--------------------"<< endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << matrix[1][0] << "  |   " << matrix[1][1] << "  |   " << matrix[1][2] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "--------------------" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << matrix[2][0] << "  |   " << matrix[2][1] << "  |   " << matrix[2][2] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
}


//This function will mark the 'X' and 'O' in the empty matrix.
int addmark(char mark)
{
    for (int i = 0, k = 1; i < 3; i++)//for row traversal
    {
        for (int j = 0; j < 3; j++, k++)//for column traversal
        {
            if (k == input)
            {
                if (matrix[i][j] != 'O' and matrix[i][j] != 'X' )//this condition checking empty condition of block.
                {  
                     matrix[i][j] = mark;
                    return 1;
                }
                else
                    return 0;
            }
        }
    }
}

//This is a logic function , which will check winning condition
int check(char mark)
{
    //three row
    if (matrix[0][0] == mark && matrix[0][1] == mark && matrix[0][2] == mark)
        return 1;
    if (matrix[1][0] == mark && matrix[1][1] == mark && matrix[1][2] == mark)
        return 1;
    if (matrix[2][0] == mark && matrix[2][1] == mark && matrix[2][2] == mark)
        return 1;

    //three column
    if (matrix[0][0] == mark && matrix[1][0] == mark && matrix[2][0] == mark)
        return 1;
    if (matrix[0][1] == mark && matrix[1][1] == mark && matrix[2][1] == mark)
        return 1;
    if (matrix[0][2] == mark && matrix[1][2] == mark && matrix[2][2] == mark)
        return 1;

    //two diagonals
    if (matrix[0][0] == mark && matrix[1][1] == mark && matrix[2][2] == mark)
        return 1;
    if (matrix[2][0] == mark && matrix[1][1] == mark && matrix[0][2] == mark)
        return 1;

    return 0;
}
