/**
 * 후위표기식
 * 1918
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
  string s;
  stack<char> st;
  cin >> s;
  for(int i=0;i<s.size();i++){
    if('A' <= s[i] && s[i] <= 'Z'){
      cout << s[i];
    }
    else if(s[i] == '('){
      st.push(s[i]);
    }
    else if(s[i] == ')'){
      while(st.top() != '('){
        cout << st.top();
        st.pop();
      }
      st.pop();
    }
    else{
      while(true){
        if(st.empty()){
          break;
        }
        if(st.top() == '('){
          break;
        }
        if((s[i] == '*' || s[i] == '/') && (st.top() == '+' || st.top() == '-')){
          break;
        }
        else{
          cout << st.top();
          st.pop();
        }
      }
      st.push(s[i]);
    }
  }
  while(!st.empty()){
    cout << st.top();
    st.pop();
  }
  cout << '\n';

  return 0;
}
