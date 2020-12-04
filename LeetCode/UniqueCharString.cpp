#include <bits/stdc++.h>
#include <vector>
#include <climits>
using namespace std;

int UniqueRecursion(vector<string> arr,int i,string s){

	int opt1, opt2; 
	opt1 = opt2 = INT_MIN; 
	if(i==arr.size()){
		int freq[26] = {0};
		for(int k=0;k<s.length();k++){
			if(freq[s[k]-'a'] == 1) return 0; 
			freq[s[k]-'a']++;
		}
        return s.length(); 
	}
	
    if(s.length()+arr[i].length()<=26){
		opt1 = UniqueRecursion(arr,i+1,s+arr[i]);
	}
	opt2 = UniqueRecursion(arr,i+1,s);

	return max(opt1,opt2);
}
int UniqueString(vector<string> arr){
	string s ="";
	return UniqueRecursion(arr,0,s);
}
	
int main(){
	vector<string> arr; 
	int n; 
	cin>>n; 
	for(int i=0;i<n;i++){
		string s; 
		cin>>s;
		arr.push_back(s);
	}
	cout<<UniqueString(arr)<<endl; 
return 0;
}