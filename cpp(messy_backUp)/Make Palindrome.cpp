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

    string str;

    cin >> str;

    int arr[29]={0}, i, j, a, b, c, x, y, p, re[str.size()], l=0, minn=111,con=0;

    for( i=0; i<str.size(); i++)
    {
        a = str[i]-97;
        arr[a]++;
        minn = min(a,minn);
    }


    x = str.size()/2;

    i = 0;
    p = 0;

    while(i < x && p < 26)
    {
        if(arr[p] > 0)
        {
            while(arr[p]/2 > 0 && i < x)
            {
                re[l]=p;
                l++;
                arr[p]-=2;
                i++;

            }


        }

        p++;
    }



    while (i < x)
    {
        for ( j=0; j<26; j++)
    {
        if(arr[j] > 0 && i < x)
        {

                re[l]=j;
                l++;
                arr[j]--;
                i++;
                con++;


        }

    }
    }
    sort(re,re+l);



        x= str.size()/2;

    for(j=0;j<l;j++)
    {
        char ch=re[j]+97;
        cout<<ch;
    }


    if(str.size()%2)
    {
        for ( j=0; j<26; j++)
    {
        if(arr[j] > 0)
        {
                char ch =j+97;
                cout << ch;
                 break;


        }

    }
    }




        x= str.size()/2;

    for(i=x-1;i>=0;i--)
    {
        char ch=re[i]+97;
        cout<<ch;
    }


   // cout<<endl<<con;





}

