class Solution {

struct Node{
    Node* links[26];
    bool flag = false;
    bool isCharExist(char ch){
        return links[ch-'a']!=NULL;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    bool isEnd(){
        return flag;
    }
    
    void setEnd(){
        flag = true;
    }
    
};
    
private:
    Node* root;
    
public:
    
    Solution(){
        root = new Node();
    }
    
    void insert(string word){
       Node* node = root;
       int WORD_SIZE = word.size();
       for(int idx=0;idx<WORD_SIZE;idx++){
            //if char does not exist insert the character
                if(!node->isCharExist(word[idx])){
                    node->put(word[idx], new Node());
                }
            //move to the next reference
                node = node->get(word[idx]);
            }//end for idx
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        int WORD_SIZE = word.size();
        
        //iterate the given word
        for(int idx=0;idx<WORD_SIZE;idx++){
            //if char does not exist return false
            if(!node->isCharExist(word[idx]))return false;
            node = node->get(word[idx]);//if exists iterate to the next reference
        }
        return node->isEnd();//after reaching the  end of the word check for flag to see whether it marks the end of the word
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        int PREFIX_SIZE = prefix.size();
        //iterate the prefix given
        for(int idx=0;idx<PREFIX_SIZE;idx++){
            if(!node->isCharExist(prefix[idx]))return false;//if char does not exist return false
            node = node->get(prefix[idx]);// iterate to the next reference if exists
        }
        return true;// if it has iterated over all the prefix then true
    }
    
    void longestWordWithAllPrefixes(string word, string& result){
        Node* node = root;
        if(word.size()<result.size())return;
        for(char ch : word){
            if(!node->isCharExist(ch) || !node->get(ch)->isEnd())return;
            node = node->get(ch);
        }
        if(word.size() != result.size() || word<result) result = word;   
    }
    
    
    
    string longestWord(vector<string>& words) {
        string result = "";
        for(string word : words) insert(word);
        for(string word : words) longestWordWithAllPrefixes(word, result);
        return result;
    }
};
