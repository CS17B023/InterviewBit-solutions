/*Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.*/


bool cmp(string a,string b)
{
    string s1 = a.append(b);
    string s2 = b.append(a);
    if(s1 > s2)
        return true;
    else
        return false;
    }
string Solution::largestNumber(const vector<int> &A)
{
    vector<string> Ans;
    string s="";
    int i,c=0;
    for(i=0;i<A.size();i++)
    {
        Ans.push_back(to_string(A[i]));
        if(A[i]==0)
            c++;
    }
    if(A.size()==c)
        return "0";
    sort(Ans.begin(),Ans.end(),cmp);
    for(i=0;i<Ans.size();i++)
        s+=Ans[i];
    return s;
}