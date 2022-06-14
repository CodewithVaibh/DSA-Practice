//A Professor conducts a Computer Science paper for N students. He had strictly instructed all students to sit according to their roll numbers. However when he started checking the papers, he found out that all the papers were randomly ordered because the students had sat randomly during the exam instead of sitting according to their roll numbers. The order is given in list of integers roll[ ]. The professor became very angry and he wanted to teach the students a lesson.
//He decided to sort the papers according to roll numbers by Bubble Sort and count the number of swaps required for each and every student and deduct as many marks of a student as were the number of swaps required for that student. The marks of every student is given in list of integers marks[ ] in the order in which they were sitting. However he also has to maintain the class average greater than or equal to a set minimum avg, else he may lose his job. The Professor wants to know whether he should punish the students or save his job.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int shouldPunish (int roll[], int marks[], int n, double avg)
    {
        // your code here
        bool isswap;
        int count=0;
            for(int i=0;i<n-1;i++)
            {
                isswap=false;
                for(int j=0;j<n-1-i;j++)
                {
                if(roll[j]>roll[j+1])
                {
                    swap(roll[j],roll[j+1]);
                    isswap=true;
                    count++;
                }
                }
                if(isswap==false)
                break;
            }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=marks[i];
        }
        sum-=count;
        int average=sum/n;
        if(average>=avg)
        return 1;
        else
        return 0;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		double avg; cin >> avg;

		int roll[n];
		int marks[n];

		for (int i = 0; i < n; ++i)
			cin >> roll[i];
		for (int i = 0; i < n; ++i)
			cin >> marks[i];
        Solution ob;
		cout << ob.shouldPunish (roll, marks, n, avg) << endl;
	}
}
  // } Driver Code Ends