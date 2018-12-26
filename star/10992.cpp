/**
 * Star 17
 * 10992
 */
#include <cstdio>

int main(){
  int n;
  int i,j;
  scanf("%d",&n);
  for(i=1;i<n;i++){
    for(j=0;j<n-i;j++)
      printf(" ");
    printf("*");
    for(j=2;j<2*i-1;j++)
      printf(" ");
    if(i!=1)
    printf("*");
    printf("\n");
  }
  for(i=0;i<n*2-1;i++)
    printf("*");
  return 0;
}
