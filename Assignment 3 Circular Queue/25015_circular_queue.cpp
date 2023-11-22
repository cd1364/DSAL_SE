/*
Name : Daphal Chaitanya Ramdas
Class : SE IT
Div : A
Batch : A
Roll no. : 25015
Assignment No. 3 : Circular Queue
*/

#include <iostream>
using namespace std;

int cqueue[5];
int front = -1, rear = -1, n = 5;

void insertCQ(int val)
{
    if ((front == 0 && rear == n - 1) || (front == rear + 1))
    {
        cout << "Queue Overflow \n"
             << endl;
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == n - 1)
            rear = 0;
        else
            rear = rear + 1;
    }
    cqueue[rear] = val;
}
void deleteCQ()
{
    if (front == -1)
    {
        cout << "Queue Underflow\n"
             << endl;
        return;
    }
    cout << "Element deleted from queue is : " << cqueue[front] << endl;

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == n - 1)
            front = 0;
        else
            front = front + 1;
    }
}
void displayCQ()
{
    int f = front, r = rear;
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements are :\n"
         << endl;
    if (f <= r)
    {
        while (f <= r)
        {
            cout << cqueue[f] << " ";
            f++;
        }
    }
    else
    {
        while (f <= n - 1)
        {
            cout << cqueue[f] << " ";
            f++;
        }
        f = 0;
        while (f <= r)
        {
            cout << cqueue[f] << " ";
            f++;
        }
    }
    cout << endl;
}
int main()
{

    int ch, val;
    cout << "\tMENU\n";
    cout << "1)Insert\n";
    cout << "2)Delete\n";
    cout << "3)Display\n";
    cout << "4)Exit\n";
    do
    {
        cout << "\nEnter choice : " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Input Data for insertion: " << endl;
            cin >> val;
            insertCQ(val);
            break;

        case 2:
            deleteCQ();
            break;

        case 3:
            displayCQ();
            break;

        case 4:
            cout << "Exit\n"
                 << endl;
            break;
        default:
            cout << "Invalid Input !!\n";
        }
    } while (ch != 4);
    return 0;
}

/*
        MENU
1)Insert
2)Delete
3)Display
4)Exit

Enter choice :
1
Input Data for insertion:
10

Enter choice :
1
Input Data for insertion:
20

Enter choice :
1
Input Data for insertion:
30

Enter choice :
1
Input Data for insertion:
40

Enter choice :
1
Input Data for insertion:
50

Enter choice :
1
Input Data for insertion:
60
Queue Overflow


Enter choice :
2
Element deleted from queue is : 10

Enter choice :
3
Queue elements are :

20 30 40 50

Enter choice :
4
Exit

*/
