/**
 * 최대 힙
 * 11279
 */
#include <iostream>
#include <utility>
using namespace std;
int heap[100010];
int hn;
void insert(int x){
  heap[++hn] = x;
  int tmp = hn;
  while(tmp > 1 && heap[tmp/2] < heap[tmp]){
    swap(heap[tmp/2], heap[tmp]);
    tmp/=2;
  }
}
int remove(){
  if(hn == 0) return 0;
  else{
    int root = heap[1];
    heap[1] = heap[hn];
    heap[hn--] = 0;
    int tmp = 1;
    while(tmp*2 <= hn && (heap[tmp] < heap[tmp*2] || heap[tmp] < heap[tmp*2+1])){
      if(heap[tmp*2] < heap[tmp*2+1]){
        swap(heap[tmp], heap[tmp*2+1]);
        tmp = tmp*2+1;
      }
      else{
        swap(heap[tmp], heap[tmp*2]);
        tmp = tmp*2;
      }
    }
    return root;
  }
}
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int N,x;
  cin>>N;
  while(N--){
    cin>>x;
    if(x == 0){
      cout<<remove()<<'\n';
    }
    else{
      insert(x);
    }
  }

  return 0;
}
