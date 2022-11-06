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
        void push(const T &item) {
            v.push_back(item);
        }
        void pop(){
            if(v.size()!=0)
            v.pop_back();
        }
        T& Top() {
            return v.back();
        }
        bool empty() const {
            return v.size() == 0;
        }
};

int main(){
    Stack<int> stack;
    stack.push(5);
    cout << stack.Top();
    return 0;
}


    
