#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag = false;
    int endsWithCount = 0;
    int countPrefixCount = 0;
    
    int getEndsWithCount(){
        return endsWithCount;
    }
    
    int getCountPrefix(){
        return countPrefixCount;
    }
    
    bool isCharExist(char ch){
        return links[ch-'a']!=NULL;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void incrementPrefixCount(){
        countPrefixCount++;
    }
    
    void decrementPrefixCount(){
        countPrefixCount--;
    }
    
    void incrementEndsWithCount(){
        endsWithCount++;
    }
    
    void decrementEndsWithCount(){
        endsWithCount--;
    }
    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

};

class Trie {
private:
    Node* root;
    
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        int WORD_SIZE = word.size();
        for(int idx=0;idx<WORD_SIZE;idx++){
            //if char does not exist insert the character
            if(!node->isCharExist(word[idx])){
                node->put(word[idx], new Node());
            }
            node = node->get(word[idx]);//move to the next reference
            node->incrementPrefixCount();//increment prefix count
        }//end for idx
        node->incrementEndsWithCount();//increment ends with count
    }//end function
    
    int countWords(string word) {
        Node* node = root;
        int WORD_SIZE = word.size();
        
        //iterate the given word
        for(int idx=0;idx<WORD_SIZE;idx++){
            //if char does not exist return 0
            if(!node->isCharExist(word[idx]))return 0;
            node = node->get(word[idx]);//if exists iterate to the next reference
        }
        return node->getEndsWithCount();//after reaching the end of the word return endsWithCount
    }
    
    int countPrefix(string prefix) {
        Node* node = root;
        int PREFIX_SIZE = prefix.size();
        
        //iterate the prefix given
        for(int idx=0;idx<PREFIX_SIZE;idx++){
            if(!node->isCharExist(prefix[idx]))return 0;//if char does not exist return 0
            node = node->get(prefix[idx]);// iterate to the next reference if exists
        }
        return node->getCountPrefix(); // after reaching end of prefix return countPrefix
    }
    
    void eraseWord(string word){
        if(!countWords(word))return;
        
        int WORD_SIZE = word.size();
        Node* node = root;
        
        for(int idx=0;idx<WORD_SIZE;idx++){
            node = node->get(word[idx]);
            node->decrementPrefixCount();
        }
        node->decrementEndsWithCount();
    }
};

int main(){
    
    Trie t;
    t.insert("apps");
    t.insert("apps");
    cout<<t.countPrefix("app")<<endl;
    cout<<t.countWords("apps")<<endl;
    
    t.eraseWord("apps");
    cout<<t.countPrefix("app")<<endl;
    cout<<t.countWords("apps")<<endl;
    return 0;
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
