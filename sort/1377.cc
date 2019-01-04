/**
 * 버블 소트
 * 1377
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N;
  scanf("%d",&N);
  vector<pair<int,int> > a(N);
  for(int i=0;i<N;i++){
    scanf("%d",&a[i].first);
    a[i].second = i;
  }
  sort(a.begin(),a.end());
  int ans=0;
  for(int i=0;i<N;i++){
    if(ans < a[i].second - i)
      ans = a[i].second - i;
  }
  printf("%d\n",ans+1);

  return 0;
}
