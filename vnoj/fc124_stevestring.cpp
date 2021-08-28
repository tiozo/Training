#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAXN    105

char str[MAXN];
int dp[3][MAXN], canDP[MAXN][MAXN][3], vis[MAXN][MAXN][3], cs;
const int INF = 1000000;

inline int min(int u, int v) {return u < v ? u : v;}

bool Can(int st, int ed, char ch)
{
	//Can we reduce the substring [st, ed] to a single character ch?

    if(st == ed) return (str[st] == ch);
    if(vis[st][ed][ch] == cs) return canDP[st][ed][ch];
    vis[st][ed][ch] = cs;

    int u, v, k;
    if(ch == 0) u = 1, v = 2;
    if(ch == 1) u = 0, v = 2;
    if(ch == 2) u = 0, v = 1;

    for(k = st; k < ed; k++)
        if( (Can(st, k, u) && Can(k+1, ed, v)) || (Can(st, k, v) && Can(k+1, ed, u)) )
            return canDP[st][ed][ch] = true;

    return canDP[st][ed][ch] = false;
}

int main()
{
    int i, j, tcase;
    int len, ch;

    scanf("%d", &tcase);
    while(tcase--)
    {
        cs++;
        scanf("%s", str + 1);
        len = strlen( str + 1);

        for(i = 1; i <= len; i++) str[i] -= 'a'; // Replacing a, b & c with 0, 1 & 2.
        for(ch = 0; ch < 3; ch++)
            for(i = 1; i <= len; i++)
            {
                dp[ch][i] = INF;
                for(j = 1; j <= i; j++)
                    if( Can(j, i, ch) )
                        dp[ch][i] = min(dp[ch][i], dp[ch][j-1] + 1);
            }

        printf("%d\n", min(dp[0][len], min(dp[1][len], dp[2][len])));
    }
    return 0;
}
