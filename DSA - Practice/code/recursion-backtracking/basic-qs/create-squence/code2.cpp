
void solve(long long target, long long curr, vector<long long> &ans)
{

    if (curr * 10 + 2 <= target)
    {
        ans.push_back(curr * 10 + 2);
        solve(target, curr * 10 + 2, ans);
    }

    if (curr * 10 + 5 <= target)
    {
        ans.push_back(curr * 10 + 5);
        solve(target, curr * 10 + 5, ans);
    }
}

vector<long long> createSequence(long long n)
{
    // Write your code here.

    vector<long long> ans;
    long long curr = 0;
    solve(n, curr, ans);
    sort(ans.begin(), ans.end());

    return ans;
}