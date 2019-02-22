/**
 * 히스토그램
 * 1725
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
  int a[100001];
  stack<int> st;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  int ans = 0;
  for(int i=0;i<n;i++){
    // 스택 탑을 높이로 하는 직사각형을 더이상 만들 수 없음
    while(!st.empty() && a[st.top()] > a[i]){
      int h = a[st.top()];
      st.pop();
      int r = i-1;
      int l = st.empty() ? 0 : (st.top() + 1);
      ans = max(ans, h*(r-l+1));
    }
    st.push(i);
  }
  while(!st.empty()){
    int h = a[st.top()];
    int r = n-1;
    st.pop();
    int l = st.empty() ? 0 : (st.top() + 1);
    ans = max(ans, h*(r-l+1));
  }

  cout << ans << '\n';

  return 0;
}
