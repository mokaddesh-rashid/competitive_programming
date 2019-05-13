#include<iostream>

using namespace std;

int main()
{
    int i,n,a,b=0,c,k;

    cin>>n>>k;

    int arr[n+1],x=0,y=0,d,f,e,t=0,hm[11111],z=0,pos=0;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        d=max(d,arr[i]);
    }

    while(k>0)
    {


        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                x=0;
                y=0;
                c=0;
                e=0;
            }
            else
            {
                if(arr[x]<arr[i])
                {
                    x=i;
                    c=0;
                }

                else if(arr[x]==arr[i])
                {
                    c++;
                }
                if(arr[y]>arr[i])
                {
                    y=i;
                    e=0;
                }
                else if(arr[y]==arr[i])
                {
                    e++;
                }
            }
        }

        if(arr[x]==arr[y])
           {
                d=0;
                break;
           }
        else if(arr[x]-1<arr[y]+1)
           {
               d=min(d,1);
                break;
           }
        else
        {
           // for(int j=0;j<n;j++)
               // cout<<arr[j]<<' ';
           // cout<<endl<<x+1<<' '<<y+1<<endl;
           // cout<<endl<<arr[x]<<' '<<arr[y]<<endl<<endl;
            t++;
            a=arr[x]-arr[y];

            arr[x]--;
            arr[y]++;


            if(c==0&&e==0)
                d=min(d,arr[x]-arr[y]);
            else if(c==0||e==0)
                d=min(d,arr[x]-arr[y]+1);
            else
                d=min(d,a);
        }
        hm[pos]=x+1;
        pos++;
        hm[pos]=y+1;
        pos++;

        k--;
    }
    cout<<d<<' '<<t<<endl;

   for(i=0;i<pos;i+=2)
        cout<<hm[i]<<' '<<hm[i+1]<<endl;
}
