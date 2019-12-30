/*Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:

1
Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.*/


int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) 
{
    int i = A.size()-1;
    int j = B.size()-1;
    int k = C.size()-1;
    int mini = INT_MAX;
    
    while(i >= 0 && j >= 0 && k >= 0)
    {
        int temp = max(A[i],max(B[j],C[k]))-min(A[i],min(B[j],C[k]));
        
        if(temp < mini)
            mini = temp;
        int maxi = max(A[i],max(B[j],C[k]));
        
        if(maxi == A[i])
            i--;
        else if(maxi == B[j])
            j--;
        else
            k--;
    }
    return mini;
}
