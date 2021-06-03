#include <stdio.h>
#include "findMaxConsecutiveOnes.c"
#include "findNumsWithEvenDigits.c"
#include "duplicateZeros.c"

#define TEST_CASE(case_name) \
    void TEST_CASE_##case_name() \
    { \
        const char* __case_name = #case_name; \
        int pass_flag = 1; \
        do { \

#define TEST_CASE_END \
        } while(0); \
        if (pass_flag) { \
            printf("%s passed!\n", __case_name); \
        } else { \
            printf("%s failed!\n", __case_name); \
        } \
    } 

#define EXPECT(a) \
        if (!(a)) { \
            printf("%s:%d EXPECT error.\n", __FUNCTION__, __LINE__); \
            pass_flag = 0; \
        }

TEST_CASE(findmax)
{   
    int nums[] = {1,0,1,1,0,1};
    int ret = findMaxConsecutiveOnes(nums, sizeof(nums)/sizeof(int));
    EXPECT(ret == 2);
}
TEST_CASE_END

TEST_CASE(findNumbers)
{
    int nums[] = {555,901,482,1771};
    int ret = findNumbers(nums, sizeof(nums) / sizeof(int));
    EXPECT(ret == 1);
}
TEST_CASE_END

TEST_CASE(duplicateZeros)
{
    int arr[] = {1,2,0,4,0,6,0,8,9};
    duplicateZeros(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
TEST_CASE_END

int main(int argc, char *argv[])
{
    TEST_CASE_findmax();
    TEST_CASE_findNumbers();
    TEST_CASE_duplicateZeros();
    return 0;        
}
