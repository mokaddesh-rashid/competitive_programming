#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s1[3],s2[3],ar[5];

    int a,b,c,d,i,n,x,br[5];

    for(i=0;i<4;i++)
       {
            cin>>ar[i];
            if(i>1)
            {
                s2[i%2]=ar[i];
            }
            else
                s1[i]=ar[i];

       }

    for(i=0;i<4;i++)
        for(n=0;n<4;n++)
        {
            if(ar[n]>ar[i])
                swap(ar[n],ar[i]);
        }

    if(ar[0]!=ar[1]||ar[2]!=ar[3])
        cout<<-1;
    if(s1.compare(ar[0]+ar[0])!=0&&s2.compare(ar[0]+ar[0]))
        cout<<ar[0]<<ar[0];


}
