class Solution {
    

struct Node{
    Node* links[26];

    bool isCharExist(char ch){
        return links[ch-'a']!=NULL;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }    
};

private:
    Node* root;
    Node* node;
    
public:
    Solution(){
        root = new Node();
    }
    
    int countDistinct(string s) {
        int SIZE = s.size();
        long long int count = 0;
        for(int i=0;i<SIZE;i++){
            node = root;
            for(int j=i;j<SIZE;j++){
                if(!node->isCharExist(s[j])){
                    node->put(s[j], new Node());
                    count++;
                }
                //move to the next reference
                node = node->get(s[j]);
            }
        }
        return count;
    } 
};
