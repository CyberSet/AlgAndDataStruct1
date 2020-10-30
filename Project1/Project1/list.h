#pragma once
#include <iostream>
#ifndef LIST_H
#define LIST_H
class elem {
private:
	int inf;
	elem* next;
public:
	elem(int elem_inf) { inf = elem_inf; next = nullptr;}
	~elem() {};
	elem* getNext() { return next; }
	void setNext(elem* elem_next) { next = elem_next; }
	int getInf() { return inf; }
	void setInf(int elem_inf) { inf = elem_inf; }
};

class list {
private:
	elem* begin, * end;
	size_t size;
public:
	list() { begin = nullptr; end = nullptr; size = 0;}
	~list() { delete[] begin; delete[] end;}

	//Adding new element to end of list
	void push_back(int temp) {
		elem* newelem = new elem(temp);
		if (!isEmpty()) end->setNext(newelem);
		end = newelem;
		if (isEmpty()) begin = end;
		size++;
	}

	//Adding new element to begin of list
	void push_front(int temp) {
		elem* newElem = new elem(temp);
		if(!isEmpty()) newElem->setNext(begin);
		begin = newElem;
		if (isEmpty()) end = begin;
		size++;
	}

	//Deleting last element from list
	void pop_back(){
		if (!isEmpty()) {
			if (size == 1) {
				end = nullptr;
				begin = nullptr;
				size = 0;
			}
			else {
				elem* newEnd = begin;
				while (newEnd->getNext() != end) newEnd = newEnd->getNext();
				newEnd->setNext(nullptr);
				end = newEnd;
				size--;
			}	
		}
	}

	//Deleting first element from list
	void pop_front() {
		if (!isEmpty()) {
			if (size == 1) {
				begin = nullptr;
				end = nullptr;
				size = 0;
			}
			else {
				elem* newBeg = begin->getNext();
				begin = newBeg;
				size--;
			}
		}
	}

	//Adding element to any position in list
	void insert(int data, size_t pos) {
		if (pos >= 0 && pos <= size) {
			elem* newElem = new elem(data);
			if(isEmpty()){
				begin = newElem;
				end = begin;
				size = 1;
			}
			else {
				elem* iter = begin;
				while (pos-- != 0)
					iter = iter->getNext();
				newElem->setNext(iter->getNext());
				iter->setNext(newElem);
				if (newElem->getNext() == nullptr) end = newElem;
				size++;
			}
		}
	}

	//Getting element from list by index
	int at(size_t pos) {
		elem* iter = begin;
		while (pos-- != 0) iter = iter->getNext();
		return iter->getInf();
	}

	//Deleting element from list by index
	void remove(size_t pos) {
		elem* iter = begin;
		while (pos-- > 1) iter = iter->getNext();
		elem* nextElem = iter->getNext();
		iter->setNext(nextElem->getNext());
		delete[] nextElem;
		size--;
	}

	//Getting size of list
	size_t getSize() { return size; }

	//Output elements from list to console
	void print_to_console() {
		elem* iter = begin;
		for (size_t i = 0; i < size; i++) {
			std::cout << iter->getInf() << " ";
			iter = iter->getNext();
		}
	}

	//Deleting elements of list
	void clear() {
		while (size) pop_back();
	}

	//Replacing element by index with new one
	void set(size_t pos, int data) {
		elem* iter = begin;
		while (pos-- != 0) iter = iter->getNext();
		iter->setInf(data);
	}

	//Checking list for filling
	bool isEmpty() {
		if (size == 0) return true; // 1 - Empty
		else return false;			// 0 - Filled
	}

	//Adding another list to front of this one
	void push_front(list lst) {
		for (size_t i = 0; i < lst.getSize(); i++)
			insert(lst.at(i), i);
	}
};
#endif