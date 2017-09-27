#include <map>
#include <set>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
/*
struct My_struct
{
	int a;
};
vector<My_struct>ivec;
bool cmp(const My_struct &p,const My_struct &q)
{
	return p.a<q.a;//升序排列
}
*/
/********************************************************/
int main()
{
    int n;
    int k;
    while(cin>>n)//读取第一个数据
    {
    	vector<int>ivec(n);
    	int tmp;
		for(int i=0;i<n;i++)
		{
			cin>>tmp;
			ivec[i]=tmp;
		}
		cin>>k;
		vector<vector<int> >table(n+1,vector<int>(n+1));
		for(int i=0;i<n;i++)
		{
			table[i][i]=ivec[i];
		}
		
		for(int i=1;i<n;i++)//列 
		{
			for(int j=0;j+i<n;j++)
			{

				table[j][j+i]=table[j][j+i-1]+table[j+1][j+i]-table[j+1][j+i-1];
			}
		}
		bool flag=0;
		for(int i=n-1;i>=0&&flag==0;i--)//列 
		{
			for(int j=0;j+i<n&&flag==0;j++)
			{

				if(table[j][j+i]%k==0)
				{
					flag=1;
					cout<<i+1<<endl;
				}
				
			}
			
		}
		if(flag==0)cout<<"0"<<endl;
		
    }
	return 0;
}






