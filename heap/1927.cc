/**
 * 최소 힙
 * 1927
 */
#include <iostream>
#include <utility>
using namespace std;
int heap[100010];
int hn;
void insert(int x){
  heap[++hn] = x;
  for(int i=hn;i>1;i/=2){
    if(heap[i/2] > heap[i]){
      swap(heap[i], heap[i/2]);
    }
    else break;
  }
}
int remove(){
  if(hn == 0) return 0;
  else{
    int root = heap[1];
    heap[1] = heap[hn];
    heap[hn--] = 0;
    for(int i=1;i*2 <= hn;){
      if(2*i+1 > hn){
        if(heap[i] > heap[2*i]){
          swap(heap[i], heap[2*i]);
        }
        i = 2*i;
      }
      else{
        if(heap[i] < heap[2*i] && heap[i] < heap[2*i+1]) break;
        else if(heap[2*i] < heap[2*i+1]){
          swap(heap[i], heap[2*i]);
          i = 2*i;
        }
        else{
          swap(heap[i], heap[2*i+1]);
          i = 2*i+1;
        }
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
