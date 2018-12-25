/**
 * Selection Sort
 * 2750
 */

#include <cstdio>
#define MAX_SIZE 1005

int i,j,n,min,tmp;
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
    min=i;
    for(j=i+1;j<n;j++){
      if(a[j]<a[min])
        min=j;
    }
    swap(&a[i],&a[min]);
  }

  for(i=0;i<n;i++)
    printf("%d\n",a[i]);

  return 0;
}
