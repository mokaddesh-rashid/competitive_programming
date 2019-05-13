
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

    set < int > st;

    for( i=0; i<n; i++)
       {
          cin >> x;

          st.insert(x);
       }



    set<int>::iterator ii;

     for( i=0; i<n; i++)
       {
           for( ii= st.begin(); ii!=st.end(); ii++)
               cout << *ii << ' ';
          cout << endl;

          cin >> x;

          st.erase(x);
       }

    return 0;

}
