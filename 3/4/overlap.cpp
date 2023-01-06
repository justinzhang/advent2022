#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool isOverlap(string s1, string s2) {
    int min1 = stoi(s1.substr(0,s1.find("-")));
    int max1 = stoi(s1.substr(s1.find("-") + 1,s1.length()));

    int min2 = stoi(s2.substr(0,s2.find("-")));
    int max2 = stoi(s2.substr(s2.find("-") + 1,s2.length()));

    cout << min1 << " woop " << max1 << "\n";
    cout << min2 << " woop " << max2 << "\n";
    return (min1 <= min2 && max1 >= max2) || (min2 <= min1 && max2 >= max1);
    
}

int main() {
    ifstream infile("input.txt");

    int res = 0;

    for (string line; getline(infile,line);) {
        
        if (isOverlap(line.substr(0,line.find(',')),line.substr(line.find(',') + 1,line.length()))) {
            res++;
        }
    }

    cout << res << "\n";
    return 0;
}