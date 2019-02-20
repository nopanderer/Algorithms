/**
 * 덩치
 * 7568
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
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  vector<pair<int,int>> a;
  cin >> n;
  for(int i=0;i<n;i++){
    int x,y;
    cin >> x >> y;
    a.push_back({x,y});
  }

  for(int i=0;i<a.size();i++){
    int cnt = 0;
    for(int j=0;j<a.size();j++){
      if(i != j && a[i].first < a[j].first && a[i].second < a[j].second){
        cnt++;
      }
    }
    cout << 1 + cnt << '\n';
  }

  return 0;
}
