#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    int m,n,a,s,b,d,i;
    char str[111111];

    cin>>str;
    cin>>m;

    s=strlen(str);

    int ar[m+1];


    for(n=0;n<m;n++)
            cin>>ar[n];

    for(n=0;n<m;n++)
        for(i=n;i<m;i++)
    {
        if(ar[n]>ar[i])
        swap(ar[n],ar[i]);
    }


    for(n=0;n<m;n++)
    {
        a=ar[n];
       if(ar[n]==ar[n+1])
       {
       	n++;
       	continue;
       }
       else if(ar[n+1]==ar[n+2])
       {
           n+=2;
       }
        if(n==m-1)
       {

           d=(s-a);
        for(i=a-1;i<d;i++,d--)
        {
            swap(str[i],str[d]);
        }

       }

       else if(n%2==1)
        continue;
       else
       for(i=a-1;i<ar[n+1]-1;i++)
       {
           swap(str[i],str[s-(i+1)]);
       }

    }

    cout<<str;

}
