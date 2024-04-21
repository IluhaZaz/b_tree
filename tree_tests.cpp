#include "btree.cpp"
#include <gtest/gtest.h>
#include <iostream>

using namespace std;

TEST(BTreeTests, InsertCheck) {
	vector<int> v;
	v.push_back(3);
	v.push_back(0);
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(2);
	v.push_back(6);
	v.push_back(4);
	v.push_back(8);
	v.push_back(9);
	v.push_back(7);
	v.push_back(-2);
	v.push_back(-1);
	v.push_back(-2);
	v.push_back(3);
	v.push_back(-3);
	BTree<int> a(2);
	for (auto i: v) {
		a.insert(i);
		a.print();
	}
}

TEST(BTreeTests, InsertCheck2) {
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	BTree<int> a(2);
	for (auto i : v) {
		a.insert(i);
		a.print();
	}
	v.clear();
	for (int i = 0; i < 10; i++)
		v.push_back(-i);

	for (auto i : v) {
		a.insert(i);
		a.print();
	}
}