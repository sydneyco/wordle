//
//  Gameplay.cpp
//  Wordle
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <unordered_map>

using namespace std;

class Gameplay {
private:
    //if this is true, show stats. if false, play game
    bool isStatsMode;
    vector<string> allWords;
    unordered_map<string, int> wordList;
public:
    Gameplay() {
        isStatsMode = false;
        allWords.reserve(5000);
    }
    
    void setStatsMode() {
        isStatsMode = true;
    }
    
    bool getStatsMode() {
        return isStatsMode;
    }
    
    char mostCommonLetter() {
        char mostCommonChar =  'a';
        int mostCommonCount = 0;
        int currentCount;
        int index = 0;
        for (char let = 'a'; let != '{'; let++) {
            currentCount = 0;
            index = 0;
            for (size_t i = 0; i < allWords.size(); i++) {
                for (size_t i = 0; i < allWords[index].length(); i++) {
                    if (let == allWords[index][i]) {
                        currentCount++;
                    }
                }
                index++;
            }
            if (currentCount > mostCommonCount) {
                mostCommonCount = currentCount;
                mostCommonChar = let;
            }
        }
        return mostCommonChar;
    }
    
    void makeWordList(ifstream &fileInput) {
        string contents;
        int size = 1;
        while (fileInput.good()) {
            fileInput >> contents;
            wordList[contents] = size;
            allWords.push_back(contents);
            size++;
        }
    }
    
    size_t getNumWords() {
        return allWords.size() - 1;
    }
    
    bool isInList(string entry) {
        if (wordList.find(entry) != wordList.end()) {
            return true;
        }
        return false;
    }
    
    string getWord() {
        srand(time(NULL));
        int num = (rand() % allWords.size()) + 1;
        return allWords[num];
    }
    
    void printResult(string entry, string wordofDay) {
        string assembled = "_____";
        for (int i = 0; i < 5; i++) {
            if (entry[i] == wordofDay[i]) {
                assembled[i] = entry[i];
            }
        }
        cout << assembled << "\n";
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (entry[i] == wordofDay[j] && assembled[i] == '_') {
                    cout << "there is a(n) " << entry[i] << " but it was not in the right spot\n";
                }
            }
        }
    }
};
