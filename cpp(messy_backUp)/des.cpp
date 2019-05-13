#include<bits/stdc++.h>
using namespace std;
int TEST=0,CASE=1;
#define         pf              printf
#define         si(x)           scanf("%d",&x)
#define         si2(x,y)        scanf("%d %d",&x,&y)
#define         si3(x,y,z)      scanf("%d %d %d",&x,&y,&z)
#define         sl(x)           scanf("%lld",&x)
#define         sl2(x,y)        scanf("%lld %lld",&x,&y)
#define         sl3(x,y,z)      scanf("%lld %lld %lld",&x,&y,&z)
#define         sd(x)           scanf("%lf ",&x)
#define         pb(x)           push_back(x)
#define         mp(x,y)         make_pair(x,y)
#define         clr(x,y)        memset(x,y,sizeof(x))
#define         all(x)          x.begin(),x.end()
#define         MX              401000
#define         left            (indx<<1)
#define         right           left+1
#define         mid             ((l+r)>>1)
#define         call            left,l,mid
#define         lnd             tree[left]
#define         calr            right,mid+1,r
#define         rnd             tree[right]
#define         cnd             tree[indx]
#define         speed           (ios::sync_with_stdio(false),cin.tie(0))
#define         fpoint(x)       (cout.precision(x),cout<<fixed)
#define         FOR(i,n)       	for(int i=1;i<=n;++i)
#define         FR(i,n)      	for(int i=0;i<n;++i)
#define		dx		xx+dirx[i]
#define		dy		yy+diry[i]
#define		N		16
long long int         mod  =    1000000007LL;
const long double     pi   =    2.0*acos(0.0);
typedef long long int ll;
typedef long double ld;
int dirx[9]={0,0,0,-1,+1,+1,+1,-1,-1};
int diry[9]={0,-1,+1,0,0,-1,+1,-1,+1};
struct vpair{
        int a,b;
        vpair(int a,int b){this->a=a,this->b=b;}
};
bool cmp(int &a,int &b){
        return a<b;                ///ascending order
        return a>b;                ///descending order
}
int n,m,a,b,k,x,y,z,ans=0,total=0;
int msglen,keylen;
int pc1[68],msgbit[68],keybit[18][68],iptab[68],pc2[68],etab[68],iprev[68];
int finalMsg[68];
int ipbit[18][68];
int msg[68],key[68];
int stab[10][6][17];
string msgs,keys;
int l[18][68],r[18][68];
int c[18][68],d[18][68];
int ite[17];
int temp[68];
int tempEbit[18][68];
int stemp[18][68];
int funtab[18][68];
int ptab[68];
void generateCD(int pro){
	if(pro>N)return;
	if(pro==0){
		for(int i=1;i<=28;i++)c[0][i]=keybit[0][i];
		for(int i=1;i<=28;i++)d[0][i]=keybit[0][28+i];
	}else{
		///Ci left shift
		for(int i=1;i<=ite[pro];i++){
			temp[i]=c[pro-1][i];
		}
		for(int i=1;i<=28-ite[pro];i++){
			c[pro][i]=c[pro-1][ite[pro]+i];
		}
		int pos=1;
		for(int i=(28-ite[pro]+1);i<=28;i++){
			c[pro][i]=temp[pos++];
		}
		///Di left shift
		for(int i=1;i<=ite[pro];i++){
			temp[i]=d[pro-1][i];
		}
		for(int i=1;i<=28-ite[pro];i++){
			d[pro][i]=d[pro-1][ite[pro]+i];
		}
		pos=1;
		for(int i=(28-ite[pro]+1);i<=28;i++){
			d[pro][i]=temp[pos++];
		}
	}
	generateCD(pro+1);
}
void generateKey(int pro){
	if(pro>N)return;
	for(int i=1;i<=28;i++){
		temp[i]=c[pro][i];
	}
	for(int i=1;i<=28;i++){
		temp[28+i]=d[pro][i];
	}
	for(int i=1;i<=48;i++){
		keybit[pro][i]=temp[pc2[i]];
	}
	generateKey(pro+1);
}
void generateEqun(int pro){
	if(pro>N){
		for(int i=1;i<=32;i++){
			temp[i]=r[pro-1][i];
		}
		for(int i=1;i<=32;i++){
			temp[i+32]=l[pro-1][i];
		}
		cout<<endl<<"Final Rev"<<endl;
		FOR(i,64){
			pf("%d",temp[i]);
			if(i%8==0)pf(" ");
		}
		cout<<endl;
		cout<<"Final Msg"<<endl;
		FOR(i,64){
			finalMsg[i]=temp[iprev[i]];
			pf("%d",finalMsg[i]);
			if(i%8==0)pf(" ");
		}
		return;
	}
///	Li
	for(int i=1;i<=32;i++){
		l[pro][i]=r[pro-1][i];
	}
///	Ri
///	E-BIT
	pf("\nEBIT(R%d) =	",pro-1);
	for(int i=1;i<=48;i++){
		tempEbit[pro][i]=r[pro-1][etab[i]];
		pf("%d",tempEbit[pro][i]);
	}
	pf("\n");
	pf("F(R%d,K%d) = ",pro-1,pro);
	for(int i=1;i<=48;i++){
		temp[i]=tempEbit[pro][i]^keybit[pro][i];
		pf("%d",temp[i]);
	}
	pf("\n");
	pf("S-BOX    = ");
	for(int i=1;i<=8;i++){
		int row,col;
		row=(temp[6*i-5])*2+(temp[6*i])*1;
		col=(temp[6*i-4])*8+(temp[6*i-3])*4+(temp[6*i-2])*2+(temp[6*i-1])*1;
		int value=stab[i][row][col];
		for(int j=(i*4);j>(i*4)-4;j--){
			if(value%2==1){
				stemp[pro][j]=1;
			}else{
				stemp[pro][j]=0;
			}
			value/=2;
		}
		for(int j=(i*4-4+1);j<=(i*4);j++){
			pf("%d",stemp[pro][j]);
		}
		pf(" ");
	}
	pf("\n");
	pf("P-Table(S-BOX) = ");
	for(int i=1;i<=32;i++){
		funtab[pro][i]=stemp[pro][ptab[i]];
		pf("%d",funtab[pro][i]);
//		if(i%4==0)pf(" ");
	}
	for(int i=1;i<=32;i++){
		r[pro][i]=funtab[pro][i]^l[pro-1][i];
	}
	cout<<endl;
	cout<<"l"<<pro<<endl;
	FOR(i,32)cout<<l[pro][i];
	cout<<endl;
	cout<<"r"<<pro<<endl;
	FOR(i,32)cout<<r[pro][i];
	generateEqun(pro+1);
}
int main(void){

    freopen("des.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	map<char,string> mp;
	mp['0']="0000";
	mp['1']="0001";
	mp['2']="0010";
	mp['3']="0011";
	mp['4']="0100";
	mp['5']="0101";
	mp['6']="0110";
	mp['7']="0111";
	mp['8']="1000";
	mp['9']="1001";
	mp['A']="1010";
	mp['B']="1011";
	mp['C']="1100";
	mp['D']="1101";
	mp['E']="1110";
	mp['F']="1111";
	string msgs1,keys1;
	cin>>msgs1;
	cin>>keys1;
	int pos=1;
	for(int i=0;i<msgs1.length();i++){
		string s=mp[msgs1[i]];
		msg[pos++]=s[0]-48;
		msg[pos++]=s[1]-48;
		msg[pos++]=s[2]-48;
		msg[pos++]=s[3]-48;
	}
	pos=1;
	for(int i=0;i<msgs1.length();i++){
		string s=mp[keys1[i]];
		key[pos++]=s[0]-48;
		key[pos++]=s[1]-48;
		key[pos++]=s[2]-48;
		key[pos++]=s[3]-48;
	}
	pf("Message\n");
	cout<<msgs1<<endl;
	FOR(i,64)pf("%d",msg[i]),i%8==0?pf(" "):i;
	pf("\nKey\n");
	cout<<keys1<<endl;
	FOR(i,64)pf("%d",key[i]),i%8==0?pf(" "):i;
	pf("\n");
	FOR(i,64)cin>>iptab[i];
	FOR(i,56)cin>>pc1[i];
	FOR(i,48)cin>>pc2[i];
	FOR(i,16){
		cin>>a>>b;
		ite[a]=b;
	}
	FOR(i,48)cin>>etab[i];
	for(int i=1;i<=8;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<16;k++){
				cin>>stab[i][j][k];
			}
		}
	}
	FOR(i,32)cin>>ptab[i];
	FOR(i,64)cin>>iprev[i];
	cout<<endl<<"PC1"<<endl;
	for(int i=1;i<=56;i++){
		keybit[0][i]=key[pc1[i]];
		pf("%d",keybit[0][i]);
		if(i%7==0)pf(" ");
	}

	generateCD(0);
	cout<<endl<<"CD"<<endl;
	for(int i=0;i<=N;i++){
		pf("\nCD%d\n",i);
		for(int j=1;j<=28;j++){
			pf("%d",c[i][j]);
		}
		pf("\n");
		for(int j=1;j<=28;j++){
			pf("%d",d[i][j]);
		}
		pf("\n");
	}

	generateKey(1);
	cout<<endl<<"KeyAll"<<endl;
	for(int i=1;i<=16;i++){
		for(int j=1;j<=48;j++){
			pf("%d",keybit[i][j]);
			if(j%6==0)pf(" ");
		}
		pf("\n");
	}
	cout<<endl<<"MSG IP-Table"<<endl;
	for(int i=1;i<=64;i++){
		msgbit[i]=msg[iptab[i]];
		pf("%d",msgbit[i]);
		if(i%4==0)pf(" ");
	}
	cout<<endl;
	for(int i=1;i<=32;i++){
		l[0][i]=msgbit[i];
	}
	for(int i=1;i<=32;i++){
		r[0][i]=msgbit[i+32];
	}
	cout<<endl<<"L0"<<endl;
	for(int i=1;i<=32;i++){
		pf("%d",l[0][i]);
		if(i%4==0)pf(" ");
	}
	cout<<endl<<"R0"<<endl;
	for(int i=1;i<=32;i++){
		pf("%d",r[0][i]);
		if(i%4==0)pf(" ");
	}
	cout<<endl;

///	Li=Ri-1
///	Ri=Li-1+f(Ri-1+Ki)
	pf("Equation\n");
	generateEqun(1);

        return 0;
}

/**
"G:\Work Station\Project\Network Security\DES.cpp"
**/
