/**
 * 수 묶기
 * 1744
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int N;
  int zero=0;
  int one=0;
  vector<int> pos;
  vector<int> neg;
  cin>>N;
  for(int i=0;i<N;i++){
    int num;
    cin>>num;
    if(num == 0){
      zero++;
    }
    else if(num == 1){
      one++;
    }
    else if(num > 0){
      pos.push_back(num);
    }
    else if(num < 0){
      neg.push_back(num);
    }
  }
  sort(pos.begin(),pos.end());
  reverse(pos.begin(),pos.end());
  sort(neg.begin(),neg.end());
  if(pos.size()%2 == 1){
    pos.push_back(1);
  }
  if(neg.size()%2 == 1){
    neg.push_back(zero ? 0 : 1);
  }
  int ans = one;
  for(int i=0;i<pos.size();i+=2){
    ans += pos[i]*pos[i+1];
  }
  for(int i=0;i<neg.size();i+=2){
    ans += neg[i]*neg[i+1];
  }
  cout<<ans<<'\n';

  return 0;
}
