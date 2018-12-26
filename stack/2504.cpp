/**
 * 2504
 */

#include <cstdio>
#include <deque>

using namespace std;

deque<int> st;
char s[31];

int main(){
  scanf("%s",s);
  for(int i=0;s[i];i++){
    if(s[i] == '('){
      st.push_back(s[i]);
    }
    else if(s[i] == '['){
      st.push_back(s[i]);
    }
    else if(s[i] == ')'){
      if(st.empty()){
        printf("0\n");
        return 0;
      }
      else{
        int top = st.back();
        st.pop_back();
        switch(top){
          case '(':
            st.push_back(2);
            break;
          case '[':
          case ']':
          case ')':
            printf("0\n");
            return 0;
          default:
            st.pop_back();
            st.push_back(top*2);
        }
      }
    }
    else if(s[i] == ']'){
      if(st.empty()){
        printf("0\n");
        return 0;
      }
      else{
        int top = st.back();
        st.pop_back();
        switch(top){
          case '[':
            st.push_back(3);
            break;
          case '(':
          case ')':
          case ']':
            printf("0\n");
            return 0;
          default:
            st.pop_back();
            st.push_back(top*3);
        }
      }
    }
  }
  for(int i=0;i<st.size();i++)
    printf("%d ",st[i]);
  printf("\n");

  return 0;
}
