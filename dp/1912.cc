/**
 * 연속합
 * 1912
 */
#include <cstdio>
#define max(a,b) (((a)>(b))?(a):(b))

int d[100001];
int a[100001];
int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);

  d[0] = a[0];
  for(int i=1;i<n;i++){
    d[i] = max(d[i-1]+a[i],a[i]);
  }
  int ans = d[0];
  for(int i=1;i<n;i++){
    ans = max(ans, d[i]);
  }
  printf("%d",ans);


  return 0;
}
