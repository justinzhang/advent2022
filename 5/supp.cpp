#include <fstream>
#include <string>
#include <iostream>
#include <list>
#include<vector>
using namespace std;

pair<int,int> findNthBox(string line, int i) {
    pair<int,int> res(4*i,4*i+2);

    return res;
}



int main() {
    ifstream infile("input.txt");

    vector<list<char>> sim(9);
    bool isDrawing = true;
    for (string line; getline(infile,line);) {
        if (line == "") isDrawing = false;

        if (isDrawing) {

            for (int i = 0; i < 9; i++) {
                pair<int,int> boxLoc = findNthBox(line,i);
                if (line.substr(boxLoc.first + 1,boxLoc.second)[0] != ' ') sim[i].emplace_back(line.substr(boxLoc.first + 1,boxLoc.second)[0]);
            }
        } else break;
    }


    bool isLines = true;
    for (string line; getline(infile,line);) {

        if (line == "") isLines = true;

        if (isLines) {
            int move = line.find("move");
            int afterMove = line.substr(move+5).find(" ");
            int fromm = line.find("from");
            int afterfrom= line.substr(fromm+5).find(" ");
            int too = line.find("to");
            int afterto = line.substr(too+3).find(" ");

            int quant = stoi(line.substr(move + 5,afterMove));
            int from = stoi(line.substr(fromm + 5,afterfrom)); 
            int to = stoi(line.substr(too + 3,afterto));  

            //haha fuck modularization

            cout << quant << " " << from << " " << to << " \n";
            list<char> temp;
            while (quant > 0) {
                temp.push_front(sim[from-1].front());
                sim[from-1].pop_front();

                quant--;
            }


            for (auto curr : temp) {
                sim[to-1].push_front(curr);
            }


            
            
        }
    }

    for (int i = 0; i < 9; i++) {
                for (auto curr : sim[i]) cout << curr << " ";
                cout << "\n";
            }

    return 0;
}