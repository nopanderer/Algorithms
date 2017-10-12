#include <iostream>
#include <algorithm>

using namespace std;

int t,n,m;
int i,j;
int mi;
int h[5001], p[100001];
long tmp, d[5001];
int main(void) {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) scanf("%d",&h[i]);
    for (i=1;i<=m;i++) scanf("%d",&p[i]);
    sort(h,h+n); // sort the holes
    // minimum cost to cover the hole of legnth i
    mi = p[m];
    for (i=m-1;i>=1;i--) {
      if (p[i] < mi) mi = p[i];
      else p[i] = mi;
    }

    for (i=1;i<=n;i++) {
      tmp = 987654321;
      for (j=0;j<i;j++) {
        tmp = min(tmp, p[h[i] - h[i-j] + 1] + d[i-j-1]);
        printf("cost from %d to %d(length: %d): %d\n",h[i],h[i-j],h[i]-h[i-j]+1,p[h[i]-h[i-j]+1]);
      }
      printf("\n");
      d[i] = tmp;
    }
    // for (i=1;i<=n;i++) printf("%ld ",d[i]);
    // printf("%ld\n",d[n]);
  }
  return 0;
}
