/**
 * 국영수
 * 10825
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student{
  string name;
  int kor,eng,math;
};
bool cmp(const Student &s1, const Student &s2){
  if(s1.kor == s2.kor){
    if(s1.eng == s2.eng){
      if(s1.math == s2.math){
        return s1.name < s2.name;
      }
      else{
        return s1.math > s2.math;
      }
    }
    else{
      return s1.eng < s2.eng;
    }
  }
  else{
    return s1.kor > s2.kor;
  }
}
int main(){
  Student s[100001];
  int N;
  cin>>N;

  for(int i=0;i<N;i++){
    cin>>s[i].name>>s[i].kor>>s[i].eng>>s[i].math;
  }

  sort(s,s+N,cmp);

  for(int i=0;i<N;i++){
    cout<<s[i].name<<'\n';
  }

  return 0;
}
