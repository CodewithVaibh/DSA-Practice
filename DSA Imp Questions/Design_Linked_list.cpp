class MyLinkedList {
public:
        class Node 
        { 
          public:
          int data; 
          Node *next; 
        }; 
    Node*head=NULL;
    int size=0;
    
    int get(int index) {
        if(head==NULL || index>=size)
            return -1;
        Node *temp=NULL;
        temp=head;
        for(int i=0;i<index;i++)
            temp=temp->next;
        return temp->data;
    }
    
    void addAtHead(int val) {
        Node *temp=new Node();
        if(head==NULL)
        {
            temp->next=NULL;
            temp->data=val;
            head=temp;
            size++;
            return;
        }
        temp->next=head;
        temp->data=val;
        head=temp;
        size++;
    }
    
    void addAtTail(int val) {
        Node *temp=new Node();
        temp->data=val;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            size++;
            return;
        }
        Node *temp1=NULL;
        temp1=head;
        while(temp1->next!=NULL)
        temp1=temp1->next;
        temp1->next=temp;
        size++;
    }
    
    void addAtIndex(int index,int val) {
        if(index>size)
            return;
        if(index==0)
        {
            addAtHead(val);
            return;
        }
        if(index==size)
        {
            addAtTail(val);
            return;
        }
        Node*temp=new Node();
        Node*temp2=head;
        for(int i=0;i<index-1;i++)
            temp2=temp2->next;
        temp->data=val;
        temp->next=temp2->next;
        temp2->next=temp;
        size++;
    }
    
    void deleteAtIndex(int index) {
        Node *temp=head;
        if(head==NULL)
            return;
        if(index>=size)
            return;
        if(index==0)
        {
            head=temp->next;
            delete temp;
            size--;
            return;
        }
        for(int i=0;i<index-1;i++)
            temp=temp->next;
        Node*temp2=temp->next;
        temp->next=temp2->next;
        delete temp2;
        size--;
    }
};    

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */