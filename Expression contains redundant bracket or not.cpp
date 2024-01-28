//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
int checkRedundancy(string s) {
        stack<int>st;
        int i=0;
        while(i<s.length()){
            if(s[i]==')'){
                int flag=0;
                while(st.top()!='('){
                    if(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/'){
                        flag=1;
                    }
                    st.pop();
                }
                st.pop();
                if(flag==1)
                    i++;
                else return 1;
            }
            else{
                st.push(s[i++]);
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
