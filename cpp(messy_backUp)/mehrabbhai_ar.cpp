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


    int t,c=1;

    cin >> t;

    while ( t > 0)
    {
         //IV=4, IX=9, XL=40, XC=90, CD=400, CM=900

    string str;

    cin >> str;

    int i , j, a, b, d, x=0;


    for ( i=0; i<str.size() ; i++)
    {

        if(str[i]=='I'&&str[i+1]=='V')
        {

            x += 4;
            i++;
        }
        else if(str[i]=='I'&&str[i+1]=='X')
        {

            x += 9;
            i++;
        }
        else if(str[i]=='X'&&str[i+1]=='L')
        {

            x += 40;
            i++;
        }
        else if(str[i]=='X'&&str[i+1]=='C')
        {

            x += 90;
            i++;
        }

        else if(str[i]=='C'&&str[i+1]=='D')
        {

            x += 400;
            i++;
        }

        else if(str[i]=='C'&&str[i+1]=='M')
        {

            x += 900;
            i++;

        }
        else if(str[i]=='I')
        {

            x += 1;

        }
         else if(str[i]=='V')
        {

            x += 5;

        }
         else if(str[i]=='X')
        {

            x += 10;

        }
         else if(str[i]=='L')
        {

            x += 50;

        }
         else if(str[i]=='C')
        {

            x += 100;

        }
         else if(str[i]=='D')
        {

            x += 500;

        }
         else if(str[i]=='M')
        {

            x += 1000;

        }            //I=1,V=5, X=10, L=50, C=100, D=500, M=1000


    }

     cout <<"case "<< c << ": " << x <<endl;

     t--;
     c++;
    }



}

