//
//  main.cpp
//  Wordle
//
//  Created by Sydney Cole on 10/16/22.
//

#include <iostream>
#include "Gameplay.cpp"
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    Gameplay game;
    ifstream fileInput;
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
    }
    if (game.getStatsMode()) {
        cout << "Wordle Stats:\n";
        cout << "There are " << game.getNumWords() << " possible words\n";
        cout << "The most common letter in this word list is " << game.mostCommonLetter() << "\n";
    }
    return 0;
}
