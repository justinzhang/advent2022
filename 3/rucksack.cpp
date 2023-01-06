#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int toPriority(char c){
    int ci = c;

    if (ci < 97) {
        //uppercase
        return ci - ((int)'A') + 26 + 1;
    }

    return ci - ((int)'a') + 1;
}


//REQUIRES: Exactly one repeated item
char repeatedItem(string s1, string s2) {
    unordered_set<char> mem;
    for (char c : s1) {
        mem.insert(c);
    }

    for (char c : s2) {
        if (mem.find(c) != mem.end()) {
            return c;
        }
    }


    return '\0';
}

int main() {
    ifstream infile("input.txt");
    int offLow = 'a';
    int offUpr = 'A';
    int res = 0;
    for (string line; getline(infile,line);) {
        //split compartment in half
        int n = line.length();
        res += toPriority(repeatedItem(line.substr(0,n / 2),line.substr(n/2,n)));
    }

    cout << res << "\n";
    return 0;
}