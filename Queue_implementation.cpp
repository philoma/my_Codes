#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;
    q.push(12);
    q.push(2);
    q.push(4);
    q.push(5);
    cout << "queue empty? " << q.empty() << endl;
    cout << "queue size or nums of elements in it is: " << q.size() << endl;
    cout << "front element: " << q.front() << endl;
    cout << "rear element: " << q.back() << endl; 
    cout<<"all elements in queue are: "<<endl;
    while (!q.empty())
    {
        cout << q.front()<<" ";
        q.pop();
    }
    return 0;
}







/////////////////////////////////////////////////////







//implement Queue
#include<iostream>
using namespace std;
class Queue
{
    int *arr;
    int size;
    int rear;
    int frontt;
public:
    
    Queue()
    {
        // Implement the Constructor
        size = 100001;
        arr = new int[size];
        
        rear = 0;
        frontt = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        if (frontt == rear)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function

        if (rear == size)
        {
            return;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (frontt == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[frontt];
            arr[frontt] = -1;
            frontt++;

            if (rear == frontt)
            { // jab khali hojae queue and to save space jo -1 dale hue the jagah pr
                rear = 0;
                frontt = 0;
            }
            return ans;
        }
    }

    int front()
    {
        // Implement the front() function
        if (frontt == rear)
        {
            return -1;
        }
        else
        {
            return arr[frontt];
        }
    }
};

int main(){
    Queue q;
    q.enqueue(3);
    q.enqueue(23);
    q.enqueue(67);
    q.enqueue(235);
    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.front()<<endl;
    cout<<q.isEmpty()<<endl;

    return 0;
}