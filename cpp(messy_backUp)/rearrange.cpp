#include<iostream>

using namespace std;

class A
{
    public:
    int x,i,n,a[11],b,c;
    void rearrange(int *a,int b)
    {
        int x,y,z;
        for(x=0;x<b;x++)
            for(y=0;y<b;y++)
        {
            if(a[y]>a[y+1])
                a[y]=z;
                a[y]=a[y+1];
                a[y+1]=a[y];
        }

        //return 0;
    }

    void earrange(int *a,int b)
    {
        int x,y,z;
        for(x=0;x<b;x++)
            cout<<a[x];
    }
};

int main()
{
   class ob;

   cin >> ob.x;

   //for(ob.i=0;ob.i<ob.x;ob.i++)
  // cin>> ob.a[ob.i];

   ob.rearrange(ob.a,ob.x);
    ob.earrange(ob.a,ob.x);

   return 0;

}
