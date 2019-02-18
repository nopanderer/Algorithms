/**
 * 숫자 야구
 * 2503
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
bool a[1000];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  fill(a,a+1000,true);
  for(int i=123;i<1000;i++){
    string tmp = to_string(i);
    if(tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0'){
      a[i] = false;
    }
    if(tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2]){
      a[i] = false;
    }
  }

  int n;
  cin >> n;
  while(n--){
    int num,s,b;
    cin >> num >> s >> b;
    for(int i=123;i<1000;i++){
      if(a[i]){
        string one = to_string(num);
        string two = to_string(i);
        int sCnt = 0;
        int bCnt = 0;
        for(int j=0;j<3;j++){
          for(int k=0;k<3;k++){
            if(j==k && one[j] == two[k]){
              sCnt++;
            }
            if(j!=k && one[j] == two[k]){
              bCnt++;
            }
          }
        }
        if(s != sCnt || b != bCnt){
          a[i] = false;
        }
      }
    }
  }

  int ans = 0;
  for(int i=123;i<1000;i++){
    if(a[i] == true){
      ans++;
    }
  }

  cout << ans << '\n';

  return 0;
}
// 100개의 질문 * 1000개의 수 * 자리수 별로 비교 3*3 = 100*1000*9
