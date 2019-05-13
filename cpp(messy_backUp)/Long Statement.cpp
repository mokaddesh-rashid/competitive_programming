#include<iostream>

using namespace std;


int main()
{
    long long int n,a=0,b=0,c=0,i,x,arr[1111],use[1111],naa[1111]={0},j;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>x;

        if(x==1)
            a++;
        else if(x==2)
            b++;
        else if(x==3)
            c++;
    }
   if(a==n||b==n||c==n)
      cout<<"No";
   else if(n==3&&(a==2||b==2||c==2))
      cout<<"No";
   else if(n==4&&(a==3||b==3||c==3))
      cout<<"No";
    else if(n==5&&(a==4||b==4||c==4))
      cout<<"No";
   else if(n<3)
      cout<<"No";
   else
      cout<<"Yes";







}
