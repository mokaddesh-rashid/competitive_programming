#include<iostream>
#include<string>


using namespace std;

int main()
{
   int t;

   cin>>t;

   while(t>0)
   {
           string str,st;

    int i,maxx=-1,p=-1,j,a,b,c,n;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>st;
        cin>>a>>b;

        if(maxx<a)
        {
            maxx=a;
            str=st;
            p=b;
        }
        else if(maxx==a&&p>b)
        {
            maxx=a;
            str=st;
            p=b;
        }
    }

    cout<<str<<endl;
    t--;
   }



}
