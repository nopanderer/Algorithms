/**
 * 진법 변환
 * 2745
 */
#include <iostream>
#include <string>

using namespace std;

int main(){
  string n;
  int b;
  long long result=0;
  cin>>n>>b;

  for(int i=0;i<n.size();i++){
    if('0' <= n[i] && n[i] <= '9')
      result = result*b + (n[i] - '0');
    else
      result = result*b + (n[i]-'A'+10);
  }

  cout<<result<<endl;

  return 0;
}
