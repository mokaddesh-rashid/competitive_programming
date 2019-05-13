int bit[MAX];
void update(int i,int val)
{
	while(i<=n)
	{
		bit[i]=max(bit[i],val);
		i=i+(i&(-i));
	}
}
int query(int i)
{
	int ret=0;
	while(i)
	{
		ret=max(ret,bit[i]);
		i=i-(i&(-i));
	}
	return ret;
}


///*************************
http://codeforces.com/blog/entry/61364

int bit_search(int v)
{
	int sum = 0;
	int pos = 0;

	for(int i=LOGN; i>=0; i--)
	{
		if(pos + (1 << i) < N and sum + bit[pos + (1 << i)] < v)
		{
			sum += bit[pos + (1 << i)];
			pos += (1 << i);
		}
	}

	return pos + 1; // +1 because 'pos' will have position of largest value less than 'v'
}
