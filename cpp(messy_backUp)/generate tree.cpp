#include <bits/stdc++.h>

using namespace std;

#define MAX 100010

int N, cnt[MAX]; /// size of the tree
vector<int> permutation;
set<int> sota;

void get_edge() ///for different tree generation at a time need to clear
{
    cout << N << endl;
    int p = 0, S = permutation.size();

    for(auto x : permutation) cnt[x]++;

    for(int i = 1; i <= N; i++)
        if(!cnt[i]) sota.insert( i );

    while(p < S)
    {
        int u = permutation[p]; p++;
        int v = *(sota.begin()); sota.erase( sota.begin() );

        cnt[u]--;
        if(!cnt[u]) sota.insert( u );
        cout << u << ' ' << v << endl;
    }

    int u = *(sota.begin()), v = *(sota.rbegin());
    cout << u << ' ' << v << endl;
    sota.clear();
}

void make_tree(int s)
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    N = s;

    permutation.clear();
    for (int i = 1; i < N - 1; i++)
        permutation.push_back( (rng() % N) + 1 );

    get_edge();/// using permutation it will create a tree
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "w", stdout);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int vao = (rng() % MAX) + 2;
    int sz = min(100000, vao);

    make_tree( sz );/// create a tree
}


