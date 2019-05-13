#include<iostream>

using namespace std;

int main()
{
    int x=0;

   // cin>>t;

    //while(t>0)
    {
        int num[10]={0};

    int n;

    cin>>n;




    while(n>0)
    {
        int a=n;
        while(a>0)
        {
            num[a%10]++;
            a/=10;
        }
        n--;
    }

    for(int i=0;i<=9;i++)
        x+=num[i];
    }

    cout<<x;
   // cout<<endl;
   // t--;
}
