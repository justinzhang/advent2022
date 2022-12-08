#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

//woops here i go not reading instructions again and including index lol
//relearning c++ moment
int main() {
    ifstream infile("input.txt");
    int currCal = 0;
    int bestCal = -1;
    int bestInd = 0;
    int currInd = 0;

    for (string line; getline(infile,line);) {
        if (line.length() == 0) {
            if (currCal > bestCal) {
                bestCal = currCal;
                bestInd = currInd;
            }
            currCal = 0;
        } else currCal += stoi(line);


        currInd++;
    }
    cout << "best ind is " << bestInd << " with " << bestCal << " cals \n";
    return 0;
}