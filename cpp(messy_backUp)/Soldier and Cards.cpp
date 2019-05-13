#include<iostream>

using namespace std;


int main()
{
   static int y,x;
   int i,a,b,c,n,p1_top,p2_top,k;
   int *p1_crd=new int[10];
   int *p2_crd=new int [10];

   cin>>n>>k;
   p1_top=k-1;
   for(i=0;i<k;i++)
   {
        cin>>p1_crd[i];
         cout<<p1_crd[i]<<" ";

   }

   cout<<endl;

   cin>>k;
   p2_top=k-1;
   for(i=0;i<k;i++)
    {
        cin>>p2_crd[i];
         cout<<p2_crd[i]<<" ";
}

   cout<<endl;
    while(p1_top>-1&&p2_top>-1)
    {
        x++;
        if(p1_crd[p1_top]<p2_crd[p2_top])
        {
            c=0;
            int *newarray=new int[n+1];

            for(i=0;i<=p1_top+1;i++)
            {
                if(i==0)
                   {
                        newarray[i]=p1_crd[p1_top];
                        cout<<p1_crd[p1_top]<<"p1 "<<p1_top<<endl;
                   }

                else if(i==1)
                   {
                        newarray[i]=p2_crd[p2_top];
                        cout<<p2_crd[p2_top]<<endl;
                   }

                else
                   {
                        newarray[i]=p1_crd[c];
                        cout<<p1_crd[c]<<endl;
                        c++;
                   }

           }
                 delete p1_crd;

                  p1_crd=newarray;
                  p1_top++;
                  p2_top--;
                  for(i=0;i<=p1_top;i++)
                    cout<<p1_crd[i]<<' ';

                  cout<<endl<<endl;
        }
        else if(p1_crd[0]>p2_crd[0])
        {
            c=0;


            int *newarray=new int[n+1];

            for(i=0;i<=p2_top+1;i++)
            {
                if(i==0)
               {
                newarray[i]=p2_crd[p2_top];
                //cout<<p2_crd[p2_top]<<endl;
                 cout<<p2_crd[p2_top]<<"p2 "<<p2_top<<endl;
               }
                else if(i==1)
                   {
                    newarray[i]=p1_crd[p1_top];
                   cout<<p1_crd[p1_top]<<endl;

                   }
               else
                   {
                        newarray[i]=p2_crd[c];
                        cout<<p2_crd[c]<<endl;
                        c++;
                   }

            }
            delete p2_crd;

            p2_crd=newarray;
            p1_top--;
            p2_top++;

             for(i=0;i<=p2_top;i++)
                    cout<<p2_crd[i]<<' ';
             cout<<endl<<endl;
        }

    }
    cout<<x<<endl;
    if(p1_top==-1)
        cout<<2;
     else if(p2_top==-1)
        cout<<1;

}
