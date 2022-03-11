/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        auto entry = cache.find(node->val);
        if (entry != cache.end())
            return entry->second;
        Node* clone = new Node(node->val);
        cache.emplace(clone->val, clone);
        for (auto &neighbor : node->neighbors)
            clone->neighbors.push_back(cloneGraph(neighbor));
        return clone;
    }
    
private:
    unordered_map<int, Node*> cache;
};