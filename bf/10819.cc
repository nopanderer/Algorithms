/**
 * 차이를 최대로
 * 10819
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
vector<int> a;
int ans;
int main(){
  cin.tie(NULL);
  cin>>N;
  for(int i=0;i<N;i++){
    int tmp;
    cin>>tmp;
    a.push_back(tmp);
  }
  sort(a.begin(),a.end());
  do{
    int tmp = 0;
    for(int i=0;i<N-1;i++){
      tmp += abs(a[i] - a[i+1]);
    }
    if(tmp > ans){
      ans = tmp;
    }
  }while(next_permutation(a.begin(),a.end()));

  cout<<ans<<'\n';

  return 0;
}
