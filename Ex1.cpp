 #include <iostream>
 #include <vector>
 #include <queue>
 using namespace std;
template <typename T>
struct treeNode {
  T data;
  struct treeNode * left;
  struct treeNode * right;
};
template <typename T>
class Tree{
    private:
        treeNode<T> *root;
        void inOrderPrint(treeNode<T> *node){
            if(node!=nullptr){
                inOrderPrint(node->left);
                cout << node->data << " ";
                inOrderPrint(node->right);
            }
        }
        void postOrderPrint(treeNode<T> *node){
            if(node!=nullptr){
                postOrderPrint(node->left);
                postOrderPrint(node->right);
                cout << node->data << " ";
            }
        }
        void preOrderPrint(treeNode<T> *node){
            if(node!=nullptr){
                cout << node->data << " ";
                preOrderPrint(node->left);
                preOrderPrint(node->right);
            }
        }
        int treeSize(treeNode<T> *node){
            if(node==nullptr){
                return 0;
            }
            return 1 + treeSize(node->left) + treeSize(node->right);
        }
        void deleteNode(T data, treeNode<T> *node){
            if(node==nullptr){
                return;
            }
            treeNode<T> *left = node->left;
            treeNode<T> *right = node->right;
            if(left!=nullptr&&left->data==data&&left->left==nullptr&&left->right==nullptr){
                delete left;
                node->left = nullptr;
            }
                if(right!=nullptr&&right->data==data&&right->left==nullptr&&right->right==nullptr){
                delete right;
                node->right = nullptr;
            }
            deleteNode(data, node->left);
            deleteNode(data, node->right);
        }
    public:
        Tree() : root(nullptr) {}

        void inOrderPrint(){
            inOrderPrint(root);
        }
        void postOrderPrint(){
            postOrderPrint(root);
        }
        void preOrderPrint(){
            preOrderPrint(root);
        }
        //Specifications:
        //Requires: An int or a char
        //Effects: add the newly created node as a child of a node in the tree that does not already have two children and whose height (distance from the root of the tree) is the smallest
        void addNode(T data) {
            treeNode<T> *node = new treeNode<T>;
            node->data = data;
            
            if(root==nullptr){
                root = node;
                return;
            }
            queue<treeNode<T>*> q;
            q.push(root);
            while (true)
            {
                treeNode<T>* n = q.front(); 
                q.pop();
                if(n->left!=nullptr){
                    q.push(n->left);
                }
                else{
                    n->left = node;
                    return;
                }
                if(n->right!=nullptr){
                    q.push(n->right);
                }
                else{
                    n->right = node;
                    return;
                }


            }
            
        }
        //Specifications:
        //Requires: An int or a char
        //Effects: Deletes that data if it is a leaf node else prints CANNOT DELETE NODE
        void deleteNode(T data){
            int x = treeSize();
            deleteNode(data, root);
            if(x==treeSize()){
                cout << "CANNOT DELETE NODE" << endl;
            }
        }
        //Specifications:
        //Requires: Nothing
        //Effects: Returns the number of nodes in the tree
        int treeSize(){
            return treeSize(root);
        }

        //Specifications:
        //Requires: A char or int
        //Effects: returns the height of the tree starting at the passed value if found else 0 
        int subTreeSize(T data){
            if(root==nullptr){
                return 0;
            }
            queue<treeNode<T>*> q;
            q.push(root);
            while (!q.empty())
            {
                treeNode<T> *node = q.front();
                q.pop();
                if(node->data==data){
                    return treeSize(node);
                }
                if(node->left!=nullptr)
                q.push(node->left);
                if(node->right!=nullptr)
                q.push(node->right);
            }
            return 0;
        }

};
int main(){

    Tree<int> tree;

    //Test: addNode methods
    tree.addNode(5);
    tree.addNode(56);
    tree.addNode(23);
    tree.addNode(7);
    //Expected: tree contains 5 as root, 56 left, 23 right, 7 to left of 56

    //Test: treeSize method
    cout << "\nTree size: " << tree.treeSize() << endl;
    //Expected: 4

    //Test: subTreeSize method with an existing element
    cout << "Sub Tree size: " << tree.subTreeSize(56) << endl;
    //Expected: 2

    //Test: subTreeSize method with a non existing element
    cout << "Sub Tree size: " << tree.subTreeSize(-6) << endl;
    //Expected: 0


    //Test: inOrderPrint
    tree.inOrderPrint();
    //Expected: 7 56 5 23

    cout << "\n";

    //Test: postOrderPrint
    tree.postOrderPrint();
    //Expected: 7 56 23 5

    cout << "\n";

    //Test: preOrderPrint
    tree.preOrderPrint();
    //Expected: 5 56 7 23

    cout << "\n";

    //Test: deleteNode method with an existing leaf node
    tree.deleteNode(7);
    //Expected: tree contains 5 as root, 56 left and 7 to left of 56

    //Test: deleting a non existing element
    tree.deleteNode(1);
    //Expected: CANNOT DELETE NODE

    //Test: deleting a non leaf node
    tree.deleteNode(5);
    //Expected: CANNOT DELETE NODE

    return 0;
}