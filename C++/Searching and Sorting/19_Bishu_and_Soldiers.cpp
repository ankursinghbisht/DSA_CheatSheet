/*
Idea:
At each Iteration of BishuPower vector, iterating each of soldierPower element,
if previous is greater than later, add to answer. Output at each outer loop
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void Solve(vector<int>& soldierPower, vector<int>& BishuPower)
    {
        int n = soldierPower.size(), fights = BishuPower.size(), sum, count;
        for (int i = 0;i < fights;++i)
        {
            sum = count = 0;
            for (int j = 0;j < n;++j)
            {
                if (BishuPower[i] >= soldierPower[j]) // if bishu is stronger than soldier
                {
                    ++count;
                    sum += soldierPower[j];
                }
            }
            cout << count << " " << sum << "\n";
        }
    }

};

int main() {

    int n, t;
    cin >> n;
    vector<int>nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cin >> t;
    vector<int>pow(t);
    for (int i = 0; i < t; i++)
        cin >> pow[i];
    Solution obj;
    obj.Solve(nums, pow);
    return 0;
}