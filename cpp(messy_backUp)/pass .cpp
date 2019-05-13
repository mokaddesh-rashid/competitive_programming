#include<iostream>

using namespace std;

int main()
{
    int total_ans_krb0,ans_krse,max_mark,max_number,median_number,baki,i,n,x=0,y,z=0,k,med_pos,a=0;

    cin>>total_ans_krb0>>ans_krse>>max_mark>>max_number>>median_number;

    k=total_ans_krb0-ans_krse;
    med_pos=(total_ans_krb0+1)/2;

    for(i=0;i<ans_krse;i++)
    {
        cin>>a;
        x+=a;

        if(a>=median_number)
            z++;
    }

    if(x+k>max_number)
        cout<<-1;
    else if(z+k<med_pos)
        cout<<-1;
    else if((x+((med_pos-z)*median_number))>max_number)
        cout<<-1;
    else
    {
        for(i=0;i<med_pos-z;i++)
            cout<<median_number<<' ';

        for(i=med_pos-z;i<k;i++)
            cout<<1<<' ';
    }





}
