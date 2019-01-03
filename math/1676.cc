/**
 * 팩토리얼 0의 개수
 * 1676
 */
#include <cstdio>

int main(){
  int N;
  scanf("%d",&N);
  printf("%d\n",N/5+N/(5*5)+N/(5*5*5));

  return 0;
}
