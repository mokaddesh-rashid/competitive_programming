#include<iostream>

using namespace std;

int main()
{
    int a,b,c,d,e,f,g,h,i,st_1[4]={1,1,1},st_2[4]={1,1,1},st_3[4]={1,1,1};

    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;

    if(a%2==1)
    {
       if(st_1[0]==0)
            st_1[0]=1;
       else
            st_1[0]=0;

       if(st_1[1]==0)
            st_1[1]=1;
       else
            st_1[1]=0;
        if(st_2[0]==0)
            st_2[0]=1;
       else
            st_2[0]=0;

    }
     if(b%2==1)
    {
        if(st_1[0]==0)
            st_1[0]=1;
       else
            st_1[0]=0;

       if(st_1[1]==0)
            st_1[1]=1;
       else
            st_1[1]=0;

       if(st_1[2]==0)
            st_1[2]=1;
       else
            st_1[2]=0;
        if(st_2[1]==0)
            st_2[1]=1;
       else
            st_2[1]=0;

    }

    if(c%2==1)
    {
       if(st_1[1]==0)
            st_1[1]=1;
       else
            st_1[1]=0;

       if(st_1[2]==0)
            st_1[2]=1;
       else
            st_1[2]=0;

        if(st_2[2]==0)
            st_2[2]=1;
       else
            st_2[2]=0;

    }

    if(d%2==1)
    {
       if(st_1[0]==0)
            st_1[0]=1;
       else
            st_1[0]=0;

       if(st_2[0]==0)
            st_2[0]=1;
       else
            st_2[0]=0;

        if(st_2[1]==0)
            st_2[1]=1;
       else
            st_2[1]=0;

        if(st_3[0]==0)
            st_3[0]=1;
       else
            st_3[0]=0;

    }

    if(e%2==1)
    {
       if(st_1[1]==0)
            st_1[1]=1;
       else
            st_1[1]=0;

       if(st_2[0]==0)
            st_2[0]=1;
       else
            st_2[0]=0;

         if(st_2[1]==0)
            st_2[1]=1;
       else
            st_2[1]=0;

        if(st_2[2]==0)
            st_2[2]=1;
       else
            st_2[2]=0;

        if(st_3[1]==0)
            st_3[1]=1;
       else
            st_3[1]=0;

    }
    if(f%2==1)
    {
       if(st_1[2]==0)
            st_1[2]=1;
       else
            st_1[2]=0;

         if(st_2[1]==0)
            st_2[1]=1;
       else
            st_2[1]=0;

        if(st_2[2]==0)
            st_2[2]=1;
       else
            st_2[2]=0;

        if(st_3[2]==0)
            st_3[2]=1;
       else
            st_3[2]=0;

    }
    if(g%2==1)
    {
       if(st_2[0]==0)
            st_2[0]=1;
       else
            st_2[0]=0;

         if(st_3[0]==0)
            st_3[0]=1;
       else
            st_3[0]=0;

         if(st_3[1]==0)
            st_3[1]=1;
       else
            st_3[1]=0;

    }

     if(h%2==1)
    {
       if(st_2[1]==0)
            st_2[1]=1;
       else
            st_2[1]=0;

         if(st_3[0]==0)
            st_3[0]=1;
       else
            st_3[0]=0;

         if(st_3[1]==0)
            st_3[1]=1;
       else
            st_3[1]=0;


         if(st_3[2]==0)
            st_3[2]=1;
       else
            st_3[2]=0;

    }

     if(i%2==1)
    {
       if(st_2[2]==0)
            st_2[2]=1;
       else
            st_2[2]=0;

         if(st_3[1]==0)
            st_3[1]=1;
       else
            st_3[1]=0;


         if(st_3[2]==0)
            st_3[2]=1;
       else
            st_3[2]=0;

    }

    cout<<st_1[0]<<st_1[1]<<st_1[2]<<endl;
    cout<<st_2[0]<<st_2[1]<<st_2[2]<<endl;
    cout<<st_3[0]<<st_3[1]<<st_3[2]<<endl;




}
