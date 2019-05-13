#include<bits/stdc++.h>

using namespace std;


#define FOR(i,j,k)  for(int i=j;i<=k;i++)
#define NL endl
#define LL long long

int rec(LL v,LL p)
{
    v %= 10000000;
    if(v%1000000 == 0) return v;
    if(p == 0) return v+1;

    return (v%1000000) + rec(v*p, p-1);
}
int main()
{
    ios::sync_with_stdio(false);

    int tc;

    cin>>tc;
    FOR(tt,1,tc)
    {
        LL i, j, n;

        cin>>n;
        cout<<"Case "<<tt<<": "<<rec(n,n-1)%10000<<NL;

    }
}
