#include <iostream>
using namespace std;

// int main()
// {
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 		string str;
// 		cin>>str;
// 		int odd_count=0,even_count=0;
// 		int pos=0;
// 		for(int i=str.length()-1;i>=0;i--)
// 		{
// 			if(pos%2!=0 && str[i]=='1')
// 			{
// 				odd_count++;
// 			}
// 			if(pos%2==0 && str[i]=='1')
// 			{
// 				even_count++;
// 			}

// 			pos++;
// 		}

// 		if((2*odd_count+even_count)%3==0) cout<<"1\n";
// 		else cout<<"0";

// 	}
// } // It should be correct but the correct answer according to video is



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int odd_count=0,even_count=0;
		for(int i=0;i<str.length();i++)
		{
			if(i%2!=0 && str[i]=='1')
			{
				odd_count++;
			}
			if(i%2==0 && str[i]=='1')
			{
				even_count++;
			}

		}

		if((2*odd_count+even_count)%3==0) cout<<"1\n";
		else cout<<"0";

	}