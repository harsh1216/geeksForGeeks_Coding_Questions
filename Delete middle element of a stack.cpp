//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMidHelper(stack<int>&s, int count,int &pos)
    {
        
        if(s.empty()){
            return;
            
        }
        if(pos==count){
       
            s.pop();
            return;
        }
        int top=s.top();s.pop();
        deleteMidHelper(s, count+1,pos);
        s.push(top);
    }
     void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        int pos = ceil((sizeOfStack+1)/2.0);
        deleteMidHelper(s, 1, pos);
        
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends
