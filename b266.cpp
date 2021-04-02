#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int R, C, M; //R直 C橫 M操作
    cin >> R >> C >> M;
    int a = max(R,C);
    int rec[a][a];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> rec[i][j];
        }
    }

    int ctrl[M]; //控制
    for(int i = 0; i < M; i++){
        cin >> ctrl[i];
    }

    bool swtch = 0; //翻轉
    int z = 0; //旋轉(逆時針)
    int y = 0; //another翻轉
    for(int i = 0; i < M; i++){
        if(ctrl[i] == 0 && swtch == 0){
            z--;
        } else if(ctrl[i] == 0 && swtch == 1){
            z++;
        } else{
            swtch = !swtch;
            y++;
        }
    }
    while(z > 0){
        z -= 4;
    }
    if(z < 0){
        z *= -1;
    }
    
    if(y % 2 != 0){ //最後有翻轉
        int temp[a][a];
		for(int i = 0; i < C; i++) {
			for(int j = 0; j < R; j++) {
				temp[R - (j + 1)][i] = rec[j][i];
			}
		}
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				rec[i][j] = temp[i][j];
			}
		}
    }

    for(int k = 0; k < z; k++){
		int temp[a][a];
		for(int i = C - 1; i >= 0; i--){
			for(int j = 0; j < R; j++){
				temp[C - (i + 1)][j] = rec[j][i]; 
			}
		}
		swap(R,C);
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				rec[i][j] = temp[i][j];
			}
		}
	}

    cout << R << " " << C << "\n";
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cout << rec[i][j] << " ";
		}
		cout << "\n";
	}
}

//0旋轉 1翻轉

/*
1 2   5 3 1   6 4 2
3 4   6 4 2   5 3 1
5 6           

1 2    5 6    1 3 5
3 4    3 4    2 4 6
5 6    1 2
*/
