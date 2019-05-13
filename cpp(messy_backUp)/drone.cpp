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
#define mod          998244353
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


struct node
{
    int v;
    node *next[26];
    node()
    {
        FOR(i,0,25) next[i]=NULL;
        v=0;
    }
};
node *org, *rev;

void in(string str,node *Root)
{
    int x=0,y,a,b,n=str.size();
    node *t=Root;

    while(x<n)
    {
        a=str[x]-'a';
        if(t->next[a]==NULL) t->next[a]=new node();
        t=t->next[a];
        x++;
        if(x==n) t->v+=1;
    }
}

int match(string str,int n, node *Root)
{
    ///cout << str << ' ' << n << endl;
    int x=0;
    node *t=Root;

    while(x<n)
    {
        int a=str[x]-'a';
        if(t->next[a]==NULL) return 0;
        t=t->next[a];
        x++;
    }
    return  t->v;
}

string str[MAX];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;

    cin >> tc;
    FOR(tt,1,tc)
    {
        int n;
        LL prin = 0;

        cin >> n;
        FOR(i,0,n-1) cin >> str[i];
        sort(str, str + n, [](string x,string y){return x.size() < y.size();} );

        org = new node(); rev = new node();
        FOR(p,0,n-1)
        {
            string use = str[p];
            reverse(use.begin(), use.end());


                REV(i,str[p].size(), 0)
                {
                    if(dudu == bobo) prin += match(str[p], i, rev);
                }

                REV(i,use.size(), 0)
                {
                    if(dudu == bobo) prin += match(use, i, org);
                }
            }
            else
            {
                FOR(i,0,n-1)
                {
                    if(i == p) continue;
                    dudu = str[i] + str[p];
                    bobo = dudu;
                    reverse(dudu.begin(), dudu.end());
                    if(dudu == bobo) prin++;

                    dudu = str[p] + str[i];
                    bobo = dudu;
                    reverse(dudu.begin(), dudu.end());
                    if(dudu == bobo) prin++;

                }
            }

            in(str[p], org); in(use, rev);
        }

        cout << prin << endl;
    }
    return 0;
}
