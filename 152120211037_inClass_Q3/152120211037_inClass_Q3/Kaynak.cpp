#include <iostream>
#include <ctime>

using namespace std;

void assignThreeArray(int*** arr, int dim1, int dim2, int dim3) {
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            for (int k = 0; k < dim3; k++) {
                arr[i][j][k] = rand() % 100;
            }
        }
    }
}

void displayThreeArray(int*** arr, int dim1, int dim2, int dim3) {
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            for (int k = 0; k < dim3; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));

    int m, n, p;
    cout << "Enter the first dimension (m): ";
    cin >> m;
    cout << "Enter the second dimension (n): ";
    cin >> n;
    cout << "Enter the third dimension (p): ";
    cin >> p;

    int*** array = new int** [m];
    for (int i = 0; i < m; i++) {
        array[i] = new int* [n];
        for (int j = 0; j < n; j++) {
            array[i][j] = new int[p];
        }
    }

    clock_t startTime = clock();
    assignThreeArray(array, m, n, p);
    displayThreeArray(array, m, n, p);
    clock_t endTime = clock();

    cout << endl;
    double elapsedTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    cout << "Elapsed time: " << elapsedTime << " seconds" << endl;


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
