#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateArray(double* arr, int n, double min, double max, int index = 0) {
    if (index < n) {
        arr[index] = min + (rand() % (int)(max - min + 1)) + (rand() % 100) / 100.0;
        generateArray(arr, n, min, max, index + 1);
    }
}

void printArray(double* arr, int n, int index = 0) {
    if (index < n) {
        cout << setw(8) << arr[index];
        printArray(arr, n, index + 1);
    }
    else {
        cout << endl;
    }
}

double sumNegativeElements(double* arr, int n, int index = 0) {
    if (index >= n) return 0;
    return (arr[index] < 0 ? arr[index] : 0) + sumNegativeElements(arr, n, index + 1);
}

double productBetweenMinMax(double* arr, int n, int minIndex = -1, int maxIndex = -1, int index = 0) {
    if (index >= n) return 1;

    if (minIndex == -1 || arr[index] < arr[minIndex]) minIndex = index;
    if (maxIndex == -1 || arr[index] > arr[maxIndex]) maxIndex = index;

    if (minIndex < maxIndex) return arr[index] * productBetweenMinMax(arr, n, minIndex, maxIndex, index + 1);
    return productBetweenMinMax(arr, n, minIndex, maxIndex, index + 1);
}

void sortEvenNumbers(double* arr, int n, int index = 0) {
    if (index >= n - 1) return;
    for (int j = index + 1; j < n; ++j) {
        if ((int)arr[index] % 2 == 0 && (int)arr[j] % 2 == 0 && arr[index] > arr[j]) {
            swap(arr[index], arr[j]);
        }
    }
    sortEvenNumbers(arr, n, index + 1);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    double* arr = new double[n];
    generateArray(arr, n, -20.0, 50.0);

    cout << "\nOriginal array:\n";
    printArray(arr, n);

    double sum = sumNegativeElements(arr, n);
    cout << "\nSum of negative elements: " << sum << endl;

    double product = productBetweenMinMax(arr, n);
    cout << "\nProduct of elements between max and min: " << product << endl;

    sortEvenNumbers(arr, n);
    cout << "\nSorted array with even numbers in ascending order:\n";
    printArray(arr, n);

    delete[] arr;
    return 0;
}
