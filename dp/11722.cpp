/**
 * 11722
 */
#include <cstdio>

int main(){
  int pr;
  int len=0;
  int n;
  int a[1001];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=0;i<n-1;i++){
    pr = 123456789;
    for(int j=i+1;j<n;j++){
      if(a[i]>a[j])
        pr = a[j];
  }
  printf("%d",len);
  
  return 0;
}

