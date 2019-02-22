/**
 * 좋은 단어
 * 3986
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
  int ans = 0;
  cin >> n;
  while(n--){
    stack<char> st;
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
      if(st.empty()){
        st.push(s[i]);
      }
      else{
        if(st.top() == s[i]){
          st.pop();
        }
        else{
          st.push(s[i]);
        }
      }
    }
    if(st.empty()){
      ans++;
    }
  }
  cout << ans << '\n';

  return 0;
}
