"""
Algorithm:
The Boyer Moore algorithm combines two heuristics, Bad Character and Good Suffix.
The Bad Character Heuristic identifies a character in the text that doesn't match the pattern's current character and shifts the pattern accordingly.
-Mismatch Becomes a Match: The algorithm aligns the pattern with the last occurrence of the mismatched character in the text.
-Pattern Moves Past the Mismatch: If the character doesn't exist in the pattern before the mismatch, the pattern is shifted past the mismatched character.

"""

NO_OF_CHARS = 256


def badCharHeuristic(string, size):
    # Initialize all occurrence as -1
    badChar = [-1] * NO_OF_CHARS

    # Fill the actual value of last occurrence
    for i in range(size):
        badChar[ord(string[i])] = i

    return badChar


def search(txt, pat):
    m = len(pat)
    n = len(txt)

    # create the bad character list by calling  the preprocessing function badCharHeuristic()  for given pattern
    badChar = badCharHeuristic(pat, m)

    # s is shift of the pattern with respect to text
    s = 0
    while s <= n - m:
        j = m - 1

        # Keep reducing index j of pattern while  characters of pattern and text are matching  at this shift s
        while j >= 0 and pat[j] == txt[s + j]:
            j -= 1

        # If the pattern is present at current shift,  then index j will become -1 after the above loop
        if j < 0:
            print("Pattern occur at shift = {}".format(s))

            '''
            Shift the pattern so that the next character in text
			aligns with the last occurrence of it in pattern.
				The condition s+m < n is necessary for the case when
				pattern occurs at the end of text
			'''
            s += (m - badChar[ord(txt[s + m])] if s + m < n else 1)
        else:
            '''
			Shift the pattern so that the bad character in text
			aligns with the last occurrence of it in pattern. The
			max function is used to make sure that we get a positive
			shift. We may get a negative shift if the last occurrence
			of bad character in pattern is on the right side of the
			current character.
			'''
            s += max(1, j - badChar[ord(txt[s + j])])


def main():
    txt = "ABAAABCD"
    pat = "ABC"
    search(txt, pat)


if __name__ == '__main__':
    main()
