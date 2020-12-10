#include<iostream>
#include <vector>

using namespace std;
int main() {
	int n; 
	cin>>n;
	int missingNumber =n; 
	vector<int> arr; 
	for(int i=0;i<n;i++){
		int number;
		cin>>number;
		arr.push_back(number); 
	}

	for(int i=0;i<n;i++){
		missingNumber^=i^arr[i];
	} 
	cout<<missingNumber;
	return 0;
}