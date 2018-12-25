/**
 * Bubble Sort
 * 2750
 */

#include <cstdio>
#define MAX_SIZE 1005

bool swapped;
int i,j,n,tmp;
int a[MAX_SIZE];

void swap(int *p, int *q){
  tmp = *p;
  *p = *q;
  *q = tmp;
}
int main(){
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  for(i=0;i<n-1;i++){
    swapped = false;
    for(j=0;j<n-1-i;j++){
      if(a[j]>a[j+1]){
        swap(&a[j],&a[j+1]);
        swapped = true;
      }
    }
    if(!swapped){
      break;
    }
  }

  for(i=0;i<n;i++)
    printf("%d\n",a[i]);

  return 0;
}
