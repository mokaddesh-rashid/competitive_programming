#include<iostream>
#include<string>


using namespace std;

int main()
{
    int t;

    cin>>t;

    while(t>0)
    {
        int n,i=0,p,j;//n==1 hole ta handle kora lagboo

        cin>>n;

        string str,st,comm,prn,un;


        cin>>st;
        n--;

        while(n>0)
        {
            i=0;
            cin>>str;

            while(i<st.size())
        {
            j=1;

           while(j+i<=st.size())
           {

               comm.assign(st,i,j);
               //cout<<comm<<endl;

               p=str.find(comm);

               if(p!=-1)
               {
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
        st=prn;
        prn="\0";


         n--;

    }
    cout<<st<<endl;

       t--;

        }
}
