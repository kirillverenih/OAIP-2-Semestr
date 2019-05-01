#include <iostream>
#include <conio.h>

using namespace std;

struct queue							//     (begin) 1 |
{										//			   2 V prev:	1 -> 2 -> 3 -> 4 -> 5 -> nullptr
	int data;							//			   3	
	queue* next, * prev;				//			   4 ^ next:	nullptr <- 1 <- 2 <- 3 <- 4 <- 5
	queue* begin, * end;				//		 (end) 5 |					

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
int task9(queue*& myQueue);



void print(queue* myQueue)
{
	if (myQueue->end == nullptr)
		return;

	queue* temp = myQueue->end;

	while (temp != nullptr)
	{
		cout << temp->data << " ";
		/*		if (temp == myQueue->begin)				// Выводить начало и конец очереди
					cout << "(begin) ";					//
				if (temp == myQueue->end)				//
					cout << "(end) ";					//   */
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



int task9(queue*& myQueue)										// Удаление элементов между максимальным и минимальным
{																// и подсчёт их количества.
	queue* temp = myQueue->end;
	queue* minPointer = nullptr, * maxPointer = nullptr,
		* firstPoint = nullptr, * secondPoint = nullptr;
	bool trueOrder = false;
	int max = myQueue->end->data, min = myQueue->end->data;
	int delNumber = 0;
	bool min_max_order = true, max_min_order = false;

	if (isEmpty(myQueue))
		return 0;

	while (temp != nullptr)
	{
		if (temp->data >= max)
		{
			max = temp->data;
			maxPointer = temp;
			min_max_order = true;
			max_min_order = false;
		}
		if (temp->data <= min)
		{
			min = temp->data;
			minPointer = temp;
			min_max_order = false;
			max_min_order = true;
		}
		temp = temp->next;
	}

	if (maxPointer == minPointer)
		return 0;

	if (min_max_order)
	{
		firstPoint = minPointer;
		secondPoint = maxPointer;
	}
	else
	{
		firstPoint = maxPointer;
		secondPoint = minPointer;
	}
	if (firstPoint == secondPoint)
		return 0;

	temp = firstPoint;

	while (temp->next != nullptr)
	{
		if (temp == secondPoint)
		{
			trueOrder = true;
			break;
		}
		temp = temp->next;
	}

	if (!trueOrder)
		return 0;

	temp = firstPoint->next;
	queue* del = nullptr;

	while (temp != secondPoint)
	{
		del = temp;
		temp = temp->next;
		delete del;
		delNumber++;
	}
	firstPoint->next = secondPoint;
	secondPoint->prev = firstPoint;

	return delNumber;
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


	pushBegin(myQueue, 3);
	pushBegin(myQueue, 3);
	pushBegin(myQueue, 3);
	pushBegin(myQueue, 3);
	pushBegin(myQueue, 9);
	pushBegin(myQueue, 1);
	pushBegin(myQueue, 1);
	pushBegin(myQueue, 0);
	pushBegin(myQueue, 3);
	pushBegin(myQueue, 3);
	cout << "New queue" << endl;
	print(myQueue);


	int delNumber = task9(myQueue);
	cout << "Delete " << delNumber << " elements between max and min:" << endl;
	print(myQueue);


	clean(myQueue);
	delete myQueue;
	_getch();
	return 0;
}