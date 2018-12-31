/**
 * 파도반 수열
 * 9461
 */
#include <cstdio>

long long d[101];
int main(){
  int t;
  int n;
  scanf("%d",&t);
  d[1] = 1;
  d[2] = 1;
  d[3] = 1;
  d[4] = 2;
  d[5] = 2;
  while(t--){
    scanf("%d",&n);
    if(d[n]) printf("%lld\n",d[n]);
    else{
      for(int i=6;i<=n;i++){
        d[i] = d[i-1] + d[i-5];
      }
      printf("%lld\n",d[n]);
    }
  }

  return 0;
}
