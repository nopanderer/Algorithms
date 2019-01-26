/**
 * 문자열 폭발
 * 9935
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool c[1000001];
int main(){
  string s,b;
  stack<pair<int,int>> st;
  cin>>s>>b;
  if(b.size() == 1){
    for(int i=0;i<s.size();i++){
      if(s[i] == b[0]) c[i] = true;
    }
  }
  else{
    for(int i=0;i<s.size();i++){
      if(s[i] == b[0]){
        st.push({i,0});
      }
      else if(!st.empty() && s[i] == b[st.top().second+1]){
        st.push({i,st.top().second+1});
        if(st.top().second == b.size()-1){
          for(int j=0;j<b.size();j++){
            c[st.top().first] = true;
            st.pop();
          }
        }
      }
      else{
        while(!st.empty()){
          st.pop();
        }
      }
    }
  }
  bool flag=false;
  for(int i=0;i<s.size();i++){
    if(!c[i]){
      cout<<s[i];
      flag=true;
    }
  }
  if(flag==false){
    cout<<"FRULA";
  }
  cout<<'\n';

  return 0;
}
