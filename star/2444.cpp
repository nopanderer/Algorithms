/**
 * Star 7
 * 2444
 */
#include <cstdio>

int main(){
  int n;
  int i,j;
  scanf("%d",&n);
  for(i=0;i<n-1;i++){
    for(j=0;j<n-1-i;j++)
      printf(" ");
    for(j=0;j<2*i+1;j++)
      printf("*");
    printf("\n");
  }

  for(i=0;i<2*n-1;i++)
    printf("*");
  printf("\n");

  for(i=1;i<n;i++){
    for(j=0;j<i;j++)
      printf(" ");
    for(j=0;j<2*n-1-2*i;j++)
      printf("*");
    printf("\n");
  }

  return 0;
}
