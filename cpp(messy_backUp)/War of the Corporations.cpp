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

    long long int i, j, x=0, y, n, m;

    string s1, s2;

    cin >> s1 >> s2;

     int position = s1.find(s2);


     while(position != string::npos)
     {
		s1.replace(position,s2.size(),"#");
		position = s1.find(s2,position+1);
		x++;
     }

     cout<<x<<endl;

    return 0;

}

