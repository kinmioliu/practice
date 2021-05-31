

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int count = 0;
    int preCount = 0;
    int maxCount = 0;
    for (int i = 0; i < numsSize; i++) {
        preCount = count;
        count += nums[i];
        if (count > preCount) {
            continue;
        }
        // reset
        maxCount = maxCount > count ? maxCount : count;
        preCount = 0;
        count = 0;        
    }
    maxCount = maxCount > count ? maxCount : count;     
    return maxCount;
}
