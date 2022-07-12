#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

class TreeN{//node declaration 
   public: 
        char d; //root
        TreeN *l, *r;
        TreeN(char d) {
            this->d = d; //root is whatever you put in the function parameter
            this->l = NULL;
            this->r = NULL;
        }
};

class StackNod{// stack basically means creating a new node under
   public: 
        TreeN *treeN;
        StackNod *n; 
        StackNod(TreeN* treeN){//constructor 
            this->treeN = treeN;
            n = NULL;
        }
};

class ExpressionTree {
   private: 
        StackNod *top;
   public: 
        ExpressionTree() {
            top = NULL;
        }
        void clear() {
            top = NULL;
        }

        void push(TreeN *ptr) {
            if (top == NULL)
                top = new StackNod(ptr); // if there's no top yet, which is initially null, stack the character on the node
            else {
                StackNod *nptr = new StackNod(ptr);
                nptr->n = top;
                top = nptr;
            }
        }

        TreeN *pop() {
            if (top == NULL) {
                cout << "Underflow" << endl;
            } else {
                TreeN *ptr = top->treeN; // make ptr the node of top
                top = top->n; // make top of what's n
                return ptr; // return node ptr
            }
        }

        TreeN *peek() {
            return top->treeN;
        }

        void insert(char val) {
            if (isDigit(val)) { // isDigit checks if it's a digit
               TreeN *nptr = new TreeN(val); // Make a Node with the number
               push(nptr); // push the number node to the tree
            } else if (isOperator(val)) {
               TreeN *nptr = new TreeN(val); // if char isOperator, then make a node
               nptr->l = pop(); // put to the left of the node a new node consisting the character from its top node
               nptr->r = pop(); // put to the right of the node a new node consisting the character from its top node
               push(nptr); // 
 
            } else {
               cout<<"Invalid Expression"<<endl;
               return;
            }
         }

        bool isDigit(char ch) {
            return ch >= '0' && ch <= '9';
        }

        bool isOperator(char ch) {
            return ch == '+' || ch == '-' || ch == '*' || ch == '/';
        }

        int toDigit(char ch) {
            return ch - '0';
        }

        void buildTree(string eqn) { //goes through all letters
            for (int i = eqn.length() - 1; i >= 0; i--)
                insert(eqn[i]); //calls insert function, which conditions if it's a number or operation
        }

        void postfix() {
            postOrder(peek());
        }

        void postOrder(TreeN*ptr) {
            if (ptr != NULL) {
                postOrder(ptr->l);
                postOrder(ptr->r);
                cout << ptr->d;
            }
        }
        void infix() {
            inOrder(peek());
        }

        void inOrder(TreeN *ptr) {
            if (ptr != NULL) {
                inOrder(ptr->l);
                cout<<ptr->d;
                inOrder(ptr->r);
            }
        }
        void prefix() {
            preOrder(peek());
        }

        int preOrder(TreeN *ptr) {
            if (ptr != NULL) {
               //cout<<ptr->d;
                char left = preOrder(ptr->l);
                char right = preOrder(ptr->r);
                /*preOrder(ptr->l);
                preOrder(ptr->r);*/
                TYPE& dynamic_cast<TYPE&> (ptr);
                TYPE* dynamic_cast<TYPE*> (ptr);
                if (ptr->d == '+') {
                    return left + right;
                }
            }
        }
};

int main() {
    //string s = "++7*626";
    string s = "6+3";
    ExpressionTree et;
    /*cout << "\nEnter equation in Prefix form: ";
    cin >> s;*/
    et.buildTree(s); //calls buildTree function
    cout<<"\nPrefix : ";
    et.prefix();
    cout<<"\n\nInfix : ";
    et.infix();
    cout<<"\n\nPostfix : ";
    et.postfix();
}