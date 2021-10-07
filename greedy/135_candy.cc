class Solution {
public:
    int candyV2(Vector<int>& ratings) {
        vector<int> candyCnt(ratings.size(), 1);
        int prevRate = ratings[0];
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > prevRate) {
                candyCnt[i] = candyCnt[i - 1] + 1;
            }
            prevRate = ratings[i];
        }
        int nextRate = ratings[ratings.size() - 1];
        for (int i = ratings.size() - 1; i >= 0; i--) {
            if (ratings[i] > nextRate) {
                candyCnt[i] = max(candyCnt[i], candyCnt[i + 1] + 1);
            }
            nextRate = ratings[i];
        }
        int totalCandy = accumulate(candyCnt.begin(), candyCnt.end(), 0);
        return totalCandy;
    }
    int candy(vector<int>& ratings) {
        int i = 1;
        int prevRate = ratings[0];
        int prelineAttr = 1; // 0:down, 1:flat, 2:up
        int prelineTailVal = 1;
        int prelineEndPos = 0;
        bool isLastRate = false;
        int totalCandy = 1;
        int curlineCnt;
        if (ratings.size() <= 1) {
            return totalCandy;
        }
        while(1) {
            // reach to bottom
            while (ratings[i] < prevRate) {
                prevRate = ratings[i];
                i++;
                prelineAttr = 0;
                if(i >= ratings.size()) {
                    isLastRate = true;
                    break;
                }
            }
            if (prelineAttr == 0) {
                curlineCnt = i - 1 - prelineEndPos;
                totalCandy += (1 + curlineCnt)* curlineCnt / 2;
                prelineEndPos = i - 1;
                if (prelineTailVal <= curlineCnt) {
                    totalCandy += curlineCnt + 1 - prelineTailVal;
                }
                //cout << "down:" << curlineCnt << ":" << totalCandy << endl;                
                if (isLastRate) {
                    return totalCandy;
                }
            }
            while (ratings[i] == prevRate) {
                prevRate = ratings[i];
                i++;
                prelineAttr = 1;
                if (i >= ratings.size()) {
                    isLastRate = true;
                    break;
                }
            }
            if (prelineAttr == 1) {
                curlineCnt = i - 1 -prelineEndPos;
                totalCandy += curlineCnt;
                prelineEndPos = i - 1;
                prelineTailVal = 1;
                if (isLastRate) {
                    return totalCandy;
                }                
                //cout << "flat:" << totalCandy << endl;                            
            }
            while (ratings[i] > prevRate) {
                prevRate = ratings[i];
                i++;
                prelineAttr = 2;
                if (i >= ratings.size()) {
                    isLastRate = true;
                    break;
                }
            }
            if (prelineAttr == 2) {
                curlineCnt = i - 1 - prelineEndPos;
                totalCandy += (2 + curlineCnt) * (1 + curlineCnt) / 2 - 1;
                prelineEndPos = i - 1;
                prelineTailVal = curlineCnt + 1;
                if (isLastRate) {
                    return totalCandy;
                }
                //cout << "up:" << curlineCnt << ":" << totalCandy << endl;                            
            }
        }        
    }
};
#if 0
class Solution {
public:
    int candy(vector<int>& ratings) {
        int i = 1;
        int prevRate = ratings[0];
        int prelineAttr = 1; // 0:down, 1:flat, 2:up
        int prelineTailVal = 1;
        int prelineEndPos = 0;
        bool isLastRate = false;
        int totalCandy = 1;
        int curlineCnt;
        while(1) {
            // reach to bottom
            while (ratings[i] < prevRate) {
                prevRate = ratings[i];
                i++;
                prelineAttr = 0;
                if(i >= ratings.size()) {
                    isLastRate = true;
                    break;
                }
            }
            curlineCnt = i - 1 - prelineEndPos;
            totalCandy += (1 + curlineCnt)* curlineCnt / 2;
            prelineEndPos = i - 1;
            totalCandy += curlineCnt + 1 - prelineTailVal;
            if (isLastRate) {
                return totalCandy;
            }
            while (ratings[i] == prevRate) {
                prevRate = ratings[i];
                i++;
                prelineAttr = 1;
                if (i >= ratings.size()) {
                    isLastRate = true;
                    break;
                }
            }
            curlineCnt = i - 1 -prelineEndPos;
            totalCandy += curlineCnt;
            prelineEndPos = i - 1;
            prelineTailVal = 1;
            if (isLastRate) {
                return totalCandy;
            }
            while (ratings[i] > prevRate) {
                prevRate = ratings[i];
                i++;
                prelineAttr = 2;
                if (i >= ratings.size()) {
                    isLastRate = true;
                    break;
                }
            }
            curlineCnt = i - 1 - prelineEndPos;
            totalCandy += (2 + curlineCnt) *(1 + curlineCnt) / 2 - 1;
            prelineEndPos = i - 1;
            prelineTailVal = curlineCnt + 1;
            if (isLastRate) {
                return totalCandy;
            }
        }
    }
};
#endif

