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
#define LL           unsigned long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

string str, f, s;
vector<int> mat[300010];
unordered_map<LL,int> mopa;

int getId(LL val)
{
    if(mopa[val] == 0) mopa[val] = mopa.size();
    return mopa[val];
}

LL retHash(int l,int r)
{
    LL ret = 0, ba = 1;

    FOR(i,l,r)
    {
        LL ch = str[i] - 'a'; ch++;
        ret += (ch * ba); ba *= 31;
    }
    ///FOR(i,l,r) cout << str[i];
    ///cout << ' ' << ret << endl;
    return ret;
}
LL getHash(string str)
{
    LL ret = 0, ba = 1;

    FOR(i,0,(int)str.size()-1)
    {
        LL ch = str[i] - 'a'; ch++;
        ret += (ch * ba); ba *= 31;
    }

    return ret;
}

void add_string(int l,int r)
{
    LL hasho = retHash(l, r);
    int id = getId( hasho );
    ///cout << "added " << id << ' ' << l << endl;
    mat[id].PB( l );
}

unordered_map<LL, int> dp;

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    //outf;

    cin >> str; int n = (int)str.size();
    FOR(i,0,n-1)
        FOR(j,0,3)
            if(i + j < n) add_string(i, i + j);

    int q, a, b;

    cin >> q;
    FOR(pp,0,q-1)
    {
        cin >> f >> s;
        LL fo = getHash( f );
        LL so = getHash( s );

        if(mopa[fo] == 0 || mopa[so] == 0) cout << -1 << endl;
        else
        {
            fo = getId( fo );
            so = getId( so );
            ///cout << "ID  = " << fo << ' ' << so << endl;

            int i, j, prin = str.size();
            i = j = 0;

            ///if(dp[fo * 1000000000 + so] != 0) prin = dp[fo * 1000000000 + so];
            ///else
            {
                while(i < mat[fo].size() && j < mat[so].size())
                {
                    int x = mat[fo][i];
                    int y = mat[so][j];
                    ///cout << x << ' ' << y << endl;

                    a = max(x + f.size(), y + s.size());
                    b = min(x, y);

                    prin = min(prin, a - b);

                    if(x < y) i++;
                    else j++;
                }
                ///dp[fo * 1000000000 + so] = prin;
            }
            cout << prin << endl;
        }
    }


    return 0;
}

