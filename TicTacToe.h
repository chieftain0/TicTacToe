/*
    Tic Tac Toe
       X X O
       O O X
       X O X

    Just include TicTacToe.h in your code and call PlayGame()
*/

#include <iostream>

using namespace std;

char GameBoard[3][3];
int moveCount = 1;
int initCount = 0;

char CheckBoard()
{
    for (int i = 0; i < 3; i++)
    {
        if (GameBoard[i][0] == GameBoard[i][1] && GameBoard[i][1] == GameBoard[i][2])
        {
            if (GameBoard[i][0] != '*')
            {
                cout << "Winner: " << GameBoard[i][0] << endl;
                return GameBoard[i][0];
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (GameBoard[0][i] == GameBoard[1][i] && GameBoard[1][i] == GameBoard[2][i])
        {
            if (GameBoard[0][i] != '*')
            {
                cout << "Winner: " << GameBoard[0][i] << endl;
                return GameBoard[0][i];
            }
        }
    }
    if (GameBoard[0][0] == GameBoard[1][1] && GameBoard[1][1] == GameBoard[2][2])
    {
        if (GameBoard[0][0] != '*')
        {
            cout << "Winner: " << GameBoard[0][0] << endl;
            return GameBoard[0][0];
        }
    }
    if (GameBoard[0][2] == GameBoard[1][1] && GameBoard[1][1] == GameBoard[2][0])
    {
        if (GameBoard[0][2] != '*')
        {
            cout << "Winner: " << GameBoard[0][2] << endl;
            return GameBoard[0][2];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (GameBoard[i][j] == '*')
            {
                return ' ';
            }
        }
    }
    cout << "Tie Game" << endl;
    return 'T';
}

void PrintGameBoard()
{
    cout << "Game Board: " << endl;
    cout << " " << GameBoard[0][0] << " | " << GameBoard[0][1] << " | " << GameBoard[0][2];
    cout << "    "
         << "7 | 8 | 9" << endl;
    cout << "-----------  -----------" << endl;
    cout << " " << GameBoard[1][0] << " | " << GameBoard[1][1] << " | " << GameBoard[1][2];
    cout << "    "
         << "4 | 5 | 6" << endl;
    cout << "-----------  -----------" << endl;
    cout << " " << GameBoard[2][0] << " | " << GameBoard[2][1] << " | " << GameBoard[2][2];
    cout << "    "
         << "1 | 2 | 3" << endl;
    cout << endl;
}

void InitGame()
{
    cout << "Tic Tac Toe" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            GameBoard[i][j] = '*';
        }
    }
    initCount = 0;
    moveCount = 1;
    PrintGameBoard();
}

void NumPadInputHandler()
{
    cout << "Choose your cell on the NumPad: ";
    int NumPadInput;
    cin >> NumPadInput;
    char player;
    if (moveCount % 2 == 1)
    {
        player = 'X';
    }
    else
    {
        player = 'O';
    }
    switch (NumPadInput)
    {
    case 1:
        if (GameBoard[2][0] != '*')
        {
            cout << "Invalid Input." << endl;
            break;
        }
        cout << "Accepted!" << endl;
        GameBoard[2][0] = player;
        moveCount++;
        break;
    case 2:
        if (GameBoard[2][1] != '*')
        {
            cout << "Invalid Input." << endl;
            break;
        }
        cout << "Accepted!" << endl;
        GameBoard[2][1] = player;
        moveCount++;
        break;
    case 3:
        if (GameBoard[2][2] != '*')
        {
            cout << "Invalid Input." << endl;
            break;
        }
        cout << "Accepted!" << endl;
        GameBoard[2][2] = player;
        moveCount++;
        break;
    case 4:
        if (GameBoard[1][0] != '*')
        {
            cout << "Invalid Input." << endl;
            break;
        }
        cout << "Accepted!" << endl;
        GameBoard[1][0] = player;
        moveCount++;
        break;
    case 5:
        if (GameBoard[1][1] != '*')
        {
            cout << "Invalid Input." << endl;
            break;
        }
        cout << "Accepted!" << endl;
        GameBoard[1][1] = player;
        moveCount++;
        break;
    case 6:
        if (GameBoard[1][2] != '*')
        {
            cout << "Invalid Input." << endl;
            break;
        }
        cout << "Accepted!" << endl;
        GameBoard[1][2] = player;
        moveCount++;
        break;
    case 7:
        if (GameBoard[0][0] != '*')
        {
            cout << "Invalid Input." << endl;
            break;
        }
        cout << "Accepted!" << endl;
        GameBoard[0][0] = player;
        moveCount++;
        break;
    case 8:
        if (GameBoard[0][1] != '*')
        {
            cout << "Invalid Input." << endl;
            break;
        }
        cout << "Accepted!" << endl;
        GameBoard[0][1] = player;
        moveCount++;
        break;
    case 9:
        if (GameBoard[0][2] != '*')
        {
            cout << "Invalid Input." << endl;
            break;
        }
        cout << "Accepted!" << endl;
        GameBoard[0][2] = player;
        moveCount++;
        break;
    default:
        cout << "Invalid Input." << endl;
        break;
    }
}

char PlayGame()
{
    if (initCount == 0)
    {
        InitGame();
        initCount++;
    }

    NumPadInputHandler();

    PrintGameBoard();

    char winner = CheckBoard();
    if (winner == ' ')
    {
        PlayGame();
    }
    else
    {
        return winner;
    }
}
