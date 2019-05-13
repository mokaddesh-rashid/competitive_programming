#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int n,m,mid,a,b,x=0,y=0;

    cin>>n>>m;

    a=0;
    while(a<m-1)
    {
        x++;
        a++;
    }
    b=m;

    while(b<n)
    {
        y++;
        b++;
    }



    if(y>x)
        cout<<m+1;
    else if((m-1)%2==1&&(m-1)/2>0)
        cout<<(m-1)/2;
    else
        cout<<(m-1);


   // cout<<a<<endl<<b<<endl;


}

   // if(a<=m)
// mid=n/2;
   //if(mid%2==1)
       // mid++;
