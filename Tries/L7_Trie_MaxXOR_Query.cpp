#include<bits/stdc++.h>

class Trie {
    // Struct for Trie Node
    struct Node {
        Node* links[2];

        bool containsKey(int bit) {
            return links[bit]!=NULL;
        }

        void put(int bit, Node* nextRef){
            links[bit] = nextRef;
        }

        Node* get(int bit){
            return links[bit];
        }
    };
    
public:
    
    Node* root;
        
    Trie() {
        root = new Node();
    }
        
    void insert(int number) {
        Node* node = root;
        for (int i=31; i>=0; i--) {
            int curBit = (number>>i) & 1;
            if (!node->containsKey(curBit)) {
                node->put(curBit, new Node());
            }
            node = node->get(curBit);
        }
    }
        
    int getMaxForANumber(int number) {
        Node* node = root;
        int result = 0;
        
        for (int i=31; i>=0; i--){
            // Get the current bit 
            int curBit = (number>>i) & 1;

            if (node->containsKey(1-curBit)) {
                node = node->get(1-curBit);
                result = result | (1<<i);
            } else {
                node = node->get(curBit);
            }
        }
        
        return result;
    }
    
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        int N = nums.size();
        int qSize = queries.size();
        vector<int> result(qSize);
        
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        // Sort the array
        sort(nums.begin(), nums.end());
        
        // Put the queries in min heap
        for (int i=0; i<qSize; i++){
            minHeap.push({queries[i][1], i});//query second element and idx
        }
        
        // Pop the queries one by one
        int iIndex = 0;
        while (!minHeap.empty()) {
            
            // Get MaxVal and index of the query
            int maxVal = minHeap.top().first;
            int qIndex = minHeap.top().second;
            minHeap.pop();
            
            // Iterate the array and insert in trie if possible
            while (iIndex < N) {
                if (nums[iIndex] > maxVal) break;
                insert(nums[iIndex]); 
                iIndex++;
            }
            
            // If the trie has some elements then find the max else assign -1
            if (iIndex > 0) {
                result[qIndex] = getMaxForANumber(queries[qIndex][0]);
            } else {
                result[qIndex] = -1; 
            }
            
        }
        return result;
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	Trie t;
	vector<int>result = t.maximizeXor(arr,queries);
	return result;
}