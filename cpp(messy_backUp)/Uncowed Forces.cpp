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

    int arr[11],wa[11],i,j,a,b,c;


    double x,y,z,t=0,s,u;

    for(i=0;i<5;i++)
        cin>>arr[i];

     for(i=0;i<5;i++)
        cin>>wa[i];

    cin >> s >> u;



            x= 500;
            x *= .3;

            y = arr[0];
            y = y/250;
            y = 1 - y;
            y = y*500;
            z = 50* wa[0];
            y = y -z ;

       t += max(x,y);

       //cout << x <<' ' << y<<endl;

            x= 1000;
            x *= .3;

            y = arr[1];
            y = y/250;
            y = 1 - y;
            y = y*1000;
            z = 50* wa[1];
            y = y -z ;

       t += max(x,y);
       //cout << x <<' ' << y<<endl;

            x= 1500;
            x *= .3;

            y = arr[2];
            y = y/250;
            y = 1 - y;
            y = y*1500;
            z = 50* wa[2];
            y = y -z ;

       t += max(x,y);

      // cout << x <<' ' << y<<endl;
            x= 2000;
            x *= .3;

            y = arr[3];
            y = y/250;
            y = 1 - y;
            y = y*2000;
            z = 50* wa[3];
            y = y -z ;

       t += max(x,y);
      // cout << x <<' ' << y<<endl;
            x = 2500;
            x *= .3;

            y = arr[4];
            y = y/250;
            y = 1 - y;
            y = y*2500;
            z = 50* wa[4];
            y = y - z ;

       t += max(x,y);
       //cout << x <<' ' << y<<endl;
       cout<<t+(s*100)-(u*50);










}

