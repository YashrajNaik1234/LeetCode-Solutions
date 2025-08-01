class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        
        while(temp){
            Node* copy = new Node(temp -> val);
            copy -> next = temp -> next;
            temp -> next = copy;
            temp = temp -> next -> next;
        }

        temp = head;
        while(temp){
            Node* copy = temp -> next;
            copy -> random = (temp -> random) ? temp -> random -> next : nullptr;
            temp = temp -> next -> next;
        }

        Node* dummy = new Node(0);
        Node* res = dummy; temp = head;
        while(temp){
            res -> next = temp -> next;
            temp -> next = temp -> next -> next;
            temp = temp -> next;
            res = res -> next;
        }

        return dummy -> next;
    }
};
