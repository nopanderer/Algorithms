/**
 * 소수 경로
 * 1963
 */
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
int T,A,B;
int c[10000];
bool prime[10000];
int change(int num,int i,int j){
  if(i==0 && j==0) return -1;
  string s = to_string(num);
  s[i] = j+'0';
  return stoi(s);
}
int main(){
  for(int i=2;i<=10000;i++){
    if(prime[i] == false){
      for(int j=i*i;j<=10000;j+=i){
        prime[j] = true;
      }
    }
  }
  for(int i=0;i<=10000;i++){
    prime[i] = !prime[i];
  }
  cin>>T;
  while(T--){
    fill(c,c+10000,0);
    cin>>A>>B;
    c[A] = 1;
    queue<int> q;
    q.push(A);
    while(!q.empty()){
      int cur = q.front();
      q.pop();
      for(int i=0;i<4;i++){ 
        for(int j=0;j<10;j++){
          int next = change(cur,i,j);
          if(next != -1){
            if(prime[next] && c[next]==0){
              c[next] = c[cur] + 1;
              q.push(next);
            }
          }
        }
      }
    }
    if(c[B]){
      cout<<c[B]-1<<'\n';
    }
    else{
      cout<<"Impossible\n";
    }
  }
  return 0;
}
