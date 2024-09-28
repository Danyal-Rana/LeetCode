class MyCircularDeque {
public:
    vector<int> deque;
    int K;
    int front;
    int rear;
    int myCounter;

    MyCircularDeque(int k)
    {
        deque = vector<int> (k, 0);
        K = k;
        front = 0;
        rear = 0;  // Rear should be initialized to 0 for consistency
        myCounter = 0;        
    }
    
    bool insertFront(int value)
    {
        if (isFull())
        {
            return false;
        }

        front = (front - 1 + K) % K;
        deque[front] = value;
        myCounter++;
        return true;
    }
    
    bool insertLast(int value)
    {
        if (isFull())
        {
            return false;
        }

        deque[rear] = value;
        rear = (rear + 1) % K;
        myCounter++;
        return true;
    }
    
    bool deleteFront()
    {
        if (isEmpty())
        {
            return false;
        }

        front = (front + 1) % K;
        myCounter--;
        return true;
    }
    
    bool deleteLast()
    {
        if (isEmpty())
        {
            return false;
        }

        rear = (rear - 1 + K) % K;
        myCounter--;
        return true;
    }
    
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }

        return deque[front];
    }
    
    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }

        return deque[(rear - 1 + K) % K]; 
    }
    
    bool isEmpty()
    {
        return myCounter == 0;
    }
    
    bool isFull()
    {
        return myCounter == K;
    }
};
