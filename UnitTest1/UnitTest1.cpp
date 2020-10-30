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

		TEST_METHOD(InsertTest2) { // empty list insert at second place
			list* list1 = new list();
			list1->insert(1, 1);
			Assert::IsTrue(list1->getSize() == 0);
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
	};
}
