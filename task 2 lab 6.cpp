#include<iostream>
using namespace std;
template<class t>
class Stack{
protected:
	t*arr;
	int size;
	int currentIndex;
public:
	Stack(int s){
		size = s;
		currentIndex = 0;
		arr = new t[size];
	}
	bool isEmpty(){
		if (currentIndex == 0)
			return 1;
		else
			return 0;
	}
	bool isFull(){
		if (currentIndex >= size)
			return 1;
		else
			return 0;
	}
	void push(t v){
		if (!isFull()){
			arr[currentIndex] = v;
			currentIndex++;
		}
		else
			cout << "stack is full. " << endl;
	}
	int pop(){
		if (!isEmpty()){
			currentIndex--;
			return arr[currentIndex];
		}
		else
			return -111111;
	}
	int top(){
		if (!isEmpty())
			return arr[currentIndex = 1];
	}
	~Stack(){ delete[] arr; }
};


int main(){
	Stack <int> s1(5);
	Stack <int> s2(5);
	cout << "enqueuing 1,2,3,4,5" << endl;

	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	for (int i = 0; i < 5; i++){
		s2.push(s1.pop());
	
	}
	cout << "dequing values" << endl;
	for (int i = 0; i < 5; i++)
		cout<<s2.pop()<<endl;
	system("pause");
	return 0;
}