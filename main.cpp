//
//  main.cpp
//  Wordle
//

#include <iostream>
#include "Gameplay.cpp"
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    Gameplay game;
    ifstream fileInput;
    bool letsPlay = false;
    string entry;
    fileInput.open("wordsList.txt");
    string contents;
    if (fileInput.is_open()) {
        while (fileInput.good()) {
            fileInput >> contents;
            game.fillVector(contents);
        }
    }
    cout << "Welcome to text based wordle! Enter 's' to get statistics on optimizing the game or 'p' to play\n";
    char option = 't';
    while (tolower(option) != 's' && tolower(option) != 'p') {
        cin >> option;
        if (tolower(option) == 's') {
            game.setStatsMode();
        }
        else if (tolower(option) != 'p') {
            cout << "invalid input\n";
        }
        else {
            letsPlay = true;
        }
    }
    if (game.getStatsMode()) {
        cout << "Wordle Stats:\n";
        cout << "There are " << game.getNumWords() << " possible words\n";
        cout << "The most common letter in this word list is " << game.mostCommonLetter() << "\n";
        cout << "\nWould you like to play the game? y/n\n";
        while (tolower(option) != 'y' && tolower(option) != 'n') {
            cin >> option;
            if (tolower(option) == 'y') {
                letsPlay = true;
            }
            else if (tolower(option) == 'n') {
                cout << "Have a good day!";
            }
            else {
                cout << "invalid input\n";
            }
        }
        
    }
    if (letsPlay) {
        string wordOfDay = game.getWord();
        int rightPlace;
        int inWord;
        cout << "Let's play wordle!\n";
        for (int i = 0; i < 5; i++) {
            while(!game.isInList(entry)) {
                cout << "Enter a 5 letter word:\n";
                cin >> entry;
                if (game.isInList(entry)) {
                    if (entry != wordOfDay) {
                        game.printResult(entry, wordOfDay);
                    }
                    else {
                        cout << "Correct! The word was " << wordOfDay;
                        return 0;
                    }
                }
                else {
                    cout << "That word is not in the list\n";
                }
            }
        }
        cout << "The word was " << wordOfDay;
    }
    return 0;
}
