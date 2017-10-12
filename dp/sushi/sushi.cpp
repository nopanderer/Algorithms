#include <iostream>

using namespace std;

int t,n;
int i,j,temp;
int s[2][100001];
int d[100001][3];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0;i<2;++i) for (j=0;j<n;++j) scanf("%d",&s[i][j]);

    for (i=0;i<n;i++) {
      // 1. not eat -> i-1's max value
      d[i][0] = max(max(d[i-1][0],d[i-1][1]), d[i-1][2]);
      // 2. eat upper sushi -> max(not eat i-1's sushi, eat i-1's lower sushi)
      d[i][1] = max(s[0][i] + max(max(d[i-2][0],d[i-2][1]), d[i-2][2]), s[0][i] + d[i-1][2]);
      // 3. eat lower sushi
      d[i][2] = max(s[1][i] + max(max(d[i-2][0],d[i-2][1]), d[i-2][2]), s[1][i] + d[i-1][1]);
    }
    printf("%d\n",max(max(d[n-1][0], d[n-1][1]), d[n-1][2]));
  }
  return 0;
}
