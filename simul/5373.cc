/**
 * 큐빙
 * 5373
 */
#include <iostream>
using namespace std;
int T,N;
char u[3][3];
char d[3][3];
char f[3][3];
char b[3][3];
char l[3][3];
char r[3][3];
void init(){
  u[0][0] = 'w';
  u[0][1] = 'w';
  u[0][2] = 'w';
  u[1][0] = 'w';
  u[1][1] = 'w';
  u[1][2] = 'w';
  u[2][0] = 'w';
  u[2][1] = 'w';
  u[2][2] = 'w';

  d[0][0] = 'y';
  d[0][1] = 'y';
  d[0][2] = 'y';
  d[1][0] = 'y';
  d[1][1] = 'y';
  d[1][2] = 'y';
  d[2][0] = 'y';
  d[2][1] = 'y';
  d[2][2] = 'y';

  f[0][0] = 'r';
  f[0][1] = 'r';
  f[0][2] = 'r';
  f[1][0] = 'r';
  f[1][1] = 'r';
  f[1][2] = 'r';
  f[2][0] = 'r';
  f[2][1] = 'r';
  f[2][2] = 'r';

  b[0][0] = 'o';
  b[0][1] = 'o';
  b[0][2] = 'o';
  b[1][0] = 'o';
  b[1][1] = 'o';
  b[1][2] = 'o';
  b[2][0] = 'o';
  b[2][1] = 'o';
  b[2][2] = 'o';

  l[0][0] = 'g';
  l[0][1] = 'g';
  l[0][2] = 'g';
  l[1][0] = 'g';
  l[1][1] = 'g';
  l[1][2] = 'g';
  l[2][0] = 'g';
  l[2][1] = 'g';
  l[2][2] = 'g';

  r[0][0] = 'b';
  r[0][1] = 'b';
  r[0][2] = 'b';
  r[1][0] = 'b';
  r[1][1] = 'b';
  r[1][2] = 'b';
  r[2][0] = 'b';
  r[2][1] = 'b';
  r[2][2] = 'b';
}
void copy(char from[3][3], char to[3][3]){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      to[i][j] = from[i][j];
    }
  }
}
void transpose(char t[3][3], char dir){
  char temp[3][3];
  copy(t, temp);

  if(dir == '+'){
    t[0][0] = temp[2][0];
    t[0][1] = temp[1][0];
    t[0][2] = temp[0][0];
    t[1][0] = temp[2][1];
    t[1][1] = temp[1][1];
    t[1][2] = temp[0][1];
    t[2][0] = temp[2][2];
    t[2][1] = temp[1][2];
    t[2][2] = temp[0][2];
  }
  else{
    t[0][0] = temp[0][2];
    t[0][1] = temp[1][2];
    t[0][2] = temp[2][2];
    t[1][0] = temp[0][1];
    t[1][1] = temp[1][1];
    t[1][2] = temp[2][1];
    t[2][0] = temp[0][0];
    t[2][1] = temp[1][0];
    t[2][2] = temp[2][0];
  }
}
void rotateFront(char dir){
  char temp[3][3];
  copy(u, temp);
  if(dir == '+'){
    for(int i=0;i<3;i++){
      u[2][i] = l[2-i][2];
      l[2-i][2] = d[0][2-i];
      d[0][2-i] = r[i][0];
      r[i][0] = temp[2][i];
    }
  }
  else{
    for(int i=0;i<3;i++){
      u[2][i] = r[i][0];
      r[i][0] = d[0][2-i];
      d[0][2-i] = l[2-i][2];
      l[2-i][2] = temp[2][i];
    }
  }
  transpose(f,dir);
}
void rotateBack(char dir){
  char temp[3][3];
  copy(u, temp);
  if(dir == '+'){
    for(int i=0;i<3;i++){
      u[0][i] = r[i][2];
      r[i][2] = d[2][2-i];
      d[2][2-i] = l[2-i][0];
      l[2-i][0] = temp[0][i];
    }
  }
  else{
    for(int i=0;i<3;i++){
      u[0][i] = l[2-i][0];
      l[2-i][0] = d[2][2-i];
      d[2][2-i] = r[i][2];
      r[i][2] = temp[0][i];
    }
  }
  transpose(b, dir);
}
void rotateUp(char dir){
  char temp[3][3];
  copy(f, temp);
  if(dir == '+'){
    for(int i=0;i<3;i++){
      f[0][i] = r[0][i];
      r[0][i] = b[0][i];
      b[0][i] = l[0][i];
      l[0][i] = temp[0][i];
    }
  }
  else{
    for(int i=0;i<3;i++){
      f[0][i] = l[0][i];
      l[0][i] = b[0][i];
      b[0][i] = r[0][i];
      r[0][i] = temp[0][i];
    }
  }
  transpose(u, dir);
}
void rotateDown(char dir){
  char temp[3][3];
  copy(f, temp);
  if(dir == '+'){
    for(int i=0;i<3;i++){
      f[2][i] = l[2][i];
      l[2][i] = b[2][i];
      b[2][i] = r[2][i];
      r[2][i] = temp[2][i];
      
    }
  }
  else{
    for(int i=0;i<3;i++){
      f[2][i] = r[2][i];
      r[2][i] = b[2][i];
      b[2][i] = l[2][i];
      l[2][i] = temp[2][i];
    }
  }
  transpose(d, dir);
}
void rotateLeft(char dir){
  char temp[3][3];
  copy(u, temp);
  if(dir == '+'){
    for(int i=0;i<3;i++){
      u[i][0] = b[2-i][2];
      b[2-i][2] = d[i][0];
      d[i][0] = f[i][0];
      f[i][0] = temp[i][0];
    }
  }
  else{
    for(int i=0;i<3;i++){
      u[i][0] = f[i][0];
      f[i][0] = d[i][0];
      d[i][0] = b[2-i][2];
      b[2-i][2] = temp[i][0];
    }
  }
  transpose(l, dir);
}
void rotateRight(char dir){
  char temp[3][3];
  copy(u, temp);
  if(dir == '+'){
    for(int i=0;i<3;i++){
      u[i][2] = f[i][2];
      f[i][2] = d[i][2];
      d[i][2] = b[2-i][0];
      b[2-i][0] = temp[i][2];
    }
  }
  else{
    for(int i=0;i<3;i++){
      u[i][2] = b[2-i][0];
      b[2-i][0] = d[i][2];
      d[i][2] = f[i][2];
      f[i][2] = temp[i][2];
    }
  }
  transpose(r, dir);
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> T;
  while(T--){
    init();
    cin >> N;
    while(N--){
      string s;
      cin >> s;
      switch(s[0]){
        case 'U':
          rotateUp(s[1]);
          break;
        case 'D':
          rotateDown(s[1]);
          break;
        case 'F':
          rotateFront(s[1]);
          break;
        case 'B':
          rotateBack(s[1]);
          break;
        case 'L':
          rotateLeft(s[1]);
          break;
        case 'R':
          rotateRight(s[1]);
          break;
      }
    }
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        cout << u[i][j];
      }
      cout << '\n';
    }
  }

  return 0;
}
