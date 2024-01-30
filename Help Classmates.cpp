//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    {   
        if(arr.size()==0){
            return arr;
        }
        vector<int> ans;
        if(arr.size()==1){
            ans.push_back(-1);
            return ans;
        }
        
        for(int i=0;i<arr.size()-1;i++){
            bool isBreak = false;
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]>arr[j]){
                    ans.push_back(arr[j]);
                    isBreak= true;
                    break;
                }
                
                
            }
            if(!isBreak){
                ans.push_back(-1);
            }
        }
        while(ans.size()!=arr.size()){
            ans.push_back(-1);
        }
        return ans;
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends
