/**
 * 트리의 순회
 * 2263
 */
#include <iostream>
using namespace std;
int n;
int in[100001];
int post[100001];
int pos[100001];
void go(int is,int ie,int ps,int pe){
  if(is == ie){
    cout<<in[is]<<" ";
    return;
  }
  else if(is > ie){
    return;
  }
  int root = post[pe];
  cout<<root<<" ";
  int rtpos = pos[root];

  int lis = is;
  int lie = rtpos - 1;
  int lps = ps;
  int lpe = ps + (lie-lis);
  go(lis,lie,lps,lpe);
  int ris = rtpos + 1;
  int rie = ie;
  int rps = lpe + 1; 
  int rpe = pe - 1;
  go(ris,rie,rps,rpe);
}
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>in[i];
    pos[in[i]] = i;
  }
  for(int i=0;i<n;i++){
    cin>>post[i];
  }
  go(0,n-1,0,n-1);

  return 0;
}

