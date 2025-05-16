#include <stdio.h>
#include <string.h>
#define d 256  // Number of characters in the input alphabet
#define q 101  // A prime number for mod

void rabinKarp(char *pat, char *txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0, t = 0, h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate hash value for pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text
    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            // Check characters one by one
            for (j = 0; j < M; j++)
                if (txt[i + j] != pat[j])
                    break;

            if (j == M)
                printf("Rabin-Karp Match found at index %d\n", i);
        }

        // Calculate hash for next window
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}
int main() {
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
    rabinKarp(pat, txt);
    return 0;
}
