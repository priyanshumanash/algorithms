// We are given a rod of length "n" which can be further cut up into smaller parts all of which should remain an integral multiple.
// Cut it in a way to maximise the profit.
#include <stdio.h>
    
int Memoized_cut_rod_aux(int p[], int n, int r[]);
int max(int q, int p);
int Memoized_cut_rod(int p[], int n);

int max(int q, int p)
{
    if (p >= q)
    {
        return p;
    }
    else
    {
        return q;
    }
}

int Memoized_cut_rod_aux(int p[], int n, int r[])
{
    int q;
    if (r[n] >= 0)
    {
        return r[n];
    }
    if (n == 0)
    {
        q = 0;
    }
    else
    {
        q = -1;
        for(int i = 0; i < n + 1; i++)
        {
            q = max(q, p[i] + Memoized_cut_rod_aux(p, n - 1, r));
        }
    }
    r[n] = q;
    return q;
}

int Memoized_cut_rod(int p[], int n)
{
    int r[n + 1];
    for(int i = 0; i < n + 1; i++)
    {
        r[i] = -1;
    }
    return Memoized_cut_rod_aux(p, n, r);
}

int main()
{
    int p[5] = {1, 5, 8, 9, 10};
    int n = 5;
    int ans = Memoized_cut_rod(p, n);
    printf("%d", ans);
    return 0;
}

/* 
int Cut_rod(int *p, int n);
int Cut_rod(int p[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    int q = -1;
    for (int i = 0; i < n; i++)
    {
        q = max(q, p[i] + Cut_rod(p, n - i));
    }
    return q;
} */
