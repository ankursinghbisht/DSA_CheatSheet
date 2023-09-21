/*
Idea:
Starting from -inf to +inf, using ternary search to find the minimum distance at each iteration

( Ternary search is a divide-and-conquer search algorithm that iteratively narrows down a search space
 into "three" equal parts and eliminates one-third of the space in each iteration)
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double dist(double x, double y, pair<int, int>p) {
        return sqrt(sq(x - p.first) + sq(y - p.second));
    }
    double compute(vector<pair<int, int>>p, int n, tuple<int, int, int>l, double X) {
        double res = 0;

        // calculating Y of chosen point by line equation
        double Y = -1 * (get<2>(l) + get<0>(l) * X) / get<1>(l);
        for (int i = 0; i < n; i++) {
            res += dist(X, Y, p[i]);
        }
        return res;
    }

    // Utility method to find minimum total distance
    double findOptimumCost(tuple<int, int, int>l, vector<pair<int, int>>p, int n) {
        double low = -1e6;
        double high = 1e6;

        // loop until difference between low and high become less than EPS
        while ((high - low) > EPS) {
            // mid1 and mid2 are representative x co-ordiantes  of search space
            double mid1 = low + (high - low) / 3;
            double mid2 = high - (high - low) / 3;


            double dist1 = compute(p, n, l, mid1);
            double dist2 = compute(p, n, l, mid2);

            // if mid2 point gives more total distance, skip third part
            if (dist1 < dist2)
                high = mid2;

            // if mid1 point gives more total distance, skip first part
            else
                low = mid1;
        }

        // compute optimum distance cost by sending average of low and high as X
        return compute(p, n, l, (low + high) / 2);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        tuple<int, int, int>line;
        int a, b, c;
        cin >> a >> b >> c;
        line = make_tuple(a, b, c);
        int n;
        cin >> n;
        vector<pair<int, int>>points;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            points.push_back({ x, y });
        }

        Solution ob;
        double ans = ob.findOptimumCost(line, points, n);

        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}
