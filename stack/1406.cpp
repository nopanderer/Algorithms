/**
 * 에디터
 * 1406
 */
#include <cstdio>
#include <stack>
using namespace std;

int main(){
  char s[100001];
  stack<char> st1;
  stack<char> st2;
  int N;
  int tp;
  scanf("%s",s);
  scanf("%d",&N);
  for(int i=0;s[i];i++){
    st1.push(s[i]);
  }
  while(N--){
    char c1,c2;
    scanf(" %c",&c1);
    if(c1 == 'P'){
      scanf(" %c",&c2);
      st1.push(c2);
    }
    else if(c1 == 'L'){
      if(!st1.empty()){
        tp = st1.top();
        st1.pop();
        st2.push(tp);
      }
    }
    else if(c1 == 'D'){
      if(!st2.empty()){
        tp = st2.top();
        st2.pop();
        st1.push(tp);
      }
    }
    else if(c1 == 'B'){
      if(!st1.empty()){
        st1.pop();
      }
    }
  }
  while(!st1.empty()){
    tp = st1.top();
    st1.pop();
    st2.push(tp);
  }
  while(!st2.empty()){
    printf("%c",st2.top());
    st2.pop();
  }
  printf("\n");

  return 0;
}
