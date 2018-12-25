/**
 * Star - 11
 * 2448
 */
#include <iostream>

using namespace std;

int i,j,n;
int main(){
  scanf("%d",&n);
  for(i=3;i<=n;i*=2){
    // upper
    for(j=0;j<n-1;j++) printf(" ");
    printf("*");

    // middle
    printf("* *");

    // low
    for(j=0;j<n;j++)
      printf("*");
    printf("\n");
  }


  return 0;
}
