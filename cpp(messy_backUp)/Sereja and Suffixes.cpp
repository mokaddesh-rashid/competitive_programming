#include<iostream>

using namespace std;

int main()
{
    int n,m;

    cin>>n>>m;


    int value[n+1],x,i,a,b,pos[10*10*10*10*10]={0},arr_dis[n+1],dis_value=0;

    for(i=0;i<n;i++)
    {
        cin>>value[i];
    }


    for(i=n-1;i>=0;i--)
    {
        if(pos[value[i]]==0)
        {

            dis_value++;
            pos[value[i]]++;

        }
        arr_dis[i]=dis_value;
        // cout<<value[i]<<' '<<pos[value[i]]<<' '<<dis_value<<' '<<arr_dis[i]<<endl;
    }

    for(i=0;i<m;i++)
    {
        cin>>a;
        cout<<arr_dis[a-1]<<endl;
    }

}
