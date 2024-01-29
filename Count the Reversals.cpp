//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends

int solve(stack<char> & st){
  int count = 0;
  while(!st.empty()){
    char temp1 = st.top();
    st.pop();
    char temp2 = st.top();
    st.pop();
    if(temp1=='{'&&temp2=='}'){
      count+=2;
    }else{
      count+=1;
    }
  }
  return count;
}
int countRev (string str)
{
       int sizeStr = str.size();
   if(sizeStr==0){
     return 0;
   }
   if(sizeStr%2!=0){
     return -1;
   }
   stack<char> st;
   for(int i=0;i<sizeStr;i++){
     if((!st.empty() && st.top()=='{') && str[i]=='}'){
       st.pop();
     }else{
       st.push(str[i]);
     }
   }
   return solve(st);
}
