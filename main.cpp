#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to check if the player has guessed all the letters
bool isWordGuessed(const string& secretWord, const string& guessedWord) {
    return secretWord == guessedWord;
}

// Function to display the current state of the secret word with guessed letters
void displayWord(const string& word, const string& guessedLetters) {
    for (char letter : word) {
        if (guessedLetters.find(letter) != string::npos) {
            cout << letter;
        } else {
            cout << "_";
        }
    }
    cout << endl;
}

int main() {
    vector<string> words = {"apple", "banana", "cherry", "orange", "strawberry"};
    srand(static_cast<unsigned int>(time(nullptr)));
    int randomIndex = rand() % words.size();
    string secretWord = words[randomIndex];
    string guessedLetters;
    int maxAttempts = 6;
    int attempts = 0;

    cout << "Welcome to Hangman!" << endl;
    cout << "Try to guess the secret word." << endl;

    while (attempts < maxAttempts) {
        cout << "Guessed letters: " << guessedLetters << endl;
        displayWord(secretWord, guessedLetters);

        char guess;
        cout << "Enter a letter: ";
        cin >> guess;

        if (guessedLetters.find(guess) != string::npos) {
            cout << "You've already guessed that letter." << endl;
            continue;
        }

        guessedLetters += guess;

        if (secretWord.find(guess) != string::npos) {
            cout << "Correct guess!" << endl;
            if (isWordGuessed(secretWord, guessedLetters)) {
                cout << "Congratulations! You've guessed the word: " << secretWord << endl;
                break;
            }
        } else {
            cout << "Incorrect guess." << endl;
            attempts++;
            cout << "Attempts left: " << maxAttempts - attempts << endl;
        }
    }

    if (attempts >= maxAttempts) {
        cout << "You ran out of attempts. The secret word was: " << secretWord << endl;
    }

    return 0;
}
