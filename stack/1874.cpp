/**
 * 1874
 */

#include <cstdio>
#include <deque>
#define SIZE 100001

using namespace std;

int n;
int a[SIZE];
deque<char> out; 
deque<int> stack;
int num=1;
int ans_idx;

int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  stack.push_back(num++);
  out.push_back('+');

  while(ans_idx < n){
    if(stack.empty()){
      stack.push_back(num++);
      out.push_back('+');
    }
    else {
      int top = stack.back();
      if(top > a[ans_idx]){
        printf("NO\n");
        return 0;
      }
      else if(top < a[ans_idx]){
        stack.push_back(num++);
        out.push_back('+');
      }
      else{
        ans_idx++;
        stack.pop_back();
        out.push_back('-');
      }
    }
  }

  for(int i=0;i<out.size();i++)
    printf("%c\n",out[i]);

  return 0;
}
