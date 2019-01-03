/**
 * 팩토리얼
 * 10872
 */
#include <cstdio>

int main(){
  int N;
  int ans=1;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    ans*=i;
  }
  printf("%d",ans);

  return 0;
}

