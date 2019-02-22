/**
 * 카드2
 * 2164
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  queue<int> q;
  cin >> n;
  for(int i=1;i<=n;i++){
    q.push(i);
  }
  while(q.size() != 1){
    q.pop();
    int front = q.front();
    q.pop();
    q.push(front);
  }
  cout << q.front() << '\n';

  return 0;
}
