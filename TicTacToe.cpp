#include <iostream>
#include <vector>

using namespace std;

const int size = 3;
char board[size][size];

void initializeBoard()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void displayBoard()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << board[i][j];
            if (j < size - 1)
                cout << "|";
        }
        if (i < size - 1)
            cout << "\n-+-+-\n";
    }
    cout << "\n";
}
bool placeMark(int row, int col, char player)
{
    if (row >= 0 && row < size && col >= 0 && col < size && board[row][col] == ' ')
    {
        board[row][col] = player;
        return true;
    }
    return false;
}

void playerInput(char player)
{
    int row, col;
    do
    {
        cout << "Player " << player << ", enter your move (row[1-3] column[1-3]): ";
        cin >> row >> col;
        row--; // Adjust for 0 index
        col--;
    } while (!placeMark(row, col, player));
}
bool isWin(char player)
{
    for (int i = 0; i < size; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool isBoardFull()
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}
void gameLoop()
{
    char player = 'X';
    bool win = false;

    initializeBoard();
    while (true)
    {
        displayBoard();
        playerInput(player);
        if (isWin(player))
        {
            displayBoard();
            cout << "Player " << player << " wins!\n";
            break;
        }
        if (isBoardFull())
        {
            displayBoard();
            cout << "The game is a draw!\n";
            break;
        }
        player = (player == 'X') ? 'O' : 'X'; // Switch player
    }
}
void playAgain()
{
    char choice;
    do
    {
        cout << "Play again? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            gameLoop(); // Restart the game
        }
        else if (choice == 'n' || choice == 'N')
        {
            cout << "Thanks for playing!\n";
            break;
        }
    } while (choice != 'n' && choice != 'N');
}
int main()
{
    gameLoop();
    playAgain();
    return 0;
}
