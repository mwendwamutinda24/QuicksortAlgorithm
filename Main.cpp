#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort(vector<int> &arr, int low, int high) {
    stack<pair<int,int>> st;
    st.push({low, high});

    while (!st.empty()) {
        auto [l, h] = st.top();
        st.pop();

        if (l < h) {
            int pi = partition(arr, l, h);

            // Push subarrays to stack
            if (pi - 1 > l) st.push({l, pi - 1});
            if (pi + 1 < h) st.push({pi + 1, h});
        }
    }
}

int main() {
    int n = 10000000; // 10 million
    vector<int> arr(n);

    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand(); // fill with random values
    }

    cout << "Sorting " << n << " values..." << endl;
    quickSort(arr, 0, n - 1);
    cout << "Sorting complete!" << endl;

   
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
