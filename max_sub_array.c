
typedef struct
{
   unsigned int low;
   unsigned int high;
    int sum;
}SUBARRAY_TYPEDEF;

SUBARRAY_TYPEDEF FindMaxSubArrayCross(int *A,unsigned int low,unsigned int mid,unsigned int high);
/*
*求最大子数组，采用分治的方法
*输入数组A，下标low，上标high
*返回最大子数组下标i，上标j，返回和sum
*分治法求最大子数组:最大子数组位置有3种情况，要嘛在左子数组，要嘛在右子数组，要嘛在跨越中点的数组，三个最大的之一就是最大子数组
*/
SUBARRAY_TYPEDEF FindMaxSubArray(int *A,unsigned int low,unsigned int high)
{
    unsigned int mid;
    SUBARRAY_TYPEDEF left_max,mid_max,right_max;

    if (low == high)
    {
        mid_max.low = low;
        mid_max.high = high;
        mid_max.sum = *(A + low);

        return mid_max;
    }
    else
    {
        mid = (high + low ) / 2;
        left_max = FindMaxSubArray(A, low, mid);
        right_max = FindMaxSubArray(A, mid + 1, high);
        mid_max = FindMaxSubArrayCross(A, low, mid, high);

        if(left_max.sum >= right_max.sum && left_max.sum >= mid_max.sum)
        {
            return left_max;
        }
        else if(right_max.sum >= left_max.sum && right_max.sum >= mid_max.sum)
        {
            return right_max;
        }
        else
        {
            return mid_max;
        }
    }
}
/*
*该函数求出跨越中点的最大子数组
*/
SUBARRAY_TYPEDEF FindMaxSubArrayCross(int *A,unsigned int low,unsigned int mid,unsigned int high)
{
    unsigned int i,j;
    int sum = 0;
    SUBARRAY_TYPEDEF s,left,right;

    left.low = mid;
    left.sum = 0;
    for (i = mid; i > low; i--)
    {
        sum += A[i];
        if (sum > left.sum)
        {
            left.sum = sum;
            left.low = i;
        }
    }

    sum = 0;
    right.high = mid;
    right.sum = 0;
    for (i = (mid + 1); i < high; i++)
    {
        sum += A[i];
        if (sum > right.sum)
        {
            right.sum = sum;
            right.high = i;
        }
    }
    s.low = left.low;
    s.high = right.high;
    s.sum = left.sum + right.sum;
    return s;
}
