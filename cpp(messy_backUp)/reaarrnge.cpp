#include<iostream>

using namespace std;

class A
{
    public:
    int i,x,y,z,n,a[111],c,d;
    void rearrange(int *ar,int b)
    {
        for(x=0;x<b;x++)
            for(y=0;y<b;y++)
        {
            if(ar[y]>ar[y+1])
            {
                z=ar[y];
                ar[y]=ar[y+1];
                ar[y+1]=z;
            }
        }
        //return 0;
    }

};

int main()
{
    int i;
    A ob;
    cin>> ob.c;
    for(ob.i=0;ob.i<ob.c;ob.i++)
    {
        cin>>ob.a[ob.i];
    }
    ob.rearrange(ob.a,ob.c);
    for(i=0;i<ob.c;i++)
    {
        cout<<ob.a[i]<<endl;
    }
    return 0;
}
