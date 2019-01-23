/**
 * 로또
 * 6603
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int k;
  while(true){
    cin>>k;
    if(k==0) break;
    vector<int> a(k);
    vector<int> c;
    for(int i=0;i<k;i++){
      cin>>a[i];
    }
    for(int i=0;i<6;i++){
      c.push_back(0);
    }
    for(int i=0;i<k-6;i++){
      c.push_back(1);
    }
    do{
      for(int i=0;i<k;i++){
        if(c[i]==0){
          cout<<a[i]<<' ';
        }
      }
      cout<<'\n';
    }while(next_permutation(c.begin(),c.end()));
    cout<<'\n';
  }
  return 0;
}
