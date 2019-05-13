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
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

string str;
multiset<int>sota;
int n;

int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        int i,j,m,cnt=0,a,b=0,v=0;
        char ch;

        cin>>str;
        n=str.size();

        while(n>0)
        {
            if(str[0]==str[n-1])cnt++;
            else break;
            n--;
        }

        FOR(i,0,n-1)
        {
           if(i==0) cnt++;
           else
           {
               ///if(cnt!=2)v=1;
               if(str[i]==str[i-1])cnt++;
               else
               {
                   if(cnt!=2)v=1;
                  //// cout<<cnt<<NL;
                   sota.insert(cnt);
                   while(sota.size()>2)
                   {
                       sota.erase(sota.begin());
                   }
                   cnt=1;
                  /// v++;
               }
           }
        }
        if(cnt!=2) v=1;
        sota.insert(cnt);
        while(sota.size()>2)
        {
           sota.erase(sota.begin());
        }

        a=*(sota.begin()); sota.erase(sota.begin());
        if(!sota.empty()) b=*(sota.begin());
         ///   cout<<a<<' '<<b<<NL;

       /// cout<<"Case "<<tt<<": ";
       /// cout<<a<<' '<<b<<' '<<v<<NL;
        if(b==0)cout<<max(1,(int)str.size()-1)<<NL;
        else if(str.size()==1)cout<<1<<NL;
        else if(str.size()==2&&str[0]==str[1])cout<<1<<NL;
        else if(str.size()==2)cout<<2<<NL;
        else if(str.size()==3)cout<<2<<NL;
        else if(b==1&&a==1)cout<<3<<NL;
        else if(b==2&&a==1)cout<<2<<NL;
        else if(v==0)cout<<3<<NL;
        else if(b!=0) cout<<max(1,max(a,b/2))<<NL;
        else cout<<max(1,a-1)<<NL;

        while(!sota.empty())
        {
           sota.erase(sota.begin());
        }

    }


    return 0;
}



