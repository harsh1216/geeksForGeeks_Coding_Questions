//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}


// } Driver Code Ends


//return the address of the string
char* reverse(char *S, int len)
{   if(len==0|| len==1){
    return S;
}
    int i =0;
    stack<char> st;
    while(len>i){
        st.push(S[i++]);
    }
    i =0 ;
    char* ans = new char[len];
    while(len>i){
        ans[i++]=st.top();
        st.pop();
    }
    return ans;
}
