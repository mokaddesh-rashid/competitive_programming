#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define FOR(i,j,k) for(int i=j; i<=k; i++)
#define MAX 100010
#define PB push_back
#define MP make_pair

typedef pair<int,int>PR;

vector<PR> mantis, santa;
vector<int> mid, sid, prin;
int pa[MAX], sPa[MAX], fPa[MAX], cnt[MAX];
int n;

int finPa(int p,int ty = 0)
{
    if(ty) return (p == sPa[p]) ? p : (sPa[p] = finPa(sPa[p], ty));
    else return (p == pa[p]) ? p : (pa[p] = finPa( pa[p] ));
}


int main()
{
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    int l, r, m;
    char ch;

    cin >> n >> m;
    FOR(i,0,m-1)
    {
        cin >> l >> r >> ch;
        if(ch == 'M') mantis.PB( MP(l, r) ), mid.PB( i );
        else if(ch == 'S') santa.PB( MP(l, r) ), sid.PB( i );;
    }
    if(n%2 == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    FOR(i,1,n) pa[i] = sPa[i] = i;

    for(auto x : mantis)
    {
        int r1 = finPa( x.F ), r2 = finPa( x.S );
        if(r1 != r2) pa[r1] = r2;
    }

    int lol = 0, tok = 0;
    for(auto x : santa)
    {
        int r1 = finPa( x.F ), r2 = finPa( x.S );
        if(r1 != r2)
        {
            int s1 = finPa(x.F, 1), s2 = finPa(x.S, 1);
            sPa[s1] = s2;

            pa[r1] = r2;
            cnt[lol] = 1;
            tok++;
        }
        lol++;
    }

    if(tok > (n-1)/2)
    {
        cout << -1 << endl;
        return 0;
    }

    lol = 0;
    for(auto x : santa)
    {
        if(tok == (n-1)/2) break;
        int r1 = finPa( x.F , 1), r2 = finPa( x.S , 1);
        if(r1 != r2)
        {
            sPa[r1] = r2;
            cnt[lol] = 1;
            tok++;
        }
        lol++;
    }

    if(tok != (n-1)/2)
    {
        cout << -1 << endl;
        return 0;
    }

    tok = lol = 0;
    for(auto x : mantis)
    {
        if(tok == (n-1)/2) break;
        int r1 = finPa(x.F, 1), r2 = finPa(x.S , 1);
        if(r1 != r2)
        {
            sPa[r1] = r2;
            prin.PB( mid[lol] + 1 );
            tok++;
        }
        lol++;
    }

    if(tok != (n-1)/2)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << n - 1 << endl;
    FOR(i,0,(int)sid.size()-1)
    {
        if(cnt[i]) prin.PB(sid[i] + 1);///cout << sid[i] + 1 << ' ';
    }
    for(auto x : prin) cout << x << ' ';

    return 0;
}
