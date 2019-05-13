#include<bits/stdc++.h>

using namespace std;

#define REV(i,j,k) for(int i=j; i>=k; i--)
#define FOR(i,j,k) for(int i=j; i<=k; i++)
#define MAX  500010


string str, pat;
int lps[MAX], n, m ,k;

void make_lps(string pattern)
{
    int n = pattern.size();

    lps[0] = lps[1] = 0;
    FOR(i,2,n)
    {
        int p = lps[i-1];
        while(true)
        {
            if(pattern[i - 1] == pattern[p])
            {
                lps[i] = p + 1;
                break;
            }

            if(p == 0) break;
            else p = lps[p];
        }
    }

}

void kmpFunction(string text,string pattern)
{
    memset(lps, 0, sizeof(lps));
    int n = text.size(), m = pattern.size();

    make_lps(pattern);

    int p = 0, i = 0;

    while(true)
    {
        if(i == n) break;

        if(p < pattern.size() && text[i] == pattern[p])
        {
            milse[i] = p + 1;
            p++; i++;
        }
        else
        {
            if(p == 0)
            {
                milse[i] = 0;
                i++;
            }
            else p = lps[p];
        }
    }

//  FOR(i,0,n-1)cout<<milse[i]<<' ';
//    cout<<endl;


    return;
}

int main()
{
    ///freopen("in.txt", "r", stdin);
    int x, y, z;

    cin >> str >> pat;
    kmpFunction(str, pat);


    return 0;
}

