class Cqueue {
	int *A;
	int front, rear;
	int max;

public:
	void push(int );

	void pop();

	int top() const { return A[front]; }

	bool empty() const { return front == -1; }

	bool full() const { return (rear + 1) % max == front; }
}


Cqueue::Cqueue(int sz) {
	max = sz;
	A = new int[sz];
	front = rear = -1;
}

void Cqueue::push(int val) {
	if(full()) return;

	rear = (rear + 1) % max;
	A[rear] = val;

	if(front == -1) front = 0;
}

void Cqueue::pop() {
	if(empty()) return;

	if(front == rear) front = rear = -1;

	else front = (front + 1) % max;
}



