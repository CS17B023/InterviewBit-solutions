/*Find the contiguous subarray within an array, A of length N which has the largest sum.

Input Format:

The first and the only argument contains an integer array, A.
Output Format:

Return an integer representing the maximum possible sum of the contiguous subarray.
Constraints:

1 <= N <= 1e6
-1000 <= A[i] <= 1000
For example:

Input 1:
    A = [1, 2, 3, 4, -10]

Output 1:
    10

Explanation 1:
    The subarray [1, 2, 3, 4] has the maximum possible sum of 10.

Input 2:
    A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

Output 2:
    6

Explanation 2:
    The subarray [4,-1,2,1] has the maximum possible sum of 6.*/


int cross(const vector<int> &A, int low, int mid, int high)
{
    int sum =  0;
    int left_sum = INT_MIN;
    
    for(int i = mid; i >= low; i--)
    {
        sum += A[i];
        if(sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    
    for(int i = mid + 1; i <= high; i++)
    {
        sum += A[i];
        if(sum > right_sum)
            right_sum = sum;
    }
    
    return left_sum + right_sum;
}


int sumsub(const vector<int> &A, int low , int high)
{
    
    if(low == high)
        return  A[low];
    int mid = (low + high)/2;
    
    int left  = sumsub(A,low,mid);
    int right = sumsub(A,mid+1,high);
    int crossing = cross(A,low,mid,high);
    
    int temp =  max(left,right);
    
    return max(temp,crossing);
}





int Solution::maxSubArray(const vector<int> &A) 
{
    int n    = A.size();
    int low  = 0;
    int high = n-1;
    
    int res  = sumsub(A,low,high); 
}

