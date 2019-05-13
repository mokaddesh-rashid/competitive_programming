#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 1000010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int bit[MAX], n, k;
void update(int i,int val)
{
	while(i<=n)
	{
		bit[i]+=val;
		i=i+(i&(-i));
	}
}
int query(int i)
{
	int ret=0;
	while(i)
	{
		ret+=bit[i];
		i=i-(i&(-i));
	}
	return ret;
}

int ar[MAX], pos[MAX], cnt[MAX];


int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;

    int a;

    cin >> n >> k;
    FOR(i,1,n) cin >> ar[i];
    FOR(i,1,k)
    {
        cin >> a;
        cnt[a]++;
    }

    FOR(i,1,n) pos[i] = i;
    sort(pos + 1, pos + n + 1, [](int a,int b)
         {
             return ar[a] < ar[b];

         });

    int st, en, mid, l, r;
    LL prin = 0;
    int ans;

    FOR(i,1,n)
    {
        int p = pos[i];

        if(!cnt[ ar[p] ])
        {
            st = p; en = n;
            while(st <= en)
            {
                mid = (st + en)>>1;
                l = query(mid) - query(p - 1);
                if(l) en = mid - 1;
                else st = mid + 1;
            }
            prin += (st - p);
            cout << p << ' ' << ar[p] <<  ' ' << st - 1 << ' ';

            st = 1; en = p; ans = p;
            while(st <= en)
            {
                mid = (st + en)>>1;
                l = query(p) - query(mid - 1);
                if(l) st = mid + 1;
                else en = mid - 1, ans = min(ans, mid);
            }
            prin += (p - ans);
            cout << ans << endl;
        }

        update(p, 1);

    }

    cout << prin << endl;

    return 0;
}
