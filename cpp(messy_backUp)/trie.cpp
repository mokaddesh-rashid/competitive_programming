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
#define MAX 100010
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,string> pr;

struct node
{
    int v,a,b;
    node *next[30];
    node()
    {
        FOR(i,0,25) next[i]=NULL;
        v=0;
    }
};
node *Root;
string str[MAX];
char ch;


void in(string str)
{
    int x=0,y,a,b,n=str.size();
    node *t=Root;

    while(x<n)
    {
        a=str[x]-'A';
        if(t->next[a]==NULL) t->next[a]=new node();
        t=t->next[a];
        x++;
        if(x==n) t->v=1;
    }
}

int ase(string str)
{
    int x=0,y,a,b,n=str.size();
    node *t=Root;

    while(x<n)
    {
        a=str[x]-'A';
        if(t->next[a]==NULL) return -1;
        t=t->next[a];
        x++;
    }
    return 0;
}

int cha[12][29];

int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    int tc;

    cin >> tc;

    FOR(tt,1,tc)
    {
        Root=new node();
        mem(cha, 0);

        int n, l;

        cin >> n >> l;
        FOR(i,0,n-1)
        {
            cin >> str[i];
            in( str[i] );
            FOR(j,0,(int)str[i].size()-1)
            {
                int p = str[i][j] - 'A';
                cha[j][p] = 1;
                //cout << j << ' ' << p << endl;
            }
        }
//        FOR(i,0,l-1)
//        {
//            FOR(j,0,25) cout << cha[i][j] << ' ';
//            cout << endl;
//        }

        string prin = "-";
        FOR(i,0,n-1)
        {
            string chk = str[i];
            FOR(j,0,l-1)
            {
               FOR(k,0,25)
               {
                   if(cha[j][k])
                   {
                       char ch = 'A' + k;
                       char org = chk[j];

                       chk[j] = ch;
                       //cout << chk << ' ' << ase( chk ) << endl;
                       if(ase( chk ) == -1)
                       {
                           prin = chk;
                       }

                       chk[j] = org;
                   }
               }
            }
           /// cout << endl << endl << endl;
        }

        cout << "Case #" << tt <<": " << prin << endl;
    }


    return 0;
}
