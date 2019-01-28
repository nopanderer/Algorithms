/**
 * 회사에 있는 사람
 * 7785
 */
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n;
  set<string> s;
  cin>>n;
  while(n--){
    string name, status;
    cin>>name>>status;
    if(status == "enter"){
      s.insert(name);
    }
    else{
      s.erase(s.find(name));
    }
  }
  for(auto it = s.rbegin();it!=s.rend();it++){
    cout<<*it<<'\n';
  }

  return 0;
}
