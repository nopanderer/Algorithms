/**
 * 좌표 정렬하기
 * 11650
 */
#include <cstdio>
#include <algorithm>
using namespace std;

struct Point{
  int x,y;
};
bool cmp(const Point &p1, const Point &p2){
  if(p1.x==p2.x) return p1.y<p2.y;
  else return p1.x<p2.x;
}
int main(){
  int N;
  Point p[100001];
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d %d",&p[i].x,&p[i].y);
  sort(p,p+N,cmp);

  for(int i=0;i<N;i++)
    printf("%d %d\n",p[i].x,p[i].y);

  return 0;
}
