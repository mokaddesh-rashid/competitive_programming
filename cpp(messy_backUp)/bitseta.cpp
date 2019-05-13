#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define MAX 100010


bitset<MAX> bits[26], use, shit;
string str, chk;

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);

    cin >> str;
    FOR(i,0,(int)str.size()-1)
    {
        int x = str[i] - 'a';
        bits[x][i] = 1;
        use[i] = 1;
    }

    int n, p, ty, l, r, v;
    char ch;

    cin >> n;

    FOR(i,0,n-1)
    {
        cin >> ty;

        if(ty == 1)
        {
            cin >> p >> ch; p--;

            int x = str[p] - 'a';
            bits[x][p] = 0;

            str[p] = ch;
            x = str[p] - 'a';
            bits[x][p] = 1;
        }
        else
        {
            cin >> l >> r >> chk; l--; r--;

            r -= (int)chk.size(); r++;

            v = (r - l) + 1;
            v = (int)str.size() - v;

            shit = use; shit >>= v; shit <<= l;


            FOR(j,0,(int)chk.size()-1)
            {
                int x = chk[j] - 'a';

                shit = shit & (bits[x]>>j);
            }
            cout << shit.count() << endl;
        }
    }

    return 0;
}
