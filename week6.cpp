#include <iostream>
#include <chrono>
// #include <ctime>
// #include <cstdlib>

using namespace std;
using namespace std::chrono;

class Node{
    public:
        Node * next;
        int data ;
        Node(int val){
            this->data = val;
            this->next = nullptr;
        }
};
class LinkedList{
    public:
        Node* head;
        LinkedList(){
            this->head = nullptr;
        }
        void push(int val){
            Node* tem = new Node(val);
            tem->next = this->head;
            this->head = tem;
        }
        int pop(){
            if(this->head == nullptr){
                cout<<"stack is empty"<<endl;
                return -1;
            }else{
                Node tem = *this->head;
                this->head = tem.next;
                cout<<tem.data<<endl;
                return tem.data;
            }
        }
};

int stack2[100], n=100, tos=-1;
void push(int x) {
    tos++;
    if(tos>=n){
        cout<<"Stack Overflow"<<endl;
    }
    else {
        stack2[tos]=x;
   }
}
int pop() {
   if(tos<0){
       cout<<"Stack Underflow"<<endl;
       return -1;
   }
   else {
       tos--;
       cout<< stack2[tos+1] <<endl;
       return stack2[tos+1];
    
   }
}

int main(){
  srand(time(nullptr));

  // stack using linked lists

  LinkedList stack;
  auto start_timei = high_resolution_clock::now();
  stack.push(8);
  stack.push(10);
  stack.push(5);
  stack.push(11);
  stack.push(15);
  stack.push(23);
  stack.push(6);
  stack.push(18);
  stack.push(20);
  stack.push(17);
  for (int i=0;i<5;i++){
    stack.pop();
  }
  stack.push(4);
  stack.push(30);
  stack.push(3);
  stack.push(1);

  auto end_timei = high_resolution_clock::now();
  auto durationi = duration_cast<nanoseconds>(end_timei - start_timei);
  cout << "Time taken to implementaion using linked list " << durationi.count() << " nanoseconds" << endl;


  // stack using arrays
  start_timei = high_resolution_clock::now();
  push(8);
  push(10);
  push(5);
  push(11);
  push(15);
  push(23);
  push(6);
  push(18);
  push(20);
  push(17);
  for (int i=0;i<5;i++){
    pop();
  }
  push(4);
  push(30);
  push(3);
  push(1);

  end_timei = high_resolution_clock::now();
  durationi = duration_cast<nanoseconds>(end_timei - start_timei);
  cout << "Time taken to implementaion using array : " << durationi.count() << " nanoseconds" << endl;
    return 0;
}