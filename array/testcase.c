#include <stdio.h>
#include "findMaxConsecutiveOnes.c"

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


int main(int argc, char *argv[])
{
    TEST_CASE_findmax();
    return 0;        
}
