/**
 * Merge Sort
 * 2751
 */

#include <cstdio>
#define MAX_SIZE 1000001

int n,i,j,k,l;
int a[MAX_SIZE];
int t[MAX_SIZE];

void merge(int left, int mid, int right){
  i = left;
  j = mid+1;
  k = left;

  // merge
  while(i<=mid && j<=right){
    if(a[i]<=a[j])
      t[k++] = a[i++];
    else
      t[k++] = a[j++];
  }

  // copy the rest
  if(i>mid){
    for(l=j;l<=right;l++)
      t[k++] = a[l];
  }

  else{
    for(l=i;l<=mid;l++)
      t[k++] = a[l];
  }

  // copy the tmp list to origin list
  for(l=left;l<=right;l++){
    a[l] = t[l];
  }
}

void sort(int left, int right){
  if(left<right){
    int mid = (left+right)/2; // DO NOT USE GLOBAL VAR FOR mid
    sort(left,mid);
    sort(mid+1,right);
    merge(left,mid,right);
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
