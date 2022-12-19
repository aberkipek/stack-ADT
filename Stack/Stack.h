using std::string;

class Stack {
public:
	static int index;
	static int stackSize;
	string stack[5];
	void push(string);
	void pop();
	string peek();
	int size();
	bool isFull();
	bool isEmpty();
	void printStackElements();
};
