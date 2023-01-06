#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#define WIN 6
#define TIE 3
#define LOSS 0

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int movePts(char opp, int outcome) {
    if (opp == 'A') {
        if (outcome == WIN) return PAPER;
        if (outcome == TIE) return ROCK;
        return SCISSORS;
    }

    if (opp == 'B') {
        if (outcome == WIN) return SCISSORS;
        if (outcome == TIE) return PAPER;
        return ROCK;
    }

    if (opp == 'C') {
        if (outcome == WIN) return ROCK;
        if (outcome == TIE) return SCISSORS;
        return PAPER;
    }
    
    //chosen == 'Z'
    cout << "bruhhh\n";
    return -1;
}

int battlePts(char you) {
    if (you == 'X') return LOSS;
    if (you == 'Y') return TIE; 
    if (you == 'Z') return WIN; 

    cout << "bruh \n";
    return -1;
     
}

int main() {
    ifstream infile("input.txt");
    int res = 0;
    for (string line; getline(infile,line);) {
        char c1 = line[0];
        char c2 = line[2];

        int outcome = battlePts(c2);

        res += outcome;
        res += movePts(c1,outcome);


    }

    cout << res << "\n";
    return 0;
}