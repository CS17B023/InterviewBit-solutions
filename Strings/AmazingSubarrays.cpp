/*You are given a string S, and you have to find all the amazing substrings of S.

Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).

Input

Only argument given is string S.
Output

Return a single integer X mod 10003, here X is number of Amazing Substrings in given string.
Constraints

1 <= length(S) <= 1e6
S can have special characters
Example

Input
    ABEC

Output
    6

Explanation
	Amazing substrings of given string are :
	1. A
	2. AB
	3. ABE
	4. ABEC
	5. E
	6. EC
	here number of substrings are 6 and 6 % 10003 = 6.*/


int Solution::solve(string A) 
{
    int n = A.size();
    int count = 0;
     for (int i = 0; i < n; i++)
     {
        for (int len = 1; len <= n - i; len++) 
        {
             string temp = A.substr(i, len); 
             if( temp[0] == 'A' || temp[0] == 'E' || temp[0] =='I' || temp[0] == 'O' || temp[0] == 'U' || temp[0] == 'a' || temp[0] == 'e' || temp[0] == 'i' || temp[0] == 'o' || temp[0] == 'u' )
                count = (count + 1)%10003;
        }
     }
    return count;
}
