"""
Rabin Karp Algorithm uses Sliding windows technique, with addition of hashing
At each iteration, checking the hash value of window with pattern, if match -only then check the alphabets 1 by 1
"""

# d is the number of characters in the input alphabet
d = 256


def search(pat, txt, q):  # A prime number
    M = len(pat)
    N = len(txt)
    j = 0
    p = 0  # hash value for pattern
    t = 0  # hash value for txt
    h = 1

    # The value of h would be "pow(d, M-1)%q"
    for i in range(M - 1):
        h = (h * d) % q

    # Calculate the hash value of pattern and first window  of text
    for i in range(M):
        p = (d * p + ord(pat[i])) % q
        t = (d * t + ord(txt[i])) % q

    # Slide the pattern over text one by one
    for i in range(N - M + 1):
        # Check the hash values of current window of text and pattern
        if p == t:
            # Check for characters one by one
            for j in range(M):
                if txt[i + j] != pat[j]:
                    break
                else:
                    j += 1
            if j == M:
                print("Pattern found at index " + str(i))

        # Calculate hash value for next window of text:
        if i < N - M:
            t = (d * (t - ord(txt[i]) * h) + ord(txt[i + M])) % q

            # We might get negative values of t, converting it to  positive
            if t < 0:
                t = t + q


if __name__ == '__main__':
    txt = "GEEKS FOR GEEKS"
    pat = "GEEK"

    q = 101

    search(pat, txt, q)
