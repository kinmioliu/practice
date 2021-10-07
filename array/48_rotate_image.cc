class Solution {
public:
    void rotate90d(int x, int y, int c, int &xp, int &yp)
    {
        /*
        if (x < c && y < c) {
            xp = y;
            yp = x;;
        }
        if (x > c && y < c) {
            
        }
        */
        xp = 2 * c - y;
        yp = x;
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int centerPos = n / 2; // 3->1 2->1 4->2
        int cirCnt = n / 2;
        vector<int> tmp(n, 0);
        int x, y, xp, yp;
        for (int i = 0; i <= cirCnt; i++) {
            
            // up
            x = centerPos - (cirCnt - i);
            y = centerPos - (cirCnt - i);
            t = 0;
            while (x <= (n - 1 - i * 2)) {
                rotate90d(x, y, centerPos, xp, yp);
                tmp[t++] = matrix[xp][yp];
                matrix[xp][yp] = matrix[x][y];
                x++;
            }
            // right
            t = 0;
            while (y <= (n - 1 - i * 2)) {
                rotate90d(x, y, centerPos, xp, yp);
                swap(tmp[t], matrix[xp][yp]);
                t++;
                y++;
            }
            // down
            t = 0;
            while (x > centerPos - (cirCnt - i)) {
                rotate90d(x, y, centerPos, xp, yp);
                swap(tmp[t], matrix[xp][yp]);
                t++
                x--;
            }
            // left
            t = 0;
            while (y > (centerPos - (cirCnt - i))) {
                rotate90d(x, y, centerPos, xp, yp);
                swap(tmp[t], matrix[xp][yp]);
                t++;
                y--;
            }
        }        
    }
};
