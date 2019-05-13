#include<iostream>

using namespace std;

int main()
{
    int n,a=0,b=0,c=0,i,x,y;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>x;

        if(i%3==0)
            a+=x;
        else if(i%3==1)
            b+=x;
        else if(i%3==2)
            c+=x;

    }
     if(a>b&&a>c)
            cout<<"chest" ;
     else if(b>a&&b>c)
           cout<<"biceps";
     else
        cout<<"back";
}
