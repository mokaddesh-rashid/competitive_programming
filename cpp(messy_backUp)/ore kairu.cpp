#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define PB push_back
#define F first
#define S second
#define MP make_pair

typedef pair<int,int> pii;
typedef long long LL;

const int MAX = 100010;

string str;
int n, a, b;

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    cin >> n;
    cin >> str;

    int a = 0,  b = 0;
    FOR(i,0,n-1)
    {
        if(str[i] == '-') a--;
        else a++;

        b = min(a, b);
    }

    a = b * -1;
    FOR(i,0,n-1)
    {
        if(str[i] == '-') a--;
        else a++;
    }

    cout << a << endl;
    return 0;
}
