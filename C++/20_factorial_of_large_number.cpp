/*
Idea: to use basic mathematics for multiplication.
Steps:
-Implement Factorial , while define multiply method using vector instead of int multiplication
*/


#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> factorial(int N)
    {
        vector<int> result; // Vector to store the digits of the factorial
        result.push_back(1); // Initialize the result with 1 (factorial of 1)

        for (int i = 2; i <= N; ++i)
            multiply(result, i); // Multiply the result with the current number

        reverse(result.begin(), result.end()); // Reverse the vector to get the correct order
        return result;
    }

    void multiply(vector<int>& result, int n)
    {
        int carry = 0, product;

        // Multiply each digit in the result vector with 'n'
        for (int i = 0; i < result.size(); ++i)
        {
            product = result[i] * n + carry; // Calculate the product
            result[i] = product % 10; // Store the last digit of the product
            carry = product / 10; // Update the carry for the next iteration
        }

        // Handle the remaining carry
        while (carry > 0)
        {
            result.push_back(carry % 10); // Store the last digit of the carry
            carry /= 10; // Move to the next digit of the carry
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}