/**
 * DSLR
 * 9019
 */
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int T,A,B;
string s[10000];
bool c[10000];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>T;
  while(T--){
    fill(c,c+10000,false);
    fill(s,s+10000,"");
    queue<int> q;
    cin>>A>>B;
    c[A] = true;
    q.push(A);
    while(!q.empty()){
      int now = q.front();
      q.pop();
      int next;
      // D
      next = (now*2)%10000;
      if(c[next] == false){
        c[next] = true;
        s[next] = s[now] + 'D';
        q.push(next);
      }
      // S
      next = now-1;
      if(next < 0) next = 9999;
      if(c[next] == false){
        c[next] = true;
        s[next] = s[now] + 'S';
        q.push(next);
      }
      // L
      next = (now%1000)*10 + now/1000;
      if(c[next] == false){
        c[next] = true;
        s[next] = s[now] + 'L';
        q.push(next);
      }
      // R
      next = (now/10) + (now%10)*1000;
      if(c[next] == false){
        c[next] = true;
        s[next] = s[now] + 'R';
        q.push(next);
      }
    }
    cout<<s[B]<<'\n';
  }
  return 0;
}
