//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends


//function Template for C++

//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    // add code here.
    stack<int> s;
    
    //putting into stack
    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }
    
    //removing from stack and putting into queue
    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
    
    return q;
}