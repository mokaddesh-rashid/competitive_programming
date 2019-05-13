
#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>




using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int i, j, x, y, n, m;


    cin >> n;

    int arr[n+1];

    for( i=0; i<n; i++)
        cin >> arr[i];

    set <int> st ( arr, arr+n);

    set<int>::iterator ii;

   for( ii = st.begin(); ii != st.end(); ii++)
   {
       cout <<<< ' ' ;
   }

    return 0;

}
