/*
Algorithm:
The Boyer Moore algorithm combines two heuristics, Bad Character and Good Suffix.
The Bad Character Heuristic identifies a character in the text that doesn't match the pattern's current character and shifts the pattern accordingly.
-Mismatch Becomes a Match: The algorithm aligns the pattern with the last occurrence of the mismatched character in the text.
-Pattern Moves Past the Mismatch: If the character doesn't exist in the pattern before the mismatch, the pattern is shifted past the mismatched character.
*/


#include <bits/stdc++.h>
using namespace std;
# define NO_OF_CHARS 256

// The preprocessing function for Boyer Moore's  bad character heuristic
void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
{
    // Initialize all occurrences as -1
    for (int i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    // Fill the actual value of last occurrence  of a character
    for (int i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

void search(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();

    int badchar[NO_OF_CHARS];

    // Fill the bad character array by calling the preprocessing function badCharHeuristic() for given pattern 
    badCharHeuristic(pat, m, badchar);

    int s = 0; // s is shift of the pattern with  respect to text
    while (s <= (n - m))
    {
        int j = m - 1;

        // Keep reducing index j of pattern while characters of pattern and text are matching at this shift s 
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        //If the pattern is present at current shift, then index j will become -1 after the above loop 
        if (j < 0)
        {
            cout << "pattern occurs at shift = " << s << endl;

            /* Shift the pattern so that the next
            character in text aligns with the last
            occurrence of it in pattern.
            The condition s+m < n is necessary for
            the case when pattern occurs at the end
            of text */
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

        }

        else
            /* Shift the pattern so that the bad character
            in text aligns with the last occurrence of
            it in pattern. The max function is used to
            make sure that we get a positive shift.
            We may get a negative shift if the last
            occurrence of bad character in pattern
            is on the right side of the current
            character. */
            s += max(1, j - badchar[txt[s + j]]);
    }
}

int main()
{
    string txt = "ABAAABCD";
    string pat = "ABC";
    search(txt, pat);
    return 0;
}

