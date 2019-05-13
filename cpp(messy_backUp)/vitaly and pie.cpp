#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    int n,x=0,y=0,z=0,i,a=0,val,ar[33];

    cin>>n;

    char ch,str[2*n],st[n*2];
    cin>>str;

    for(i=0;i<26;i++)
    {
        ar[i]=0;
    }

    for(i=0;i<2*n-2;i++)
    {
        if(i%2==0)
        {
           val=str[i]-97;
           ar[val]++;

        }
        else if(i%2==1)
        {
            val=str[i]-65;
            if(ar[val]>0)
                ar[val]--;
            else
                x++;
        }

    }

    cout<<x;


}
