#include<bits/stdc++.h>
using namespace std;

#define Mod_Val 1000000007

long long int Count_Binary_String(long long int );
void Calculate_Multi(long long int tab1[][2],long long int tab2[][2]);
void Calculate_Pow(long long int tab1[][2],long long int );
int main()
{
	int t;
	long long int num;
	cin>>t;
	while(t--)
	{
		cin>>num;
		cout<<Count_Binary_String(num)<<endl;
	}
	return 0;
}
long long int Count_Binary_String(long long int num)
{
	long long int table1[2][2]={{1,1},{1,0}};
	if (num==0)
    	return 0;
  	if (num == 1)
    	return 2;
  	if (num == 2)
    	return 3;
  Calculate_Pow(table1, num-2);
  return (table1[0][0]*3+table1[0][1]*2)%Mod_Val;
}
void Calculate_Pow(long long int table1[2][2],long long int num)
{
	if(num==0 || num==1)
		return;
	long long int table2[2][2]={{1,1},{1,0}};
	Calculate_Pow(table1,num/2);
	Calculate_Multi(table1,table1);
	if(num%2!=0)
		Calculate_Multi(table1,table2);
	
}
void Calculate_Multi(long long int table1[][2],long long int table2[][2])
{
	long long int x1 =((table1[0][0]*table2[0][0])%Mod_Val + (table1[0][1]*table2[1][0])%Mod_Val)%Mod_Val;
  	long long int x2 =((table1[0][0]*table2[0][1])%Mod_Val + (table1[0][1]*table2[1][1])%Mod_Val)%Mod_Val;
  	long long int x3 =((table1[1][0]*table2[0][0])%Mod_Val + (table1[1][1]*table2[1][0])%Mod_Val)%Mod_Val;
  	long long int x4 =((table1[1][0]*table2[0][1])%Mod_Val + (table1[1][1]*table2[1][1])%Mod_Val)%Mod_Val;
 
 	table1[0][0] = x1;
  	table1[0][1] = x2;
  	table1[1][0] = x3;
  	table1[1][1] = x4;
}
