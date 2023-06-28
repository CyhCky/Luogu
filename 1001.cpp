#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+(c&15); c=getchar();}
	return x*f;
}
int main()
{
	int a=read(),b=read();
	printf("%d\n",a+b);
	return 0;
}
