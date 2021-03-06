// https://www.interviewbit.com/problems/min-steps-in-infinite-grid/
// Input : X and Y co-ordinates of the points in order.
// Each point is represented by (X[i], Y[i])


int Solution::coverPoints(vector<int> &A, vector<int> &B) 
{
    int n = A.size();
    int res = 0;
    for(int i = 0; i < n-1; i++)
    {
        res += max(abs(A[i]-A[i+1]),abs(B[i]-B[i+1]));
    }
    return res;
}

