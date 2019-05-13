#include<bits/stdc++.h>

using namespace std;

#define REV(i,j,k) for(int i=j; i>=k; i--)
#define FOR(i,j,k) for(int i=j; i<=k; i++)
#define MAX  110


int lps[MAX], n, m ,k;

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

int dp[MAX][MAX][MAX];
string s1, s2, vir;

int rec(int p,int po,int vo)
{
    ///cout << vo << endl;
    if(vo == vir.size()) return -1000;
    if(p == s1.size() || po == s2.size()) return 0;
    if(dp[p][po][vo] != -1) return dp[p][po][vo];

    int temp = -1000;

    if(s1[p] == s2[po])
    {
        int ovo = vo;

            while(ovo)
            {
                if(s1[p] == vir[ovo]) break;
                vo = lps[ovo];
            }
        if(s1[p] == vir[ovo]) temp = max(temp, 1 + rec(p + 1, po + 1, ovo + 1));
        else temp = max(temp, 1 + rec(p + 1, po + 1, 0));
    }
    temp = max(rec(p + 1, po, vo), temp);
    temp = max(temp, rec(p, po + 1, vo));

    return dp[p][po][vo] = temp;
}

void prin(int p,int po,int vo)
{
    ///cout << p << ' ' << po << ' ' << vo << endl;
    if(vo == vir.size()) return;
    if(p == s1.size() || po == s2.size()) return;
    if(s1[p] == s2[po])
    {
        int ovo = vo;

        while(ovo)
        {
            if(s1[p] == vir[ovo]) break;
            vo = lps[ovo];
        }

        cout << s1[p];

        if(s1[p] == vir[ovo] && rec(p, po, vo) == 1 + rec(p + 1, po + 1, ovo + 1))
        {
            prin(p + 1, po + 1, vo + 1);
            return;
        }
        else if(rec(p, po, vo) == 1 + rec(p + 1, po + 1, 0))
        {
            prin(p + 1, po + 1, 0);
            return;
        }
    }
    if(rec(p, po, vo) == rec(p + 1, po, vo))
    {
        prin(p + 1, po, vo);
        return;
    }
    if(rec(p, po, vo) == rec(p, po + 1, vo))
    {
        prin(p, po + 1, vo);
        return;
    }

    return;
}


int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);

    cin >> s1 >> s2 >> vir;

    memset(dp, -1, sizeof(dp));
    make_lps( vir );
    int x = rec(0, 0, 0);
    ///cout << x << endl;

    if(x <= 0) cout << 0 << endl;
    else prin(0, 0, 0);

    return 0;
}
