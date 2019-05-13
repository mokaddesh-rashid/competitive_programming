#include<iostream>

using namespace std;

int main()
{
    long long int n;

    cin>>n;

    long long int pos_x[n+1],neg_x[n+1],value_pos[n+1],value_neg[n+1],x=0,maxx,a,i,b,c,y=0,z,pos=0,neg=0,ans=0,address;

    for(i=0;i<n;i++)
    {
        cin>>address;

        if(address<0)
        {
            neg_x[neg]=address;
            cin>>value_neg[neg];
            neg++;
        }

       else
        {
            pos_x[pos]=address;
            cin>>value_pos[pos];
            pos++;
        }


    }

    for(i=0;i<neg;i++)
        for(x=i;x<neg;x++)
    {
        if(neg_x[i]<neg_x[x])
        {
            swap(neg_x[i],neg_x[x]);
            swap(value_neg[i],value_neg[x]);
        }
         if(neg_x[i]==neg_x[x]&&value_neg[i]<value_neg[x])
        {
            swap(neg_x[i],neg_x[x]);
            swap(value_neg[i],value_neg[x]);
        }
    }

    for(i=0;i<pos;i++)
        for(x=i;x<pos;x++)
    {
        if(pos_x[i]>pos_x[x])
        {
            swap(pos_x[i],pos_x[x]);
            swap(value_pos[i],value_pos[x]);
        }

         if(pos_x[i]==pos_x[x]&&value_pos[i]<value_pos[x])
        {
            swap(pos_x[i],pos_x[x]);
            swap(value_pos[i],value_pos[x]);
        }
    }



   x=min(pos,neg);

  // cout<<x<<endl;

   for(i=0;i<x;i++)
   {
       ans=ans+value_pos[i]+value_neg[i];
   }

   //cout<<ans<<endl;

   if(x<pos)
      ans+=value_pos[x];

   else if(x<neg)
      ans+=value_neg[x];

      cout<<ans;

}
