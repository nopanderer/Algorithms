/**
 * 숨바꼭질
 * 1697
 */
#include <iostream>
#include <queue>
using namespace std;
int N,K;
int c[100001];
queue<int> q;
int main(){
  cin>>N>>K;
  c[N] = 1;
  q.push(N);
  while(!q.empty()){
    int front = q.front();
    q.pop();
    if(0<=front+1 && front+1 <= 100000 && c[front+1] == 0){
      if(front+1 == K){
        cout<<c[front]<<'\n';
        return 0;
      }
      c[front+1] = c[front] + 1;
      q.push(front+1);
    }
    if(0<=front-1 && front-1 <= 100000 && c[front-1] == 0){
      if(front-1 == K){
        cout<<c[front]<<'\n';
        return 0;
      }
      c[front-1] = c[front] + 1;
      q.push(front-1);
    }
    if(0<=front*2 && front*2 <= 100000 && c[front*2] == 0){
      if(front*2 == K){
        cout<<c[front]<<'\n';
        return 0;
      }
      c[front*2] = c[front] + 1;
      q.push(front*2);
    }
  }
  cout<<"0\n";

  return 0;
}
