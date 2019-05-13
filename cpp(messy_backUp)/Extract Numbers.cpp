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

    int arr[100000+1]={0}, i, j, a=0, b=0, c;

    for(i=0;i<str.size();i++)
    {
        int num = str[i]-48,nnn,k=0;

        if( num > 0 && num<10 && arr[i] == 0 )
        {
            for( j=i; j<str.size(); j++)
            {
                nnn=str[i]-48;

                if(str[j]==','||str[j]==';')
                    break;
                else if(nnn<0||nnn>9)
                    k=1;
            }

            if(k==0)
            {
                if(a!=0)
                    cout<<',';
                a++;
               for( j=i; j<str.size(); j++)
            {


                if(str[j]==','||str[j]==';')
                    {
                        break;

                    }
                else
                    cout << str[j];
                    arr[j]++;
            }

            }
        }

    }
    cout << endl;

    for(i=0;i<str.size();i++)
    {
        if(arr[i]==0 && str[i] != ',' && str[i] != ';'||(b != 0))
        {
            if(arr[i]==0&&ch!=','||ch)
            cout <<  str[i];
            ch=
        }
    }



}

