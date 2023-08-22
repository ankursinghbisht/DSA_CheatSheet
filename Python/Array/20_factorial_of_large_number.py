"""
Idea: to use basic mathematics for multiplication.
Steps:
-Implement Factorial , while define multiply method using list instead of int multiplication
"""


def multiply(result, n):
    carry = 0
    # Multiply each digit in the result vector with 'n'
    for i in range(len(result)):
        product = result[i] * n + carry  # Calculate the product
        result[i] = product % 10  # Store the last digit of the product
        carry = product // 10  # Update the carry for the next iteration

    # Handle the remaining carry
    while carry > 0:
        result.append(carry % 10)
        carry = carry // 10


def factorial(Number):
    # Initialize the result with 1 (factorial of 1)
    result = [1]
    for i in range(2, Number + 1):
        multiply(result, i)
    result.reverse()  # Reverse the vector to get the correct order
    return result


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        ans = factorial(N)
        for i in ans:
            print(i, end="")
        print()
