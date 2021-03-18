#include <iostream>
using namespace std;

int main() {
    int r, c, m;
    while (cin >> r) {
        cin >> c;
        cin >> m;
        int matrix[10][10][10] = {0};
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[0][i][j];
            }
        }
        int did[m];
        for (int i = m - 1; i >= 0; i--) {
            cin >> did[i];
        }   

        int count = 0;
        for (int i = 0; i < m; i++) {
            count++;
            if (did[i] == 1) {
                for (int a = 0; a < c; a++) {
                    for (int b = 0; b < r; b++) {
                        matrix[count][b][a] = matrix[count - 1][r - b - 1][a];
                    }
                }
            } else {
                for (int a = 0; a < r; a++) {
                    for (int b = c - 1; b >= 0; b--) {
                        matrix[count][c - b - 1][a] = matrix[count - 1][a][b];
                    }
                }
                int temp = r;
                r = c;
                c = temp;
            }
        }

        cout << r << " " << c << endl;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << matrix[count][i][j];
                if (j != c - 1) {
                    cout << " ";
                } else {
                    cout << endl;
                }
            }
        }
    }    
}
