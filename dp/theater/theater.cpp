#include <iostream>

using namespace std;

int i,n,m,ret;
int d[50];
int v[50];
int cal(int n) {
  if (n <= 0)
    return 1;
  if (d[n]) {
    return d[n];
  }
  else if (n==1) {
    d[n]=1;
    return 1;
  }
  else if (n==2) {
    d[n]=2;
    return 2;
  }
  else {
    d[n] = cal(n-1) + cal(n-2);
    return d[n];
  }
}

int main() {
  scanf("%d",&n);
  scanf("%d",&m);
  for (i=1;i<=m;i++) {
    scanf("%d",&v[i]);
  }

  ret = 1;

  for (i=1;i<=m;i++) {
    ret *= cal(v[i]-v[i-1]-1);
  }
  ret *= cal(n-v[m]);


  printf("%d\n",ret);

  return 0;
}
