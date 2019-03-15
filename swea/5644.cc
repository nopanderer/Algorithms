/**
 * 무선 충전
 * 5644
 */
#include<iostream>
#include<cmath>
using namespace std;
//int main(int argc, char** argv){
struct BC{
  int x;
  int y;
  int c;
  int p;
};
int main(){
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
    int board[10][10];
    int a[101];
    int b[101];
    BC bc[8];
    int M,A;
    int dx[] = {0,-1,0,1,0};
    int dy[] = {0,0,1,0,-1};
    int ax = 0;
    int ay = 0;
    int bx = 9;
    int by = 9;
    int ans = 0;


    cin >> M >> A;
    for(int i=0;i<M;i++){
      cin >> a[i];
    }
    for(int i=0;i<M;i++){
      cin >> b[i];
    }
    for(int i=0;i<A;i++){
      cin >> bc[i].y >> bc[i].x >> bc[i].c >> bc[i].p;
      bc[i].x--;
      bc[i].y--;
    }


    for(int m=-1;m<M;m++){
      bool bc_a[8] = {false, };
      bool bc_b[8] = {false, };
      int sum = 0;

      if(m != -1){
        ax += dx[a[m]];
        ay += dy[a[m]];
        bx += dx[b[m]];
        by += dy[b[m]];
      }

      for(int i=0;i<A;i++){
        if(abs(ax - bc[i].x) + abs(ay - bc[i].y) <= bc[i].c){
          bc_a[i] = true;
        }

        if(abs(bx - bc[i].x) + abs(by - bc[i].y) <= bc[i].c){
          bc_b[i] = true;
        }
      }
      
      for(int i=0;i<A;i++){
        for(int j=0;j<A;j++){
          int ap,bp;
          if(i == j && bc_a[i] && bc_b[i]){
            sum = max(sum, bc[i].p);
          }
          else{
            ap = bc_a[i] ? bc[i].p : 0;
            bp = bc_b[j] ? bc[j].p : 0;
            sum = max(sum, ap + bp);
          }
        }
      }

      ans += sum;
    }
    cout << '#' << test_case << ' ' << ans << '\n';

	}
  return 0;
}
