/**
 * 나이순 정렬
 * 10814
 */
#include <cstdio>
#include <algorithm>
using namespace std;

struct Member{
  int age;
  char name[101];
};
bool cmp(const Member &m1, const Member &m2){
  return m1.age < m2.age;
}
Member m[100001];
int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %s",&m[i].age,m[i].name);
  }
  stable_sort(m,m+N,cmp);
  for(int i=0;i<N;i++){
    printf("%d %s\n",m[i].age,m[i].name);
  }

  return 0;
}
