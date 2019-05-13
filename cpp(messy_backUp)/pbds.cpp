
#include<bits/stdc++.h>

using namespace std;

#define PB push_back
#define MEM(n, val) memset(n, val, sizeof(n))
#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = k; i >= j; i--)


#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

template<typename T> using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class data  {
public:
    int num;
    data()  {}
    data(int pp)    {
        num = pp;
    }
    bool operator < (const data& b) const   {
        return num < b.num;
    }
};

/**
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/



ordered_set<data> yo;
int main()  {
    std::ios_base::sync_with_stdio(false);

    ///ordered_set yo;
    /**
    yo.insert(1);
    yo.insert(2);
    yo.insert(4);
    yo.insert(8);
    yo.insert(16);
    */

    yo.insert(data(1));
    yo.insert(data(2));
    yo.insert(data(4));
    yo.insert(data(8));
    yo.insert(data(16));

    ///returns an iterator to the k-th largest element (counting from zero)
    auto it = yo.find_by_order(4);
    cout << (*it).num << "\n";
    cout << (*yo.find_by_order(4)).num << "\n";


    ///the number of items in a set that are strictly smaller than our item
    cout << yo.order_of_key(data(10)) << "\n";
    return 0;
}
