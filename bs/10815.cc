/**
 * 숫자 카드
 * 10815
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector<int> a;
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin>>N;
  for(int i=0;i<N;i++){
    int num;
    cin>>num;
    a.push_back(num);
  }
  sort(a.begin(),a.end());
  cin>>M;
  for(int i=0;i<M;i++){
    int num;
    cin>>num;
    int left=0;
    int right=a.size()-1;
    bool find = false;
    while(left <= right){
      int mid=left+(right-left)/2;
      if(a[mid] == num){
        find = true;
        break;
      }
      else if(num < a[mid]){
        right = mid-1;
      }
      else if(a[mid] < num){
        left = mid+1;
      }
    }
    if(find) cout<<"1 ";
    else cout<<"0 ";
  }
  cout<<"\n";

  return 0;
}
