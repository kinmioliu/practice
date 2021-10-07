class Solution {
public:
    int mySqrt(int x) {
        // find low bound from 0 - x m which m**2 <= x
        int l = 0, r = x
        long m, s;
        while (l != r) {
            m = (l + r) / 2;
            s = m * m;
            if (s < x) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        // find low bound from 0 - x m which m**2 <= x
        long l = 0, r = x;
        long m, s;
        while (l < r) {
            m = (l + r) / 2;
            s = m * m;
            //s = m;
            //cout << l << r << s << endl;
            if (s < x) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        s = l * l;
        if (s > x) {
            return l - 1;
        } else {
            return l;
        }
    }
};

