/**
 * 최소공배수
 * 1934
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
  int t,a,b,g;
  cin>>t;
  while(t--){
    cin>>a>>b;
    cout<<(long long)(a*b)/gcd(a,b)<<endl;
  }

  return 0;
}
