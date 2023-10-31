class Node
{
    public:
    int data;
    Node *next;

    Node (int x)
    {
        this->data = x;
        next = NULL;
    }
};

class MyLinkedList {
public:
    int size = 0;
    Node *head = NULL;
    Node *tail = NULL;

    MyLinkedList () {}
    
    int get(int index)
    {
        if (index >= size)
        {
            return -1;
        }
        Node *temp = head;
        for (int i=0; i<index; i++)
        {
            temp = temp->next;
        }     
        return temp->data;
    }
    
    void addAtHead(int val)
    {
        Node *temp = new Node (val);
        temp->next = head;
        head = temp;
        if (tail == NULL)
        {
            tail = head;
        }
        size++;
    }
    
    void addAtTail(int val)
    {
        Node *temp = new Node (val);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    
    void addAtIndex(int index, int val)
    {
        if (index>size)
        {
            return;
        }
        Node *temp = new Node (val);

        if (index==0)
        {
            temp->next = head;
            head = temp;
            size++;
        }
        else if (index==size)
        {
            tail->next = temp;
            tail = temp;
            size++;
        }
        else
        {
            Node *t = head;
            for (int i=0; i<index-1; i++)
            {
                t = t->next;
            }
            temp->next = t->next;
            t->next = temp;
            size++;
        }

    }
    
    void deleteAtIndex(int index)
    {
        if (index>=size)
        {
            return;
        }
        else if (index == 0)
        {
            head = head->next;
            size--;
        }
        else if (index == size-1)
        {
            Node *temp = head;

            while (temp->next != tail)
            {
                temp = temp->next;
            }
            tail = temp;
            temp->next = NULL;
            size--;
        }
        else
        {
            Node *temp = head;

            for (int i=0; i<index-1; i++)
            {
                temp = temp->next;
            }
            Node *t = temp->next;
            temp->next = temp->next->next;
            t->next = NULL;
            size--;
        }

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