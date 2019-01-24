/**
 * 물통
 * 2251
 */
#include <iostream>
#include <queue>
using namespace std;
bool check[201][201];
bool ans[201];
int main(){
  int A,B,C;
  cin>>A>>B>>C;
  queue<pair<int,int>> q;
  q.push(make_pair(0,0));
  check[0][0] = true;
  ans[C] = true;
  while(!q.empty()){
    int a = q.front().first;
    int b = q.front().second;
    int c = C-a-b;
    int ta,tb,tc;
    q.pop();
    // A->B
    ta = a;
    tb = b;
    tc = c;

    tb += ta;
    ta = 0;
    if(tb >= B){
      ta = tb-B;
      tb = B;
    }
    if(!check[ta][tb]){
      check[ta][tb] = true;
      q.push(make_pair(ta,tb));
      if(ta == 0){
        ans[tc] = true;
      }
    }
    // B->A
    ta = a;
    tb = b;
    tc = c;

    ta += tb;
    tb = 0;
    if(ta >= A){
      tb = ta-A;
      ta = A;
    }
    if(!check[ta][tb]){
      check[ta][tb] = true;
      q.push(make_pair(ta,tb));
      if(ta == 0){
        ans[tc] = true;
      }
    }
    // B->C
    ta = a;
    tb = b;
    tc = c;

    tc += tb;
    tb = 0;
    if(tc >= C){
      tb = tc-C;
      tc = C;
    }
    if(!check[ta][tb]){
      check[ta][tb] = true;
      q.push(make_pair(ta,tb));
      if(ta == 0){
        ans[tc] = true;
      }
    }
    // C->B
    ta = a;
    tb = b;
    tc = c;

    tb += tc;
    tc = 0;
    if(tb >= B){
      tc = tb-B;
      tb = B;
    }
    if(!check[ta][tb]){
      check[ta][tb] = true;
      q.push(make_pair(ta,tb));
      if(ta == 0){
        ans[tc] = true;
      }
    }
    // A->C
    ta = a;
    tb = b;
    tc = c;

    tc += ta;
    ta = 0;
    if(tc >= C){
      ta = tc-C;
      tc = C;
    }
    if(!check[ta][tb]){
      check[ta][tb] = true;
      q.push(make_pair(ta,tb));
      if(ta == 0){
        ans[tc] = true;
      }
    }
    // C->A
    ta = a;
    tb = b;
    tc = c;

    ta += tc;
    tc = 0;
    if(ta >= A){
      tc = ta-A;
      ta = A;
    }
    if(!check[ta][tb]){
      check[ta][tb] = true;
      q.push(make_pair(ta,tb));
      if(ta == 0){
        ans[tc] = true;
      }
    }
  }
  for(int i=0;i<=C;i++){
    if(ans[i]) cout<<i<<' ';
  }
  cout<<'\n';

  return 0;
}
