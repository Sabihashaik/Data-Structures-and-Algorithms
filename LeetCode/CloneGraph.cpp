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
        
        map<Node*,Node*>imap;
        queue<Node*> q; 
        
        if(node == NULL){return NULL;}
        q.push(node);
        Node* copyNode = new Node();
        copyNode ->val = node->val;
        imap[node] = copyNode; 
       
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            vector<Node*> v = front->neighbors; 
            int size = v.size();

            for(int i=0;i<size;i++){
                if(imap[v[i]]==NULL){
                    Node * p = new Node();
                    p->val = v[i]->val; 
                    imap[v[i]] = p;
                    q.push(v[i]);
                }
             imap[front]->neighbors.push_back(imap[v[i]]);
            
            
        }
            }
                return imap[node]; 

    }
};