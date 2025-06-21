#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> count(maxVal + 1, 0);
    
    // Step 1: Count occurrences
    for (int num : arr) {
        count[num]++;
    }

    // Step 2: Cumulative count
    for (int i = 1; i <= maxVal; ++i) {
        count[i] += count[i - 1];
    }

    // Step 3: Build output array
    vector<int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 4: Copy to original array
    arr = output;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countSort(arr);

    for (int num : arr)
        cout << num << " ";
    return 0;
}
