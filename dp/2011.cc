/**
 * 암호코드
 * 2011
 */
#include <iostream>
#include <cstring>

using namespace std;

int mod = 1000000;
int d[5001];
char s[5001];
int main(){
  cin>>s;
  int n = strlen(s);

  d[0] = 1;
  d[1] = 1;

  for(int i=2;i<=n;i++){
    if(s[i-1] > '0'){
      d[i] = d[i-1];
      d[i] %= mod;
    }
    int tmp = (s[i-2]-'0')*10 + s[i-1]-'0';
    if(10<=tmp && tmp<=26){
      d[i] += d[i-2];
      d[i] %= mod;
    }
  }
  if(s[0]-'0'==0) cout<<"0"<<endl;
  else cout<<d[n]<<endl;

  return 0;
}
