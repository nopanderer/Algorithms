/**
 * 보물상자 비밀번호
 * 5658
 */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  for(int t=1;t<=T;t++){
    int N,K;
    vector<string> a;
    string s;
    cin >> N >> K;
    cin >> s;
    for(int i=0;i<N/4;i++){
      for(int j=0;j<N;j+=N/4){
        a.push_back(s.substr(j,N/4));
      }
      string tmp = s.substr(0, N-1);
      reverse(tmp.begin(), tmp.end());
      tmp += s[N-1];
      s = tmp;
      reverse(s.begin(), s.end());
    }
    set<string> b;
    for(int i=0;i<(int)a.size();i++){
      b.insert(a[i]);
    }
    set<string>::reverse_iterator it = b.rbegin();
    for(int i=0;i<K-1;i++){
      it++;
    }
    string ans = *it;
    int num = 0;
    for(int i=0;i<ans.size();i++){
      if('A' <= ans[i] && ans[i] <= 'Z'){
        num = (ans[i] - 'A' + 10) + num*16;
      }
      else{
        num = (ans[i] - '0') + num*16;
      }
    }
    cout << '#' << t << ' ';
    cout << num << '\n';
  }

  return 0;
}
