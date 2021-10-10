class Solution {
private:
    int convertStr2Int(const string& str)
    {
        return stoi(str);
    }

    int operate(int l, int r, char o) 
    {
        if (o == '+') {
            return l + r;
        } else if (o == '-') {
            return l - r;
        } else if (o == '*') {
            return l * r;
        } else {
            return l / r;
        }
    }

    inline bool isOperator(char o) 
    {
        return o == '+' || o == '-' || o == '*' || o == '/';
    }
    
public:
    /* 3+5/2-4/3 */
    int calculate(string s) {
        stack<int> integers;
        stack<char> operators;
        for (int i = 0; i < s.length();) {
            if (isOperator(s[i])) {
                if (s[i] == '*' || s[i] == '/') {
                    string integer = "";
                    i++;
                    while (isDigit(s[i])) {
                        integer.push_back(s[i++]);
                    }
                    int intval = convertStr2Int(integer);
                    int stackVal = integers.pop();                    
                    integers.push(operate(stackVal, intval, s[i]));
                } else {
                    if (integers.size() >= 2) {
                        int lv = integers.top();
                        integers.pop();
                        int rv = integers.top();
                        integers.pop();
                        integers.push(operate(lv, rv, operators.top()));
                        operators.pop();
                    }
                    operators.push(s[i++]);
                }
            } else {
                string integer = "";
                while (isDigit(s[i])) {
                    integer.push_back(s[i++]);
                }
                integers.push(integer);
            }
        }
        return integers.top();
    }
};


class Solution {
private:
    int convertStr2Int(const string& str)
    {
        //cout << "str:" << str << endl;
        //string::size_type sz;
        std::string::size_type sz;   // alias of size_t

        //int i_dec = std::stoi (str_dec,&sz);
        return std::stoi(str, &sz);
    }

    int operate(int l, int r, char o)
    {
        //cout << l << o << r << endl;
        if (o == '+') {
            return l + r;
        } else if (o == '-') {
            return l - r;
        } else if (o == '*') {
            return l * r;
        } else {
            return l / r;
        }
    }

    inline bool isOperator(char o)
    {
        return (o == '+') || (o == '-') || (o == '*') || (o == '/');
    }

    inline bool isDigit(char c)
    {
        return (c >= '0') && (c <= '9');
    }

public:
    /* 3+5/2-4/3 */
    int calculate(string s) {
        stack<int> integers;
        stack<char> operators;
        for (int i = 0; i < s.length();) {
            while (s[i] == ' '){i++;}
            if (isOperator(s[i])) {
                //cout << s[i] << endl;
                if (s[i] == '*' || s[i] == '/') {
                    char op = s[i];
                    string integer = "";
                    i++;
                    while (s[i] == ' '){i++;}
                    while (isDigit(s[i])) {
                        integer.push_back(s[i++]);
                    }
                    while (s[i] == ' '){i++;}
                    int intval = convertStr2Int(integer);
                    int stackVal = integers.top();
                    integers.pop();
                    integers.push(operate(stackVal, intval, op));
                } else {
                    if (integers.size() >= 2) {
                        int rv = integers.top();
                        integers.pop();
                        int lv = integers.top();
                        integers.pop();
                        integers.push(operate(lv, rv, operators.top()));
                        operators.pop();
                    }
                    operators.push(s[i++]);
                    while (s[i] == ' '){i++;}
                }
            } else {
                //cout << s[i] << endl;
                string integer = "";
                while (s[i] == ' '){i++;}
                while (isDigit(s[i])) {
                    integer.push_back(s[i++]);
                }
                while (s[i] == ' '){i++;}
                integers.push(convertStr2Int(integer));
            }
        }
        if (operators.size() != 0) {
            char op = operators.top();
            operators.pop();
            int r = integers.top();
            integers.pop();
            int l = integers.top();
            integers.pop();
            integers.push(operate(l, r, op));
        }
        //cout << integers.size() << ":" << operators.size() << endl;

        return integers.top();
    }
};

