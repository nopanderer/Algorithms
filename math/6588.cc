/**
 * 골드바흐의 추측
 * 6588
 */
#include <cstdio>

const int MAX = 1000001;
bool c[MAX];
int p[MAX];
int main(){
  int n;
  int pn=0;
  for(int i=2;i<=MAX;i++){
    if(c[i] == false){
      p[pn++] = i;
      for(int j=i+i;j<=MAX;j+=i){
        c[j] = true;
      }
    }
  }
  while(true){
    scanf("%d",&n);
    if(n==0)
      break;
    for(int i=0;i<pn;i++){
      if(c[n-p[i]] == false){
        printf("%d = %d + %d\n",n,p[i],n-p[i]);
        break;
      }
    }
  }

  return 0;
}
