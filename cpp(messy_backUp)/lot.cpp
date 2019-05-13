///design a post (string) s and a hidden phrase p such that p appears in s as a subsequence exactly n times

#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define MAX 1000010

int dp[MAX], n;
int dao[MAX/10][205];
string str, pat;

int shit(int p,int milse)
{
    if(p == str.size()) return (milse == pat.size());

    int &temp = dao[p][milse];
    if(temp != -1) return temp;

    temp = 0;

    int isSame = 0;
    if(milse < pat.size() && str[p] == pat[milse]) isSame = 1;
    temp = shit(p + 1, milse + isSame);

    if(isSame) temp += shit(p + 1, milse);

    return temp;
}

int rec(int p)
{
    if(p >= n) return p == n;

    int &temp = dp[p];
    if(temp != -1) return temp;

    temp = 0;
    FOR(i,1,2)
        temp = max(temp, rec(p * 2 + i));
    return temp;
}

int chao;
int update(int v)
{
    chao++;
    string newStr = ""; ///cout << str << ' ' << pat << ' ' << v << ' ';

    newStr = pat;
    FOR(i,0,v-1) newStr = newStr + (char)chao;
    FOR(i,pat.size(),str.size() - 1) newStr = newStr + str[i];

    newStr = newStr + (char) chao + (char) chao;
    pat = pat + (char) chao;

    str = newStr; ///cout << str << ' ' << pat << endl;
}

void prin(int p)
{
    if(p >= n) return;

    FOR(i,1,2)
    {
        if(rec(p * 2 + i))
        {
            update( i );
            prin(p * 2 + i);
            return;
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);

    cin >> n;
    pat = "a"; chao = 97;
    memset(dp, -1, sizeof(dp));

    FOR(i,1,n)
    {
        if(rec( i ))
        {
            FOR(j,1,i) str += "a";
            prin( i );
            break;
        }
    }
    cout << str << ' ' << pat << endl;

    memset(dao, -1, sizeof(dao));
    if(n <= 100000 && shit(0, 0) != n) cout << "FUck " << shit(0, 0) << endl;
    return 0;
}
