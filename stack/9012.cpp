/**
 * 9012
 */

#include <cstdio>
#include <deque>

using namespace std;

int t;
char s[51];

int main(){
  scanf("%d",&t);
  while(t--){
    deque<int> st;
    scanf("%s",s);
    for(int i=0;s[i];i++){
      if(s[i] == '(')
        st.push_back(s[i]);
      else if(s[i] == ')'){
        if(st.empty()){
          st.push_back('a');
          break;
        }
        else if(st.back() == '(')
          st.pop_back();
      }
    }
    if(st.empty())
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
