#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define MAX 200001
#define ba 3
#define ULL unsigned long long
typedef pair<int,int> PR;

map< pair<PR,int>, int > dp;

string str;
char coco[MAX];
int nex[26][MAX], link[26], n, bits[26][MAX];
ULL has[26][MAX], mul[MAX];


void info()
{
    mul[0] = 1;
    FOR(i,1,n-1) mul[i] = mul[i - 1] * ba;
    FOR(i,0,25)
    {
        ULL c = 0;
        FOR(j,0,n-1)
        {
            c += (bits[i][j] * mul[j]);
            has[i][j] = c;
        }
    }
}

ULL ran(int p,int l,int r)
{
    ULL ret = has[p][r];
    if(r)
    {
        ret -= has[p][l - 1];
        ret /= mul[l - 1];
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    int q, x, y, l1, l2, r1, r2, v, p, d, cv;

    cin >> n >> q;
    cin >> str;


    FOR(i,0,25)
    {
        int p = n;
        REV(j,n-1,0)
        {
            int x = str[j] - 'a';
            if(x == i) p = j, bits[i][j] = 1;;
            nex[i][j] = p;
        }
    }

    FOR(t,1,q)
    {
        int chao = 1;
        memset(link, -1, sizeof(link));
        scanf("%d %d %d", &l1, &l2, &v);
        if(l1 > l2) swap(l1, l2); l1--; l2--;
        r1 = l1 + v; r1--;
        r2 = l2 + v; r2--;

        FOR(i,0,25)
        {
            x = nex[i][l1];
            d = x - l1;
            y = l2 + d;

            if(y <= r2 && x <= r1)
            {
                link[i] = str[y] - 'a';
            }
        }

        FOR(i,0,25)
        {
            if(link[i] != -1)
            {
                if(ran(i, l1, r1) != ran(link[i], l2, r2)) chao = 0;
            }
        }

        if(chao) cout << "YES" << endl;
        else cout << "NO" << endl;


    }

    return 0;
}
