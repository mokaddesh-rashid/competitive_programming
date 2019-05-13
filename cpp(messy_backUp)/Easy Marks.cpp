#include<iostream>


using namespace std;


int main()
{
    int t,o=1;

    cin>>t;

    while(t>0)
    {
        int n,av;

        cin>>n>>av;

        int x=(n+1)*av,y=0,a,b,c;

        for(int i=0;i<n;i++)
        {
            cin>>a;
            y+=a;
        }

        cout<<"Case "<<o<<": "<<x-y<<endl;
        o++;
        t--;
    }
}
