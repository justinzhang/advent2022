#include <fstream>
#include <string>
#include <iostream>
#include <queue>
using namespace std;


int main() {
    ifstream infile("input.txt");
    //although pq in c++ is auto max heap, im lazy so I'll just use negatives
    priority_queue<int> pq;

    int currCal = 0;
    int bestCal = -1;


    for (string line; getline(infile,line);) {
        if (line.length() == 0) {
            if (pq.size() < 3 || -currCal < pq.top()) {
                if (pq.size() == 3) pq.pop();

                pq.push(-currCal);
            }
            currCal = 0;
        } else currCal += stoi(line);
    }
    int res = 0;
    while (!pq.empty()) {
        res += pq.top();
        cout << pq.top() << "\n";
        pq.pop();
    }

    cout << res << "\n";
    return 0;
}