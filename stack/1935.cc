/**
 * 후위표기식2
 * 1935
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
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
  int n;
  char s[300];
  double a[26];
  stack<double> st;
  scanf("%d",&n);
  scanf("%s",s);
  for(int i=0;i<n;i++){
    scanf("%lf",&a[i]);
  }
  int size = strlen(s);
  for(int i=0;i<size;i++){
    if('A' <= s[i] && s[i] <= 'Z'){
      st.push(a[s[i]-'A']);
    }
    else{
      double b = st.top();
      st.pop();
      double a = st.top();
      st.pop();
      if(s[i] == '+'){
        st.push(a+b);
      }
      else if(s[i] == '-'){
        st.push(a-b);
      }
      else if(s[i] == '*'){
        st.push(a*b);
      }
      else{
        st.push(a/b);
      }
    }
  }
  printf("%.2lf\n",st.top());

  return 0;
}
