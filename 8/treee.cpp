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

    int res = 2 * (rows + cols) - 4;

    for (int i = 1; i < cols - 1; i++) {
        for (int j = 1; j < rows - 1; j++) {
            int curr = graph[i][j];

            bool isVis = true;

            //check visible
            for (int ii = 0; ii < i; ii++) {
                int check = graph[ii][j];
                if (curr <= check) isVis = false;
            }

            if (isVis) {
                res++;
                continue;
            }

isVis = true;

            for (int ii = i + 1; ii < cols; ii++) {
                int check = graph[ii][j];
                if (curr <= check) isVis = false;
            }

            if (isVis) {
                res++;
                continue;
            }

isVis = true;

            for (int jj = 0; jj < j; jj++) {
                int check = graph[i][jj];
                if (curr <= check) isVis = false;
            }

            if (isVis) {
                res++;
                continue;
            }

isVis = true;

            for (int jj = j + 1; jj < rows; jj++) {
                int check = graph[i][jj];
                if (curr <= check) isVis = false;
            }

            if (isVis) {
                res++;
                continue;
            }
            
        }
    }

    cout << res << "\n";
    return 0;
}