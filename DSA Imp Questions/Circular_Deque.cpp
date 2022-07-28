/* Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise. */

class MyCircularDeque {
    int deque[1000];
    int f,r,k;
public:
    MyCircularDeque(int k){
        f=r=-1;
        this->k=k;
    }
    bool insertFront(int value) {
        if(isFull())
            return false;
        else if(f==-1 && r==-1)
        {
            f=r=0;
            deque[f]=value;
        }
        else if(f==0)
        {
            f=k-1;
            deque[f]=value;
        }
        else
        {
            f--;
            deque[f]=value;
        }
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())
            return false;
        else if(f==-1 && r==-1)
        {
            f=r=0;
            deque[r]=value;
        }
        else if(r==k-1)
        {
            r=0;
            deque[r]=value;
        }
        else
        {
            r++;
            deque[r]=value;
        }
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
            return false;
        else if(f==r)
        {
            f=r=-1;
        }
        else if(f==k-1)
        {
            f=0;
        }
        else
        {
            f++;
        }
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
            return false;
        else if(f==r)
        {
            f=r=-1;
        }
        else if(r==0)
        {
            r=k-1;
        }
        else
        {
            r--;
        }
        return true;
    }
    
    int getFront() {
        if(f==-1)
            return -1;
        else
            return deque[f];
    }
    
    int getRear() {
        if(r==-1)
            return -1;
        else
            return deque[r];
    }
    
    bool isEmpty() {
        if(f==-1 && r==-1)
            return true;
        return false;
    }
    
    bool isFull() {
        if((f==0 && r==k-1)|| (f==r+1))
            return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */