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
#define MAX 500010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

string str, ocr;
int lps[MAX];

void make_lps(string pattern)
{
    int n = pattern.size();

    lps[0] = lps[1] = 0;
    FOR(i,2,n)
    {
        int p = lps[i-1];
        while(true)
        {
            if(pattern[i - 1] == pattern[p])
            {
                lps[i] = p + 1;
                break;
            }

            if(p == 0) break;
            else p = lps[p];
        }
    }

}

int n, m, nex[500005][2], a, b;

int getNexMil(int milse,char ch)
{
    int b = milse, org = milse;
    int cc = ch - '0';

    for(; str[b] != ch; b = lps[b])
            {
                if(nex[b][cc] != -1) return nex[b][cc];
                if(b == 0) {b = -1; break;}
            }

    return nex[org][cc] = b + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(nex, -1);
    int d = 0;

    cin >> ocr; m = ocr.size();
    FOR(i,0,(int)ocr.size() - 1)
    {
        if(ocr[i] == '0') a++;
        else b++;
    }
    cin >> str; n = str.size();
    make_lps( str );

    FOR(i,0,n) nex[i][0] = getNexMil(i, '0');
    FOR(i,0,n) nex[i][1] = getNexMil(i, '1');

    int milse = 0; d = 0;

    while(a || b)
    {
        if((b && nex[milse][1] > nex[milse][0]) || !a)
        {
            b--; milse = nex[milse][1];
            cout << 1;
        }
        else
        {
            a--; milse = nex[milse][0];
            cout << 0;
        }

        if(milse == n) d++;
    }
    cout << endl;

    return 0;
}
