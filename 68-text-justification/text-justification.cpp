class Solution {
public:
    int MAX_WIDTH;
    string findLine(int i ,int j,int eachGaddheSpace,int extragaddhespace, vector<string>& words ){
        string line;
        for(int k=i ; k<j; k++){
            line += words[k];

            if(k == j-1){
                continue;
            }

            for(int z=0; z<eachGaddheSpace ;z++){
                line += " ";
            }

            if (extragaddhespace>0){
                line += " ";
                extragaddhespace--;
            }
        }

        while(line.length() < MAX_WIDTH){
            line += " ";
        } return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>result;
        int n = words.size();
        MAX_WIDTH = maxWidth;
        int i=0;
        while(i<n){
            int letterCount = words[i].length();
            int j = i+1;
            int gaddhe  = 0;

            while(j<n && words[j].length() + 1 + gaddhe + letterCount <= maxWidth ){
                letterCount += words[j].length();
                gaddhe += 1;
                j++; 
            }

            int emptySpace = maxWidth - letterCount;
            int eachGaddheSpace = gaddhe == 0? 0 :emptySpace / gaddhe;
            int extragaddhespace = gaddhe == 0? 0 :emptySpace % gaddhe;

            if(j==n ){
            eachGaddheSpace = 1;
            extragaddhespace = 0;
            }

            
            result.push_back(findLine(i, j, eachGaddheSpace, extragaddhespace, words));
            i=j;

        }
        return result;
    }
};