#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *lChild;
    Node *rChild;
};
typedef class Node node;
typedef node *BinTree;

class Node1{
public:
    BinTree btnode;
    bool isFirst;
};
typedef class Node1 node1;
typedef node1 *BTNode;

class Tree{
public:
    Node *root;
    bool creatT(int n);
    void preTraval1(BinTree root);
    void inTraval1(BinTree root);
    void postTraval1(BinTree root);
    void preTraval2(BinTree root);
    void inTraval2(BinTree root);
    void postTraval2(BinTree root);
    int countNode(BinTree root);
    int countLeaves(BinTree root);
    int maxDepth(BinTree root);
    int FindNodeLevel(int target);
private:
    int findNodeLevel(BinTree root, int target, int level);
};

bool Tree::creatT(int n) {
    cout << "请输入对应数量的节点（-1表示为空）:";
    vector<int> data(n);
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }
    int len = data.size();
    if(len == 0)return false;
    queue<BinTree> queue1;
    int index = 0;
    root = new node;
    root->data = data[index++];
    root->lChild = NULL;
    root->rChild = NULL;
    queue1.push(root);
    BinTree p = NULL;
    while (!queue1.empty() && index < len){
        p = queue1.front();
        queue1.pop();
        if(index < len && data[index] != -1){
            BinTree lNode = new node ;
            lNode->data = data[index];
            lNode->lChild = NULL;
            lNode->rChild = NULL;
            p->lChild = lNode;
            queue1.push(lNode);
        }
        index++;
        if(index < len && data[index] != -1){
            BinTree rNode = new node ;
            rNode->data = data[index];
            rNode->lChild = NULL;
            rNode->rChild = NULL;
            p->rChild = rNode;
            queue1.push(rNode);
        }
        index++;
    }
    return true;

}

void Tree::preTraval1(BinTree root) {
    if(root != NULL){
        cout << root->data << " ";
        preTraval1(root->lChild);
        preTraval1(root->rChild);
    }
}

void Tree::inTraval1(BinTree root) {
    if(root != NULL){
        inTraval1(root->lChild);
        cout << root->data << " ";
        inTraval1(root->rChild);
    }
}

void Tree::postTraval1(BinTree root) {
    if(root != NULL){
        postTraval1(root->lChild);
        postTraval1(root->rChild);
        cout << root->data << " ";
    }
}

void Tree::preTraval2(BinTree root) {
    stack<BinTree> stack1;
    BinTree p = root;
    while(!stack1.empty() || p != NULL){
        while( p != NULL){
            cout << p->data << " ";
            stack1.push(p);
            p = p->lChild;
        }
        if(!stack1.empty()) {
            p = stack1.top();
            stack1.pop();
            p = p->rChild;
        }
    }
}

void Tree::inTraval2(BinTree root) {
    stack<BinTree> stack1;
    BinTree p = root;
    while(!stack1.empty() || p != NULL){
        while(p != NULL){
            stack1.push(p);
            p = p->lChild;
        }
        if(!stack1.empty()){
            p = stack1.top();
            cout << p->data << " ";
            stack1.pop();
            p = p->rChild;
        }
    }
}

void Tree::postTraval2(BinTree root) {
    stack<BTNode> stack1;
    BinTree p = root;
    BTNode temp;
    while(!stack1.empty() || p != NULL){
        while(p!=NULL)
        {
            BTNode btn = new Node1;
            btn->btnode=p;
            btn->isFirst=true;
            stack1.push(btn);
            p=p->lChild;
        }
        if(!stack1.empty())
        {
            temp=stack1.top();
            stack1.pop();
            if(temp->isFirst == true)
            {
                temp->isFirst = false;
                stack1.push(temp);
                p = temp->btnode->rChild;
            }
            else
            {
                cout << temp->btnode->data << " ";
                p = NULL;
            }
        }
    }
}

int Tree::countNode(BinTree root) {
    if(root != NULL){
        int leftCount = countNode(root->lChild);
        int rightCount = countNode(root->rChild);
        return 1 + leftCount + rightCount;
    }
    return 0;
}

int Tree::countLeaves(BinTree root) {
    if (root == NULL)
        return 0;

    if (root->lChild == NULL && root->rChild == NULL)
        return 1;

    int leftLeaves = countLeaves(root->lChild);
    int rightLeaves = countLeaves(root->rChild);
    return leftLeaves + rightLeaves;
}

int Tree::maxDepth(BinTree root) {
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->lChild);
    int rightDepth = maxDepth(root->rChild);
    return max(leftDepth, rightDepth) + 1;
}

int Tree::findNodeLevel(BinTree root, int target, int level) {
    if (root == NULL)
        return 0;

    if (root->data == target)
        return level;

    int leftLevel = findNodeLevel(root->lChild, target, level + 1);
    if (leftLevel != 0)
        return leftLevel;

    int rightLevel = findNodeLevel(root->rChild, target, level + 1);
    return rightLevel;
}

int Tree::FindNodeLevel(int target) {
    return findNodeLevel(this->root, target, 1);
}


int main(){
    int i;
    Tree l;
    cout << "1.层次创建二叉树   2.先序遍历   3.中序遍历   4.后续遍历   \n";
    cout << "5.总节点数    6.叶子节点数     7.深度     8.节点所在层次\n";
    cout<<"9.非递归先序遍历   10.非递归中序遍历   11.非递归后序遍历    0.退出" << endl;
    do
    {
        cout << "请输入要执行的操作: ";
        cin >> i;
        switch (i)
        {
            case 1:
                int n;
                cout << "请输入节点数量:";
                cin >> n;
                l.creatT(n);
                break;
            case 2:
                l.preTraval1(l.root);
                cout << endl;
                break;
            case  3:
                l.inTraval1(l.root);
                cout << endl;
                break;
            case  4:
                l.postTraval1(l.root);
                cout << endl;
                break;
            case 5:
                cout << l.countNode(l.root) << endl;
                break;
            case 6:
                cout << l.countLeaves(l.root) << endl;
                break;
            case 7:
                cout << l.maxDepth(l.root) << endl;
                break;
            case 8:
                cout << "请输入节点:";
                int data;
                cin >> data;
                cout << l.FindNodeLevel(data) << endl;
                break;
            case  9:
                l.preTraval2(l.root);
                cout << endl;
                break;
            case  10:
                l.inTraval2(l.root);
                cout << endl;
                break;
            case  11:
                l.postTraval2(l.root);
                cout << endl;
                break;
            default:
                break;
        }
    }while (i != 0);
    return 0;
}