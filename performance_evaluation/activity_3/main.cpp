#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>


using namespace std;

vector<int> readFile()
{
    ifstream file("performance_evaluation/activity_3/arq.txt");
    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
        exit(1);
    }
    vector<int> numbers;
    int x;

    while (file >> x)
        numbers.push_back(x);

    return numbers;
}

void writeFile(const vector<int>& v)
{
    ofstream file("performance_evaluation/activity_3/arq-ordenado.txt");
    for (int num : v)
        file << num << " ";
}

void pipeline(const string& name, void (*sortFunc)(vector<int>&), const vector<int>& original)
{
    cout << "Algorithm: " << name << endl;

    vector<double> durations;
    for (int i = 1; i <= 5; ++i)
    {
        vector<int> copy = original;
        auto start = chrono::high_resolution_clock::now();
        sortFunc(copy);
        auto end = chrono::high_resolution_clock::now();

        double duration = chrono::duration<double>(end - start).count();
        durations.push_back(duration);

        cout << "Execution " << i << ": " << duration << "s" << endl;
    }

    double average = 0.0;
    for (auto duration : durations)
        average += duration;
    average /= static_cast<double>(durations.size());

    cout << "Average: " << average << "s" << endl;
    cout << endl;
}

void bubbleSort(vector<int>& v);
void insertionSort(vector<int>& v);
void selectionSort(vector<int>& v);
void mergeSort(vector<int>& v);
void quickSort(vector<int>& v);
void heapSort(vector<int>& v);
void stlSort(vector<int>& v);

int main() {
    vector<int> original = readFile();

    pipeline("Bubble Sort", bubbleSort, original);
    pipeline("insertion Sort", insertionSort, original);
    pipeline("Selection Sort", selectionSort, original);
    pipeline("Merge Sort", mergeSort, original);
    pipeline("Quick Sort", quickSort, original);
    pipeline("Heap Sort", heapSort, original);
    pipeline("STL (std::sort)", stlSort, original);

    sort(original.begin(), original.end());

    writeFile(original);
    return 0;
}

void bubbleSort(vector<int>& v)
{
    auto n = v.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}

void insertionSort(vector<int>& v)
{
    auto n = v.size();
    for (int i = 1; i < n; ++i)
    {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = key;
    }
}

void selectionSort(vector<int>& v)
{
    auto n = v.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n - i; ++j)
        {
            if (v[j] < v[minIndex])
                minIndex = j;
        }

        swap(v[i], v[minIndex]);
    }
}

void merge(vector<int>& v, int left, int mid, int right)
{
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (v[i] <= v[j])
            temp.push_back(v[i++]);
        else
            temp.push_back(v[j++]);
    }

    while (i <= mid) temp.push_back(v[i++]);
    while (j <= right) temp.push_back(v[j++]);

    for (int k = 0; k < temp.size(); ++k)
        v[left + k] = temp[k];

}
void mergeSortHandler(vector<int>& v, int left, int right)
{
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSortHandler(v, left, mid);
    mergeSortHandler(v, mid + 1, right);

    merge(v, left, mid, right);
}
void mergeSort(vector<int>& v)
{
    int n = static_cast<int>(v.size());
    mergeSortHandler(v, 0, n);
}

int partition(vector<int>& v, int low, int high)
{
    int pivot = v[high];
    int i = low - 1;
    for (int j = low; j < high; ++j)
    {
        if (v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i + 1], v[high]);
    return i + 1;
}
void quickSortHandler(vector<int>& v, int low, int high)
{
    if (low < high)
    {
        int pi = partition(v, low, high);

        quickSortHandler(v, low, pi - 1);
        quickSortHandler(v, pi + 1, high);
    }
}
void quickSort(vector<int>& v)
{
    int n = static_cast<int>(v.size());
    quickSortHandler(v, 0, n);
}

void heapify(vector<int>& v, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && v[left] > v[largest])
        largest = left;

    if (right < n && v[right] > v[largest])
        largest = right;

    if (largest != i)
    {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}
void heapSort(vector<int>& v)
{
    int n = static_cast<int>(v.size());

    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(v, n, i);

    for (int i = n - 1; i > 0; --i)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

void stlSort(vector<int>& v)
{
    sort(v.begin(), v.end());
}
