#include <iostream>

using namespace std;

int t,n;
int i,j,temp;
int s[2][100001];
int d[2][100001];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0;i<2;++i) for (j=0;j<n;++j) scanf("%d",&s[i][j]);

    for (i=0;i<n;i++) {
      for (j=0;j<2;j++) {
        temp = max(max(d[0][i-1],d[1][i-1]), s[j][i] + max(d[0][i-2], d[1][i-2]));
        d[j][i] = max(temp, s[j][i] + s[(j+1)%2][i-1] + d[j][i-2]);
      }
    }
    
    printf("%d\n",max(d[0][n-1], d[1][n-1]));
  }

  return 0;
}
