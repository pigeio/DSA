class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";

        int i = a.size()-1;
        int j = b.size()-1;

        int carry = 0;

        while(i>=0 || j>=0 || carry>0){
            int bitA = (i>=0)? a[i] -'0': 0 ;
            int bitB = (j>=0)? b[j] -'0': 0 ;

            int sum = bitA + bitB + carry;
            carry = sum/2;
            result.push_back((sum % 2) + '0');

            i--,j--;
        }reverse(result.begin(), result.end());

        return result;

    }
    
};