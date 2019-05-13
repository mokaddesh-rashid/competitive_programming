void rec( int x )
{
    if( top == -1 && len != 0 )
       return;

    if( lar[x].cnt == 1 )
    {
       cout << x << ' ';
       arr[len].lev = lar[x].lev;
       arr[len].val = x;

       if( lar[x].lft == 0 )
          lar[x].lft = len;
       lar[x].rig = len;
       len++;
       lar[x].cnt++;
       top++;
       stk[top] = x;
    }
        //cout << x << ' ' << stk[top] << ' ' << mat[x][0] << endl;


    if( mat[x][0] > 0 )
    { cout << x << ' ';
    arr[len].lev = lar[x].lev;
    arr[len].val = x;

    if( lar[x].lft == 0 )
        lar[x].lft = len;
    lar[x].rig = len;
    len++;
        mat[x][0]--;
        rec( mat[x][mat[x][0]+1] );
    }
    else
    {
        //cout << 'h';
        cout << x << ' ';
        arr[len].lev = lar[x].lev;
        arr[len].val = x;
        lar[x].rig = len;
        len++;

        top--;

        if( top == -1 )
            return;
        else
            rec( stk[top] ); // rte chck
    }
}
