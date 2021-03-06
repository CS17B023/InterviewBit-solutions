/*Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

 Example: Input : 
    A : [1 3 5] 
    k : 4
 Output : YES as 5 - 1 = 4 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Try doing this in less than linear space complexity.*/

int Solution::diffPossible(vector<int> &A, int B) 
{
    if(A.size() == 1)return 0;
    int low  = 0;
    int high = 1;
    int diff;
    int n = A.size();
    
    if(B == 0)
    {
        for(int i = 1; i < n; i++)
        {
            if(A[i] == A[i-1])return 1;
        }
        return 0;
    }
    while(low < n && high < n)
    {
        diff = A[high] - A[low];
        
        if(diff == B && low != high)
            return 1;
        else if(diff < B)
            high++;
        else 
            low++;
    }
    return 0;
    
}
