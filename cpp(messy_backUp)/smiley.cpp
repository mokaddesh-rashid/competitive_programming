#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define NL '\n'
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pi 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 100005

set <int> st;
set <int> ::iterator it;
stack <int> a, b;

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    std::ios_base::sync_with_stdio(0);
    int cases, caseno=0, n, i, j, k, cnt, sum;
    string s;

    cin >> cases;

    while(cases--)
    {
        cin >> s;
        n = s.size();
        st.clear();

        while(!a.empty()) a.pop();
        while(!b.empty()) b.pop();

        FOR(i,0,n-1)
        {
            if(s[i] == '^')
            {
                st.insert(i);
                a.push(i);
            }
            else b.push(i);
        }

        cnt = 0;

        while(!a.empty() && !b.empty())
        {
            i = a.top();

            while(st.find(i) == st.end())
            {
                a.pop();
                if(a.empty()) break;
                i = a.top();
            }

            if(a.empty()) break;

            a.pop();

            while(!b.empty() && b.top() > i) b.pop();

            if(b.empty()) break;

            it = st.end();
            it--;
            st.erase(it);

            if(st.empty()) break;

            it = st.lower_bound(b.top());
            if(it == st.begin()) break;
            it--;

            st.erase(it);
            b.pop();
            cnt++;
        }

        cout << "Case " << ++caseno << ": " << cnt << NL;
    }

    return 0;
}
