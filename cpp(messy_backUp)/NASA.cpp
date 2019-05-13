#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n,m;

    cin >> n;

    string str[111],  ans[111], sss;

    char ch;

    int i, j, a, b, x, l;

    for(i=0;i<n;i++)
       {
        cin >> str[i];
        cin >> ch;
        cin >> ans[i];
       }


    cin >> m;

    while( m-- )
    {
        cin >> l;

        for( i=0; i<l; i++)
        {
            cin >> sss;

            for( j=0; j<n; j++)
            {
                if( sss==str[j])
                    cout<< ans[j] <<' ';
            }


        }

        cout << endl;
    }


}

