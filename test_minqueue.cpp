#include <iostream>
#include "minqueue.cpp"


using namespace std;

void test_insert() {
    try {
        // FOR CHAR TYPE
        MinQueue<char> empty;
        empty.insert('a');
        string mq_str = empty.to_string();
        if(mq_str != "a") {
            cout << "Incorrect insert result. Epected a but got : " << mq_str << endl;
        }

        // FOR INT TYPE
        int* int_data = new int[10];
        for(int i = 0; i < 10; i++) {
            int_data[i] = 10-i;
        }
        MinQueue<int> mq(int_data, 10);
        mq.insert(25);
        mq.insert(0);
        mq_str = mq.to_string();
        if(mq_str != "0 2 1 3 6 4 8 10 7 9 25 5") {
            cout << "Incorrect insert result. Expected 0 2 1 3 6 4 8 10 7 9 25 5 but got : " << mq_str << endl;
        }

        // FOR STRING TYPE
        string* string_data = new string[4];
        string_data[0] = "EEE";
        string_data[1] = "DDD";
        string_data[2] = "FFF";
        string_data[3] = "BBB";
        
        MinQueue<string> string_mq(string_data, 4);
        string_mq.insert("ZZZ");
        string_mq.insert("AAA");
        string result = string_mq.to_string();
        if(result != "AAA DDD BBB EEE ZZZ FFF") {
            cout << "Incorrect insert result. Expected AAA DDD BBB EEE ZZZ FFF but got : " << result << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting into the priority queue : " << e.what() << endl;
    }
}

void test_min() {
    try {
        MinQueue<int> empty;
        int min = empty.min();
        if(min != 0) {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }

        int* int_data = new int[10];
        for(int i = 0; i < 10; i++){
            int_data[i] = 10-i;
        }
        MinQueue<int> mq(int_data, 10);
        min = mq.min();
        if(min != 1) {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }
}

void test_extract_min() {
    try {
        // FOR INT TYPE
        MinQueue<int> empty;
        int min = empty.extract_min();
        string mq_str = empty.to_string();
        if(min != 0 || mq_str != "") {
            cout << "Incorrect extract min result. Expected 0 and an empty queue but got : " << min << " and a queue of : " << mq_str << endl;
        }
        int* int_data = new int[10];
        for(int i = 0; i < 10; i++){
            int_data[i] = 10-i;
        }
        MinQueue<int> mq(int_data, 10);
        min = mq.extract_min();
        mq_str = mq.to_string();
        if(min != 1 || mq_str != "2 3 4 7 6 5 8 10 9") {
            cout << "Incorrect extract min result. Expected 1 and the queue 2 3 4 7 6 5 8 10 9 but got : " << min << " and a queue of : " << mq_str << endl;
        }

        // FOR STRING TYPE
        string* string_data = new string[4];
        string_data[0] = "ZZZ";
        string_data[1] = "YYY";
        string_data[2] = "XXX";
        string_data[3] = "GGG";
        
        MinQueue<string> string_mq(string_data, 4);
        string min_value = string_mq.extract_min();
        mq_str = string_mq.to_string();
        if(min_value != "GGG" || mq_str != "XXX YYY ZZZ") {
            cout << "Incorrect extract min result. Expected GGG and the queue XXX YYY ZZZ but got : " << min_value << " and a queue of : " << mq_str << endl;
        }


    } catch (exception& e) {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }
}

void test_decrease_key() {
    try {
        MinQueue<int> empty;
        empty.decrease_key(0, 0);
        string mq_str = empty.to_string();
        if (mq_str != "") {
            cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str << endl;
        }
        int* int_data = new int[10];
        for(int i = 0; i < 10; i++){
            int_data[i] = 10-i;
        }
        MinQueue<int> mq(int_data, 10);
        mq.decrease_key(0, -6);
        mq.decrease_key(9, -1);
        mq_str = mq.to_string();
        if (mq_str != "-6 -1 4 3 2 5 8 10 7 6") {
            cout << "Incorrect decrease key result. Expected -6 -1 4 3 2 5 8 10 7 6 but got : " << mq_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error in decreasing key : " << e.what() << endl;
    }
}

void test_heapsort() {
    try {
        // FOR INT TYPE
        MinQueue<int> empty;
        int* empty_data = new int[0];
        empty.sort(empty_data);
        
        int* int_data = new int[10];
        for(int i = 0; i < 10; i++){
            int_data[i] = 10-i;
        }
        
        MinQueue<int> heap(int_data, 10);
        heap.sort(int_data);
        string sorted_str = to_string(int_data[0]);
        for(int i = 1; i < 10; i++) {
            sorted_str += (" " + to_string(int_data[i]));
        }
        if(sorted_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect heapsort result. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << sorted_str << endl;
        }

        // FOR STRING TYPE
        string* string_data = new string[4];
        string_data[0] = "EEE";
        string_data[1] = "DDD";
        string_data[2] = "FFF";
        string_data[3] = "BBB";
        
        MinQueue<string> string_mq(string_data, 4);
        string_mq.sort(string_data);
        string sorted = string_data[0];
        for(int i = 1; i < 4; i++) {
            sorted += (" " + string_data[i]);
        }
        if(sorted != "BBB DDD EEE FFF") {
            cout << "Incorrect heapsort result. Expected BBB DDD EEE FFF but got : " << sorted << endl;
        }

    } catch (exception& e) {
        cerr << "Error in sorting : " << e.what() << endl;
    }
}

int main() {
    
    test_insert();
    test_min();
    test_extract_min();
    test_decrease_key();
    test_heapsort();
    
    cout << "Testing completed" << endl;
    
    return 0;
}