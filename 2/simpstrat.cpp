#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#define WIN 6;
#define TIE 3;
#define LOSS 0;

int movePts(char chosen) {
    if (chosen == 'X') return 1;
    if (chosen == 'Y') return 2;
    
    //chosen == 'Z'
    return 3;
}

int battlePts(char opp, char you) {
    if (opp == 'A' && you == 'X') return TIE;
    if (opp == 'A' && you == 'Y') return WIN; 
    if (opp == 'A' && you == 'Z') return LOSS; 
    if (opp == 'B' && you == 'X') return LOSS; 
    if (opp == 'B' && you == 'Y') return TIE; 
    if (opp == 'B' && you == 'Z') return WIN; 
    if (opp == 'C' && you == 'X') return WIN; 
    if (opp == 'C' && you == 'Y') return LOSS; 
    if (opp == 'C' && you == 'Z') return TIE; 

    cout << "bruh \n";
    return -1;
     
}

int main() {
    ifstream infile("input.txt");
    int res = 0;
    for (string line; getline(infile,line);) {
        char c1 = line[0];
        char c2 = line[2];

        res += movePts(c2);
        res += battlePts(c1,c2);


    }

    cout << res << "\n";
    return 0;
}