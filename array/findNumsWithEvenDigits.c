/*
 * 2 has 1 digit
 * 12 has 2 digit
 * 121 has 3 digit
 * */
int getDigitNums(int number)
{
    int count = 1;
    int divider = 10;
    while (number / divider != 0) {
        count++;
        divider *= 10;
    }
    return count;
}

/*
 * input constrains:
 * 1 <= numSize <= 500
 * nums <= 10^5
 * */
int findNumbers(int *nums, int numSize)
{
    int count = 0;
    for (int i = 0; i < numSize; i++) {
        if (getDigitNums(nums[i]) % 2 == 0) {
            count++;
        }
    }
    return count;
}
