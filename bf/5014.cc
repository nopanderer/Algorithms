/**
 * 스타트링크
 * 5014
 */
#include <iostream>
#include <queue>
using namespace std;
int c[1000001];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int f,s,g,u,d;
  cin >> f >> s >> g >> u >> d;
  queue<int> q;
  c[s] = 1;
  q.push(s);
  while(!q.empty()){
    int now = q.front();
    q.pop();
    // U
    if(now + u <= f){
      if(c[now+u] == false){
        c[now+u] = c[now] + 1;
        q.push(now+u);
      }
    }
    // D
    if(now - d >= 1){
      if(c[now - d] == false){
        c[now-d] = c[now] + 1;
        q.push(now-d);
      }
    }
  }

  if(c[g] == 0)
    cout << "use the stairs\n";
  else
    cout << c[g] - 1 << '\n';

  return 0;
}

