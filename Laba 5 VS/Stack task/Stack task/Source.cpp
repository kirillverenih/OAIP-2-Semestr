﻿#include "pch.h"
#include <iostream>
using namespace std;

template <typename T>
class stack {
public:
	stack()
	{
		size = 0;
		head = nullptr;
	};

	int get_size()
	{
		return size;
	};

	void clear()
	{
		while (size) {
			pop();
		}
	};

	void push(T data)
	{
		if (head == nullptr) {
			head = new element<T>(data);
		}
		else {
			element<T>* current = this->head;

			while (current->ptr != nullptr) {
				current = current->ptr;
			}
			current->ptr = new element<T>(data);
		}

		size++;
	};

	void pop()
	{
		if (this->head->ptr == nullptr) {
			delete head;
			head = nullptr;
			size--;
		}
		else {
			element<T>* prev = this->head;
			while (prev->ptr->ptr != nullptr) {
				prev = prev->ptr;
			}
			delete prev->ptr;
			prev->ptr = nullptr;
			size--;
		}
	}

	T see()
	{

		element<T>* last = this->head;
		while (last->ptr != nullptr) {
			last = last->ptr;
		}
		return last->data;
	};

	void Task()
	{

		element<T>* prev = this->head;
		if (prev->ptr != nullptr) {

			while (prev->ptr != nullptr && (prev->ptr->data % 2 != 0)) {
				prev = prev->ptr;
			}
			element<T>* toDelete = prev->ptr;

			if (toDelete != nullptr) {
				prev->ptr = toDelete->ptr;
				delete toDelete;
				size--;
				if (prev->ptr != nullptr) {
					return Task();
				}
			}
		}
	};

private:
	int size;

	template <typename T>
	class element {

	public:
		element* ptr;
		T data;

		element(T data = T(), element* ptr = nullptr)
		{

			this->data = data;
			this->ptr = ptr;
		}
	};
	element<T>* head;

	void _sort_by_value(element<T>* pointer)
	{
		element<T> *prev = pointer, *next = pointer->ptr;
		if (next != nullptr) {
			if (prev->data > next->data) {
				T temp = prev->data;
				prev->data = next->data;
				next->data = temp;
				return _sort_by_value(next);
			}
		}
		else {
			return;
		}
	};

public:
	void sort_by_value()
	{
		element<T>* qwerty = this->head;
		for (int i = 0; i < size; i++) {
			_sort_by_value(qwerty);
		}
	};

	void sort_by_adress()
	{
		element<T> *potr = head, *tmp = nullptr, *prev = nullptr;
		bool flag = false;
		if (head) {
			do {
				flag = false;
				potr = head;
				while (potr->ptr) {
					if (potr->data > potr->ptr->data) {
						if (potr == head) {
							tmp = potr;
							potr = tmp->ptr;
							tmp->ptr = potr->ptr;
							potr->ptr = tmp;
							head = potr;
							flag = true;
						}
						else {
							tmp = potr;
							potr = tmp->ptr;
							tmp->ptr = potr->ptr;
							potr->ptr = tmp;
							prev->ptr = potr;
							flag = true;
						}
					}
					prev = potr;
					potr = potr->ptr;
				}
			} while (flag);
		}
	};
};
