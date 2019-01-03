/**
 * 조합 0의 개수
 * 2004
 */
#include <cstdio>

int main(){
  long long n,m;
  long long two=0;
  long long five=0;
  scanf("%lld %lld",&n,&m);

  for(long long i=2;i<=n;i*=2){
    two += n/i;
  }
  for(long long i=2;i<=m;i*=2){
    two -= m/i;
  }
  for(long long i=2;i<=n-m;i*=2){
    two -= (n-m)/i;
  }
  for(long long i=5;i<=n;i*=5){
    five += n/i;
  }
  for(long long i=5;i<=m;i*=5){
    five -= m/i;
  }
  for(long long i=5;i<=n-m;i*=5){
    five -= (n-m)/i;
  }

  if(two<five) 
    printf("%lld\n",two);
  else
    printf("%lld\n",five);

  return 0;
}
