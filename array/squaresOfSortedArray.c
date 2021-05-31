int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
    int *squares = (int *)malloc(sizeof(int) * numsSize);
    // find pos "0", compare between negative and postive, and extand into two sides
    int fillPos = 0, nPos, pPos, zeroPos = 0;
    int nSquare , pSquare;
    for (; zeroPos < numsSize; zeroPos++) {
        if (nums[zeroPos] >= 0) {
            break;
        }
    }
    pPos = zeroPos;
    nPos = zeroPos - 1;
    
    while (nPos >= 0 && pPos < numsSize) {
        nSquare = nums[nPos] * nums[nPos];
        pSquare = nums[pPos] * nums[pPos];
        if (nSquare < pSquare) {
            squares[fillPos++] = nSquare;
            nPos--;
        } else {
            squares[fillPos++] = pSquare;
            pPos++;
        }
    }

    while (nPos >= 0) {
        nSquare = nums[nPos] * nums[nPos];
        squares[fillPos++] = nSquare;
        nPos--;
    }
 
    while (pPos < numsSize) {
        pSquare = nums[pPos] * nums[pPos];
        squares[fillPos++] = pSquare;
        pPos++;
    }

    *returnSize = fillPos;
    return squares;
}
