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
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<char,int> pr;

class compare
{
public:
    bool operator()(int x,int y)
    {
        return x>y;
    }
};
string str,ss;
int cnt[100010];
set<pr> ms; set<pr>::iterator it;
set<int,compare> pos; set<int>::iterator ii;
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    pr k;
    int i,j,x,y,n,m,top=0,a,b,c;
    char ch='z';
    cin>>str; ss=str;
    n=str.size();
    ch='z';
    REV(i,n-1,0)
    {
        ch=min(ch,str[i]);
        ss[i]=ch;
    }
    FOR(i,0,n-1)
    {
        if(ss[i]==str[i])
        {
            while(!ms.empty())
            {
                it=ms.begin(); k=*it;
                if(k.F<str[i])
                {
                    while(!pos.empty())
                    {
                        ii=pos.begin(); a=*ii;
                        cout<<str[a]; cnt[a]=1;
                        ms.erase(MK(str[a],a));
                        pos.erase(pos.begin());
                        if(a==k.S) break;
                    }
                }
                else break;
            }
            cout<<str[i]; cnt[i]=1;
        }
        else
        {
            ms.insert(MK(str[i],i));
            pos.insert(i);
        }
    }
    REV(i,n-1,0)
    {
        if(cnt[i]==0) cout<<str[i];
    }
    return 0;
}
