#include "btree.cpp"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "bin_tree.cpp"
#include <algorithm>
#include <fstream>
#include <set>


void main() {
	{
		vector<int> sizes{ 50000, 100000, 200000, 300000, 400000, 500000};

		std::ofstream file;
		file.open("C:\\b_tree\\insert.txt");

		for (const auto& size : sizes) {

			BTree<int> b(30);
			auto begin = std::chrono::steady_clock::now();
			for (int i = 0; i < size; i++) {
				b.insert(rand());
			}
			auto end = std::chrono::steady_clock::now();
			auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
			std::cout << elapsed_ms << " BTree for " << size << " values" << endl;
			file << elapsed_ms.count() << " ";

			set<int> s;
			begin = std::chrono::steady_clock::now();
			for (int i = 0; i < size; i++) {
				s.insert(rand());
			}
			end = std::chrono::steady_clock::now();
			elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
			std::cout << elapsed_ms << " Set for " << size << " values" << endl;
			file << elapsed_ms.count() << " ";

			BinaryTree<int> bin;
			begin = std::chrono::steady_clock::now();
			for (int i = 0; i < size; i++) {
				bin.insert(rand());
			}
			end = std::chrono::steady_clock::now();
			elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
			std::cout << elapsed_ms << " Binary tree for " << size << " values" << endl;
			file << elapsed_ms.count() << " ";

			vector<int> v;
			begin = std::chrono::steady_clock::now();
			for (int i = 0; i < size; i++) {
				v.push_back(rand());
			}
			end = std::chrono::steady_clock::now();
			elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
			std::cout << elapsed_ms << " vector for " << size << " values" << endl;
			file << elapsed_ms.count() << " ";
		}
		file.close();
	}

	{
		std::ofstream file;
		file.open("C:\\b_tree\\search.txt");

		vector<int> sizes{ 50000, 100000, 200000, 300000, 400000, 500000};
		for (const auto& size : sizes) {

			BTree<int> b(30);
			set<int> s;
			BinaryTree<int> bin;
			vector<int> v;

			vector<int> values;
			for (int i = 0; i < size; i++) {
				int r = rand();
				b.insert(r);
				s.insert(r);
				bin.insert(r);
				v.push_back(r);

				values.push_back(r);
			}

			auto begin = std::chrono::steady_clock::now();
			for (int i = 0; i < size; i++) {
				b.find(values[i]);
			}
			auto end = std::chrono::steady_clock::now();
			auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
			std::cout << elapsed_ms << " BTree for " << size << " values" << endl;
			file << elapsed_ms.count() << " ";

			begin = std::chrono::steady_clock::now();
			for (int i = 0; i < size; i++) {
				s.find(values[i]);
			}
			end = std::chrono::steady_clock::now();
			elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
			std::cout << elapsed_ms << " Set for " << size << " values" << endl;
			file << elapsed_ms.count() << " ";

			begin = std::chrono::steady_clock::now();
			for (int i = 0; i < size; i++) {
				bin.contains(values[i]);
			}
			end = std::chrono::steady_clock::now();
			elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
			std::cout << elapsed_ms << " Binary tree for " << size << " values" << endl;
			file << elapsed_ms.count() << " ";

			begin = std::chrono::steady_clock::now();
			for (int i = 0; i < size; i++) {
				std::find(v.begin(), v.end(), values[i]);
			}
			end = std::chrono::steady_clock::now();
			elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
			std::cout << elapsed_ms << " Vector for " << size << " values" << endl;
			file << elapsed_ms.count() << " ";
		}
	}
}
