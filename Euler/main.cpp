//
//  main.cpp
//  Euler
//
//  Created by Diana Ovechkina on 15.05.2022.
//

#include <iostream>
#include <vector>
using namespace std;

vector <int> Euler() {
    const int row = 10;
    vector <int> visited;
    vector <int> euler;
    
    int matrixSmezhnosti[row][row] = {
        {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 1, 1},
        {0, 1, 0, 0, 0, 1, 1, 0, 1, 0},
        {1, 0, 0, 1, 1, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 1, 1, 0, 1, 0, 0},
        {0, 1, 1, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0}
    };
    int j = 0;
    int i = 0;
    visited.push_back(0);
    int begin = 0;
    int number = 1;
    
    if (i < row) {
        j = 0;
        while (j < row) {

            if (visited.size() - number > 0 && begin == *(visited.end()-1) ) {
                euler.push_back(*(visited.end() - 1));
                visited.pop_back();
                if (visited.size() == 0) {
                    i = row;
                    j = row;
                }
                else {
                    begin = *(visited.end() - 1);
                    number = visited.size();
                    i = begin;
                    j = 0;
                }
            }
            else {
                if (matrixSmezhnosti[i][j] == 1) {
                    visited.push_back(j);
                    matrixSmezhnosti[i][j] = matrixSmezhnosti[j][i] = 0;
                    i = j;
                    j = 0;
                }
                else {
                    if (matrixSmezhnosti[i][j] == 0 && j == row - 1) {
                        j--;
                        number = 0;
                    }
                    j++;
                    }
                }
            }
        
        }
//    cout << endl;
//
//    for (int i = 0; i < visited.size(); i++) {
//        cout << visited[i] << " ";
//    }

    return euler;
}

void printEuler(vector <int> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }

}

int main(int argc, const char * argv[]) {
    
    vector <int> a = Euler();
    printEuler(a);
    
    return 0;
}
