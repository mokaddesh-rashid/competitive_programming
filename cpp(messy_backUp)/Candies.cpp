#include<iostream>


using namespace std;


int main()
{
    int t,o=1;

    cin>>t;

    while(t>0)
    {
        int n;

        cin>>n;

        int x=5,y=-1,a,b,c;

        while(x<n)
        {
           if((n-x)%3==0)
           {
              y=n-x;
              break;
           }
           x+=5;
        }

        cout<<"Case "<<o<<": "<<y<<endl;
        o++;
        t--;
    }
}
