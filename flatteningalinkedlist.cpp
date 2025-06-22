Node* flatten(Node* root) {
    priority_queue<Node*, vector<Node*>, mycomp> pq;

    Node* head = nullptr;
    Node* tail = nullptr;

   
    while (root != nullptr) {
        pq.push(root);
        root = root->next;
    }
    while (!pq.empty()) {

        auto minNode = pq.top();
        pq.pop();

        if (head == nullptr) {
            head = minNode;
            tail = minNode;
        }
        else {
            tail->bottom = minNode;
            tail = tail->bottom;
        }
        if (minNode->bottom) {
            pq.push(minNode->bottom);
            minNode->bottom = nullptr;
        }
    }
  
  	return head;
}

