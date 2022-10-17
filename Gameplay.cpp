//
//  Gameplay.cpp
//  Wordle
//
//  Created by Sydney Cole on 10/16/22.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Gameplay {
private:
    //if this is true, show stats. if false, play game
    bool isStatsMode;
    vector<string> allWords;
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
        for (char let = 'a'; let != '{'; let++) {
            currentCount = 0;
            
        }
        return mostCommonChar;
    }
    
    void fillVector(string contents) {
        allWords.push_back(contents);
    }
    
    int getNumWords() {
        return allWords.size();
    }
};
