/**
 * 병든 나이트
 * 1783
 */
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int w,h;
  cin>>h>>w;
  if(h == 1){
    cout<<"1\n";
  }
  else if(h == 2){
    cout<<min(4,(w+1)/2)<<'\n';
  }
  else{
    if(w>=7){
      cout<<(w-2)<<'\n';
    }
    else{
      cout<<min(4,w)<<'\n';
    }
  }

  return 0;
}
