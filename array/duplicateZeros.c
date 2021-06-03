void duplicateZeros(int *arr, int size)
{
    // 1. calculate how many zero need be duplicated, 
    int pos = 0;
    int lastDuplicatedInx = -1;
    int duplicateCnt = 0;
    while (pos + duplicateCnt < size) {
        if (arr[pos] == 0) {
            duplicateCnt++;
            if (pos + duplicateCnt >= size) {
                duplicateCnt--;
                break;
            }
            lastDuplicatedInx = pos;
        }
        pos++;
    }
    // 2. move the elems from the tail of the array
    int movPos = size - 1 - duplicateCnt;
    int fillPos = size - 1;
    while (movPos != fillPos) {
        // duplicate zero
        if (movPos <= lastDuplicatedInx && arr[movPos] == 0) {
            arr[fillPos--] = 0;
        }
        arr[fillPos] = arr[movPos];
        movPos--;
        fillPos--;
    }
}
