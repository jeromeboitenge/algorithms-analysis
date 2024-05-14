#include <iostream>
#include <vector>

template <typename T>
void displayVector(const std::vector<T>& v, const std::string& label)
{
    std::cout << label << ": ";
    for (const auto& element : v) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void bubbleSort(std::vector<T>& v)
{
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < v.size() - 1; ++i) {
            if (v[i] > v[i + 1]) {
                std::swap(v[i], v[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

template <typename T>
void insertionSort(std::vector<T>& v)
{
    for (size_t i = 1; i < v.size(); ++i) {
        T key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

template <typename T>
void selectionSort(std::vector<T>& v)
{
    for (size_t i = 0; i < v.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(v[i], v[minIndex]);
        }
    }
}

template <typename T>
int partition(std::vector<T>& v, int low, int high) {
    T pivot = v[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; ++j) {
        if (v[j] < pivot) {
            ++i;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i + 1], v[high]);
    return (i + 1);
}

template <typename T>
void quickSortHelper(std::vector<T>& v, int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);
        quickSortHelper(v, low, pi - 1);
        quickSortHelper(v, pi + 1, high);
    }
}

template <typename T>
void quickSort(std::vector<T>& v)
{
    quickSortHelper(v, 0, v.size() - 1);
}

template <typename T>
void merge(std::vector<T>& v, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    std::vector<T> L(n1), R(n2);
    
    for (int i = 0; i < n1; ++i)
        L[i] = v[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = v[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            ++i;
        } else {
            v[k] = R[j];
            ++j;
        }
        ++k;
    }
    
    while (i < n1) {
        v[k] = L[i];
        ++i;
        ++k;
    }
    
    while (j < n2) {
        v[k] = R[j];
        ++j;
        ++k;
    }
}

template <typename T>
void mergeSortHelper(std::vector<T>& v, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortHelper(v, l, m);
    mergeSortHelper(v, m + 1, r);
    merge(v, l, m, r);
}

template <typename T>
void mergeSort(std::vector<T>& v)
{
    mergeSortHelper(v, 0, v.size() - 1);
}

template<typename T>
bool isSorted(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size() - 1; ++i)
        if (v.at(i) > v.at(i + 1)) return false;
    return true;
}

int main()
{
    std::vector<int> v1{ 23,45,12,7,6,9,3 };
    std::vector<int> v3{ 4,3,2,1,7,8,9,6 };
    std::vector<int> v4{ 3,6,1,7,9,8,2,4,5 };
    std::vector<int> v5{ 22,44,33,11,66,55,88,77 };
    std::vector<int> v2{ 9,2,3,1,7,8,6,4,5 };

    int sortedCount = 0;

    displayVector(v1, "Unsorted v1");
    bubbleSort(v1);
    displayVector(v1, "Sorted v1 (Bubble Sort)");
    if (isSorted(v1)) ++sortedCount;

    displayVector(v2, "Unsorted v2");
    insertionSort(v2);
    displayVector(v2, "Sorted v2 (Insertion Sort)");
    if (isSorted(v2)) ++sortedCount;

    displayVector(v3, "Unsorted v3");
    selectionSort(v3);
    displayVector(v3, "Sorted v3 (Selection Sort)");
    if (isSorted(v3)) ++sortedCount;

    displayVector(v4, "Unsorted v4");
    quickSort(v4);
    displayVector(v4, "Sorted v4 (Quick Sort)");
    if (isSorted(v4)) ++sortedCount;

    displayVector(v5, "Unsorted v5");
    mergeSort(v5);
    displayVector(v5, "Sorted v5 (Merge Sort)");
    if (isSorted(v5)) ++sortedCount;

    std::cout << "sorted: " << sortedCount << std::endl;

    return 0;
}
