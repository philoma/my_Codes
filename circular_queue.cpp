class CircularQueue
{
public:
    // Initialize your data structure.
    int *arr;
    int size;
    int front;
    int rear;
    CircularQueue(int n)
    {
        // Write your code here.
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value)
    {
        //link: https://www.codingninjas.com/codestudio/problems/circular-queue_1170058?leftPanelTab=1
        // Write your code here
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            // queue full he
            return false;
        }
        else if (front == -1)
        {
            // first element to push
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            // maintain cyclic nature of queue
            rear = 0;
        }
        else
        {

            rear++;
        }
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue()
    {
        // Write your code here.
        if (front == -1)
        {
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;

            if (rear == front)
            { // yani if ek hi element tha
                rear = front = -1;
            }
            else if (front == size - 1)
            {
                front = 0; // for cyclic
            }
            else
            {
                front++;
            }
            return ans;
        }
    }
};