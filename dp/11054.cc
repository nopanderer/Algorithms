/**
 * 가장 긴 바이토닉 부분 수열
 * 11054
 */
#include <cstdio>
#define max(a,b) (((a)>(b))?(a):(b))

int up[1001];
int dn[1001];
int a[1001];
int main(){
  int n;
  scanf("%d",&n);

  for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);

  for(int i=1;i<=n;i++){
    up[i] = 1;
    for(int j=1;j<i;j++)
      if(a[j]<a[i]) up[i] = max(up[i], up[j] + 1);
  }
  for(int i=n;i>=1;i--){
    dn[i] = 1;
    for(int j=i+1;j<=n;j++)
      if(a[i]>a[j]) dn[i] = max(dn[i], dn[j] + 1);
  }

  int ans = 0;
  for(int i=1;i<=n;i++){
    ans = max(ans, dn[i]+up[i]-1);
  }

  printf("%d",ans);
  return 0;
}
