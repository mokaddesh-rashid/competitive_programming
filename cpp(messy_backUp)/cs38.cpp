#include<bits/stdc++.h>

using namespace std;

#define MAX 100010
#define FOR(i,j,k) for(int i=j;i<=k;i++)

int ar[MAX], cnt[MAX], can[MAX];
multiset<int>sota;
multiset<int>::iterator it;
map<int,int>mopa;

int main()
{
    ios::sync_with_stdio(false);

    int n, a, b, c = 0, d = MAX, e = 0;

    cin>>n;
    FOR(i,0,n-1) cin>>ar[i];

    FOR(i,0,n-1)
    {
        a = ar[i];
        if(sota.lower_bound(a)!=sota.end())
        {
            it = (sota.lower_bound(a));
            b = *it;

            sota.erase(it);
            if(sota.lower_bound(a) == sota.end()) cnt[mopa[b]]++;
            sota.insert(b);
        }
        else can[i]++, e++;

        sota.insert(ar[i]);
        mopa[a] = i;
    }

    FOR(i,0,n-1)
    {
        b = cnt[i] - can[i];
        c = max(e+b,c);
    }
    cout<<c<<endl;

    return 0;
}
