#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int n;

    cin>>n;

    string num;
    int right[n+1],wrong[n+1],minn=0,maxx=0;

    int a,b,check=0,r=0,w=0,i;

     cin>>num;

    for(i=0;i<2*n;i++)
        {
            a=num[i]-48;
            if(i<n)
            {
                right[r]=a;
                r++;


            }
            else
            {
                wrong[w]=a;
                w++;

            }
        }

    sort(right,right+n);
    sort(wrong,wrong+n);

    for(i=0;i<n;i++)
    {
        if(right[i]>wrong[i])
            maxx++;
        else if(right[i]<wrong[i])
            minn++;
        else
        {
            minn=1;
            maxx=1;
        }
    }

    if(maxx==0||minn==0)
        cout<<"YES";
    else
        cout<<"NO";



}
