/**
 * 계단 오르기
 * 2579
 */
#include <cstdio>
#define max(a,b) (((a)>(b))?(a):(b))

int a[301];
int d[301][2];

int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);

  d[0][0] = a[0];
  d[0][1] = a[0];

  d[1][0] = a[1];
  d[1][1] = a[0] + a[1];

  for(int i=2;i<n;i++){
    d[i][0] = max(d[i-2][0],d[i-2][1])+ a[i];
    d[i][1] = d[i-1][0] + a[i];
  }

  printf("%d",max(d[n-1][0],d[n-1][1]));

  return 0;
}
