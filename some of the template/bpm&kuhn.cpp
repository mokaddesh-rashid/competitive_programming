const int N = 2e6 + 5;

vector<int> g[N];
int mt[N];
int used[N];
int T = 1;

bool try_kuhn(int v)
{
    if (used[v] == T)
        return false;
    used[v] = T;

    for (auto to : g[v]) {
        if (mt[to] == -1) {
            mt[to] = v;
            return true;
        }
    }

    for (auto to : g[v]) {
        if (try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }

    return false;
}



int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    //outf;

    memset(mt, -1, sizeof(mt));
    int match = 0;
    for (int i = 0; i < m; ++i) {
        if (try_kuhn(i))
        {
            ++T;
            ++match;
            if (match == n)
            {
                return 0;
            }
        }
    }

    return 0;
}


