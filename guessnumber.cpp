#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

void initializeRandomSeed()
{
    srand(static_cast<unsigned int>(time(0)));
}
int generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
void guessNumber()
{
    int randomNumber = generateRandomNumber(1, 100);
    int guess = 0;

    cout << "Guess the number between 1 and 100.\n";

    do
    {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < randomNumber)
        {
            cout << "Too low. Try again.\n";
        }
        else if (guess > randomNumber)
        {
            cout << "Too high. Try again.\n";
        }
        else
        {
            cout << "Congratulations! You guessed the correct number.\n";
        }
    } while (guess != randomNumber);
}
int main()
{
    initializeRandomSeed();
    guessNumber();
    return 0;
}
