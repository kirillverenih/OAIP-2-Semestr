#include <iostream>
#include <conio.h>

using namespace std;

struct queue						
{									
	int data;							
	queue* next, *prev;				
	queue* begin, *end;								

	queue()
	{
		next = nullptr;
		prev = nullptr;
		begin = nullptr;
		end = nullptr;
		data = NULL;
	}
};

void print(queue* myQueue);
int isEmpty(queue* myQueue);
void pushBegin(queue*& myQueue, int info);
void pushEnd(queue*& myQueue, int info);
void clean(queue*& myQueue);
int popBegin(queue*& myQueue);
int popEnd(queue*& myQueue);
int peekBegin(queue* myQueue);
int peekEnd(queue* myQueue);
int size(queue* myQueue);




void print(queue* myQueue)
{
	if (myQueue->end == nullptr)
		return;

	queue* temp = myQueue->end;

	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;

	return;
}



int isEmpty(queue* myQueue)
{
	if (myQueue->end == nullptr && myQueue->begin == nullptr)
		return 1;
	return 0;
}



void pushBegin(queue*& myQueue, int info)
{
	queue* newNode = new queue;

	if (isEmpty(myQueue))
	{
		newNode->data = info;
		newNode->next = nullptr;
		newNode->prev = nullptr;
		myQueue->begin = newNode;
		myQueue->end = newNode;
	}
	else
	{
		newNode->data = info;
		newNode->next = nullptr;
		myQueue->begin->next = newNode;
		newNode->prev = myQueue->begin;
		myQueue->begin = newNode;
	}

	return;
}



void pushEnd(queue*& myQueue, int info)
{
	queue* newNode = new queue;

	if (isEmpty(myQueue))
	{
		newNode->data = info;
		newNode->next = nullptr;
		newNode->prev = nullptr;
		myQueue->begin = newNode;
		myQueue->end = newNode;
	}
	else
	{
		newNode->data = info;
		newNode->next = myQueue->end;
		myQueue->end->prev = newNode;
		newNode->prev = nullptr;
		myQueue->end = newNode;
	}

	return;
}



void clean(queue*& myQueue)
{
	queue* temp = nullptr;

	while (myQueue->end != nullptr)
	{
		temp = myQueue->end;
		myQueue->end = myQueue->end->next;
		delete temp;
	}
	myQueue->begin = nullptr;

	return;
}



int popBegin(queue*& myQueue)
{
	int info;

	if (isEmpty(myQueue))
		return 0;
	if (size(myQueue) == 1)
	{
		info = myQueue->begin->data;
		delete myQueue->begin;
		myQueue->begin = nullptr;
		myQueue->end = nullptr;
		myQueue->next = nullptr;
		myQueue->prev = nullptr;
		return info;
	}
	queue* temp = myQueue->begin->prev;
	myQueue->begin->prev->next = nullptr;
	info = myQueue->begin->data;
	delete myQueue->begin;
	myQueue->begin = temp;

	return info;
}



int popEnd(queue*& myQueue)
{
	int info;

	if (isEmpty(myQueue))
		return 0;
	if (size(myQueue) == 1)
	{
		info = myQueue->end->data;
		delete myQueue->end;
		myQueue->begin = nullptr;
		myQueue->end = nullptr;
		myQueue->next = nullptr;
		myQueue->prev = nullptr;
		return info;
	}
	queue* temp = myQueue->end->next;
	myQueue->end->next->prev = nullptr;
	info = myQueue->end->data;
	delete myQueue->end;
	myQueue->end = temp;

	return info;
}



int peekBegin(queue* myQueue)
{
	return myQueue->begin->data;
}



int peekEnd(queue* myQueue)
{
	return myQueue->end->data;
}



int size(queue* myQueue)
{
	if (myQueue->end == nullptr)
		return 0;

	queue* temp = myQueue->end;
	int counter = 0;

	while (temp != nullptr)	
	{
		temp = temp->next;
		counter++;
	}
	return counter;
}



void checkFromSides(queue *&myQueue) {
	while (myQueue->begin->data % 2 == 0) {
		popBegin(myQueue);
	}

	while (myQueue->end->data % 2 == 0) {
		popEnd(myQueue);
	}
}



void task(queue* myQueue)
{
	if (isEmpty(myQueue))
		return;

	int size_ = size(myQueue);
	if (size_ == 1) {
		if (myQueue->data % 2 == 0) {
			clean(myQueue);
		}
		return;
	}

	if (size_ == 2) {
		if (myQueue->begin->data % 2 == 0) {
			int val = myQueue->end->data;
			clean(myQueue);
			pushBegin(myQueue, val);
			return;
		}
		if (myQueue->end->data % 2 == 0) {
			int val = myQueue->begin->data;
			clean(myQueue);
			pushBegin(myQueue, val);
			return;
		}
		return;
	}

//2 1 2 3 4 5 6 4 6 3 10
// если очередь из 2

	checkFromSides(myQueue);
	queue* temp = myQueue->begin;
	while (temp != nullptr) 
	{
		if (temp->data % 2 == 0) 
		{
			queue *val = temp;
			temp->prev->next = temp->next;
			temp = temp->prev;
			delete val;
		}
		else
		{
			temp = temp->prev;
		}
		
	}
	cout << endl;
	return;
}

int main(void)
{
	queue* myQueue = new queue;


	pushBegin(myQueue, 0);
	pushBegin(myQueue, 1);
	pushBegin(myQueue, 2);
	pushBegin(myQueue, 3);
	pushBegin(myQueue, 4);
	cout << "Push begin:" << endl;
	print(myQueue);


	pushEnd(myQueue, 5);
	pushEnd(myQueue, 6);
	pushEnd(myQueue, 7);
	pushEnd(myQueue, 8);
	pushEnd(myQueue, 9);
	cout << "Push end:" << endl;
	print(myQueue);


	clean(myQueue);
	cout << "Clean:" << endl;
	print(myQueue);

	pushBegin(myQueue, 2);
	pushBegin(myQueue, 2);
	pushBegin(myQueue, 2);
	pushBegin(myQueue, 2);
	pushBegin(myQueue, 1);
	pushBegin(myQueue, 2);
	pushBegin(myQueue, 3);
	pushBegin(myQueue, 4);
	pushBegin(myQueue, 5);
	pushBegin(myQueue, 6);
	pushBegin(myQueue, 4);
	pushBegin(myQueue, 6);
	pushBegin(myQueue, 3);
	pushBegin(myQueue, 10);
	pushBegin(myQueue, 2);
	pushBegin(myQueue, 2);
	pushBegin(myQueue, 2);
	pushBegin(myQueue, 2);


	cout << "Before " << endl;
	print(myQueue);

	cout << "After " << endl;
	task(myQueue);
	print(myQueue);

	clean(myQueue);
	delete myQueue;
	_getch();
	return 0;
}