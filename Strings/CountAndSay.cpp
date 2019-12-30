/*The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.*/

string Solution::countAndSay(int A) 
{
    string res = "1";
    if(A == 1)
        return res;
    res += "1";
    if(A == 2) return res;
    
    for(int i =3; i <= A; i++)
    {
        string temp = "";
        for(int i = 0; i < res.size();)
        {
            char c = res[i];
            int count = 0;
            int j = i;
            while(res[j] == c)
            {
                count++;
                j++;
            }
            temp = temp + to_string(count) + c; 
            i = j;
        }
        res = temp;
    }
    return res;
}
