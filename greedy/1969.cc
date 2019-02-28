/**
 * DNA
 * 1969
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
int N,M;
int cnt[1001][26];
vector<string> dna;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0;i<N;i++){
    string s;
    cin >> s;
    dna.push_back(s);
    for(int j=0;j<M;j++){
      cnt[j][s[j] - 'A']++;
    }
  }

  int ans = 0;
  for(int i=0;i<M;i++){
    int idx = 0;
    for(int j=1;j<26;j++){
      if(cnt[i][idx] < cnt[i][j]){
        idx = j;
      }
    }
    cout << (char)('A' + idx);
    for(int j=0;j<N;j++){
      if(dna[j][i] - 'A' != idx){
        ans++;
      }
    }
  }
  cout << '\n' << ans << '\n';;


  return 0;
}
