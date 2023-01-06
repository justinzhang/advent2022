#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <utility>
using namespace std;

typedef std::pair<int,int> coord;

int main() {
    ifstream infile("input.txt");

    int hx = 0;
    int hy = 0;
    int tx = 0;
    int ty = 0;


    set<coord> seen;
    coord x(0,0);
    seen.insert(x);

    for (string line; getline(infile,line);) {
        char mov = line[0];
        int num = stoi(line.substr(line.find(" ") + 1));

        if (mov == 'U') {
            while (num > 0) {
                cout << "(" << hx << "," << hy << "), (" << tx << "," << ty << ")\n";
                hy += 1;
                if (abs(ty - hy) > 1) {
                    ty = hy - 1;
                    tx = hx;
                }
                num--;


                seen.insert(make_pair(tx,ty));
            }
        }
        if (mov == 'D') {
            while (num > 0) {
                cout << "(" << hx << "," << hy << "), (" << tx << "," << ty << ")\n";
                hy -= 1;
                if (abs(ty - hy) > 1) {
                    ty = hy + 1;
                    tx = hx;
                }
                num--;



                seen.insert(make_pair(tx,ty));
            }
        }
        if (mov == 'L') {
            while (num > 0) {
                cout << "(" << hx << "," << hy << "), (" << tx << "," << ty << ")\n";
                hx -= 1;
                if (abs(tx - hx) > 1) {
                    tx = hx + 1;
                    ty = hy;
                }
                num--;




                seen.insert(make_pair(tx,ty));
            }            
        }
        if (mov == 'R') {
            while (num > 0) {
                cout << "(" << hx << "," << hy << "), (" << tx << "," << ty << ")\n";
                hx += 1;
                if (abs(tx - hx) > 1) {
                    tx = hx - 1;
                    ty = hy;
                }
                num--;


                seen.insert(make_pair(tx,ty));
            }
        }        
    }

    cout << seen.size() << "\n";
    return 0;
}