class Solution {
public:
    int myAtoi(string s) {
        int i = 0 , sign = 1;
        long long num = 0;

        while(s[i] == ' '){  // if the string is empty 
            i++;
        }
        if(i < s.size() && (s[i] =='-' || s[i] == '+')){  // if thw string contains any -ve or +ve string
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }

        while(i < s.size() && isdigit(s[i])){ //while statement for only digits no char are allowed 
            num = num * 10 + (s[i] - '0'); //we return the integer after converting it from string to integer
            i++; 
            if (num * sign > INT_MAX) return INT_MAX;
            if (num * sign < INT_MIN) return INT_MIN;

        }
        return num*sign; //return 0 if no digits found or it returns digits with sign if it contains any sign 
    }
};