/**
 * 히스토그램에서 가장 큰 직사각형
 * 6549
 */
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
int main(){
  int T;
  long long a[100001];
  stack<long long> st;
  long long left,right;

  while(true){
    long long ans = 0;
    cin>>T;
    if(T == 0) break;
    for(int i=0;i<T;i++){
      cin>>a[i];
    }
    for(int i=0;i<T;i++){
      right = i-1;
      while(!st.empty() && a[st.top()] > a[i]){
        long long top  =  st.top();
        st.pop();
        left = st.empty() ? 0 : st.top()+1;
        ans = max(ans,(abs(right - left) + 1) * a[top]);
      }
      st.push(i);
    }
    while(!st.empty()){
      long long top = st.top();
      st.pop();
      right = T-1;
      left = st.empty() ? 0 : st.top()+1;
      ans = max(ans,(abs(right-left)+1)*a[top]);
    }
    cout<<ans<<'\n';
  }

  return 0;
}
