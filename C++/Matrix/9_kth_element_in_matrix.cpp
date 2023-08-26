
/*
Idea: using priority queue as max heap(highest value element at top) to store elements from matrix,
popping top most element if size of queue exceeds 'k' , after iterating, returning top most element.
*/


#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];


int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<int> maxHeap;
    for (int i = 0;i < n;++i)
        for (int j = 0;j < n;++j)
        {
            //iterating each element and pushing in priority queue
            maxHeap.push(mat[i][j]);
            if (maxHeap.size() > k)
                //if size exceeds k , pop top element
                maxHeap.pop();
        }
    return maxHeap.top();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                cin >> mat[i][j];
        int r;
        cin >> r;
        cout << kthSmallest(mat, n, r) << endl;
    }
    return 0;
}


