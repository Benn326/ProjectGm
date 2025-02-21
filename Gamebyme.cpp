#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
bool isWordRight(vector<bool> &guessed)
{
    for (bool b : guessed)
    {
        if (!b)
        {
            return false;
        }
    }
    return true;
}
void display(string word, const vector<bool> &guessed)
{
    int wordlength = word.size();
    for (int i = 0; i < wordlength; i++)
    {
        if (guessed[i] == 1)
        {
            cout << word[i];
        }
        else
        {
            cout << "_";
        }
    }
    cout << endl;
}
int main()
{
    while (true)
    {
        vector<string> words = {"programming", "hangman", "computer", "science", "cplusplus"};
        srand(time(0));
        string word = words[rand() % words.size()];
        vector<bool> guessed(word.size(), false);
        char guess;
        cout << "Welcome to Hangman!" << endl;
        int attemp = 6;
        while (!isWordRight(guessed) && attemp > 0)
        {
            cout << "Attempts remaining: " << attemp << endl;
            display(word, guessed);
            cout << "Enter your guess: ";
            cin >> guess;
            bool correctGuess = false;
            for (int i = 0; i < word.size(); i++)
            {
                if (guess == word[i])
                {
                    guessed[i] = 1;
                    correctGuess = true;
                }
            }
            if (!correctGuess)
            {
                attemp--;
                cout << "Incorrect guess. Attempts remaining: " << attemp << endl;
            }
        }
        if (isWordRight(guessed))
        {
            cout << "Congratulations! You've guessed the word: " << word << endl;
        }
        else
        {
            cout << "Game Over! The word was: " << word << endl;
        }
        cout << "Do you want to play again? (y/n): ";
        char option;
        cin >> option;
        if (option == 'y' || option == 'Y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
}