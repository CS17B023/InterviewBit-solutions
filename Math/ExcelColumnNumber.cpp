/*Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 */

int Solution::titleToNumber(string A)
{
    int n = A.size();
    int res = 0, j = n-1;
    for(int i = 0; i < n; i++)
    {
        int x = A[i]-'A'+1;
        res = res + pow(26,j)*x;
        j--;
    }
    return res;
}
