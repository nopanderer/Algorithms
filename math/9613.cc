/**
 * GCD 합
 * 9613
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
  int a[101];
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    long long sum=0;
    for(int i=0;i<n;i++)
      cin>>a[i];
    for(int i=0;i<n-1;i++)
      for(int j=i+1;j<n;j++)
        sum += gcd(a[i],a[j]);

    cout<<sum<<endl;
  }

  return 0;
}
