#include<iostream>

using namespace std;
#define ERROR NULL
typedef  int DataType;

class Node
{
public:
    int data;
    Node *next;
};

typedef class Node node;
typedef node *link;

class QueueList {
public:
    link front;
    link rear;
public:
    QueueList();//构造函数
    ~QueueList();//析构函数
    void enqueue(int data);
    bool dequeue(int &e);
    bool isEmpty();
    int GetLength();
    void TravalQueueList();
    void CreateLinkList(int n);
};

//初始化表头
QueueList::QueueList ()
{
    front = rear = new Node;
    front->next = NULL;
//    cout << front << endl;
//    cout << rear << endl;
}

// 销毁单链表
QueueList::~QueueList()
{
    link p = front;
    while(front)
    {
        front = front->next;
        delete p;
        p = front;
    }
    //删除头结点
}

void QueueList::CreateLinkList(int n){
    link p = front;
    for (int i = 1; i <= n; i++)
    {
        link newN = new Node;
        cout << "请输入第" << i << "个值: " ;
        cin >> newN->data;
        p->next = newN;
        p = newN;
    }
    p->next = NULL;
    rear = p;
}

void QueueList::enqueue(int data) {
    link p = new Node;
    p->data = data;
    p->next = NULL;
    rear->next = p;
    rear = p;
}

bool QueueList::dequeue(int &e) {
    if(front == rear) {
       cout << "队列为空" << endl;
        return false;
    }
    link p = front->next;
    e = p->data;
    front->next = p->next;
    if(rear == p) rear = front;
    delete p;
    return true;
}

bool QueueList::isEmpty() {
    return rear == front;
}

void QueueList::TravalQueueList()
{
    if (isEmpty()) {
        cout << "链表为空表" << endl;
        return;
    }
    link temp = front->next;
    while (temp != NULL)
    {
        cout << temp->data<< " ";
        temp = temp->next;
    }
    cout << endl;
}

int QueueList::GetLength ()
{
    int count = 0;
    link p = front->next;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int main(){
    int i, data, n;
    QueueList l;
    cout << "************************" << endl;
    cout << "Creat:   1   Print:   2" << endl;
    cout << "Pop:  3   Push:  4" << endl;
    cout << "Length: 5  Esc:  0" << endl;
    cout << "************************" << endl;
    do
    {
        cout << "请输入要执行的操作: ";
        cin >> i;
        switch (i)
        {
            case 1:
                cout << "请输入队列的长度: ";
                cin >> n;
                l.CreateLinkList(n);
                break;
            case 2:
                l.TravalQueueList();
                break;
            case 3:
                int e;
                if(l.dequeue(e)) cout << e << " is out！" << endl;
                break;
            case 4:
                cout << "请输入入队值：";
                cin >> data;
                l.enqueue(data);
                break;
            case 5:
                cout << l.GetLength() << endl;
                break;
            default:
                break;
        }
    }while (i != 0);
    return 0;
}
