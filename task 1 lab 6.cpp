#include<iostream>
using namespace std;
template <typename T>
class AbstractQueue {
public:
	AbstractQueue(){}
	virtual void enQueue(T value) = 0;
	virtual T deQueue() = 0;
	
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual ~AbstractQueue() {}
};template <typename T>class myQueue: public AbstractQueue<T>{
	T*arr;
	int front;
	int rear;
	int size;
public:
	myQueue(int s):AbstractQueue(){
		size = s;
		arr = new T [size];
		front = 0;
		rear = 0;
	

	}
	void enQueue(T value){
		if (!isFull()){
			arr[rear] = value;
			rear++;
		}

	}
	T top(){
		return arr[front];
	}
	T deQueue(){
		if (!isEmpty()){
			front++;
			return arr[front - 1];
		}
	}
	bool isEmpty(){
		if (front == rear)
			return 1;
		else
			return 0;
	}
	bool isFull(){
		if (rear > size)
			return 1;
		else
			return 0;
	}
	void display(){
		cout << "printing whole queue " << endl;
		if (!isEmpty()){
			for (int i = front; i < rear; i++){
				cout << arr[i] << "  ";
			}
		}
	}
	~myQueue() { delete[]arr; }
};
int main(){
	int s=0;
	cout << "enter size " << endl;
	cin >> s;
	myQueue <int> q(s);
	
	while (true){
		cout << "enter 1 to add value , enter 2 to take value out , enter 3 to check value of top , enter 4 to display queue , enter 0 to exit" << endl;
		cin >> s;
		if (s == 0)
			break;
		else if (s == 1){
			if (q.isFull())
				cout << "queue is full  " << endl;
			else{
				int val = 0;
				cout << endl << "enter value : ";
				cin >> val;
				q.enQueue(val);
				cout << endl;
			}
		}
		else if (s == 2){
			cout<<q.deQueue()<<endl;
		}
		else if (s == 3){
			cout << q.top();
		}
		else if (s == 4)
			q.display();

		else
			cout << "invalid number enter again thanks : " << endl;
	}
	

	return 0;
}