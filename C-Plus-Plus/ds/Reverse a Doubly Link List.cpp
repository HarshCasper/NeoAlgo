Node* reverseDLL(Node * head)
{
    //Your code here
    Node *second = (head)->next, *helper;

    if(head==NULL)
        return head;

    while(second){
        helper = second->next;
        second->next = head;
        if(head->prev == NULL){
            head->next = NULL;
            head->prev = second;
        }
        second->prev=helper;
        head=second;
        second=helper;
    }

    head->prev=NULL;
    return head;
}
