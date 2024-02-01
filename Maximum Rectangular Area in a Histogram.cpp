//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{   public:
     vector<long long> nextSmallElement(long long arr[],int n)
    {
        vector<long long> res(n);
        stack<long long> s;
        s.push(-1);
        for(int i=n-1;i>=0;i--)
        {
            
            while(s.top()!=-1 && arr[s.top()]>=arr[i])
            s.pop();

            res[i]=s.top();
            s.push(i);
        }
        return res;
    }
    vector<long long> prevSmallElement(long long arr[],int n)
    {
        vector<long long> res(n);
        stack<long long> s;
        s.push(-1);
        
        for(int i=0;i<n;i++)
        {
            while(s.top()!=-1 && arr[s.top()]>=arr[i])
            s.pop();
            
            res[i]=s.top();
            s.push(i);
        }
        return res;
    }
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long res=0;
        vector<long long> NS,PS;
        PS=prevSmallElement(arr,n);
        NS=nextSmallElement(arr,n);
        
       for(int i=0;i<n;i++)
       {
           long long  in=arr[i];
           if(NS[i]==-1)
           NS[i]=n;
           long long r=NS[i]-PS[i]-1;
           long long curr=in*r;
           res=max(curr,res);
       }
      
       return res;
        
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
