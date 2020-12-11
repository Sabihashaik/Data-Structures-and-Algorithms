#include<iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> arr){
	int num=arr[0];

	for(int i=1;i<arr.size();i++){
		num^=arr[i];
	}

	return num;
}
int main() {
	int n;
	cin>>n; 

	vector<int> arr;
	for(int i=0;i<n;i++){
		int input; 
		cin>>input; 
		arr.push_back(input);
	}
	
	cout<<missingNumber(arr);
	return 0;
}