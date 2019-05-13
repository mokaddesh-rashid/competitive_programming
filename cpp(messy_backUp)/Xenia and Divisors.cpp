#include<iostream>

using namespace std;

int main()
{

    int n;

    cin>>n;

    int a=0,b=0,c=0,d=0,x=0,e=0,k,y,z,l,arr[n+1],i;

    for(i=0;i<n;i++)
    {
        cin>>k;

        if(k==1)
            a++;
        else if(k==2)
            b++;
        else if(k==3)
            c++;
        else if(k==4)
            d++;
        else if(k==6)
            e++;
        else
            x=1;
    }

    i=0;
    while(b>0)
    {
       if(a>0)
       {
           arr[i]=1;
           i++;
           a--;
       }
       else
       {
           x=1;
           break;

       }
       if(b>0)
       {
           arr[i]=2;
           i++;
           b--;
       }

       if(d>0)
       {
           arr[i]=4;
           i++;
           d--;
       }
       else if(e>0)
       {
           arr[i]=6;
           i++;
           e--;
       }
       else
       {
           x=1;
           break;

       }


    }
    while(c>0)
    {
       if(a>0)
       {
           arr[i]=1;
           i++;
           a--;
       }
       else
       {
           x=1;
           break;

       }
       if(c>0)
       {
           arr[i]=3;
           i++;
           c--;
       }

       if(e>0)
       {
           arr[i]=6;
           i++;
           e--;
       }
       else
       {
           x=1;
           break;

       }


    }

    if(x==1||a!=0||b!=0||c!=0)
        cout<<-1;
    else
     for(i=0;i<n;i+=3)
        cout<<arr[i]<<' '<<arr[i+1]<<' '<<arr[i+2]<<endl;




}
