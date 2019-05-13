#include<iostream>
#include<string>


using namespace std;

int main()
{
       int n,i=0,p,j;//n==1 hole ta handle kora lagboo

        //cin>>n;

        string str,st,comm,prn,un;


        cin>>st>>str;

       int  a=st.size();

        while(i<a)
        {
            cout<<i<<endl;

            j=1;

           while(j+i<a)
           {

               comm.assign(st,i,j);
               cout<<comm<<endl;

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
        cout<<prn;


}
