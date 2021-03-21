#include <iostream>
using namespace std;

int main(){
  int R, C, M, input, ab=1;
  cin >> R >> C >> M;
  int B[R][C], B2[R][C], A[C][R], A2[C][R], action[M];
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      cin >> input;
      B[i][j] = input;
    }
  }
  for(int i=0; i<M; i++){
    cin >> action[i];
  }
  for(int i=M-1; i>=0; i--){
    if(action[i]==1){ //上下翻轉
      if(ab==1){ //b
       for(int i=0; i<R; i++){
         for(int j=0; j<C; j++){
           B2[i][j]=B[i][j];
          }
        }
        for(int i=0; i<R; i++){
          for(int j=0; j<C; j++){
            B[i][j]=B2[R-i-1][j];
          }
        }  
      }else{ //a
       for(int i=0; i<C; i++){
         for(int j=0; j<R; j++){
           A2[i][j]=A[i][j];
          }
        }
        for(int i=0; i<C; i++){
          for(int j=0; j<R; j++){
            A[i][j]=A2[C-i-1][j];
          }
        } 
      }
    }else{ //旋轉90度
      if(ab==0){ //a
        for(int i=0; i<R; i++){
          for(int j=0; j<C; j++){
            B[i][j]=A[C-j-1][i];
          }
        }
       ab=1;
      }else{ //b
        for(int i=0; i<C; i++){
          for(int j=0; j<R; j++){
            A[i][j]=B[R-j-1][i];
          }
        }
        ab=0;
      }
    }
  }
  if(ab==1){ //b
    cout << R << " " << C << endl;
    for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
        cout << B[i][j];
        if(j!=C-1) cout << " ";
      }
      cout << endl;
    }
  }else{ //a
    cout << C << " " << R << endl;
    for(int i=0; i<C; i++){
      for(int j=0; j<R; j++){
        cout << A[i][j];
        if(j!=R-1) cout << " ";
      }
      cout << endl;
    }
  }
}
