#include<vector>
#include<iostream>

using namespace std;


void Merge(vector<int>& values, vector<int> scratch, int l, int q, int r) {
    int left_index = l;
    int right_index = q + 1;
    int scratch_index = left_index;

    while (left_index <= q && right_index <= r) {
        if (values[left_index] >= values[right_index]) { //! Изменение оператора для изменения порядка
            scratch[scratch_index] = values[left_index];
            ++left_index;
        } else {
            scratch[scratch_index] = values[right_index];
            ++right_index;
        }
        ++scratch_index;
    }

    for (int i (left_index); i <= q; ++i) {
        scratch[scratch_index] = values[i];
        ++scratch_index;
    }

    for (int i(right_index); i <= r; ++i) {
        scratch[scratch_index] = values[i];
        ++scratch_index;
    }

    for (int i(l); i <= r; ++i) {
        values[i] = scratch[i];
    }
}

void MergeSorting(vector<int>& values, vector<int>& scratch, int l, int r) {
    if (l < r) {
        int q = (l+r)/2;
        MergeSorting(values, scratch, l, q);
        MergeSorting(values, scratch, q + 1, r);
        Merge(values, scratch, l, q, r);
    }
}

void MergeSort(vector<int>& values) {
    if (values.size() == 1) {
        return;
    }

    vector<int> scratch(values.size());
    MergeSorting(values, scratch, 0, values.size()-1);
}


int main () {
    vector<int> b = {6,8,3,8,9,12,14, 7};
    MergeSort(b);
    for (const auto& i : b) {
        cout << i << " ";
    }

    return 0;
}