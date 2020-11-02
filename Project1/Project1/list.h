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
	~list() { clear(); }

	//Adding new element to end of list
	void push_back(int temp) {
		elem* newElem = new elem(temp);
		if (isEmpty()) begin = newElem;
		else end->setNext(newElem);
		end = newElem;
		size++;
	}

	//Adding new element to begin of list
	void push_front(int temp) {
		elem* newElem = new elem(temp);
		if (isEmpty()) end = newElem;
		else newElem->setNext(begin);
		begin = newElem;
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
				elem* deleted = end;
				delete deleted;
				end = newEnd;
				size--;
			}
		}
		else throw "List is Empty";
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
				elem* deleted = begin;
				delete deleted;
				begin = newBeg;
				size--;
			}
		}
		else throw "List is Empty";
	}

	//Adding element to any position in list
	void insert(int data, size_t pos) {
		if (pos <= size) {
			if (isEmpty() || pos == size) push_back(data);
			else {
				if (pos == 0) push_front(data);
				else {
					elem* newElem = new elem(data);
					elem* iter = begin;
					while (pos-- > 1)
						iter = iter->getNext();
					newElem->setNext(iter->getNext());
					iter->setNext(newElem);
					size++;
				}
			}
		}
		else throw "Wrong index";
	}

	//Getting element from list by index
	int at(size_t pos) {
		if (pos < size) {
			elem* iter = begin;
			while (pos-- != 0) iter = iter->getNext();
			return iter->getInf();
		}
		else throw "Wrong index";
	}

	//Deleting element from list by index
	void remove(size_t pos) {
		if (pos < size) {
			if (pos == 0) pop_front();
			else {
				if (pos == size - 1) pop_back();
				else {
					elem* iter = begin;
					while (pos-- > 1) iter = iter->getNext();
					elem* nextElem = iter->getNext();
					iter->setNext(nextElem->getNext());
					size--;
				}
			}
		}
		else throw "Wrong index";
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
		if (pos < size) {
			elem* iter = begin;
			while (pos-- != 0) iter = iter->getNext();
			iter->setInf(data);
		}
		else throw "Wrong index";
	}

	//Checking list for filling
	bool isEmpty() {
		if (size == 0) return true; // 1 - Empty
		else return false;			// 0 - Filled
	}

	//Adding another list to front of this one
	void push_front(list *lst) {
		for (size_t i = 0; i < lst->getSize(); i++) 
			insert(lst->at(i), i);
	}
};
#endif