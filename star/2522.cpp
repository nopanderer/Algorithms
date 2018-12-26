/**
 * Star 12
 * 2522
 */
#include <cstdio>

int main(){
  int n;
  int i,j;
  scanf("%d",&n);
  for(i=0;i<n-1;i++){
    for(j=0;j<n-1-i;j++){
      printf(" ");
    }
    for(j=0;j<i+1;j++){
      printf("*");
    }
    printf("\n");
  }
  for(i=0;i<n;i++)
    printf("*");
  printf("\n");
  for(i=0;i<n-1;i++){
    for(j=0;j<i+1;j++){
      printf(" ");
    }
    for(j=0;j<n-1-i;j++){
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
