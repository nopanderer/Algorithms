/**
 * 수 정렬하기 2
 * 2751
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int N;
  int a[1000001];
  cin>>N;
  for(int i=0;i<N;i++)
    cin>>a[i];
  sort(a,a+N);
  for(int i=0;i<N;i++)
    cout<<a[i]<<'\n';

  return 0;
}
