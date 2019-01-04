/**
 * 수 정렬하기 3
 * 10989
 */
#include <iostream>
using namespace std;

int a[10001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    int tmp;
    cin>>tmp;
    a[tmp]++;
  }

  for(int i=0;i<10001;i++){
    for(int j=0;j<a[i];j++){ 
      cout<<i<<'\n';
    }
  }
  return 0;
}
