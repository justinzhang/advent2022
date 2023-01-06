#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;


int main() {
    ifstream infile("input.txt");
    vector<vector<int>> graph;

    for (string line; getline(infile,line);) {
        vector<int> curr;
        for (char c : line) {
            curr.emplace_back(atoi(&c));
        }
        graph.emplace_back(curr);
    }


    int rows = graph.size();
    int cols = graph[0].size();

    int res = 0;

    for (int i = 1; i < cols - 1; i++) {
        for (int j = 1; j < rows - 1; j++) {
            int currScore = 1;

            int curr = graph[i][j];

            //check visible
            int s1 = 0;
            for (int ii = i-1; ii >= 0; ii--) {

                int check = graph[ii][j];
                if (curr > check) {
                    s1++;
                } else {
                    s1++;
                    break;
                }
            }

            int s2 = 0;
            for (int ii = i+1; ii < cols; ii++) {
                
                int check = graph[ii][j];
                if (curr > check) {
                    s2++;
                } else {
                    s2++;
                    break;
                }
            }
            
            int s3 = 0;
            for (int jj = j-1; jj >= 0; jj--) {

                int check = graph[i][jj];
                if (curr > check) {
                    s3++;
                } else {
                    s3++;
                    break;
                }
            }

            int s4 = 0;
            for (int jj = j+1; jj < rows; jj++) {
                
                int check = graph[i][jj];
                if (curr > check) {
                    s4++;
                } else {
                    s4++;
                    break;
                }
            }

            currScore = s1 * s2 * s3 * s4;
            res = max(currScore,res);
            
        }
    }

    cout << res << "\n";
    return 0;
}