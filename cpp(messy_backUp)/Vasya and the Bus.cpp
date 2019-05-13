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

    int n, m, minn, maxx;

    cin >> n>> m;

    maxx=n+max(m-1,0);

    minn = n + max(m-n,0);

    if(n==0&&m!=0)
        cout << "Impossible";

    else
        cout << minn <<' ' << maxx;





}

