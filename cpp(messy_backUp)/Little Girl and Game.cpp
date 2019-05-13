#include<iostream>
#include<string>

using namespace std;


int main()
{
    string str;


    cin>>str;

    int x=str.size(),i,a,b,c=0,arr[200]={0};

    for(i=0;i<x;i++)
    {
        a=str[i];
        arr[a]++;
    }

    for(i=0;i<200;i++)
    {
       if(arr[i]%2==1)
        c++;
    }

    if(c==0||c%2==1)
        cout<<"First";
    else
        cout<<"Second";



}
