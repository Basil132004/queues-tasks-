#include<iostream>
using namespace std;
template <typename T>
class AbstractQueue {
public:
	AbstractQueue(){}
	virtual void enQueue(T value) = 0;
	virtual T deQueue() = 0;
	virtual T Front() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual ~AbstractQueue() {}
};template <typename T>class myQueue : public AbstractQueue<T>{
	T*arr;
	int front;
	int rear;
	int size;
public:
	myQueue(int s) :AbstractQueue(){
		size = s;
		arr = new T[size];
		front = 0;
		rear = 0;


	}
	void enQueue(T value){
		if (!isFull()){
			arr[rear] = value;
			rear++;
		}

	}
	T Front(){
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
	void reverseQ(int k){
		if ( k-front <= 1)
			cout << "no reversal needed in this case : " << endl;
	else if (k>=rear) {
			cout << "Invalid range!" << endl;
			return;
		}
		else{
			int end = front + k - 1;
			for (int i = front; i < front + k / 2; i++) {
				T temp = arr[i];
				arr[i] = arr[end];
				arr[end] = temp;
				end--;
			}
		}
	}
	~myQueue() { delete[]arr; }
};

int main(){
	int s = 0;
	cout << "enter size " << endl;
	cin >> s;
	myQueue <int> q(s);
	while (true){
		cout << "enter 1 to add value ," << endl << "enter 2 to take value out " << endl << "enter 3 to check value of top" << endl << " enter 4 to display queue " << endl << "enter 5 to reverse " << endl << "enter 0 to exit" << endl;
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
			cout << q.deQueue() << endl;
		}
		else if (s == 3){
			cout << q.Front()<<endl;
		}
		else if (s == 4)
			q.display();
		else if (s == 5){
			int k = 0;
			cout << "enter how many elements you want to reverse :" << endl;
			cin >> k;
			q.reverseQ(k);
		}
		else
			cout << "invalid number enter again thanks : " << endl;
	}
	return 0;
}