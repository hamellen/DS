
#include <iostream>
using namespace std;

class Tree;
class Node
{
    friend class Tree;
private:
    Node* left;
    Node* right;
    string data;
public:
    Node(const string& data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Tree 
{
public:
    Node* root = nullptr;
    Node* current = nullptr;
    
public:
    Tree(const string& data) {
        root = new Node(data);
        cout << "최상위 노드에" << data << "를 넣었습니다" << endl;
    }
    Node* find_Node(const string& name,Node* root) 
    {
        if (root == nullptr)
            return nullptr;
        
        else if (root->data == name)
            return root;
        auto firstfound =find_Node(name, root->left);
        if (firstfound != nullptr)
            return firstfound;
        return find_Node(name, root->right);
    }
    void add_data(Node* root,const string& downdata,const string& updata) 
    {
        current = find_Node(updata, root);
        if (current == nullptr)
            return;
        else if (current->left == nullptr) {
            current->left = new Node(downdata);
            current = current->left;
            cout << updata << "밑에 " << downdata << "를 넣었습니다." << endl;
        }
        else  if (current->right == nullptr) {
            current->right = new Node(downdata);
            current = current->right;   
            cout << updata << "밑에 " << downdata << "를 넣었습니다." << endl;
        }
        else{
            cout << "아래 노드가 남는 구간이 없습니다." << endl;
        }
    }
    void return_current() {
        cout << "현재 노드의 데이터는 " << current->data << "입니다." << endl;
    }
    static void preorder(Node* start) {
        if (start != nullptr) {
            cout << start->data<<"\t";
            preorder(start->left);
            preorder(start->right);
        }
    }
    
    static void inorder(Node* start) {
        if (start != nullptr) {
            inorder(start->left);
            cout << start->data<<"\t";
            inorder(start->right);
        }
       
    }
    static void postorder(Node* start) {
        if (start != nullptr) {
            postorder(start->left);
            postorder(start->right);
            cout << start->data<<"\t";
        }
      
    }
};



int main()
{
    Tree a("회장님");
    a.add_data(a.root, "부사장", "회장님");
    a.add_data(a.root, "디렉터", "부사장");
    a.add_data(a.root, "운영팀장", "부사장");
    a.add_data(a.root, "아트디렉터", "디렉터");
    a.add_data(a.root, "크리에이티브 디렉터", "디렉터");
    a.add_data(a.root, "운영부서 직원", "운영팀장");
    a.return_current();
    Tree::preorder(a.root);
    cout << endl;
    Tree::inorder(a.root);
    cout << endl;
    Tree::postorder(a.root);
    return 0;
}

