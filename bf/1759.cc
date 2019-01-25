/**
 * 암호 만들기
 * 1759
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int L,C;
char alpha[16];
bool check(string pw){
  int m=0;
  int z=0;
  for(int i=0;i<pw.size();i++){
    if(pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'o' || pw[i] == 'u' || pw[i] == 'i') m++;
    else z++;
  }
  if(m>=1 && z>=2) return true;
  else return false;
}
void go(string pw, int idx){
  if(pw.size() == L){
    if(check(pw)){
      cout<<pw<<'\n';
    }
    return;
  }
  else if(idx >= C) return;
  else{
    go(pw+alpha[idx],idx+1);
    go(pw,idx+1);
  }
}
int main(){
  string pw = "";
  cin>>L>>C;
  for(int i=0;i<C;i++){
    cin>>alpha[i];
  }
  sort(alpha,alpha+C);
  go(pw,0);

  return 0;
}
