#include <iostream>
#include <cstring>

using namespace std;

int t,i;
char str[16];
void print(int n) {
    for (i=1;i<=n;i++) {
      if (i%3==0) printf("..*.");
      else printf("..#.");
    }
    printf(".\n");

    for (i=1;i<=n*2;i++) {
      if (i%6==0 || i%6==5) printf(".*");
      else printf(".#");
    }
    printf(".\n");

    /* printing the string */
    printf("#");
    for (i=1;i<=n*2-1;i++) {
      if (i%2!=0) printf(".%c",str[i/2]);
      else {
        if (i%6==0 || i%6==4) printf(".*");
        else printf(".#");
      }
    }
    if (n%3==0) printf(".*\n");
    else printf(".#\n");

    for (i=1;i<=n*2;i++) {
      if (i%6==0 || i%6==5) printf(".*");
      else printf(".#");
    }
    printf(".\n");

    for (i=1;i<=n;i++) {
      if (i%3==0) printf("..*.");
      else printf("..#.");
    }
    printf(".\n");
}
int main() {
  scanf("%d",&t);
  while(t--) {
    scanf("%s",str);
    print(strlen(str));
  }

  return 0;
}
