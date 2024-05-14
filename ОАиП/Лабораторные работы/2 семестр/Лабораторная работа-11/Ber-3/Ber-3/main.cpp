#include <iostream>
#include <set>
using namespace std;

struct Tree
{
    int key;
    char text[15];
    Tree* Left, * Right;
};

Tree* makeTree(Tree* Root);       //�������� ������
Tree* list(int i, char* s);       //�������� ������ ��������
void insertElem(Tree*& Root, int key, char* s);  //���������� ������ ��������
Tree* search(Tree* n, int key);   //����� �������� �� ����� 
Tree* deleteElem(Tree* Root, int key); //�������� �������� �� �����
int view(Tree* t, int level);     //����� ������ 
bool delAll(Tree* t);             //������� ������
int sumOfValues(Tree* p);          //����� �������� ���� ������
int countNodesWithValueK(Tree* p, int k); //���������� ������ �� ��������� k
int countLeaves(Tree* p);          //���������� ������� � ������
void printLevel(Tree* tree, int level);
Tree* Root = NULL;  //��������� �� ������

int main()
{
    setlocale(0, "Russian");
    int key, choice, n;
    Tree* rc; char s[15];
    for (;;)
    {
        cout << "1 : �������� ������\n";
        cout << "2 : ���������� ��������\n";
        cout << "3 : ����� �� �����\n";
        cout << "4 : �������� ��������\n";
        cout << "5 : ����� ������\n";
        cout << "6 : ������� ������\n";
        cout << "7 : ����� n-�� ������ ������(3)\n";
        cout << "8 : ����� �������� ���� ������ ������(10)\n";
        cout << "9 : ���������� ������� � ������(7)\n";
        cout << "10: ���������� ������ �� ��������� t(9)\n";
        cout << "11: �����\n";
        cout << "�������: ";
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:  
            Root = makeTree(Root);   
            break;

        case 2:  
            cout << "\n������� ����: ";
            cin >> key;
            cout << "������� �����: ";
            cin >> s;
            insertElem(Root, key, s); 
            break;

        case 3:  
            cout << "\n������� ����: ";
            cin >> key;
            rc = search(Root, key);
            if (rc)
                cout << "��������� �����= " << rc->text << endl;
            break;
        case 4:  
            cout << "\n������� ��������� ����: ";
            cin >> key;
            Root = deleteElem(Root, key);  
            break;
        case 5:  
            if (Root)
        {
            view(Root, 0);
        }
              else cout << "������ ������\n";
            break;

        case 6:  
            delAll(Root); 
            break;

        case 7:
            int level;
            cout << "������� ������� ��� ������: ";
            cin >> level;
            printLevel(Root, level);
            break;

        case 8:
            n = sumOfValues(Root);
            cout << "����� �������� ���� ������ ������: " << n << endl;
            break;

        case 9:
            n = countLeaves(Root);
            cout << "���������� ������� � ������: " << n << endl;
            break;

        case 10:
            int k;
            cout << "������� �������� k\n";
            cin >> k;
            cin.ignore();
            n = countNodesWithValueK(Root, k);
            cout << "���������� ������ �� ��������� " << n << endl;
            break;
        case 11:
            return 0;
        }
    }
}


Tree* makeTree(Tree* Root)    //�������� ������
{
    int key; char s[5];
    set<int> keys; // ��� �������� ���������� ������

    cout << "����� ����� - ����� 0\n\n";
    if (Root == NULL)    // ���� ������ �� �������
    {
        cout << "������� ���� �����: ";
        cin >> key;
        while (key == 0 || keys.count(key)) {
            cout << "���� ������ ���� �� ����� 0 � �� �����������. ������� ���� ������: ";
            cin >> key;
        }
        keys.insert(key);
        cout << "������� ����� �����: ";
        cin >> s;
        Root = list(key, s);    // ��������� ��������� �� ������
    }
    while (1)                //���������� ���������
    {
        cout << "\n������� ����: ";
        cin >> key;
        if (key == 0) break;
        while (keys.count(key)) {
            cout << "���� �� ������ �����������. ������� ���� ������: ";
            cin >> key;
        }
        keys.insert(key);
        cout << "������� �����: ";
        cin >> s;
        insertElem(Root, key, s);
    }
    return Root;
}

Tree* list(int key_value, char* word)     // �������� ������ ���� ������
{
    Tree* newNode = new Tree;
    newNode->key = key_value;
    for (int idx = 0; idx < 5; idx++)
        newNode->text[idx] = word[idx];
    newNode->Left = newNode->Right = NULL;
    return newNode;
}

void insertElem(Tree*& tree, int key_value, char* word)  // ���������� ������ ���� � ������
{
    if (tree == NULL)
        tree = list(key_value, word);
    else if (key_value < tree->key)
        insertElem(tree->Left, key_value, word);
    else
        insertElem(tree->Right, key_value, word);
}

Tree* deleteElem(Tree* treeRoot, int key_value)  // �������� ���� �� ������ �� �����
{
    if (treeRoot == NULL)
        return NULL;

    if (key_value < treeRoot->key)
        treeRoot->Left = deleteElem(treeRoot->Left, key_value);
    else if (key_value > treeRoot->key)
        treeRoot->Right = deleteElem(treeRoot->Right, key_value);
    else {
        // ���� � ����� ��� ��� �����
        if (treeRoot->Left == NULL) {
            Tree* tempNode = treeRoot->Right;
            delete treeRoot;
            return tempNode;
        }
        else if (treeRoot->Right == NULL) {
            Tree* tempNode = treeRoot->Left;
            delete treeRoot;
            return tempNode;
        }
        // ���� � ����� ������, �������� ���������� ������� � ������ ���������
        Tree* tempNode = treeRoot->Right;
        while (tempNode->Left != NULL)
            tempNode = tempNode->Left;
        // �������� ���������� ����������� �������� � ������� ����
        treeRoot->key = tempNode->key;
        // ������� ���������� ������� � ������ ���������
        treeRoot->Right = deleteElem(treeRoot->Right, tempNode->key);
    }
    return treeRoot;
}

Tree* search(Tree* node, int key_value)  // ����� ���� � ������ �� ����� 
{
    if (node == NULL || node->key == key_value)
        return node;

    if (key_value < node->key)
        return search(node->Left, key_value);

    return search(node->Right, key_value);
}

int view(Tree* tree, int level) // ����� ������ 
{
    if (tree != NULL)
    {
        view(tree->Right, level + 1);    // ����� ������� ���������
        for (int i = 0; i < level; i++)
            cout << "   ";
        cout << tree->key << ' ' << tree->text << endl;
        view(tree->Left, level + 1);    // ����� ������ ���������
    }
    return 0;
}

bool delAll(Tree* tree) // ������� ������
{
    if (tree != NULL)
    {
        delAll(tree->Left);
        delAll(tree->Right);
        delete tree;
        return true;
    }
    return false;
}

void printLevel(Tree* tree, int level) // ����� ����� �� ������������ ������
{
    if (tree == NULL)
        return;
    if (level == 0)
        cout << tree->key << ' ' << tree->text << endl;
    else
    {
        printLevel(tree->Left, level - 1);
        printLevel(tree->Right, level - 1);
    }
}

int sumOfValues(Tree* p) {
    if (p == NULL)
        return 0;

    int sum = p->key;


    sum += sumOfValues(p->Left);
    sum += sumOfValues(p->Right);

    return sum;
}

int countLeaves(Tree* p) {
    if (p == NULL)
        return 0;
    if (p->Left == NULL && p->Right == NULL)
        return 1;
    return countLeaves(p->Left) + countLeaves(p->Right);
}

int countNodesWithValueK(Tree* p, int k) {
    if (p == NULL)
        return 0;

    int count = 0;


    if (p->key == k)
        count++;


    count += countNodesWithValueK(p->Left, k);
    count += countNodesWithValueK(p->Right, k);

    return count;
}