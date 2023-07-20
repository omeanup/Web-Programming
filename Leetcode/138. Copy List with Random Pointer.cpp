/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Hashmap stores the old nodes as keys and new nodes as values.
    unordered_map<Node*, Node*> visited;

    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        // If we have already processed the current node, then we simply return the cloned version of it.
        if (visited.count(head)){
            return visited[head];
        }
        // Create a new node with the value same as the old node.(i.e. copy the node).
        Node *node = new Node(head->val, nullptr, nullptr);

        // Save this value in the hash map. This is needed since there might be loops during traversal due to randomness of random pointer and this would help us avoid them.
        visited[head] = node;

        // recursively copy the remanining linked list starting once from the next pointer and then from the random ointer. Thus we have two independent recursive calls.
        // Finally we update the next and random pointers for the new node created.
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        return node;
    }
};
