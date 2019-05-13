#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define MAX 100010

int lps[MAX], match[MAX], go[MAX];
string text, pattern;

void make_lps(string str)
{
    memset(lps, 0, sizeof(lps));
    int n = str.size();

    FOR(i,2,n)
    {
        int p = lps[i - 1];
        while(true)
        {
            if(str[p] == str[i - 1])
            {
                lps[i] = p + 1;
                break;
            }
            if(p == 0) break;
            else p = lps[p];
        }
    }
    return;
}

void kmp(string text,string pattern)
{
    memset(match, 0, sizeof(match));
    memset(go, -1, sizeof(go));
    make_lps( pattern );

    int n = text.size(), m = pattern.size();

    FOR(i,0,n-1)
    {
        int p = 0;
        if(i) p = match[i - 1];

        while(true)
        {
            if(pattern[p] == text[i])
            {
                match[i] = p + 1;
                break;
            }

            if(p == 0) break;
            p = lps[p];
        }
    }

    REV(i,n-1,0)
    {
        if(match[i] == m) go[(i - m) + 1] = i;
    }

    int p = -1;
    REV(i,n-1,0)
    {
        if(go[i] != -1) p = go[i];
        go[i] = p;
    }

    return;
}

int dp[MAX][2], n, m, M = 1000000007;

int rec(int p,int t)
{
    if(p == n) return t;

    int &temp = dp[p][t];
    if(temp != -1) return temp;

    temp = rec(n, t) + rec(p + 1, t);
    temp %= M;

    if(!t && go[p] != -1) temp += rec(go[p] + 1, 1);
    else if(t) temp += rec(p, 0);
    temp %= M;

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> text >> pattern;
    kmp(text, pattern);

    memset(dp, -1, sizeof(dp));
    n = text.size();

    int prin = rec(0, 0);
    cout << prin << endl;

    return 0;
}
