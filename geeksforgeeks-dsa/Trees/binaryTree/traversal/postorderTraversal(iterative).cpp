vector<int> postOrder(Node* node) {
    // code here
    stack<Node*>s1;
    stack<Node*>s2;
    vector<int>v;
    s1.push(node);
    Node*temp;
    while(!s1.empty()){
        temp= s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left)s1.push(temp->left);
        if(temp->right)s1.push(temp->right);
    }
    while(!s2.empty()){
        Node*tmp = s2.top();
        s2.pop();
        v.push_back(tmp->data);
    }
    return v;
     
}