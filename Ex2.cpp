 #include <iostream>
 #include <vector>
 using namespace std;

template <class T>
class Stack{
    private:
        vector<T> v;
    public:
        Stack(){
            
        }
        //Specifications:
        //Expects: An item of type T
        //Effects: Adds item of type T to the top of the stack
        void push(const T &item) {
            v.push_back(item);
        }
        //Specifications:
        //Expects: Nothing
        //Effects: Removes the item on top of the stack
        void pop(){
            if(v.size()!=0)
            v.pop_back();
        }
        //Specifications:
        //Expects: Nothing
        //Effects: Returns the element on the top of the stack
        T& Top() {
            return v.back();
        }
        //Specifications:
        //Expects: Nothing
        //Effects: Returns 0 if the stack is empty else returns 1
        bool empty() const {
            return v.size() == 0;
        }
};

int main(){
    Stack<int> stack;
    //Test: push method with integers
    stack.push(5);
    stack.push(6);
    //Expected: stack contains 5 and 6 with 6 on the top

    //Test: Top method with a non empty stack
    cout << stack.Top() << endl;
    //Expected: 6

    //Test: empty method with a non empty stack
    cout << stack.empty() << endl;
    //Expected: 0

    //Test pop method with a non empty stack
    stack.pop();
    //Expected: 6 is removed
    stack.pop();
    cout << stack.Top() << endl;
    //Expected: 5 is removed

    //Test: pop method with an empty stack
    stack.pop();
    //Expected: Nothing happens

    //Testing: empty method with an empty stack
    cout << stack.empty() << endl;
    //Expected: 1
    return 0;
}


    
