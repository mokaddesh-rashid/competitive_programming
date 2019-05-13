#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j; i<=k; i++)
#define MAX 100010

int n, ara[MAX], c;
multiset< int > sota;
vector<pair<int,int> > aho;

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);

    cin >> n;
    FOR(i,0,n-1) cin >> ara[i], c += ara[i];

    if(c%2)
    {
        cout << -1 << endl;
        return 0;
    }

    sort(ara, ara + n);
    FOR(i,0,n-1)
        sota.insert( ara[i] );

    while(!sota.empty())
    {
        if(sota.size() == 1)
        {
            int v = *(sota.begin());
            aho.push_back( make_pair(v, v/2));
            sota.erase( sota.begin() );
        }
        else
        {
            multiset<int>::iterator it = sota.begin();

            int v1 = *it; it++;
            int v2 = *it;
            int v3 = *(sota.rbegin());

            if(v1 == v2)
            {
                sota.erase(  sota.find( v1 )  );
                sota.erase(  sota.find( v2 )  );
            }
            else
            {
                sota.erase( sota.find( v3 ) );
                sota.erase( sota.find( v1 ) );

                if(v3 - v1) sota.insert( v3 - v1 );
                aho.push_back( make_pair(v3, v1) );
            }
        }
    }

    cout << aho.size() << endl;
    for(auto x : aho) cout << x.first << ' ' << x.second << endl;
    return 0;
}

