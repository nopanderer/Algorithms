#include <iostream>

using namespace std;

int i,n,m,ret;
int d[41], v[41];
int fibo(int n) {
  if (d[n]) {}

  else if (n<=1)
    d[n]=1;

  else if (n==2)
    d[n]=2;

  else
    d[n] = fibo(n-1) + fibo(n-2);

  return d[n];
}

int main() {
  scanf("%d",&n);
  scanf("%d",&m);
  for (i=1;i<=m;i++) scanf("%d",&v[i]);

  ret = 1;

  for (i=1;i<=m;i++) ret *= fibo(v[i]-v[i-1]-1);

  ret *= fibo(n-v[m]);


  printf("%d\n",ret);

  return 0;
}
