#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int r, c, m, rage;
	bool spin = false;
	cin >> r >> c >> m;

	rage = max(r, c);

	int ary[m + 1][rage][rage];
	int mary[m];
		
	for (int i = 0; i < rage; i++) {
		for (int j = 0; j < rage; j++) {
			if (i < r && j < c) {
				cin >> ary[0][i][j];
			} else {
				ary[0][i][j] = 0;
			}
		}
	}

	for (int i = 0; i < m; i++) cin >> mary[i];

	for (int i = 0; i < m; i++) {
		if (mary[i] == 0) {
			spin = !spin;
			for (int k = 0; k < rage; k++) {
				for (int j = 0; j < rage; j++) {
					ary[i + 1][j][rage - k - 1] = ary[i][k][j];
				}
			}
		} else {
			for (int k = 0; k < rage; k++) {
				for (int j = 0; j < rage; j++) {
					ary[i + 1][rage - k - 1][j] = ary[i][k][j];
				}
			}
		}
	}

	if (spin) {
		int q = r;
		r = c;
		c = q;
	}

	int rlt[r][c];

	cout << r << " " << c << endl;

	for (int i = 0, n = 0, j; i < rage; i++) {
		j = 0;
		for (int p = 0; j < rage; j++) {
			if (ary[m][i][j]) {
				rlt[n][p] = ary[m][i][j];
				p++;
			} 
		}
		if (ary[m][i][j - 1]) n++;
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << rlt[i][j];
			if (j < c - 1) cout << " ";
		}
		cout << endl;
	}	
}
