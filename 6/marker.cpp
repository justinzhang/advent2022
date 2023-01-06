#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

bool checkUnique(list<char> buf){
    unordered_set<char> set;
    cout << "check ";
    for (char c : buf) {
        cout << c;
    }
    cout << "\n";
    for (char c : buf) {
        if (set.find(c) != set.end()) return false;
        set.insert(c);
    }
    return true;
}

int main() {
    ifstream infile("input.txt");


    for (string line; getline(infile,line);) {
        //sliding window, does not need to be optimal
        list<char> buf;
        int i = 1;
        for (char c : line) {
            cout << i << "\n";
            if (buf.size() < 14) {
                buf.emplace_back(c);
            }

            if (buf.size() == 14) {
                if (checkUnique(buf)) {
                    cout << i << "\n";
                    for (char cc : buf) cout << cc;

                    cout << "\n";
                    break;
                } else buf.pop_front();
            }
            

            i++;
        }
    }
    return 0;
}