#include <stdio.h>

#define ROWS    2
typedef struct
{
    int row,line;   //行属性，列属性
    int val[ROWS][ROWS];
}MATRIX_TYPE;

/*
*函数功能:矩阵A、B、C都是N*N的矩阵，求出C = A * B
*该原始算法运算时间为rows的三次方
*/
MATRIX_TYPE SquareMatrix_Multiply(MATRIX_TYPE *a, MATRIX_TYPE *b)
{
    int i,j,k;
    MATRIX_TYPE c;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < ROWS; j++)
        {
            c.val[i][j] = 0;
            for (k = 0; k < ROWS; k++)
            {
                c.val[i][j] +=  a->val[i][k] * b->val[k][j];
            }
            printf("c[%d][%d] = %d;\n",i,j,c.val[i][j]);
        }
    }
    return c;
}


MATRIX_TYPE MatrixAdd(MATRIX_TYPE *a, MATRIX_TYPE *b,int size)
{
    int i,j;
    MATRIX_TYPE c;

    for (i = 0; i < size; i++)
    {
        for ( j = 0; j < size; j++)
        {
            c.val[i][j] = a->val[i][j] + b->val[i][j];
        }
    }
    return c;
}
MATRIX_TYPE MatrixSub(MATRIX_TYPE *a, MATRIX_TYPE *b,int size)
{
    int i,j;
    MATRIX_TYPE c;

    for (i = 0; i < size; i++)
    {
        for ( j = 0; j < size; j++)
        {
            c.val[i][j] = a->val[i][j] - b->val[i][j];
        }
    }
    return c;
}

MATRIX_TYPE MatrixMul(MATRIX_TYPE *a, MATRIX_TYPE *b,int size)
{
    int i,j,k;
    MATRIX_TYPE c;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            c.val[i][j] = 0;
            for (k = 0; k < size; k++)
            {
                c.val[i][j] +=  a->val[i][k] * b->val[k][j];
            }
        }
    }
    return c;
}
/*
s1 = b12 - b22
s2 = a11 + a12
s3 = a21 + a22
s4 = b21 - b11
s5 = a11 + a22
s6 = b11 + b22
s7 = a12 - a22
s8 = b21 + b22
s9 = a11 - a21
s10 = b11 + b12
p1 = a11 * s1
p2 = s2  * b22
p3 = s3  * b11
p4 = a22 * s4
p5 = s5 * s6
p6 = s7 * s8
p7 = s9 * s10
c11 = p5 + p1 - p2 + p6
c12 = p1 + p2
c21 = p3 + p4
c22 = p5 + p1 -p3 -p7
*/
MATRIX_TYPE StrassenMatrix(MATRIX_TYPE *a, MATRIX_TYPE *b)
{
    MATRIX_TYPE a11, a12, a21, a22;
    MATRIX_TYPE b11, b12, b21, b22;
    int i,j;
    int half_size = ROWS/2;

    MATRIX_TYPE s1,s2,s3,s4,s5,s6,s7,s8,s9,s10;
    MATRIX_TYPE p1,p2,p3,p4,p5,p6,p7;
    MATRIX_TYPE c11,c12,c21,c22;
    MATRIX_TYPE c;

    for (i = 0; i < half_size; i++)
    {
        for (j = 0; j < half_size; j++)
        {
            a11.val[i][j] = a->val[i][j];
            a12.val[i][j] = a->val[i][j + half_size];
            a21.val[i][j] = a->val[i + half_size][j];
            a22.val[i][j] = a->val[i + half_size][j + half_size];

            b11.val[i][j] = b->val[i][j];
            b12.val[i][j] = b->val[i][j + half_size];
            b21.val[i][j] = b->val[i + half_size][j];
            b22.val[i][j] = b->val[i + half_size][j + half_size];
        }
    }
    s1 = MatrixSub(&b12, &b22, half_size);
    s2 = MatrixAdd(&a11, &a12, half_size);
    s3 = MatrixAdd(&a21, &a22, half_size);
    s4 = MatrixSub(&b21, &b11, half_size);
    s5 = MatrixAdd(&a11, &a22, half_size);
    s6 = MatrixAdd(&b11, &b22, half_size);
    s7 = MatrixSub(&a12, &a22, half_size);
    s8 = MatrixAdd(&b21, &b22, half_size);
    s9 = MatrixSub(&a11, &a21, half_size);
    s10 = MatrixAdd(&b11, &b12, half_size);

    p1 = MatrixMul(&a11, &s1, half_size);
    p2 = MatrixMul(&b22, &s2, half_size);
    p3 = MatrixMul(&b11, &s3, half_size);
    p4 = MatrixMul(&a22, &s4, half_size);
    p5 = MatrixMul(&s5, &s6, half_size);
    p6 = MatrixMul(&s7, &s8, half_size);
    p7 = MatrixMul(&s9, &s10, half_size);

    c11 = MatrixAdd(&p5, &p4, half_size);
    c11 = MatrixSub(&c11, &p2,half_size);
    c11 = MatrixAdd(&c11, &p6,half_size);

    c12 = MatrixAdd(&p1, &p2, half_size);

    c21 = MatrixAdd(&p3, &p4, half_size);

    c22 = MatrixAdd(&p5, &p1, half_size);
    c22 = MatrixSub(&c22, &p3,half_size);
    c22 = MatrixSub(&c22, &p7,half_size);

    for (i = 0; i < half_size; i++)
    {
        for (j = 0; j < half_size; j++)
        {
            c.val[i][j] = c11.val[i][j];
            c.val[i][j + half_size] = c12.val[i][j];
            c.val[i + half_size][j] = c21.val[i][j];
            c.val[i + half_size][j + half_size] = c22.val[i][j];
        }
    }
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < ROWS; j++)
        {
            printf("%d ",c.val[i][j]);
        }
        printf("\n");
    }
    return c;
}

void MatrixTest(void)
{
    MATRIX_TYPE a, b;

    a.val[0][0] = 1;
    a.val[0][1] = 3;
    a.val[1][0] = 7;
    a.val[1][1] = 5;
    b.val[0][0] = 6;
    b.val[0][1] = 8;
    b.val[1][0] = 4;
    b.val[1][1] = 2;
    StrassenMatrix(&a, &b);
    StrassenMatrix(&a ,&b);
}
