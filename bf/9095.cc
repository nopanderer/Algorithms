/**
 * 1,2,3 더하기
 * 9095
 */
#include <iostream>
using namespace std;
int T,n,ans;
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin>>T;
  while(T--){
    ans = 0;
    cin>>n;
    for(int i1=1;i1<=3;i1++){
      if(i1 == n) ans++;
      for(int i2=1;i2<=3;i2++){
        if(i1+i2 == n) ans++;
        for(int i3=1;i3<=3;i3++){
          if(i1+i2+i3 == n) ans++;
          for(int i4=1;i4<=3;i4++){
            if(i1+i2+i3+i4 == n) ans++;
            for(int i5=1;i5<=3;i5++){
              if(i1+i2+i3+i4+i5 == n) ans++;
              for(int i6=1;i6<=3;i6++){
                if(i1+i2+i3+i4+i5+i6 == n) ans++;
                for(int i7=1;i7<=3;i7++){
                  if(i1+i2+i3+i4+i5+i6+i7 == n) ans++;
                  for(int i8=1;i8<=3;i8++){
                    if(i1+i2+i3+i4+i5+i6+i7+i8 == n) ans++;
                    for(int i9=1;i9<=3;i9++){
                      if(i1+i2+i3+i4+i5+i6+i7+i8+i9 == n) ans++;
                      for(int i10=1;i10<=3;i10++){
                        if(i1+i2+i3+i4+i5+i6+i7+i8+i9+i10 == n) ans++;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}
