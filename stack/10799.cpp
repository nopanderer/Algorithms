/**
 * 쇠막대기
 * 10799
 */
#include <cstdio>
#include <stack>

using namespace std;

char s[100001];
int main(){
  stack<int> st;
  scanf("%s",s);
  int sum=0;

  for(int i=0;s[i];i++){
    if(s[i] == '(')
      st.push(i);
    else{
      if(i-st.top() == 1){
        st.pop();
        sum += st.size();
      }
      else{
        st.pop();
        sum += 1;
      }
    } 
  }

  printf("%d",sum);

  return 0;
}
