/**
 * 트리 순회
 * 1991
 */
#include <cstdio>

int a[26][2];
void preorder(int x){
  if(x == -1) return;
  printf("%c",(char)(x + 'A'));
  preorder(a[x][0]);
  preorder(a[x][1]);
}
void inorder(int x){
  if(x == -1) return;
  inorder(a[x][0]);
  printf("%c",(char)(x + 'A'));
  inorder(a[x][1]);
}
void postorder(int x){
  if(x == -1) return;
  postorder(a[x][0]);
  postorder(a[x][1]);
  printf("%c",(char)(x + 'A'));
}
int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    char n,l,r;
    scanf(" %c %c %c",&n,&l,&r);
    a[n-'A'][0] = (l == '.') ? -1 : l-'A';
    a[n-'A'][1] = (r == '.') ? -1 : r-'A';
  }
  preorder(0);
  printf("\n");
  inorder(0);
  printf("\n");
  postorder(0);
  printf("\n");

  return 0;
}
