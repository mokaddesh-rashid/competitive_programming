#include<iostream>
#include<string>


using namespace std;

int main()
{
    int t;

    cin>>t;

    while(t>0)
    {
        int n,i=0,p,j,x;//n==1 hole ta handle kora lagboo

        cin>>n;

        x=n;

        string str1,st,comm,prn,un,str2,str3,str4,str5,str6,str7,str8,str9;


        cin>>st;
        n--;

        if(n>0)
            cin>>str1;
        n--;

        if(n>0)
            cin>>str2;
        n--;

        if(n>0)
            cin>>str3;
        n--;

        if(n>0)
            cin>>str4;
        n--;

        if(n>0)
            cin>>str5;
        n--;

        if(n>0)
            cin>>str6;
        n--;

        if(n>0)
            cin>>str7;
        n--;

        if(n>0)
            cin>>str8;
        n--;

        if(n>0)
            cin>>str9;
        n--;



            i=0;

            while(i<st.size())
        {
            j=1;

           while(j+i<=st.size())
           {
               p=0;

               comm.assign(st,i,j);
              // cout<<comm<<endl;

            if(1<x)
               p=str1.find(comm);

               //cout<<p<<endl;

            if(2<x&&p!=-1)
               p=str2.find(comm);

                //cout<<p<<endl;

            if(3<x&&p!=-1)
               p=str3.find(comm);

                //cout<<p<<endl;

            if(4<x&&p!=-1)
               p=str4.find(comm);

                //cout<<p<<endl;

            if(5<x&&p!=-1)
               p=str5.find(comm);

            if(6<x&&p!=-1)
               p=str6.find(comm);

            if(7<x&&p!=-1)
               p=str7.find(comm);

            if(8<x&&p!=-1)
               p=str8.find(comm);

            if(9<x&&p!=-1)
               p=str9.find(comm);

               if(p!=-1)
               {
                   //cout<<"ok"<<comm<<endl;
                   if(prn.size()==0)
                   {
                       prn=comm;
                   }
                   else if(prn.size()<comm.size())
                   {
                      prn=comm;
                   }
                   else if(prn.size()==comm.size()&&prn>comm)
                   {
                      prn=comm;
                   }
               }


               j++;
           }

           i++;
        }

        cout<<prn<<endl;


       t--;

        }
}
