#include "pch.h"
#include "CppUnitTest.h"
#include "..\Project1\Project1\List.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListTests
{
	TEST_CLASS(ListTests)
	{
	public:
		
		TEST_METHOD(CreateTest)
		{
			list *list1 = new list();
			Assert::IsTrue(list1->getSize() == 0);
		}

		TEST_METHOD(PushBackTest1) {
			list *list1 = new list();
			list1->push_back(1);
			Assert::IsTrue(list1->at(0) == 1 && list1->getSize() == 1);
		}

		TEST_METHOD(PushBackTest2) {
			list* list1 = new list();
			list1->push_back(1);
			list1->push_back(2);
			Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->getSize() == 2);
		}

		TEST_METHOD(PushFrontTest1) {
			list *list1 = new list();
			list1->push_front(1);
			Assert::IsTrue(list1->at(0) == 1 && list1->getSize() == 1);
		}

		TEST_METHOD(PushFrontTest2) {
			list* list1 = new list();
			list1->push_front(2);
			list1->push_front(1);
			Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->getSize() == 2);
		}

		TEST_METHOD(PopBackTest1) { // 2 elements
			list* list1 = new list();
			list1->push_back(1);
			list1->push_back(2);
			list1->pop_back();
			Assert::IsTrue(list1->at(0) == 1 && list1->getSize() == 1);
		}

		TEST_METHOD(PopBackTest2) { // 1 element
			list* list1 = new list();
			list1->push_back(1);
			list1->pop_back();
			Assert::IsTrue(list1->getSize() == 0);
		}

		TEST_METHOD(PopBackTest3) { // empty list
			list* list1 = new list();
			list1->pop_back();
			Assert::IsTrue(list1->getSize() == 0);
		}

		TEST_METHOD(PopFrontTest1) { // 2 elements
			list* list1 = new list();
			list1->push_back(2);
			list1->push_back(1);
			list1->pop_front();
			Assert::IsTrue(list1->at(0) == 1 && list1->getSize() == 1);
		}

		TEST_METHOD(PopFrontTest2) { // 1 element
			list* list1 = new list();
			list1->push_back(1);
			list1->pop_front();
			Assert::IsTrue(list1->getSize() == 0);
		}

		TEST_METHOD(PopFrontTest3) { // empty list
			list* list1 = new list();
			list1->pop_front();
			Assert::IsTrue(list1->getSize() == 0);
		}

		TEST_METHOD(InsertTest1) { // empty list insert at first place
			list* list1 = new list();
			list1->insert(1, 0);
			Assert::IsTrue(list1->at(0) == 1 && list1->getSize() == 1);
		}

		TEST_METHOD(InsertTest2) { // empty list insert at second place - out of range
			list* list1 = new list();
			list1->insert(1, 1);
			Assert::IsTrue(list1->getSize() == 0);
		}

		TEST_METHOD(InsertTest3) { // same as push_back
			list* list1 = new list();
			list1->push_back(1);
			list1->insert(2, 1);
			Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->getSize() == 2 );
		}

		TEST_METHOD(InsertTest4) { // same as push_front
			list* list1 = new list();
			list1->push_back(2);
			list1->insert(1, 0);
			Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->getSize() == 2);
		}

		TEST_METHOD(InsertTest5) { // insert to middle
			list* list1 = new list();
			list1->push_back(1);
			list1->push_back(3);
			list1->insert(2, 1);
			Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->at(2) == 3 && list1->getSize() == 3);
		}

		TEST_METHOD(AtTest) {
			list* list1 = new list();
			list1->push_back(1);
			list1->push_back(2);
			list1->push_back(3);
			Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->at(2) == 3);
		}

		TEST_METHOD(RemoveTest1) { // empty list remove 
			list* list1 = new list();
			list1->remove(1);
			Assert::IsTrue(list1->getSize() == 0);
		}
		
		TEST_METHOD(RemoveTest2) { // same as pop_back
			list* list1 = new list();
			list1->push_back(1);
			list1->push_back(2);
			list1->push_back(3);
			list1->remove(2);
			Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->getSize() == 2);
		}

		TEST_METHOD(RemoveTest3) { // same as pop_front
			list* list1 = new list();
			list1->push_back(3);
			list1->push_back(1);
			list1->push_back(2);
			list1->remove(0);
			Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->getSize() == 2);
		}

		TEST_METHOD(RemoveTest4) { // remove from middle
			list* list1 = new list();
			list1->push_back(1);
			list1->push_back(3);
			list1->push_back(2);
			list1->remove(1);
			Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->getSize() == 2);
		}

		TEST_METHOD(RemoveTest5) { // out of range check
			list* list1 = new list();
			list1->push_back(1);
			list1->push_back(2);
			list1->push_back(3);
			list1->remove(3);
			Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->at(2) == 3 && list1->getSize() == 3);
		}

		TEST_METHOD(GetSizeTest1) {
			list* list1 = new list();
			Assert::IsTrue(list1->getSize() == 0);
		}

		TEST_METHOD(GetSizeTest2) {
			list* list1 = new list();
			list1->push_back(1);
			list1->push_back(2);
			list1->push_back(3);
			Assert::IsTrue(list1->getSize() == 3);
		}

		TEST_METHOD(SetTest1) { 
			list* list1 = new list();
			list1->push_back(0);
			list1->push_back(2);
			list1->push_back(3);
			list1->set(0, 1);
			Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->at(2) == 3 && list1->getSize() == 3);
		}

		TEST_METHOD(SetTest2) { //out of range
			list* list1 = new list();
			list1->push_back(1);
			list1->push_back(2);
			list1->push_back(3);
			list1->set(3, 1);
			Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->at(2) == 3 && list1->getSize() == 3);
		}

		TEST_METHOD(SetTest3) { //set same
			list* list1 = new list();
			list1->push_back(1);
			list1->push_back(2);
			list1->push_back(3);
			list1->set(0, 1);
			Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->at(2) == 3 && list1->getSize() == 3);
		}

		TEST_METHOD(SetTest4) { //set twice
			list* list1 = new list();
			list1->push_back(1);
			list1->push_back(2);
			list1->push_back(3);
			list1->set(0, 2);
			list1->set(0, 1);
			Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->at(2) == 3 && list1->getSize() == 3);
		}

		TEST_METHOD(IsEmptyTest1) {
			list *list1 = new list();
			Assert::IsTrue(list1->isEmpty());
		}

		TEST_METHOD(IsEmptyTest2) {
			list* list1 = new list();
			list1->push_front(1);
			Assert::IsTrue(!list1->isEmpty());
		}

		TEST_METHOD(PushFrontListTest1) {
			list* list1 = new list();
			list* list2 = new list();
			list2->push_back(1);
			list2->push_back(2);
			list2->push_back(3);
			list1->push_back(4);
			list1->push_back(5);
			list1->push_back(6);
			list1->push_front(list2);
			Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->at(2) == 3 && list1->at(3) == 4 && list1->at(4) == 5 && list1->at(5) == 6 && list1->getSize() == 6);
		}

		TEST_METHOD(PushFrontListTest2) { //pushed list is empty
			list* list1 = new list();
			list* list2 = new list();
			list1->push_back(1);
			list1->push_back(2);
			list1->push_back(3);
			list1->push_front(list2);
			Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->at(2) == 3 && list1->getSize() == 3);
		}

		TEST_METHOD(PushFrontListTest3) { //first list is empty
			list* list1 = new list();
			list* list2 = new list();
			list2->push_back(1);
			list2->push_back(2);
			list2->push_back(3);
			list1->push_front(list2);
			Assert::IsTrue(list1->at(0) == 1 && list1->at(1) == 2 && list1->at(2) == 3 && list1->getSize() == 3);
		}

		TEST_METHOD(PushFrontListTest4) { //both lists are empty
			list* list1 = new list();
			list* list2 = new list();
			list1->push_front(list2);
			Assert::IsTrue(list1->getSize() == 0);
		}
	};
}
