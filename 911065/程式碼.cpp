#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int r,c,m;
	cin >> r >> c >> m;
	int b = max(r,c);
	int arr[b][b];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	int marr[m];
	for (int i = 0; i < m; i++) {
		cin >> marr[i];
	}

	bool check = false;
	int angle = 0;
	int times = 0;
	for (int i = 0; i < m; i++) {
		if (marr[i] == 0 && check == false) {
			angle--;
		} else if (marr[i] == 0 && check == true) {
			angle++;
		} else {
			check = !check;
			times++;
		}
	}

	while (angle > 0) {
		angle -= 4;
	}

	if (times % 2 == 1) {
		int temp[b][b];
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < r; j++) {
				temp[r - 1 - j][i] = arr[j][i];
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				arr[i][j] = temp[i][j];
			}
		}
	}
	for (int p = 0; p < abs(angle); p++) {
		int temp[b][b];
		for (int i = c - 1; i >= 0; i--) {
			for (int j = 0; j < r; j++) {
				temp[c - 1 - i][j] = arr[j][i]; 
			}
		}
		swap(r,c);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				arr[i][j] = temp[i][j];
			}
		}
	}

	cout << "\n" << r << " " << c << "\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}