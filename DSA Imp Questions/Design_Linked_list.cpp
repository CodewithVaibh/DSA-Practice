class MyLinkedList {
public:
        class Node 
        { 
          public:
          int data; 
          Node *next; 
        }; 
    Node*head=NULL;
    
    int get(int index) {
        if(head==NULL)
            return -1;
        Node *temp=NULL;
        temp=head;
        int count=0;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            count++;
        }
        Node *temp2=NULL;
        temp2=head;
        if(index>=count)
            return -1;
        for(int i=0;i<index;i++)
            temp2=temp2->next;
        return temp2->data;
    }
    
    void addAtHead(int val) {
        Node *temp=new Node();
        if(head==NULL)
        {
            temp->next=NULL;
            temp->data=val;
            head=temp;
            return;
        }
        temp->next=head;
        temp->data=val;
        head=temp;
    }
    
    void addAtTail(int val) {
        Node *temp=new Node();
        temp->data=val;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            return;
        }
        Node *temp1=NULL;
        temp1=head;
        while(temp1->next!=NULL)
        temp1=temp1->next;
        temp1->next=temp;
    }
    
    void addAtIndex(int index,int val) {
        Node *temp1=NULL;
        temp1=head;
        int count=0;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
            count++;
        }
        if(index>count)
            return;
        Node*temp=new Node();
        if(index==count)
        {
            temp->data=val;
            temp->next=NULL;
            temp1->next=temp;
            return;
        }
        Node*temp2=head;
        for(int i=0;i<index-1;i++)
            temp2=temp2->next;
        temp->data=val;
        temp->next=temp2->next;
        temp2->next=temp;
    }
    
    void deleteAtIndex(int index) {
        Node *temp=head;
        if(head==NULL)
            return;
        if(index==0)
        {
            head=temp->next;
            delete temp;
            return;
        }
        for(int i=0;i<index-1;i++)
            temp=temp->next;
        Node*temp2=temp->next;
        temp->next=temp2->next;
        delete temp2;
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