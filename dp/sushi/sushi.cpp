#include <iostream>

using namespace std;

int t,n,i,j,k,ret;
int s[2][100001];
int d[100001];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0;i<2;++i) for (j=0;j<n;++j) scanf("%d",&s[i][j]);

    d[0] = max(s[0][0],s[1][0]);

    if (s[0][0]+s[1][1] > s[1][0]+s[0][1]) {
      d[1] = s[0][0]+s[1][1];
      i=0;j=1;
    }
    else {
      d[1] = s[1][0]+s[0][1];
      i=1;j=0;
    }

    for (k=2;k<n;k++) {
      if (d[k-1] + s[i%2][k] > d[k-2] + s[j%2][k]) {
        d[k] = d[k-1] + s[i%2][k];
        i++,j++;
      }
      else
        d[k] = d[k-2] + s[j%2][k];
    }

    ret = d[n-1];




    d[n-1] = max(s[0][n-1],s[1][n-1]);

    if (s[0][n-1]+s[1][n-2] > s[1][n-1]+s[0][n-2]) {
      d[n-2] = s[0][n-1]+s[1][n-2];
      i=0;j=1;
    }
    else {
      d[n-2] = s[1][n-1]+s[0][n-2];
      i=1;j=0;
    }

    for (k=n-3;k>=0;k--) {
      if (d[k+1] + s[i%2][k] > d[k+2] + s[j%2][k]) {
        d[k] = d[k+1] + s[i%2][k];
        i++,j++;
      }
      else
        d[k] = d[k+2] + s[j%2][k];
    }

    ret = max(ret,d[0]);


    for (i=n-1;i>=0;i--) printf("%d ",d[i]);
    // printf("%d\n",ret);

  }


  return 0;
}
