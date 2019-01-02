/**
 * 최대공약수와 최소공배수
 * 2609
 */
#include <iostream>

using namespace std;

int gcd(int a, int b){
  while(b != 0){
    int r = a%b;
    a = b;
    b = r;
  }

  return a;
}
int main(){
  int a,b;
  int g;
  cin>>a>>b;
  g = gcd(a,b);
  cout<<g<<endl;
  cout<<(a*b)/g<<endl;

  return 0;
}
