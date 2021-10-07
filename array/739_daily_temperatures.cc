class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> deltas(temperatures.size() - 1, 0);
        for (int i = 1; i < temperatures.size(); i++) {
            deltas[i - 1] = temperatures[i] - dailyTemperatures[i - 1];
        }
        vector<int> ans(temperatures.size(), 0);
        vector<pair<int, int>> v;
        for (int i = 0; i < deltas.size(); i++) {
            if (v.empty()) {
                if(deltas[i] > 0) {
                    ans[i] = 1;
                } else {
                    v.push_back(make_pair(deltas[i], i));
                }
           } else {
                if (deltas[i] > 0) {
                    ans[i] = 1;
                    v.push_back(make_pair(deltas[i], i));
                    while (!v.empty() && v.back().first > 0) {
                        int v = v.back().first;
                        ans[v.back().second] = i - v.back().second + 1;
                        v.pop_back();
                        v[v.size() - 1].first += v;
                    }
                } else {
                    v.push_back(make_pair(deltas[i], i));
                }
           }
        }
        for (auto a : ans) {
            cout << a << " ";
        }
        cout << endl;
        return ans;
/*        
        int sum = 0;
        for (int i = 0; i < deltas.size(); i++) {
            if (v.empty()) {
                sum = 0;
                if (deltas[i] > 0) {
                    ans[i] = 1;
                } else {
                    v.push_back(deltas[i]);
                    sum += deltas[i];
                }
            } else {
                if (deltas[i] > 0) {
                    if (deltas[i] + v.back() > 0) {
                        ans[i - 1] = 1;
                    }
                    v[v.size() - 1] += deltas[i];
                    sum += deltas[i];
                }
                sum += deltas[i];
                if (sum <= 0) {
                    v.push_back(deltas[i]);
                } else {
                    // pop stack
                    int days = 0;
                    while (sum > 0) {
                        sum -= v.back();
                        v.pop_back();
                        ans[i - days] = days + 1;
                        days++;
                   }
                }
            }
        }
*/        
    }
};




class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> deltas(temperatures.size() - 1, 0);
        for (int i = 1; i < temperatures.size(); i++) {
            deltas[i - 1] = temperatures[i] - temperatures[i - 1];
        }
        vector<int> ans(temperatures.size(), 0);
        vector<pair<int, int>> v;
        for (int i = 0; i < deltas.size(); i++) {
            if (v.empty()) {
                if(deltas[i] > 0) {
                    ans[i] = 1;
                } else {
                    v.push_back(make_pair(deltas[i], i));
                }
           } else {
                if (deltas[i] > 0) {
                    /*
                    for (auto a : ans) {
                        cout << a << " ";
                    }
                    cout << endl;
                    for (auto p : v) {
                        cout << p.first << "|" << p.second << " ";
                    }
                    cout << endl;
                    */
                    ans[i] = 1;
                    v.push_back(make_pair(deltas[i], i));
                    while (!v.empty() && v.back().first > 0) {
                        int val = v.back().first;
                        ans[v.back().second] = i - v.back().second + 1;
                        v.pop_back();
                        if (!v.empty()) {
                            v[v.size() - 1].first += val;
                        }
                    }
                } else {
                    v.push_back(make_pair(deltas[i], i));
                }
           }
        }
        /*
        for (auto a : ans) {
            cout << a << " ";
        }
        cout << endl;
        */
        return ans;
/*
        int sum = 0;
        for (int i = 0; i < deltas.size(); i++) {
            if (v.empty()) {
                sum = 0;
                if (deltas[i] > 0) {
                    ans[i] = 1;
                } else {
                    v.push_back(deltas[i]);
                    sum += deltas[i];
                }
            } else {
                if (deltas[i] > 0) {
                    if (deltas[i] + v.back() > 0) {
                        ans[i - 1] = 1;
                    }
                    v[v.size() - 1] += deltas[i];
                    sum += deltas[i];
                }
                sum += deltas[i];
                if (sum <= 0) {
                    v.push_back(deltas[i]);
                } else {
                    // pop stack
                    int days = 0;
                    while (sum > 0) {
                        sum -= v.back();
                        v.pop_back();
                        ans[i - days] = days + 1;
                        days++;
                   }
                }
            }
        }
*/
    }
};

