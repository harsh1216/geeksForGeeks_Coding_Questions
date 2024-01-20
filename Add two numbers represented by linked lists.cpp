//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

Node* reverseList(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr=next;
    }
    return prev;
}

void insertAtHead(int data,Node* &head){
    Node* temp = new Node(data);
    if(head->data==-1){
        delete head;
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {   
        if(first==NULL){
            return second;
        }
        if(second==NULL){
            return first;
        }
        Node* A = reverseList(first);
        Node* B = reverseList(second);
        Node* ansHead = new Node(-1);
        int carry=0;
        while(A!=NULL && B!=NULL){
            int sum = A->data + B->data + carry;
            carry = 0;
            if(sum>=10){
                carry = sum/10;
                sum = sum%10;
            }
            insertAtHead(sum,ansHead);
            A=A->next;
            B=B->next;
        }
        while(A!=NULL){
            int sum = A->data+carry;
            if(sum>=10){
                carry= sum/10;
                sum=sum%10;
            }else{
                carry =0;
            }
            insertAtHead(sum,ansHead);
            A= A->next;
            
        }
        while(B!=NULL){
            int sum = B->data+carry;
            if(sum>=10){
                carry= sum/10;
                sum=sum%10;
            }else{
                carry =0;
            }
            insertAtHead(sum,ansHead);
            B=B->next;
        }
        if(carry!=0){
            insertAtHead(carry,ansHead);
        }
        return ansHead;
        
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
