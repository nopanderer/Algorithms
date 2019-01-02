/**
 * 진법 변환 2
 * 11005
 */
#include <iostream>
#include <stack>

using namespace std;

int main(){
  int n,b;
  stack<int> st;
  cin>>n>>b;
  while(n!=0){
    st.push(n%b);
    n/=b;
  }
  while(!st.empty()){
    if(10 <= st.top() && st.top() <= 35)
      cout<<char(st.top() - 10 + 'A');
    else cout<<st.top();
    st.pop();
  }

  return 0;
}
