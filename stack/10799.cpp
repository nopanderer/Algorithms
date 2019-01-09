/**
 * 쇠막대기
 * 10799
 */
#include <cstdio>
#include <stack>
using namespace std;

int main(){
  char s[100001];
  stack<int> st;
  scanf("%s",s);
  int ans=0;
  for(int i=0;s[i];i++){
    if(s[i] == '('){
      st.push(s[i]);
    }
    else if(s[i] == ')'){
      st.pop();
      if(s[i-1] == '('){
        ans += st.size();
      }
      else{
        ans += 1;
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}
