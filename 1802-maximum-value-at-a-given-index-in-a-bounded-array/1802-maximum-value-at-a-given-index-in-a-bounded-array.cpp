class Solution {
public:
    long get_arithmetic_sequence_sum(int value)
    {
        return (long) (value) * (value + 1) / 2;
    }

    long get_part_sum(int value, int part) 
    {
        if(value > part)
        {
            return get_arithmetic_sequence_sum(value) - get_arithmetic_sequence_sum(value - part);
        }
        else
        {
            return get_arithmetic_sequence_sum(value) + part - value;
        }
    }

    long get_sum(int value, int index, int n)
    {
        int left_n = index + 1;
        int right_n = n - index;
        long sum = get_part_sum(value, left_n) + get_part_sum(value, right_n);
        return sum - value;
    }

    int maxValue(int n, int index, int maxSum) 
    {
        int left = 1, right = maxSum;

        while(left < right) 
        {
            int mid = (left + right + 1) / 2;

            if(get_sum(mid, index, n) <= maxSum)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};