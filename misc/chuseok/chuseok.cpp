#include <iostream>

using namespace std;

int t,i;
char str[16];
void print(int n) {
  if (n%3) {
    for (i=0;i<n;i++)
      printf("..#.");
    printf(".");

    for (i=0;i<n*2;i++)
      printf(".#");
    printf(".");

    /* printing the string */

    for (i=0;i<n*2;i++)
      printf(".#");
    printf(".");

    for (i=0;i<n;i++)
      printf("..#.");
    printf(".");
  }
  else {

  }
}
int main() {
  scanf("%d",&t);
  while(t--) {
    scanf("%s",str);
    print(strlen(str));

  }

  return 0;
}
