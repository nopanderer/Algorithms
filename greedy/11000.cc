/**
 * 강의실 배정
 * 11000
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  vector<pair<int,int>> a;
  cin >> N;
  for(int i=0;i<N;i++){
    int s,t;
    cin >> s >> t;
    a.push_back({s,t});
  }
  sort(a.begin(), a.end());

  priority_queue<int,vector<int>,greater<int>> q;
  q.push(a[0].second);
  for(int i=1;i<a.size();i++){
    if(a[i].first < q.top()){
      q.push(a[i].second);
    }
    else{
      q.pop();
      q.push(a[i].second);
    }
  }

  cout << q.size() << '\n';


  return 0;
}


