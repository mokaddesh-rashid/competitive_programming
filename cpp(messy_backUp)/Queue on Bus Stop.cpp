#include<iostream>

using namespace std;

int main()
{
    long long int i,front0=0,rear,n,m,count0=0,x,c,d,e;

    cin>>n>>m;

    long long que[n+1];

    for(i=0;i<n;i++)
    {
        cin>>que[i];
    }

    for(i=0;i<n;i++)
    {
        x=que[i];

        //cout<<x<<' '<<i<<endl;

       if(x<=m)
       {
         //  cout<<"here"<<endl;
         while(x<=m)
        {
            i++;
            x+=que[i];

        }
        if(i!=n)
           i--;
       // cout<<x<<' '<<i<<endl;
        count0++;
       }

       else if(x>m)
       {
           c=x/m;

           if(x%m)
            c++;

           d=x%m;
           x=x%m;

           e=d;
           i++;
          while(x<=m-d)
        {

            d+=que[i];
             i++;


        }
         if(i!=n)
            i--;

        count0+=c;


       }


    }

    cout<<count0+n;


}
