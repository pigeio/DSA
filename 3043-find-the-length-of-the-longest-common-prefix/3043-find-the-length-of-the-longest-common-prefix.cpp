struct trieNode{
    char digit;
    trieNode* children[10];
};
class Solution {
public:
    trieNode* getTrie(){
        trieNode* node = new trieNode();
        for(int i = 0; i< 10; i++){
            node->children[i] = NULL;
        }

        return node;
    }

    void insert(int num , trieNode* root){
        trieNode* crawl = root;
        string numString = to_string(num);
        
        for(char ch: numString){
            int idx = ch-'0';
            if(crawl->children[idx] == NULL){
                crawl->children[idx] = getTrie();
            }

            crawl = crawl->children[idx];
        } 
    }   

    int search(int num,  trieNode* root){
        trieNode* crawl = root;
        string numStr = to_string(num);
        int length = 0;

        for(char ch: numStr){
            int idx = ch-'0';
            if(crawl->children[idx]){
                length++;
                crawl = crawl->children[idx];
            }else{
                break;
            }
        }
        return length;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trieNode* root = getTrie();

        for(int num : arr1){
            insert(num , root);
        }

        int result = 0;
        for(int num: arr2){
            result = max(result , search(num , root));
        }
        return result;
    }
};