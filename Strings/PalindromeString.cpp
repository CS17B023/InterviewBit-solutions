/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem*/

int Solution::isPalindrome(string A)
{
    string temp = "";
    
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] >= 'A' && A[i] <= 'Z')
            temp += A[i]-'A' + 'a';
        else if(A[i] >= 'a' && A[i] <= 'z')
            temp += A[i];
        else if(A[i] >= '0' && A[i] <= '9')
            temp += A[i];
    }
    
    int low = 0;
    int high = temp.size()-1;
    
    while(low <= high)
    {
        if(temp[low] != temp[high])return false;
        
        low++;
        high--;
    }
    return true;
}
