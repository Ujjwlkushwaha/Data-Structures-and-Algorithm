#include<bits/stdc++.h>
#include<vector>
using namespace std;

void subset(int arr[],int i,vector<vector<int>&ans,vector<int>&temp,int size)
{
	//base case
	if(size==size)
	{
		ans.push_back(temp);
		return;
	}
	temp.push_back(arr[size])//yes ke liye
	subset(arr,i+1,ans,temp,size);//no ke liye
}
int main(){
	int arr[]={1,2,3};
	vector<vector<int>>&ans;//2D vector ke liye
	vector<int>&temp;
	int size=3;
	cout<<subset(arr,0,ans,temp,size);//function call 
	for(int i=0; i<arr.size(); i++)
	{
		for(int j=0; j<arr[i].size(); j++)
		{
			cout<<arr[i][j];
		}
	}
}
