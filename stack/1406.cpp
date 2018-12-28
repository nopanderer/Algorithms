/**
 * 에디터
 * 1406
 */
#include <cstdio>
#include <stack>

using namespace std;

int main(){
  char s[600001];
  stack<char> ls;
  stack<char> rs;
  int tmp;
  int n;

  scanf("%s",s);
  for(int i=0;s[i];i++)
    ls.push(s[i]);

  scanf("%d",&n);
  while(n--){
    char x,y;
    scanf("\n%c",&x);
    switch(x){
      case 'L':
        if(!ls.empty()){
          tmp = ls.top();
          ls.pop();
          rs.push(tmp);
        }
        break;
      case 'D':
        if(!rs.empty()){
          tmp = rs.top();
          rs.pop();
          ls.push(tmp);
        }
        break;
      case 'B':
        if(!ls.empty())
          ls.pop();
        break;
      case 'P':
        scanf(" %c",&y);
        ls.push(y);
        break;
    }
  }

  while(!ls.empty()){
    tmp = ls.top();
    ls.pop();
    rs.push(tmp);
  }
  while(!rs.empty()){
    printf("%c",rs.top());
    rs.pop();
  }


  return 0;
}
