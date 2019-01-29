/**
 * 별 찍기 - 13
 * 2523
 */
#include <iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n-1;i++){
    for(int j=0;j<i+1;j++){
      cout<<'*';
    }
    cout<<'\n';
  }
  for(int i=0;i<n;i++){
    cout<<'*';
  }
  cout<<'\n';
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1-i;j++){
      cout<<'*';
    }
    cout<<'\n';
  }

  return 0;
}
