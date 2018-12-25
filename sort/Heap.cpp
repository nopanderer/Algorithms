/**
 * Heap Sort
 * 2751
 */

#include <cstdio>
#define MAX_SIZE 1000001

int i,n,tmp;
int a[MAX_SIZE];

void swap(int *p, int *q){
  tmp = *p;
  *p = *q;
  *q = tmp;
}

void heapify(int size, int i){
  int largest = i;
  int l = 2*i +1;
  int r = 2*i +2;

  if (l<size && a[l] > a[largest])
    largest = l;
  if (r<size && a[r] > a[largest])
    largest = r;

  if(largest!=i){
    swap(&a[i],&a[largest]);
    heapify(size,largest);
  }
}

void heapsort(){
  for(i=n/2-1;i>=0;i--){
    heapify(n,i);
  }

  for(i=n-1;i>=0;i--){
    swap(&a[0],&a[i]);
    heapify(i,0);
  }
}

int main(){
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  heapsort();

  for(i=0;i<n;i++)
    printf("%d\n",a[i]);

  return 0;
}
