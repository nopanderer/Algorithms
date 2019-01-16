/**
 * 사다리
 * 2022
 */
#include <cstdio>
#include <cmath>
using namespace std;
double x,y,c,l,r,m,h,h1,h2;
int main(){
  scanf("%lf %lf %lf",&x,&y,&c);
  r = x+y;
  while(abs(l-r) > 1e-6){
    m = (l+r)/2;
    h1 = sqrt(pow(x,2)-pow(m,2));
    h2 = sqrt(pow(y,2)-pow(m,2));
    h = (h1*h2)/(h1+h2);
    if(h > c){
      l = m;
    }
    else{
      r = m;
    }
  }
  printf("%.3lf\n",m);

  return 0;
}
