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

    int t,n;

    cin>>t;

    while( t > 0)
    {
        cin>>n;

        cout<<((n*n)/2)+1<<'/'<<n*n<<endl;
        t--;
    }



}


