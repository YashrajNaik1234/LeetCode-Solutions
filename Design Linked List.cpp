class MyLinkedList {
    struct Node{
        int val;
        Node* next;

        Node(int val){
            this -> val = val;
            next = nullptr;
        }
    };
    Node* head;
public:
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        Node* temp = head;

        while(temp and index > 0){
            index--;
            temp = temp -> next;
        }

        return temp ? temp -> val : -1;
    }
    
    void addAtHead(int val) {
        Node* addHead = new Node(val);
        addHead -> next = head;
        head = addHead;
    }
    
    void addAtTail(int val){
        Node* newNode = new Node(val);
        Node* curr = head;
        if (!head) {
            head = newNode; return;
        }
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr -> next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        Node *curr = head;
        if (index == 0) {
            addAtHead(val); return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        while(temp and index > 0){
            if (index == 1) {
                newNode -> next = temp -> next;
                temp -> next = newNode;
                return;
            }
            index--;
            temp = temp -> next;
        }

        newNode -> next = temp;
        temp = newNode; 
    }
    
    void deleteAtIndex(int index) {
        if (!head) return;

        if (index == 0) {
            Node* n = head;
            head = head -> next;
            delete n; return;
        }

        Node* temp = head;
        int cnt(0);

        while(temp and index > 0){
            index--;
            if(index == 0){
                Node* node = temp -> next; 
                if(temp -> next == nullptr) temp -> next = nullptr;
                else temp -> next = temp -> next -> next;
                delete node; return;
            }
            temp = temp -> next;
        }
    }
};
