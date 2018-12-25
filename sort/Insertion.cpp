/**
 * Insertion Sort
 * 2750
 */

#include <cstdio>
#define MAX_SIZE 1005

int i,j,n,tmp;
int a[MAX_SIZE];

int main(){
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  for(i=1;i<n;i++){
    tmp=a[i];
    for(j=i-1;j>=0 && tmp<a[j];j--){
      a[j+1]=a[j];
    }
    a[j+1]=tmp;
  }

  for(i=0;i<n;i++)
    printf("%d\n",a[i]);

  return 0;
}
