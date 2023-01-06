#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;


int main() {
    ifstream infile("input.txt");

    vector<int> X;
    vector<int> crt;
    X.push_back(1); 
    int t = 1;
    int currX = 1;
    for (string line; getline(infile,line);) {
        cout << line << "\n";

        string mov = line.substr(0,line.find(" "));

        if (t == 5) printf("%d\n",currX);


        if (mov == "noop") {
            cout << X.size() << "\n";
            cout << X.back() << "\n";
            cout << t << " " << currX << "\n";
            if (t  % 40>= currX  && t  % 40<= currX + 2) crt.push_back(1);
            else crt.push_back(0);
            t += 1;
            X.push_back(currX);
            cout << t << " " << currX << "\n";
        }

        if (mov == "addx") {

            int addAm = stoi(line.substr(line.find(" ")));
            X.push_back(currX);
            X.push_back(currX);
            
            cout << t << " " << currX << "\n";

            if (t % 40 >= currX  && t  % 40<= currX + 2) crt.push_back(1);
            else crt.push_back(0);

            t += 1;

            cout << t << " " << currX << "\n";
            if (t  % 40>= currX  && t  % 40<= currX + 2) crt.push_back(1); 
            else crt.push_back(0);

            cout << t << " " << currX << "\n";
            t += 1;

            currX += addAm;
        }


    }
    printf("%d %d %d %d %d %d\n",X[20] ,X[60],X[100],X[140] ,X[180],X[220] );
    cout << X[20] * 20 + X[60] * 60 + X[100] * 100 + X[140] * 140  + X[180] * 180 + X[220] * 220 << "\n";

    for (int row = 0; row < 6; row ++) {
        for (int col = 0; col < 40; col++) {
            if (crt[row*40 + col]) cout << "#" << " ";
            else cout << "." << " ";
        }
        cout << "\n";
    }
    
    return 0;
}