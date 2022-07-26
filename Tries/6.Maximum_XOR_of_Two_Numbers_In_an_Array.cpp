class Solution {


struct Node{
    Node* bits[2];
    bool containsBit(int bit){
        return (bits[bit]!=NULL);
    } 
    Node* get(int bit){
        return bits[bit];
    }
    void put(int bit, Node* node){
        bits[bit] = node;
    }
};
    
private:
    Node* root;
    
    
public:
    Solution(){
        root = new Node();
    }
    
    void insertElementsToTries(vector<int>& nums){
        for(int& num : nums){
            Node* node = root;
            for(int i=31;i>=0;i--){
                int bit = (num>>i)&1;
                if(!node->containsBit(bit)) node->put(bit, new Node());
                node = node->get(bit);
            }
        }
    }
    
    int getMax(int num){
        Node* node = root;
        int max = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->containsBit(1-bit)){ // if it contains the opposite bit then just set that bit and iterate to the next node
                max = max | (1<<i);
                node = node->get(1-bit);
            }
            else node = node->get(bit);//else iterate to the enxt node
        }
        return max;
    }
    
    
    int findMaximumXOR(vector<int>& nums) {
        int result = 0;
        insertElementsToTries(nums);
        for(int& num : nums){
            int temp = getMax(num);
            result = max(result, temp);// maintain the running maximum
        }
        return result;
    }
};
