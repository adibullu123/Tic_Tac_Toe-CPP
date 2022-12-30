#include <iostream>
#include <ctime>
using namespace std;
// tic tac toe game

// function that gives the compiler the ability to block the winning move of the user
int smartcomp(char ttt[][3], int row, int column, char *mark, char *mark2, int *a1, int *a2)
{
    int i, j, count1 = 0, count2 = 0, temp;
    // horizontal check
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (ttt[i][j] == *mark)
            {
                count1++;
            }
            else if (ttt[i][j] == '?')
            {
                temp = j;
                count2++;
            }
        }
        if (count1 == 2 && count2 == 1)
        {
            *a1 = i;
            *a2 = temp;
            return 2;
        }
        count1 = 0;
        count2 = 0;
    }
    count1 = 0;
    count2 = 0;
    // vertical check
    for (j = 0; j < column; j++)
    {
        for (i = 0; i < row; i++)
        {
            if (ttt[i][j] == *mark)
            {
                count1++;
            }
            else if (ttt[i][j] == '?')
            {
                temp = i;
                count2++;
            }
        }
        if (count1 == 2 && count2 == 1)
        {
            *a1 = temp;
            *a2 = j;

            return 2;
        }
        count1 = 0;
        count2 = 0;
    }
    // diagonal check-1{doin it manually cos im lazy}
    for (i = 0; i < row; i++)
    {
        if (ttt[i][i] == *mark)
            count1++;
        else if (ttt[i][i] == '?')
        {
            count2++;
            temp = i;
        }
    }
    if (count1 == 2 && count2 == 1)
    {
        *a1 = temp;
        *a2 = temp;
        if (ttt[*a1][*a2] != *mark && ttt[*a1][*a2] != *mark2)
            return 3;
    }
    count1 = 0;
    count2 = 0;

    // diagonal check-2
    if (ttt[2][0] == *mark)
        count1++;
    else if (ttt[2][0] == '?')
        count2 = 1;
    if (ttt[1][1] == *mark)
        count1++;
    else if (ttt[1][1] == '?')
        count2 = 2;
    if (ttt[0][2] == *mark)
        count1++;
    else if (ttt[0][2] == '?')
        count2 = 3;
    if (count1 == 2)
    {
        if (count2 == 1)
        {
            *a1 = 2;
            *a2 = 0;
        }
        else if (count2 == 2)
        {
            *a1 = 1;
            *a2 = 1;
        }
        else if (count2 == 3)
        {
            *a1 = 0;
            *a2 = 2;
        }
        if (ttt[*a1][*a2] != *mark && ttt[*a1][*a2] != *mark2)
            return 3;
    }

    return 0;
}
int wincheck(char ttt[][3], int row, int column, char *mark, char *mark2)
{
    int count1 = 0, count2 = 0, i, j;
    // checking horizontally
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (ttt[i][j] == *mark)
                count1++;
            else if (ttt[i][j] == *mark2)
            {
                count2++;
            }
        }
        if (count1 == 3)
        {
            cout << "*****************************************************" << endl;
            cout << "You Won" << endl;
            return 0;
        }
        else if (count2 == 3)
        {
            cout << "*****************************************************" << endl;
            cout << "Compiler Won" << endl;
            return 0;
        }
        count1 = 0;
        count2 = 0;
    }
    // checking vertically
    count1 = 0, count2 = 0;
    for (j = 0; j < column; j++)
    {
        for (i = 0; i < row; i++)
        {
            if (ttt[i][j] == *mark)
                count1++;
            else if (ttt[i][j] == *mark2)
            {
                count2++;
            }
        }
        if (count1 == 3)
        {
            cout << "*****************************************************" << endl;
            cout << "You Won" << endl;
            return 0;
        }
        else if (count2 == 3)
        {
            cout << "*****************************************************" << endl;
            cout << "Compiler Won" << endl;
            return 0;
        }
        count1 = 0;
        count2 = 0;
    }
    // checking diagonally
    if (ttt[0][0] == *mark && ttt[1][1] == *mark && ttt[2][2] == *mark)
    {
        cout << "*****************************************************" << endl;
        cout << "You Won" << endl;
        return 0;
    }
    else if (ttt[0][2] == *mark2 && ttt[1][1] == *mark2 && ttt[2][0] == *mark2)
    {
        cout << "*****************************************************" << endl;
        cout << "Compiler Won" << endl;
        return 0;
    }
    else if (ttt[0][2] == *mark && ttt[1][1] == *mark && ttt[2][0] == *mark)
    {
        cout << "*****************************************************" << endl;
        cout << "You Won" << endl;
        return 0;
    }
    else if (ttt[0][0] == *mark2 && ttt[1][1] == *mark2 && ttt[2][2] == *mark2)
    {
        cout << "*****************************************************" << endl;
        cout << "Compiler Won" << endl;
        return 0;
    }
    return 1;
}

void choice(char *mark, char *mark2)
{
    cout << "What marker would you like to choose ? X or O " << endl;
    cin >> *mark;
    *mark = toupper(*mark);
    if (*mark == 'X')
    {
        *mark2 = 'O';
    }
    else
    {
        *mark2 = 'X';
    }

    cout << "You chose " << *mark << " The compiler has " << *mark2 << endl;
    cout << "*****************************************************" << endl;
}
void game(char ttt[][3], int row, int column, char *mark, char *mark2)
{
    int i, j, size = 5, x, check, a1, a2, check2; // a1 and a2 are comp coords. random numbers generated.
    int p, z;                                     // p and z are the coordinates
    // printing blank table for user reference
    int *ptr1 = &a1, *ptr2 = &a2; // pointers for smartcomp function
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            cout << ttt[i][j] << " ";
        }
        cout << endl;
    }
    cout << "*****************************************************" << endl;
    // toss and first player to go -> selection
    srand(time(0));
    int toss = rand() % 2 + 1;
    if (toss == 1)
    {
        cout << "You can go first" << endl;
    }
    else
    {
        cout << "The compiler will go first" << endl;
    }
    cout << "*****************************************************" << endl;
    cout << "Please specify coords to place your marker in the desired location.Look at the table for reference " << endl;
    for (x = 0; x < size; x++)
    {
        if (toss == 1)
        {
            cout << "Where would you like to place your Marker " << *mark << " ? (Please Enter coordinates x,y|range->(0 to 2)" << endl;
            cin >> p >> z;
            while (ttt[p][z] == *mark || ttt[p][z] == *mark2)
            {
                cout << "Choose a Vacant Position" << endl;
                cin >> p >> z;
            }
            cout << "Your Turn" << endl;
            ttt[p][z] = *mark;
            for (i = 0; i < row; i++)
            {
                for (j = 0; j < column; j++)
                {
                    cout << ttt[i][j] << " ";
                }
                cout << endl;
            }
            // wincheck

            check = wincheck(ttt, row, column, mark, mark2);
            if (check == 0)
            {
                return;
            }
            cout << "*****************************************************" << endl;
            if (x < size - 1)
            {
                cout << "Compiler's Turn Completed" << endl;
                check2 = smartcomp(ttt, row, column, mark, mark2, ptr1, ptr2);
                if (check2 == 2 || check2 == 3)
                {
                    ttt[a1][a2] = (*mark2);
                    cout << "*****************************************************" << endl;
                    cout << check2 << endl;
                    cout << "The Compiler blocked your winning move" << endl;
                    cout << "*****************************************************" << endl;
                }
                else

                {

                    a1 = rand() % 3;
                    a2 = rand() % 3;
                    if (ttt[a1][a2] != '?')
                    {
                        for (i = 0; i < 100; i++)
                        {
                            a1 = rand() % 3;
                            a2 = rand() % 3;
                            if (ttt[a1][a2] == '?')
                                break;
                        }
                    }
                    ttt[a1][a2] = (*mark2);
                }
                cout << "Compiler placed " << ttt[a1][a2] << " at (x,y) = " << a1 << "," << a2 << endl;
                for (i = 0; i < row; i++)
                {
                    for (j = 0; j < column; j++)
                    {
                        cout << ttt[i][j] << " ";
                    }
                    cout << endl;
                }
                // wincheck

                check = wincheck(ttt, row, column, mark, mark2);
                if (check == 0)
                {
                    return;
                }

                cout << "*****************************************************" << endl;
            }
            if (x == size - 1 && check == 1)
            {
                cout << "Tie.Better Luck next time" << endl;
                return;
            }
        }
        else
        {
            cout << "Compiler's Turn Completed" << endl;
            check2 = smartcomp(ttt, row, column, mark, mark2, ptr1, ptr2);

            if (check2 == 2 || check2 == 3)
            {
                ttt[a1][a2] = (*mark2);
                cout << "*****************************************************" << endl;
                cout << check2 << endl;
                cout << "The Compiler blocked your winning move" << endl;
                cout << "*****************************************************" << endl;
            }
            else

            {

                a1 = rand() % 3;
                a2 = rand() % 3;
                if (ttt[a1][a2] != '?')
                {
                    for (i = 0; i < 100; i++)
                    {
                        a1 = rand() % 3;
                        a2 = rand() % 3;
                        if (ttt[a1][a2] == '?')
                            break;
                    }
                }
                ttt[a1][a2] = (*mark2);
            }
            cout << "Compiler placed " << ttt[a1][a2] << " at (x,y) = " << a1 << "," << a2 << endl;
            for (i = 0; i < row; i++)
            {
                for (j = 0; j < column; j++)
                {
                    cout << ttt[i][j] << " ";
                }
                cout << endl;
            }
            // wincheck

            check = wincheck(ttt, row, column, mark, mark2);
            if (check == 0)
            {
                return;
            }

            cout << "*****************************************************" << endl;
            if (x < size - 1)
            {
                cout << "Where would you like to place your Marker " << *mark << " ? (Please Enter coordinates x,y|range->(0 to 2)" << endl;
                cin >> p >> z;
                while (ttt[p][z] == *mark || ttt[p][z] == *mark2)
                {
                    cout << "Choose a Vacant Position" << endl;
                    cin >> p >> z;
                }
                cout << "Your Turn" << endl;
                ttt[p][z] = *mark;
                for (i = 0; i < row; i++)
                {
                    for (j = 0; j < column; j++)
                    {
                        cout << ttt[i][j] << " ";
                    }
                    cout << endl;
                }
                // wincheck

                check = wincheck(ttt, row, column, mark, mark2);
                if (check == 0)
                {
                    return;
                }

                cout << "*****************************************************" << endl;
            }
            if (x == size - 1 && check == 1)
            {
                cout << "Tie.Better Luck next time" << endl;
                return;
            }
        }
    }
}
//*mark is for the user and *mark2 is for the compiler
void Menu(char *mark, char ttt[][3], int row, int column, char *mark2)
{
    int i;
    cout << "Please Select the following options from the menu " << endl;
    cout << "Press 1 to play the game" << endl;
    cout << "Press 2 to Exit the game" << endl;
    cin >> i;
    switch (i)
    {
    case 1:
        choice(mark, mark2);
        game(ttt, row, column, mark, mark2);
        break;
    case 2:
        break;
    default:
        cout << "Enter a Valid Number" << endl;
    };
}

int main()
{
    int i, j;
    char mark, *choice1, mark2, *choicecomp;
    choice1 = &mark;
    choicecomp = &mark2;
    char ttt[3][3];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            ttt[i][j] = '?';
        }
    }
    int row = sizeof(ttt) / sizeof(ttt[0]),
        column = sizeof(ttt[0]) / sizeof(ttt[0][0]);
    cout << "*****************************************************" << endl;
    cout << "Welcome to the TIC TAC TOE game {Created By Aditya Y}" << endl;
    cout << "*****************************************************" << endl;
    Menu(choice1, ttt, row, column, choicecomp);
    cout << "Thank you for playing the game.See you next time !!!" << endl;
    cout << "*****************************************************" << endl;

    return 0;
}