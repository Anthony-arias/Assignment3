#pragma once
class Tower
{
private:
	struct StackNode
	{
		int value; //Value in the node
		StackNode* next;  // Pointer to next node
	};

	StackNode* top;     // Pointer to the stack top

public:
	//Constructor
	Tower()
	{
		top = nullptr;
	}


	~Tower();
	void push(int element);
	void pop(int& element);
	bool isEmpty() const;
	void print() const;

};
//PreCondition: input element (int) 
//PostCondition: pops the value at the top of the stack off, and copies it into element. 

void Tower::pop(int& element)
{

	// First make sure the stack isn't empty.
	if (isEmpty())
		cout << "ERROR: Cannot make the move." << endl;
	else  // pop value off top of stack
	{
		StackNode* temp = nullptr; // Temporary pointer
		element = top->value;
		temp = top->next;
		top = temp;
	}
}

//PreCondition: input element (int)
//PostCondition: pushes the argument onto the stack. 

void Tower::push(int element)
{
	StackNode* newNode = nullptr; // Pointer to a new node

	// Allocate a new node and store num there.
	newNode = new StackNode;
	newNode->value = element;

	// If there are no nodes in the list
	// make newNode the first node.
	if (isEmpty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else  // Otherwise, insert NewNode before top.
	{
		newNode->next = top;
		top = newNode;
	}
}

// Destructor 

Tower::~Tower()
{
	int element;

	while (!isEmpty())
	{
		pop(element);
	}
}

//PreCondition: NA
//PostCondition: returns true if the stack is empty, and false otherwise. 

bool Tower::isEmpty() const
{
	return (!top) ? true : false;
}

//PreCondition: NA
//PostCondition: displays the value stored in the stack on the screen. 
void Tower::print() const
{
	if (isEmpty())
		cout << "Stack is empty" << endl;
	else
	{
		cout << top->value << endl;

		if (top->next != nullptr)
		{
			StackNode* temp = top->next;

			while (temp)
			{
				cout << temp->value << endl;
				temp = temp->next;
			}
		}
		cout << endl;
	}
}