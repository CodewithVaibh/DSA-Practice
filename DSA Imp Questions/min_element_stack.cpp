//You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(s.empty())
           return -1;
           else
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(s.empty())
           return -1;
           else
           {
               int temp=s.top();
               s.pop();
               if(temp<=minEle)
               {
                   int res=minEle;
                   minEle=2*minEle-temp;
                   return res;
               }
               else
               return temp;
           }
           //Write your code here
       }
       
       
       /*push element x into the stack*/
       void push(int x){
           if(s.empty())
           {
               s.push(x);
               minEle=x;
           }
           else if(x<=minEle)
           {
               s.push(2*x-minEle);
               minEle=x;
           }
           else
           {
               s.push(x);
           }
       }
       
};

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends