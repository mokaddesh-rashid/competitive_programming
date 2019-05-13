#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define PB push_back
#define F first
#define S second
#define MAX 14905
#define MP make_pair
typedef pair<int,int> pii;
typedef pair<char,char> pcc;

string str;
map<pcc,int> mopa;
map<int,pcc> rev;

int getId(pcc v)
{
    if(mopa[v] == 0)
    {
        mopa[v] = mopa.size();
        rev[ mopa[v] ] = v;
    }

    return mopa[v];
}

pcc ulta(int v)
{
    return rev[v];
}

vector<int> mat[MAX];
int in[MAX], out[MAX], mn;

int isEuler()
{
    int st, en;

    st = en = -1;

    FOR(i,0,mn)
    {
        ///cout << in[i] << ' ' << out[i] << endl;
        if(in[i] == out[i]) continue;
        else if(out[i] - in[i] == 1 && st == -1) st = i;
        else if(in[i] - out[i] == 1 && en == -1) en = i;
        else return -1;
    }

    if(st == -1 && en == -1) return 1;
    else if(st != -1 && en != -1) return st;
    else return -1;
}

int show[300010], pos;
void dfs(int p)
{
    while(out[p])
    {
        out[p]--;
        dfs( mat[p][ out[p] ] );
    }

    show[pos++] = p;

}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int n, u, v;

    cin >> n;
    FOR(i,0,n-1)
    {
        cin >> str;
        u = getId(MP(str[0], str[1] ));
        v = getId(MP(str[1], str[2] ));

        mat[u].PB( v ); mn = max(mn, max(u, v));
        out[u]++; in[v]++;
        ///cout << u << ' ' << v << endl;
    }

    int can = isEuler();
    if(can == -1) cout << "NO" << endl;
    else
    {
        dfs( can );
        reverse(show, show + pos);
        if(pos != n + 1)
        {
            cout << "NO";
            return 0;
        }

        cout << "YES" << endl;
        FOR(i,0,pos-1)
        {
            pcc v = rev[ show[i] ];

            if(!i) cout << v.F << v.S;
            else cout << v.S;
        }
    }

    return 0;
}


