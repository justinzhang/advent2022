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
char repeatedItem(string s1, string s2, string s3) {
    unordered_set<char> mem1;
    unordered_set<char> mem2;
    for (char c : s1) {
        mem1.insert(c);
    }

    for (char c : s2) {
        if (mem1.find(c) != mem1.end()) {
            mem2.insert(c);
        }
    }

    for (char c : s3) {
        if (mem2.find(c) != mem2.end()) return c;
    }


    return '\0';
}

int main() {
    ifstream infile("input.txt");
    int res = 0;
    int count = 0;
    vector<string> buf;
    for (string line; getline(infile,line);) {
        buf.emplace_back(line);
        count++;

        if (count % 3 == 0) {
            res += toPriority(repeatedItem(buf[0],buf[1],buf[2]));
            buf.clear();
        }
        //split compartment in half
    }

    cout << res << "\n";
    return 0;
}