#include <bits/stdc++.h>
#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

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
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

string str;
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i, j, x=0, y, n, m;
    cin>>n;
    FOR(i,1,n)
    {
        cin>>str;
        if(str=="Tetrahedron") x+=4;
        else if(str=="Cube") x+=6;
        else if(str=="Octahedron") x+=8;
        else if(str=="Dodecahedron") x+=12;
        else if(str=="Icosahedron") x+=20;
    }
    cout<<x<<NL;
    return 0;
}


