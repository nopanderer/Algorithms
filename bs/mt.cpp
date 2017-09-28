#include <iostream>

using namespace std;

int a[102],b[102],sc[102],sp[102],lc[102],lp[102];
int t,n,m;
int s,l;
int money,food,cost;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++) scanf("%d%d%d%d%d%d",&a[i],&b[i],&sc[i],&sp[i],&lc[i],&lp[i]);

    food=1;
    while (true) {
      money=0;
      cost=123456789;
      for (int i = 0; i < n; i++) {
        if (a[i]*food <= b[i]) continue;
        for (l=1;;l++)
          if (a[i]*food <= b[i] + lc[i]*l) { cost = lp[i]*l; break; }
        for (l=l-1;l>=0;l--)
          for (s=1;;s++)
            if (a[i]*food <= b[i] + sc[i]*s + lc[i]*l) {
              cost = min(cost, sp[i]*s + lp[i]*l);
              break;
            }
        money += cost;
      }
      if (money > m) { printf("%d\n",food-1); break; }
      else food++;
    }
  }

  return 0;
}
