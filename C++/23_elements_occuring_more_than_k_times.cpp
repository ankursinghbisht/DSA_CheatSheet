/*
Question: find elements occurring more than n/k times, n=length, and k-constant
Idea:
Counting occurrences of each element, and checking if any surpass the threshold
*/
#include<bits/stdc++.h>
using namespace std;


vector<int> elementsAppearance(int arr[], int n, int k)
{
    map<int, int> mp;
    vector<int> ans;

    //Counting each element's occurrences
    for (int i = 0;i < n;++i)
        mp[arr[i]]++;

    for (auto it : mp)
    {
        //if count reaches threshold , append in result
        if (it.second > (n / k))
            ans.push_back(it.first);
    }
    return ans;
}

int main()
{
    int arr[] = { 1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    vector<int>ans = elementsAppearance(arr, n, k);
    for (int i = 0;i < ans.size();++i)
        cout << ans[i] << " ";
    cout << "\n";
}