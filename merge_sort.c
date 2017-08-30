#include <stdio.h>

void Merge(unsigned int *A, int p ,int q, int r)
{

    int ln = q - p + 1;
    int rn = r - q;
    unsigned int *lp = (int *)malloc(sizeof( unsigned int) * (ln + 1));
    unsigned int *rp = (int *)malloc(sizeof( unsigned int) * (rn + 1));

    int i,j,k;
    for (i = 0; i < ln; i++)
    {
        *(lp+i) = A[p + i];

    }
    for (i = 0; i < rn ; i++)
    {
        *(rp+i) = A[q + 1 + i];
    }
    *(lp + ln ) = 0xffffffff;
    *(rp + rn) = 0xffffffff;

    i = 0;
    j = 0;

    for (k = p; k <= r;k++)
    {
        if (*(lp+i) > *(rp+j))
        {
            A[k] = *(rp+j);
            j++;
        }
        else
        {
            A[k] = *(lp+i);
            i++;
        }
    }
}

void Merge_Sort(unsigned int *A, int p, int r)
{
    if(p < r)
    {
        int q = (p + r)/2;
        Merge_Sort(A, p, q);
        Merge_Sort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}
void MergeTest(void)
{
    int i;
    unsigned int A[] = {45, 454, 66, 66, 88, 99,2,79,65,55};
    for ( i = 0; i < 10; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");

    Merge_Sort(A,0,9);

    for ( i = 0; i < 10; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
