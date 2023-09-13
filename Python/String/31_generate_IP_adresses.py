"""
Idea:
Generating all possible combination of IP addresses, and checking if each combination is valid
"""


class Solution:
    def is_valid(self, ip):
        # Splitting by "."
        ips = ip.split(".")

        # Checking for the corner cases
        for i in ips:
            num = int(i)
            if len(i) > 3 or num < 0 or num > 255:
                return 0

            if len(i) > 1 and num == 0:
                return 0

            if len(i) > 1 and num != 0 and i[0] == '0':
                return 0
        return 1

    # Function converts string to IP address
    def genIp(self, ip):
        l = len(ip)
        check = ip
        ans = []

        if l > 12 or l < 4:
            return ans

        # Generating different combinations.
        for i in range(1, l - 2):
            for j in range(i + 1, l - 1):
                for k in range(j + 1, l):
                    check = check[:i] + "." + check[i:j] + "." + check[j:k] + "." + check[k:]

                    if self.is_valid(check):
                        ans.append(check)
                    check = ip
        return ans


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = input().strip()
        res = Solution().genIp(s)
        res.sort()
        if len(res):
            for u in res:
                print(u)
        else:
            print(-1)
