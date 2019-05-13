#include<iostream>

using namespace std;

int size_d=5,i,n,end0=-1,empty0=-2,start0=-1,last_end=-1;
int *data=new int[size_d];
int *list0=new int[size_d];

int main()
{
    for(i=0;i<size_d;i++)
       list0[i]=empty0;

    for(i=0;i<size_d;i++)
    {
        int x,pos;

        again:
        cout<<"value and pos : \n";
        cin>>x>>pos;

        if(list0[pos]!=empty0)
           {
               cout<<"invalid address\n";
                goto again;
           }
        else
        {
            if(last_end!=-1)
                list0[last_end]=pos;
            if(i==0)
                {
                    start0=pos;
                    cout<<start0<<endl;
                }
            data[pos]=x;
            list0[pos]=-1;
            last_end=pos;
        }

    }

    cout<<"1st input :: "<<data[start0]<<endl;

    for(i=0;i<size_d;i++)
    {


        else if(list0[i]==end0)
             cout<<"last input :: "<<data[i]<<endl;

    }


}
