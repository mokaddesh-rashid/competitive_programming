#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

set<int>ms;
set<int>::iterator it;
int ar[200010], br[200010], ev[200010], odd[200010], ok[200010], chk[200010], cnt[200010];

int main()
{
    ios::sync_with_stdio(false);
    int i, j, x, y, n, m, en, on, a, b, c, p;
    x = y = en = on = 0;
    cin >> n >> m ;
    FOR(i,0,n-1)
    {
        cin >> ar[i];
        chk[i] = br[i] = ar[i];
        if(ar[i]%2==0) x++;
        else y++;
    }
    sort(br,br+n);
    FOR(i,1,min(m,400040))
    {
       p =  lower_bound(br,br+n,i)-br;
       if( br[p] != i )
       {
           if(i%2) odd[on] = i, on++;
           else ev[en] = i, en++;
       }
    }
    on = en = 0;
    FOR(i,0,n-1)
    {
       p = lower_bound(br,br+n,ar[i])-br;
       if(br[p]==br[p+1]&&ok[p]==0) ok[p] = 1;
       else if(br[p]==br[p+1]&&ok[p]==1)
       {
           if(ar[i]%2==0)
           {
               if(x>y) ar[i] = odd[on], on++, x--, y++;
               else ar[i] = ev[en], en++;
           }
           else
           {
               if(y>x) ar[i] = ev[en], en++, x++, y--;
               else ar[i] = odd[on], on++;
           }
       }
    }
    //FOR(i,0,n-1) cout << ar[i] << ' ';
    //cout << endl;
    a = b = 0;
    if(n%2==0)
    {
        FOR(i,0,n-1)
        {
            if(ar[i]%2==1&&y>x)
                ar[i] = ev[en], en++, x++, y--;
            else if(ar[i]%2&&x>y)
                ar[i] = odd[on], on++, x--, y++;

        }
        FOR(i,0,n-1)
        {
            if(ar[i]%2==1&&y>x)
                ar[i] = ev[en], en++, x++, y--;
            else if(ar[i]%2&&x>y)
                ar[i] = odd[on], on++, x--, y++;

        }
        FOR(i,0,n-1)
        {
            if(ar[i]==0) a = 1;
            if(ar[i]!=chk[i]) b++;
        }
    }
    else a = 1;

    if(a==1) cout << -1;
    else
    {
        cout << b << endl;
        FOR(i,0,n-1)
        {
            cout << ar[i] << ' ';
        }
    }
    return 0;

}

