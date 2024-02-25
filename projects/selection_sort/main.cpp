#include <iostream>
#include <vector>

void sort_by_selection(std::vector<int>& arr);

int main() {
	std::vector<int> arr = { 1, 8, 2, 5, 3, 11 };
	std::cout << "Массив до сортировки:";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << ' ' << arr[i];
	}
	std::cout << std::endl;

	sort_by_selection(arr);

	std::cout << "Массив после сортировки:";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << ' ' << arr[i];
	}
	std::cout << std::endl;

	std::system("PAUSE");
	return 0;
}

void sort_by_selection(std::vector<int>& arr) {
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (arr[i] > arr[j])
				std::swap(arr[i], arr[j]);
		}
	}
	for (int i = 0; i < 6; ++i) {
		std::cout << arr[i] << " ";
	}
}
