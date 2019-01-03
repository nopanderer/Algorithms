/**
 * Base Conversion
 * 11576
 */
#include <iostream>
using namespace std;

int a[26];
void go(int dec, int B){
  if(dec == 0) return;
  go(dec/B,B);
  cout<<dec%B<<" ";
}
int main(){
  int A,B,m;
  int dec=0;
  cin>>A>>B>>m;
  for(int i=0;i<m;i++){
    cin>>a[i];
    dec = dec*A + a[i];
  }
  go(dec,B);

  return 0;
}
