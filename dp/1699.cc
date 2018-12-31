/**
 * 제곱수의 합
 * 1699
 */
#include <cstdio>
#include <cmath>
#define min(a,b) (((a)<(b))?(a):(b))

int d[100001];
int main(){
  int n;
  scanf("%d",&n);

  for(int i=1;i<=n;i++){
    d[i] = i;
    for(int j=1;j*j<=i;j++){
      d[i] = min(d[i],1 + d[i-j*j]);
    }
  }

  printf("%d",d[n]);

  return 0;
}
