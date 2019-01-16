/**
 * 집합
 * 11723
 */
#include <cstdio>
#include <cstring>
int main(){
  int M,x;
  int S=0;
  char s[10];
  scanf("%d",&M);
  while(M--){
    scanf("%s",s);
    if(strcmp(s,"add") == 0){
      scanf("%d",&x);
      S = S | (1<<x);
    }
    else if(strcmp(s,"remove") == 0){
      scanf("%d",&x);
      S = S & ~(1<<x);
    }
    else if(strcmp(s,"check") == 0){
      scanf("%d",&x);
      printf("%d\n",((S & (1<<x)) == (1<<x)) ? 1 : 0);
    }
    else if(strcmp(s,"toggle") == 0){
      scanf("%d",&x);
      S = S ^ (1<<x);
    }
    else if(strcmp(s,"all") == 0){
      S = (1<<21)-1;
    }
    else if(strcmp(s,"empty") == 0){
      S = 0;
    }
  }

  return 0;
}
