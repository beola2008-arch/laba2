#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <cmath>
using namespace std;
using namespace chrono;

mt19937 gen(random_device{}());
uniform_int_distribution<> d(-99, 99);
int getN(string message, int min, int max) {
    int x;
    while (true) {
        cout << message;
        if (cin >> x) {
            if (x >= min and x <= max) {
                return x;
            }
            cout << "Wrong number! Try again.\n";
        }
        else {
            cout << "Wrong input! Enter an integer.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

void nar(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = d(gen);
	}
}

void input_array(vector<int>& arr) {
	cout << "Enter numbers from -99 to 99:\n";
	for (int i = 0; i < arr.size(); i++) {
        arr[i] = getN("Enter nuber -99-99:", -99, 99);
	}
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;       
    for (int j = low; j <= high - 1; j++){ 
        if (arr[j] < pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick(arr, low, pi - 1);
        quick(arr, pi + 1, high);
    }
}

void print(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}

	}
}


void bubble(vector<int>& arr) {
    bool flag = false;
    int a = arr.size();
    for (int i = 0;i < a - 1;++i) {
        flag = false;
        for (int j = 0;j < a - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}

void shaker(vector <int>& arr) {
    int last;
    int a = arr.size();
    int r = a - 1;
    int l = 0;
    while (l < r) {
        last = l;
        for (int i = l;i < r;++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                last = i;
            }
        }
        r = last;
        last = r;
        for (int i = r;i > l; --i) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                last = i;
            }
        }
        l = last;
    }
}

void insert(vector<int>& arr) {
    int a = arr.size();
    for (int i = 1; i < a; i++) {
        int flag = arr[i];
        int j = i - 1;
        while (j >= 0 and arr[j] > flag) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = flag;
    }
}

void selection(vector<int>& arr) {
    int a = arr.size();
    for (int i = 0; i < a - 1; i++) {
        int minI = i;
        for (int j = i + 1; j < a; j++) {
            if (arr[j] < arr[minI]) {
                minI = j;
            }
        }
        if (minI != i) {
            swap(arr[i], arr[minI]);
        }
    }
}
void rsort(vector<int>& arr, vector<int>& orig) {
    int ss;
    cout<<"Which sort do you want to use? Choose the number\n"
        << "1 - Bubble\n"
        << "2 - Shaker\n"
        << "3 - Selection\n"
        << "4 - Insert\n"
        << "5 - Quick\n"
        << "0 - Exit in menu\n\n";
    ss=getN("What do you want to do: ",0,5);
    switch (ss) {
    case 1: {
        cout << "Bubble Sort.\n";
        arr = orig;
        auto t1 = steady_clock::now();
        bubble(arr);
        auto t2 = steady_clock::now();
        auto us = duration_cast<microseconds>(t2 - t1).count();
        cout << us << " microseconds\n\n";
        cout << "sort array:";
        print(arr);
        break;
    }
    case 2: {
        cout << "Shaker Sort.\n";
        arr = orig;
        auto t1 = steady_clock::now();
        shaker(arr);
        auto t2 = steady_clock::now();
        auto us = duration_cast<microseconds>(t2 - t1).count();
        cout <<  us << " microseconds\n\n";
        cout << "sort array:";
        print(arr);
        break;
    }
    case 3: {
        cout << "Selection Sort.\n";
        arr = orig;
        auto t1 = steady_clock::now();
        selection(arr);
        auto t2 = steady_clock::now();
        auto us = duration_cast<microseconds>(t2 - t1).count();
        cout << us << " microseconds\n\n";
        cout << "sort array:";
        print(arr);
        break;
    }
    case 4: {
        cout << "Insert Sort.\n";
        arr = orig;
        auto t1 = steady_clock::now();
        insert(arr);
        auto t2 = steady_clock::now();
        auto us = duration_cast<microseconds>(t2 - t1).count();
        cout << us << " microseconds\n\n";
        cout << "sort array:";
        print(arr);
        break;
    }
    case 5: {
        cout << "Quick Sort.\n";
        arr = orig;
        auto t1 = steady_clock::now();
        quick(arr,0,arr.size()-1);
        auto t2 = steady_clock::now();
        auto us = duration_cast<microseconds>(t2 - t1).count();
        cout << us << " microseconds\n\n";
        cout << "sort array:";
        print(arr);
        break;
    }
    case 0:
        break;
    default:
        cout << "Error, try again";
        return;
    }
}
void maxmin(vector<int>& arr, int& min,int& max, int&sr) {
    min = arr[0];
    max = arr[0];
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < min) 
            min = arr[i];
        if (arr[i] > max) 
            max = arr[i];
        
    }
    sr = round((min + max) / 2.0);

}
void find(vector<int>& arr, int sr) {
    int count = 0;
    cout << "Indexes of elements equal to average: ";
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == sr) {
            cout << i  << " ";
            count++;
        }
    }
    cout << "\nNumber of such elements: " << count << endl;
}
void num(const vector<int>arr) {
    int a;
    cout << "The number of elements is less  \n";
    cin >> a;
    int count = 0;
    for (int i = 0;i < arr.size();++i) {
        if (arr[i] < a)
            count++;
    };
    cout << "Number of elements less than " << a << ": " << count << endl;
}

void num1(const vector<int>& arr) {
    int b;
    cout << "The number of elements is more \n";
    cin >> b;
    int count = 0;
    for (int i = 0; i < arr.size();++i) {
        if (arr[i] > b)
            count++;
        }
    cout << "Number of elements more than " << b << ": " << count << endl;
}
int binSearch(const vector<int>& arr, int f_number, int start, int end) {
    if (start > end) {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == f_number) {
        return mid;
    }
    if (arr[mid] > f_number) {
        return binSearch(arr, f_number, start, mid - 1);
    }
    return binSearch(arr, f_number, mid + 1, end);
}

int uSearch(vector<int>& arr, int f_number){
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] == f_number){
            return i;
        }
    }
    return -1;
}

void change(vector<int>& arr) {
    int a, b;
    a = getN("Enter first index: ", 0, (int)arr.size() - 1);
    cout << "Enter secomd number(0-99)";
    b = getN("Enter second index: ", 0, (int)arr.size() - 1);
    if ((a >= 0 and a < arr.size()) and (b >= 0 and b < arr.size())) {
        swap(arr[a], arr[b]);;
        cout << "Change array: \n";
        print(arr);
    }
    else{
        cout << "Wrong try again!\n";
    }
}
void idz(vector <int>& arr) {
    int a = arr.size() / 2;
    for (int i = 0;i < a;i++) {
        swap(arr[i], arr[i + (arr.size() + 1) / 2]);
    }
    int pos = 0;
    int neg = 0;
    for (int i = 0; i < a; i++) {
        if (arr[i] > 0)
            pos++;
        if (arr[i + arr.size() - a] < 0)
            neg++;
    }
    cout << "Positive elements in the first half: " << pos << endl;
    cout << "Negative elements in the second half: " << neg << endl;
    print(arr);
}

void menu(vector <int>& arr, vector<int>& orig) {
    int chois;
    while (true) {
        cout << "1 - Generate  array\n"
            << "2 - Sort array\n"
            << "3 - Find minimum, maximum and average\n"
            << "4 - Count elements less than a\n"
            << "5 - Count elements more than b\n"
            << "6 - Search number (linear and binary)\n"
            << "7 - Swap two elements\n"
            << "8 - Swap first and second halves\n"
            << "0 - Exit\n";
        chois = getN("What do you want to do:", 0, 8);
        switch (chois) {
        case 1: {
            int a;
            a = getN("Do you want write array yourself 0-No, 1-Yes:", 0, 1);
            ;
            if (a == 1) {
                input_array(arr);
                orig = arr;
                cout << "Array entered!\n";
                print(arr);
                break;
            }
            else if (a == 0) {
                nar(arr);
                orig = arr;
                cout << "Random array generated!\n";
                print(arr);
                break;
            }
            else {
                cout << "Try again";
                break;
            }
        }
        case 2: {
            rsort(arr, orig);
            break;
        }

        case 3: {
            int min, max, sr;
            auto t1 = steady_clock::now();
            maxmin(arr, min, max, sr);
            auto t2 = steady_clock::now();
            auto time1 = duration_cast<nanoseconds>(t2 - t1).count();
            cout << "Unsorted array:\n";
            cout << "Minimum: " << min << endl;
            cout << "Maximum: " << max << endl;
            cout << time1 << " nanoseconds\n";
            vector<int> sorted = arr;
            quick(sorted, 0, (int)sorted.size() - 1);
            auto t3 = steady_clock::now();
            int min2 = sorted[0];
            int max2 = sorted[sorted.size() - 1];
            auto t4 = steady_clock::now();
            auto time2 = duration_cast<nanoseconds>(t4 - t3).count();

            cout << "Sorted array:\n";
            cout << "Minimum: " << min2 << endl;
            cout << "Maximum: " << max2 << endl;
            cout << "Search time: " << time2 << " nanoseconds\n";
            cout << "Average of min and max: " << sr << endl;
            find(arr, sr);
            break;
        }

        case 4: {
            vector<int> sorted = arr;
            quick(sorted, 0, (int)sorted.size() - 1);
            num(sorted);
            break;
        }
        case 5: {
            vector<int> sorted = arr;
            quick(sorted, 0, (int)sorted.size() - 1);
            num1(sorted);
            break;
        }
        case 6: {
            int number;
            cout << "Enter number to search: ";
            cin >> number;
            vector<int> sorted = arr;
            quick(sorted, 0, (int)sorted.size() - 1);
            int result1, result2;
            auto t1 = steady_clock::now();
            for (int i = 0; i < 100000; i++) {
                result1 = uSearch(sorted, number);
            }

            auto t2 = steady_clock::now();
            auto time1 = duration<double, nano>(t2 - t1).count() / 100000;
            auto t3 = steady_clock::now();
            for (int i = 0; i < 100000; i++) {
                result2 = binSearch(sorted, number, 0, (int)sorted.size() - 1);
            }
            auto t4 = steady_clock::now();
            auto time2 = duration<double, nano>(t4 - t3).count() / 100000;
            cout << "Linear search result: " << result1 << endl;
            cout << "Linear search time: " << time1 << " nanoseconds\n";
            cout << result2 << endl;
            cout << time2 << " nanoseconds\n";
            break;
        }

        case 7: {
            auto t1 = steady_clock::now();
            change(arr);
            auto t2 = steady_clock::now();
            auto us = duration_cast<microseconds>(t2 - t1).count();
            cout << us << " microseconds\n";
            break;
        }

        case 8: {
            idz(arr);
            orig = arr;
            break;
        }

        case 0: {
            cout << "Program finished!\n";
            return;
        }

        default: {
            cout << "Wrong choice! Try again.\n";
            break;
        }
        }
        }
    }

int main(){
    vector<int> arr(100);
    nar(arr);
    vector<int> orig = arr;
    menu(arr, orig);
    return 0;
}