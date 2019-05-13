#include<bits/stdc++.h>

using namespace std;

#define MAX 110
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
int dp[MAX][MAX][MAX];

int gcd(int x,int y)
{
    int c=__gcd(x,y);
    return (x==0||y==0) ? max(x,y):c;
}
int rec(int p,int v,int g)
{
    if(v==0&&g==1)return 1;
    if((v<0)||(p>v))return 0;
    if(dp[p][v][g]!=-1)return dp[p][v][g];

    return dp[p][v][g]=rec(p+1,v,g)+rec(p,v-p,gcd(p,g));
}

int main()
{
    int n;
    mem(dp,-1);
    FOR(i,1,20)
    {
        ///mem(dp,-1);
        n=i;
        cout<<rec(1,n,0)<<endl;
    }

}
