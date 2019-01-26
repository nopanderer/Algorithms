/**
 * 검열
 * 3111
 */
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  string t,a,ar;
  string tmp;
  bool lflag = true;
  stack<char> l,r;
  cin>>a>>t;
  ar = a;
  reverse(ar.begin(),ar.end());
  int lidx = 0;
  int ridx = t.size()-1;
  while(lidx <= ridx){
    tmp = "";
    if(lflag){
      l.push(t[lidx]);
      if(l.size() >= a.size()){
        for(int i=0;i<a.size();i++){
          tmp += l.top();
          l.pop();
        }
        // check
        if(tmp == ar){
          lflag = false;
        }
        else{
          for(int i=0;i<a.size();i++){
            l.push(tmp[a.size()-i-1]);
          }
        }
      }
      lidx++;
    }
    else{
      r.push(t[ridx]);
      if(r.size() >= a.size()){
        for(int i=0;i<a.size();i++){
          tmp += r.top();
          r.pop();
        }
        // check
        if(tmp == a){
          lflag = true;
        }
        else{
          for(int i=0;i<a.size();i++){
            r.push(tmp[a.size()-i-1]);
          }
        }
      }
      ridx--;
    }
  }
  // L > R
  while(!l.empty()){
    char c = l.top();
    r.push(c);
    l.pop();
    tmp = "";
    if(r.size() >= a.size()){
      for(int i=0;i<a.size();i++){
        tmp += r.top();
        r.pop();
      }
      if(tmp == a){
        continue;
      }
      else{
        for(int i=0;i<a.size();i++){
          r.push(tmp[a.size()-i-1]);
        }
      }
    }
  }
  while(!r.empty()){
    char c = r.top();
    cout<<c;
    r.pop();
  }
  cout<<'\n';

  return 0;
}
