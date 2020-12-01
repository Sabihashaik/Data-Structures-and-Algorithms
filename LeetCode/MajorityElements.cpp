#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> majorityEle(vector<int> arr){
    
    int n= arr.size();
    vector<int> ans;
    int ele1 = arr[0];
    int count1=1;

    int ele2 = 0;
    int count2=0;

    for(int i=1;i<arr.size();i++){
        if(arr[i] == ele1){
            count1++; 
        }
        else if(arr[i] == ele2){
            count2++; 
        }
        else if(count1 == 0){
            ele1 = arr[i];
            count1=1;
        }
        else if(count2 == 0){
            ele2 = arr[i];
            count2=1;
        }
        else{
            count1--;
            count2--;
        }
    }

    count1=count2=0;
    for(int i=0;i<n;i++){
        if(ele1 == arr[i]) count1++;
        if(ele2 == arr[i]) count2++;
    }

    if(count1 > floor(arr.size()/3)){
        ans.push_back(ele1);
    }

    if(count2 > floor(arr.size()/3)){
        ans.push_back(ele2);
    }

    return ans;

}

int main() {
    int n,input; 
    vector<int> arr; 
    cin>>n; 

    for(int i=0;i<n;i++){
        cin>>input; 
        arr.push_back(input);
    }

    vector<int> result = majorityEle(arr);

    for(int ele:result){
        cout<<ele<<" ";
    }
}
