

#include <iostream>
class BST;
using namespace std;
class node {//노드 정의 
    friend class BST;//프렌드 클래스 정의 
private:
    int data;
    node* left;
    node* right;
public:
   
    node(int k) {//노드 생성자 함수
        data = k;
        left = nullptr;
        right = nullptr;
    }
};
class BST {
public:
    node* delete_ex(node* start, int value) {//한 노드를 삭제해야 하는 함수 사후정리 까지 포함하므로 재귀형식,start는 최상단 루트포인터이며,value는 삭제해야 하는 값이다
        if (!start)
            return nullptr;
        else if (value < start->data)
            start->left = delete_ex(start->left, value);//초기 노드를 반환해야 하므로 current 포인터를 사용하지 않는다.
        else if (value > start->data)
            start->right = delete_ex(start->right, value);//노드삭제후 후기 엣지를 연결하기 위해 
        else if (value == start->data) {//탐색 감지
            if (!start -> left) {//오른쪽 노드만 있거나 자식노드가 없는경우
                auto temp = start->right;
                delete start;
                return temp;
            }
            else if (!start->right) {//왼쪽 노드만 있는 경우
                auto temp = start->left;
                delete start;
                return temp;
            }
            auto succnode = successor(start);//왼쪽 오른쪽 노드 둘다 있는경우 상속자를 찾는다
            start->data = succnode->data;//시작 데이터에 상속자 데이터를 입력하고 
            start->right = delete_ex(start->right, succnode->data);//상속자 데이터에 기입된 노드 오른쪽트리에 존재하는 BST에서 본 상속자 값을 제거하고 트리를 재 정렬한다.
                
             
        }
        return start;
    }
    void inorder_ex(node* root) {
        inorder_ex(root->left);
        cout << root->data << endl;
        inorder_ex(root->right);
    }

public:
    node* root = nullptr;
    
    node* find_ex(node* current, int value) {//재귀알고리즘
        if (!current)//탐색 중지 
            return nullptr;
        else if (current->data == value)//탐색 성공 
            return current;
        else if (current->data > value)
            return find_ex(current->left, value);
        else if (current->data < value)
            return find_ex(current->right, value);
    }
    void insert_ex(node* current, int value) {
        if (current->data > value) 
        {
            if (current->left == nullptr)
                current->left = new node(value);
            else
                insert_ex(current->left, value);
        }
        else if (current->data < value)
        {
            if (current->right == nullptr)
                current->right = new node(value);
            else
                insert_ex(current->right, value);
        }
    }
    
    node* find(int value) {
        return find_ex(root, value);
    }
    void insert(int value) {
        if (!root)//생성된 노드가 하나도 없을시 
            root = new node(value);
        else
            insert_ex(root, value);
    }
    void inorder() {
        if (!root)
            return;
        inorder_ex(root);
    }
    node* successor(node* start) {
        if (!start)
            return nullptr;
        node* current = start->right;
        while (current->left)
            current = current->left;
        return current;
    }
    void deletvalue(int value) {
        root = delete_ex(root, value);//루트 노드 삽입
    }
};


int main()
{
    BST tree;
    tree.insert(17);
    tree.insert(20);
    tree.insert(10);
    tree.insert(34);
    tree.insert(65);
    tree.insert(21);
    tree.insert(22);
    tree.insert(54);

    tree.inorder_ex(tree.root);//BST에서 중위순회는 오름차순의 정렬을 따진다
    return 0;
}

