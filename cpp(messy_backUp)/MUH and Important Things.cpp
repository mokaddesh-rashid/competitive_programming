#include<iostream>


using namespace std;

int main()
{
    int n;

    cin>>n;

    int value[n+1],pos[n+1],hard_time[2000+6]={0},i,x=0,a,b,c,s[2222]={0};

    for(i=0;i<n;i++)
    {
        cin>>value[i];
        pos[i]=i+1;
        hard_time[value[i]]++;
    }
    for(i=0;i<2001;i++)
    {
        if(hard_time[i]==2)
            x++;
        else if(hard_time[i]>2)
            x+=2;
    }



    if(x<2)
     cout<<"NO";

    else
    {
         cout<<"YES\n";
        c=n;

        for(i=0;i<c;i++,c--)
        {
            for(x=i;x<c;x++)
            {
                if(value[i]>value[x])
                {
                    swap(value[i],value[x]);
                    swap(pos[i],pos[x]);
                }
                else if(value[c-1]<value[x])
                {
                    swap(value[c-1],value[x]);
                    swap(pos[c-1],pos[x]);
                }
            }
        }
        for(i=0;i<n;i++)
            cout<<pos[i]<<' ';

        cout<<endl;

         for(i=0;i<n;i++)
            {
                if(value[i]==value[i+1]&&(s[i]==0||s[i+1]==0))
                {
                    swap(pos[i],pos[i+1]);
                    s[i]++;
                    s[i+1]++;
                    break;
                }

            }

        for(i=0;i<n;i++)
            cout<<pos[i]<<' ';

        cout<<endl;

         for(i=0;i<n;i++)
            {
                if(value[i]==value[i+1]&&(s[i]==0||s[i+1]==0))
                {
                    swap(pos[i],pos[i+1]);
                    s[i]++;
                    s[i+1]++;
                    break;
                }

            }

        for(i=0;i<n;i++)
            cout<<pos[i]<<' ';



    }





}
