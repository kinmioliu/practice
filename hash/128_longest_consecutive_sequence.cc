class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unsorted_map<int, pair<int, int>> hahsmap;
        int maxc = 0;
        for (int i = 0; i < nums.size(); i++) {
            hashmap.insert(make_pair(nums[i], make_pair(i, 0)));
        }
        for (int i = 0; i < nums.size(); i++) {
            auto curpos = hashmap.find(nums[i]);
            if (curpos == hahsmap.end()) {
                continue;
            }
            do {
                auto pos = hashmap.find(nums[i] - 1);
                if (pos != hashmap.end()) {
                    curpos->second.second += pos->second.second + 1;
                    hahsmap.erase(pos);
                    continue;
                } else {
                    break;
                }
            } while (1);
        }
        for (auto pos = hahsmap.begin(); pos != hashmap.end(); pos++) {
            maxc = max(pos->second.second, maxc);
        }
        return maxc + 1; // need add self;                
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        unordered_map<int, pair<int, int>> hashmap;
        int maxc = 0;
        for (int i = 0; i < nums.size(); i++) {
            hashmap.insert(make_pair(nums[i], make_pair(i, 0)));
        }
        for (int i = 0; i < nums.size(); i++) {
            auto curpos = hashmap.find(nums[i]);
            if (curpos == hashmap.end()) {
                continue;
            }
            int cnt = 1;
            do {
                auto pos = hashmap.find(nums[i] - cnt++);
                if (pos != hashmap.end()) {
                    curpos->second.second += pos->second.second + 1;
                    hashmap.erase(pos);
                    continue;
                } else {
                    break;
                }
            } while (1);
        }
        for (auto pos = hashmap.begin(); pos != hashmap.end(); pos++) {
            //cout << "(" << pos->first << "," << pos->second.first << "," << pos->second.second << ")";
            maxc = max(pos->second.second, maxc);
        }
        return maxc + 1; // need add self;
    }
};

