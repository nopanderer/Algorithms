/**
 * Quick Sort
 * 2750
 */

#include <cstdio>
#define MAX_SIZE 1000001

int n,i,j,tmp;
int a[MAX_SIZE];

void swap(int *p, int *q){
  tmp = *p;
  *p = *q;
  *q = tmp;
}

int partition(int left, int right){
  int pivot = a[left]; // leftmost is pivot
  int low = left;
  int high = right+1;

  do{
    do{
      low++;
    }while(low<=right && a[low]<pivot);
    
    do{
      high--;
    }while(high>=left && a[high]>pivot);

    if(low<high){
      swap(&a[low], &a[high]);
    }
  }while(low<high);

  swap(&a[left], &a[high]); // swap pivot with high

  return high; // return the pivot index
}

void sort(int left, int right){
  if(left < right){
    int pivot = partition(left, right);
    sort(left, pivot-1);
    sort(pivot+1, right);
  }
}

int main(){
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  sort(0,n-1);

  for(i=0;i<n;i++)
    printf("%d\n",a[i]);

  return 0;
}
