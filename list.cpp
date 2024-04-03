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

class LinkList {
public:
    Node *head;

public:
    LinkList();//构造函数
     ~LinkList();//析构函数
    void CreateLinkList(int n);
    void TravalLinkList();
    int GetLength ();
    bool IsEmpty();
    link FindNode (DataType data);
    void InsertElemAtIndex (DataType data, int n);
    void DeleteElemAtPoint (DataType data);
    void DeleteAll();
    void Invert();
    link Find_middle(link head);
    link sortList(link head);
    void SortList();
};



//初始化表头
LinkList::LinkList ()
{
    head = new Node;
    head->data = 0;
    head->next = NULL;
}

// 销毁单链表
LinkList::~LinkList()
{
    link p = head;
    while(head)
    {
        head = head->next;
        delete p;
        p = head;
    }
    //删除头结点
}

//创建链表
void LinkList::CreateLinkList (int n)
{
    link newnode, ptr;
    ptr = head;
    //建链表
    for (int i = 1; i <= n; i++)
    {
        newnode = new Node;
        cout << "请输入第" << i << "个值: " ;
        cin >> newnode->data;
        ptr->next = newnode;
        ptr=newnode;
    }
    ptr->next=NULL;
}

//输出链表
void LinkList::TravalLinkList()
{
    if (head->next ==NULL) {
        cout << "链表为空表" << endl;
        return;
    }
    link temp = head->next;
    while (temp != NULL)
    {
        cout << temp->data<< " ";
        temp = temp->next;
    }
    cout << endl;
}

//求长
int LinkList::GetLength ()
{
    int count = 0;
    link p = head->next;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

//判断单链表是否为空
bool LinkList::IsEmpty()
{
    if (head->next == NULL) {
        return true;
    }
    return false;
}

//搜索节点
link LinkList::FindNode (DataType data)
{

    link p = head->next;
    if (p == NULL) {                           //当为空表时，报异常
        cout << "此链表为空链表" << endl;
        return ERROR;
    }
    while (p != NULL)
    {
        if(p->data == data) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
//插入节点
void LinkList::InsertElemAtIndex (DataType data, int n)
{

    if ( n < -1 || n > GetLength()){
        cout << "输入的值错误" << endl; //输入有误报异常
        return;
    }
    link InsertNode = new node;
    InsertNode->data = data;
    InsertNode->next = NULL;
    link p = head;
    int i = 1;
    if(n == 0) {//插入第一个节点
        InsertNode->next = head;
        head = InsertNode;
        return;
    }
    if(n == -1) {
        n = GetLength();
    }
    while (n > i)    //遍历到指定的位置
    {
        p = p->next;
        i++;
    }
    if(p->next == NULL) //插入最后一个节点
    {
        p->next = InsertNode;
    }
    else //插入中间位置节点
    {
        InsertNode->next = p->next;
        p->next = InsertNode;
    }
}

//删除所有数据
void LinkList::DeleteAll()
{
    link p = head->next;
    link ptemp = new node;
    while (p != NULL)                    //在头结点的下一个节点逐个删除节点
    {
        ptemp = p;
        p = p->next;
        head->next = p;
        ptemp->next = NULL;
        delete ptemp;
    }
    head->next = NULL;                 //头结点的下一个节点指向NULL
}

//删除
void LinkList::DeleteElemAtPoint (DataType data)
{
    link p = FindNode(data);
    if( p == NULL) {
        cout << "该数据不存在" << endl;
        return;
    }
    link top = head;

    if(p == head)
    {
        head = head->next;
    }
    else
    {
        while (top->next != p)
            top = top->next;
        if (p->next == NULL)
        {
            top->next = NULL;
        }
        else
        {
            top->next = p->next;
        }
    }
    delete p;
}

//逆置
void LinkList::Invert ()
{
    link ptr, q, r;
    ptr = head->next;
    q = NULL;
    while (ptr != NULL)
    {
        r = q;
        q = ptr;
        ptr = ptr->next;
        q->next = r;
    }
    head->next = q;
}

/*
//合并
void LinkList::merge (LinkList l1, LinkList l2)
{
    link p1,p2,p3;
    p1 = l1.head->next;
    p2 = l2.head->next;
    p3 = head;
    while(p1 && p2)
    {
        if(p1->data <= p2->data)
        {
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
        }
    }
    if(p1) p3->next = p1;
    else  p3->next = p2;
}*/

//找到链表中间位置(奇数中间那个，偶数偏左那个)
link LinkList::Find_middle(link head)
{
    if (!head || !head->next) return head;

    //使用快，慢指针的方法：慢指针走一步，快指针走两步
    link slow = head, fast = head->next;
    while (fast !=NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

link Merge(link Head1, link Head2)
{
    if (Head1 == NULL) return Head2;
    if (Head2 == NULL) return Head1;

    link res , p ;

    if(Head1->data < Head2->data)
        {res = Head1; Head1 = Head1->next;}
    else{res = Head2; Head2 = Head2->next;}
    p = res;

    while (Head1 && Head2)
    {
        if (Head1->data <= Head2->data)
        {
            p->next = Head1;
            Head1 = Head1->next;
        }
        else
        {
            p->next = Head2;
            Head2 = Head2->next;
        }

        p = p->next;
    }
    if (Head1)
        p->next = Head1;
    if (Head2)
        p->next = Head2;

    return res;
}


link LinkList::sortList(link head) {
    if (head == NULL || head->next == NULL) return head;

    link pMid = Find_middle(head);
    link pRightHead = pMid->next;
    pMid->next = NULL;

    link left = sortList(head);//左半部分排序
    link right = sortList(pRightHead);//右半部分排序
    return Merge(left, right);

}

void LinkList::SortList(){
    head->next = sortList(head->next);
}


int main ()
{
    LinkList l;
    LinkList la,lb,lc;
    int i;
    cout << "1.创建单链表   2.遍历单链表   3.获取单链表的长度   4.判断单链表是否为空   5.判断节点是否存在\n";
    cout << "6.逆置   7.在指定位置插入指定元素\n";
    cout<<"8.删除所有元素   9.删除指定元素   10.合并    11.排序    0.退出" << endl;
    do
    {
        cout << "请输入要执行的操作: ";
        cin >> i;
        switch (i)
        {
            case 1:
                int n;
                cout << "请输入单链表的长度: ";
                cin >> n;
                l.CreateLinkList(n);
                break;
            case 2:
                l.TravalLinkList();
                break;
            case 3:
                cout << "该单链表的长度为" << l.GetLength() << endl;
                break;
            case 4:
                if (l.IsEmpty() == 1)
                    cout << "该单链表是空表" << endl;
                else
                {
                    cout << "该单链表不是空表" << endl;
                }
                break;
            case 5:
                DataType data;
                cout << "请输入要获取节点的值: ";
                cin >> data;
                if(l.FindNode(data) == NULL){
                    cout << "该节点不存在" << endl;
                    break;
                }
                cout << "该节点存在值为" << l.FindNode(data)->data << endl;
                break;
            case 6:
                l.Invert();
                break;
            case 7:
                DataType pointData;
                int index;
                cout << "请输入要插入的数据: ";
                cin >> pointData;
                cout << "请输入要插入数据的位置(0在头部插入指定元素,-1在尾部删除元素): ";
                cin >> index;
                l.InsertElemAtIndex(pointData, index);
                break;
            case 8:
                l.DeleteAll();
                break;
            case 9:
                DataType pointDeleteData;
                cout << "请输入要删除的数据: ";
                cin >> pointDeleteData;
                l.DeleteElemAtPoint(pointDeleteData);
                break;
            case 10:
                int n1,n2;
                cout << "请输入第一个链表长度: ";
                cin >> n1;
                la.CreateLinkList (n1);
                cout << "请输入第二个链表长度: ";
                cin >> n2;
                lb.CreateLinkList (n2);
                la.SortList();
                lb.SortList();
                lc.head->next = Merge(la.head->next, lb.head->next);
                lc.TravalLinkList();
                break;
            case 11:
                l.SortList();
                break;
            default:
                break;
        }
    }while (i != 0);
    system("pause");
    return 0;
}
