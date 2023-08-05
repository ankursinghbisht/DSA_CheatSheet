"""
Remember one rule :- You can only buy one time & sell one time

Idea:
If we choose the minimum number at each element, and find the highest difference if sold at current element,
saving the highest difference will be the answer.
"""


def maxProfit(prices):
    least = prices[0]
    result = 0
    profit = 0
    # setting up least value, result, and profit

    for i in range(len(prices)):
        if prices[i] < least:
            # checking if current element is least of the list
            least = prices[i]

        profit = prices[i] - least  # calculating the profit
        if profit > result:
            # saving if profit is greater than max.
            result = profit

    return result


if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        a = int(input())
        array1 = list(map(int, input().strip().split()))
        ans = maxProfit(array1)
        print(ans)
