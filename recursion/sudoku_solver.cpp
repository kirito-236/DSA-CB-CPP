#include <iostream>
#include <cmath>
using namespace std;

void display(int** grid, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkSquare(int** grid, int r, int c, int n, int toBePlaced) {
    int sq = sqrt(n);
    int sR = (r / sq) * sq;
    int sC = (c / sq) * sq;
    
    for (int i = sR; i < sR + sq; i++) {
        for (int j = sC; j < sC + sq; j++) {
            if(grid[i][j] == toBePlaced) {
                return false;
            }
        }
    }
    return true;
}

bool checkRowAndCol(int** grid, int n, int r, int c, int toBePlaced) {
    for(int i = 0; i < n; i++) {
        if(grid[i][c] == toBePlaced || grid[r][i] == toBePlaced) {
            return false;
        }
    }
    return true;
}

bool sudokuSolver(int** grid, int n, int r, int c) {
    // base case
    if (r >= n) {
        display(grid, n);
        return true;
    }

    // if out of bounds return
    if(c >= n) {
        return sudokuSolver(grid, n, r + 1, 0);
    }

    // if place is empty try placing
    if(grid[r][c] == 0) {
        for(int i = 1; i <= n; i++) {
            if (checkRowAndCol(grid, n, r, c, i) && checkSquare(grid, r, c, n, i)) {
                grid[r][c] = i;
                bool couldWeSolve = sudokuSolver(grid, n, r, c + 1);
                if(couldWeSolve) return true;
            }
        }
        grid[r][c] = 0;
        return false;
    } else {
        return sudokuSolver(grid, n, r, c + 1);
    }
}

int main() {
    int n;
    cin >> n;
    int** grid = new int*[n];

    for(int i = 0; i < n; i++) {
        grid[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    sudokuSolver(grid, n, 0, 0);
    // display(grid, n);
    return 0;
}