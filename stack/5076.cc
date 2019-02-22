/**
 * Web Pages
 * 5076
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
bool check(string s){
  stack<string> st;
  int i = 0;
  while(i < s.size()){
    // tag open
    if(s[i] == '<'){
      i++;
      // br
      if(s[i] == 'b' && s[i+1] == 'r'){
        i += 4;
      }
      // a
      else if(s[i] == 'a'){
        st.push("a");
        while(s[i] != '>'){
          i++;
        }
      }
      // tag close
      else if(s[i] == '/'){
        i++;
        string tmp = "";
        // there should be a tag in stack
        if(st.empty()){
          return false;
        }
        while(s[i] != '>'){
          tmp += s[i];
          i++;
        }
        // compare with stack top
        string top = st.top();
        st.pop();
        if(top != tmp){
          return false;
        }
      }
      else{
        string tmp = "";
        while(s[i] != '>'){
          tmp += s[i];
          i++;
        }
        st.push(tmp);
      }
    }
    i++;
  }
  if(!st.empty()){
    return false;
  }
  return true;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  while(true){
    getline(cin, s);
    if(s[0] == '#'){
      break;
    }
    bool c = check(s);
    if(c){
      cout << "legal\n";
    }
    else{
      cout << "illegal\n";
    }
  }

  return 0;
}
