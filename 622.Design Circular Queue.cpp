class MyCircularQueue {
public:
    vector<int> queue;
    int front,rear,size,length;
    MyCircularQueue(int k)
    {
     queue.assign(k,-1);
     front=0;
     rear=0;
     size=k;
     length=0;
    }

    bool enQueue(int value)
    {
        if(isFull()) return false;
        else
            length++;
            queue[rear]=value;
            rear=(rear+1)%size;
            return true;
    }

    bool deQueue()
    {
        if(this->isEmpty()) return false;
        else
            length--;
            queue[front]=-1;
            front=(front+1)%size;
            return true;
    }

    int Front()
    {
       return isEmpty() ? -1:queue[front];
    }

    int Rear()
    {
      if(isEmpty()) return -1;
        int end=rear-1;
        if(end<0) end=end+size;

        return queue[end];
    }

    bool isEmpty()
    {
        return length==0? true:false;
    }
    bool isFull() {
        return length==size? true:false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
