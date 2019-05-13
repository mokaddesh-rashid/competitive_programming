#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

#define rep(i,n) for(i=1;i<=n;i++)
#define Rep(i,n) for(i=0;i<n;i++)
#define For(i,a,b) for(i=a;i<=b;i++)

#define pb(x) push_back(x)
#define sz(x) x.size()

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define eps 1e-11

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(str) scanf("%s",str)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define NL printf("\n")
#define Max 200005
#define INF 1e9
#define mod 1000000007
#define un(x) x.erase(unique( x.begin() , x.end() ), x.end())

#define FI freopen("in.txt","r",stdin)

#define D(x) cout << #x << " = " << x << endl
#define DD(x,y) cout << #x << " = " << x << "   " << #y << " = " << y << endl
#define DDD(x,y,z) cout << #x << " = " << x << "   " << #y << " = " << y << "   " << #z << " = " << z << endl

typedef long long LL;
typedef unsigned long long ULL;
typedef long double ld;

using namespace std;

int setb(int n,int pos)
{
    return n=n | (1 << pos);
}
int resb(int n,int pos)
{
    return n=n & ~(1 << pos);
}
bool checkb(int n,int pos)
{
    return (bool)(n & (1 << pos));
}

struct name
{
	char str[1005];
};
vector <name> v;
char str[1005];

int main()
{
	freopen("codename.txt","r",stdin);
	freopen("total.txt","w",stdout);
	while( gets(str) )
	{
		name tmp;
		strcpy( tmp.str , str );
		v.pb( tmp );
	}
	fclose(stdin);
	for(int i = 0; i < sz(v); i++)
	{
		freopen(v[i].str,"r",stdin);
		puts(v[i].str);
		puts("--------------------------------------------------");
        while( gets(str) )
        {
			puts(str);
        }
        puts("");
		fclose(stdin);
	}
	return 0;
}

