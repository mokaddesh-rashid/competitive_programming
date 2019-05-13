#include<iostream>


using namespace std;

int main()
{
    int x[5],y[5],x2,y2,x3,y3,ab,bc,ca,i,a=0,d=0;

    cin>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3];

    ab=(x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]);
    bc=(x[2]-x[3])*(x[2]-x[3])+(y[2]-y[3])*(y[2]-y[3]);
    ca=(x[3]-x[1])*(x[3]-x[1])+(y[3]-y[1])*(y[3]-y[1]);

    if(ab<bc)
    swap(ab,bc);
    if(ab<ca)
    swap(ab,ca);
    else if(ab==bc+ca)
   {
        cout<<"RIGHT";
        a=1;
   }
    if(a==0)
    for(i=1;i<4;i++)
    {
     x[i]=x[i]+1;

    ab=(x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]);
    bc=(x[2]-x[3])*(x[2]-x[3])+(y[2]-y[3])*(y[2]-y[3]);
    ca=(x[3]-x[1])*(x[3]-x[1])+(y[3]-y[1])*(y[3]-y[1]);

    if(ab<bc)
    swap(ab,bc);
    if(ab<ca)
    swap(ab,ca);
    if(ab==bc||bc==ca||ca==ab)
        d=1;
    else if(ab==bc+ca)
    {
        cout<<"ALMOST";
        a=1;
        break;
    }

    x[i]=x[i]-2;

    ab=(x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]);
    bc=(x[2]-x[3])*(x[2]-x[3])+(y[2]-y[3])*(y[2]-y[3]);
    ca=(x[3]-x[1])*(x[3]-x[1])+(y[3]-y[1])*(y[3]-y[1]);

    if(ab<bc)
    swap(ab,bc);
    if(ab<ca)
    swap(ab,ca);
     if(ab==bc||bc==ca||ca==ab)
        d=1;
    else if(ab==bc+ca)
    {
        cout<<"ALMOST";
        a=1;
        break;
    }

    x[i]=x[i]+1;

    y[i]=y[i]+1;

    ab=(x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]);
    bc=(x[2]-x[3])*(x[2]-x[3])+(y[2]-y[3])*(y[2]-y[3]);
    ca=(x[3]-x[1])*(x[3]-x[1])+(y[3]-y[1])*(y[3]-y[1]);

    if(ab<bc)
    swap(ab,bc);
    if(ab<ca)
    swap(ab,ca);
     if(ab==bc||bc==ca||ca==ab)
        d=1;
    else if(ab==bc+ca)
    {
        cout<<"ALMOST";
        a=1;
        break;
    }

    y[i]=y[i]-2;

    ab=(x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]);
    bc=(x[2]-x[3])*(x[2]-x[3])+(y[2]-y[3])*(y[2]-y[3]);
    ca=(x[3]-x[1])*(x[3]-x[1])+(y[3]-y[1])*(y[3]-y[1]);


    if(ab<bc)
    swap(ab,bc);
    if(ab<ca)
    swap(ab,ca);
    if(ab==bc||bc==ca||ca==ab)
        d=1;
    else if(ab==bc+ca)
    {
        cout<<"ALMOST";
        a=1;
        break;
    }

    y[i]=y[i]+1;


    }

     if(a==0)
        cout<<"NEITHER";


}
