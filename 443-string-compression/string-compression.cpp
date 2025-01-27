class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int i = 0;
        int index = 0;

        while(i < n){
            char curr_ch = chars[i];
            int count = 0;

            while(i < n && chars[i] == curr_ch){
                count++;
                i++;
            }

            chars[index] = curr_ch; // index jis place pe hoga uske box me curr_char aayega  
            index++;

            if(count > 1){
                string count_str = to_string(count); //here we convert int to string  
                for(char &ch : count_str){
                    chars[index] = ch;
                    index++;
                }           
            }

        }
        return index;
        
    }
};