/**
 * 행렬
 * 1080
 */
#include <iostream>
#include <string>
using namespace std;
int main(){
  int N,M;
  int a[51][51];
  int b[51][51];
  string s;
  int ans=0;
  cin>>N>>M;
  for(int i=0;i<N;i++){
    cin>>s;
    for(int j=0;j<M;j++){
      a[i][j] = s[j]-'0';
    }
  }
  for(int i=0;i<N;i++){
      cin>>s;
    for(int j=0;j<M;j++){
      b[i][j] = s[j]-'0';
    }
  }
  for(int i=0;i<N-2;i++){
    for(int j=0;j<M-2;j++){
      if(a[i][j] != b[i][j]){
        for(int l=0;l<3;l++){
          for(int m=0;m<3;m++){
            a[i+l][j+m] = 1-a[i+l][j+m];
          }
        }
        ans++;
      }
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(a[i][j] != b[i][j]){
        cout<<"-1\n";
        return 0;
      }
    }
  }
  cout<<ans<<'\n';

  return 0;
}
