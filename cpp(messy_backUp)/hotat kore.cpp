#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define ROF(i,j,k) for(int i=j;i>=k;i--)
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define MAX 300010

LL ara[MAX], n, k, cnt = 0;
LL por[MAX], cul[MAX];
LL st, en, mid, val, v, soso, vovo, prin;

int main()
{
    LL c = 0;
    sff(n, k);
    FOR(i,0,n-1) sf(ara[i]), c += ara[i], cul[i] = c;

    LL p = n;
    ///FOR(i,0,n-1) por[i] = n;
    ROF(i,n-1,0)
    {
        por[i] = p;
        if(ara[i] != 1) p = i;
    }


    FOR(i,0,n-1)
    {
        val = 1;
        for(int j=i; j<n; j = por[j])
        {
            LL pre = val;
            val *= ara[j];

            if(!pre) break;
            if(val % pre || val % ara[j]) break;

            st = j; en = por[j] - 1;
            v = 0;

            while(st <= en)
            {
                mid = (st + en)>>1;

                soso = cul[mid];
                if(i) soso -= cul[i - 1];
                vovo = soso * k;

               /// if(!soso && !k) break;
                if(vovo <= val && vovo % soso == 0 && vovo % k == 0)
                {
                    st = mid + 1;
                    if(vovo == val)
                    {
                        v = 1;
                        break;
                    }
                }
                else en = mid - 1;
            }

            prin += v;
        }
    }

    printf("%lld", prin);
    return 0;
}

