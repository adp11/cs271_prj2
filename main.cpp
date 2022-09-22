#include <iostream>
#include "usecase.cpp"

using namespace std;

void test_sliding_window() {
    try {
        int* empty = new int[0];
        string window_result = sliding_window(empty, 0, 0);
        if(window_result != "") {
            cout << "Incorrect sliding window result. Expected and empty string but got : " << window_result << endl;
        }
        int nums[8] = {1,3,-1,-3,5,3,6,7};
        window_result = sliding_window(nums, 8, 3);
        if(window_result != "-1 -3 -3 -3 3 3") {
            cout << "Incorrect sliding window result. Expected -1 -3 -3 -3 3 3 but got : " << window_result << endl;
        }
        window_result = sliding_window(nums, 1, 1);
        if(window_result != "1") {
            cout << "Incorrect sliding window result. Expected 1 but got : " << window_result << endl;
        }
    } catch(exception &e) {
        cerr << "Error in generating sliding window result : " << e.what() << endl;
    }
}

int main() {
	test_sliding_window();
	cout << "Testing sliding window completed" << endl;
	return 0;
}