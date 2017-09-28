#include <iostream>
#include <cmath>

using namespace std;

int t,n,i,j,re;
int main() {
  scanf("%d",&t);
  while (t--) {
    i=0,j=0;
    scanf("%d",&n);
    if (n == 2) { printf("1\n"); continue; }
    else if (n == 3) { printf("2\n"); continue; }
    else if (n%3 == 1) { i = 2; j = n/3 - 1; }
    else if (n%3 == 2) { i = 1; j = n/3; }
    else { j = n/3; }

    re = pow(2,i);
    while (j != 0) {
      re *= 3;
      if (re >= 2017) re %= 2017;
      j--;
    }
    printf("%d\n",re);
  }
  return 0;
}
