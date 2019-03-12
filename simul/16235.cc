/**
 * 나무 재테크
 * 16235
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Tree{
  int x;
  int y;
  int age;
};
bool cmp(const Tree &t1, const Tree &t2){
  return t1.age < t2.age;
}
int N,M,K;
int a[11][11];
int A[11][11];
vector<Tree> tree;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int main(){
  cin >> N >> M >> K;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> A[i][j];
      a[i][j] = 5;
    }
  }
  for(int i=0;i<M;i++){
    int x,y,z;
    cin >> x >> y >> z;
    tree.push_back({x-1, y-1, z});
  }
  while(K--){
    sort(tree.begin(), tree.end(), cmp);
    vector<Tree> alive;
    vector<Tree> dead;

    // spring
    for(auto &tr : tree){
      if(a[tr.x][tr.y] >= tr.age){
        a[tr.x][tr.y] -= tr.age;
        alive.push_back({tr.x, tr.y, tr.age+1});
      }
      else{
        dead.push_back({tr.x, tr.y, tr.age});
      }
    }
    
    // summer 
    for(auto &tr : dead){
      a[tr.x][tr.y] += tr.age/2;
    }

    tree.clear();

    // fall
    for(auto &tr : alive){
      if(tr.age%5 == 0){
        for(int i=0;i<8;i++){
          int nx = tr.x + dx[i];
          int ny = tr.y + dy[i];
          if(0 <= nx && nx < N && 0 <= ny && ny < N){
            tree.push_back({nx, ny, 1});
          }
        }
      }
    }
    
    // winter
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        a[i][j] += A[i][j];
      }
    }

    for(auto &tr : alive){
      tree.push_back({tr.x, tr.y, tr.age});
    }
  }

  cout << tree.size() << '\n';

  return 0;
}
