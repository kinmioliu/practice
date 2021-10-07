class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        array<int, arr.size()> postiveMax;
        array<int, arr.size()> reverseMin;
        int tmpMax = arr[0];
        int tmpMin = arr[arr.size() - 1];
        int chunkCnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            postiveMax[i] = max(tmpMax, arr[i]);
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            reverseMin[i] = min(tmpMin, arr[i]);
        }
        chunkCnt = 1;
        for (int i = 1; i < arr.size() - 1; i++) {
            if (postiveMax[i] == postiveMax[i - 1]) {
                continue;
            } else {
                if (reverseMin[i] >= postiveMax[i - 1]) {
                    chunkCnt++;
                }
                continue;
            }
        }
        return chunkCnt;
    }
};

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> postiveMax(arr.size());
        vector<int> reverseMin(arr.size());
        int chunkCnt = 0;
        postiveMax[0] = arr[0];
        reverseMin[arr.size() - 1] = arr[arr.size() - 1];
        for (int i = 1; i < arr.size(); i++) {
            postiveMax[i] = max(postiveMax[i - 1], arr[i]);
        }
        for (int i = arr.size() - 2; i >= 0; i--) {
            reverseMin[i] = min(reverseMin[i + 1], arr[i]);
        }
        chunkCnt = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (postiveMax[i] == postiveMax[i - 1]) {
                continue;
            } else {
                if (reverseMin[i] >= postiveMax[i - 1]) {
                    chunkCnt++;
                }
                continue;
            }
        }
        return chunkCnt;
    }
};

