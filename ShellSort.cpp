/*
Write a C++ program to store second year percentage of students in array. Write function
for sorting array of floating point numbers in ascending order using : 1. Insertion Sort
2. Shell Sort & display top 5 scores.
*/

#include <bits/stdc++.h>
using namespace std;
void insertionSort(float *ar , int n) {
    int j = 0;
    float temp;
    for(int i = 1 ; i < n ; i++) {
        j = i-1;
        temp = ar[i];
        while(j >= 0 && ar[j] > temp) {
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = temp;
    }
}

void shellSort(float *ar , int n) {
	for(int gap = n/2 ; gap > 0 ; gap = gap/2) {
		for(int i = gap ; i < n ; i++) {
			float temp = ar[i];
			int j = i;
			while(j >= gap && ar[j-gap] > temp) {
				ar[j] = ar[j-gap];
				j = j - gap;
			}
			ar[j] = temp;
		}
	}
}

int main() {
    int n , ch;
    cout << "Enter no of students : ";
    cin >> n;
    float ar[n];
    cout << "Enter percentage of students : " << endl;
    for(int i = 0 ; i < n ; i++) {
        cin >> ar[i];
    }
    cout << "Enter choice : " << endl;
    cout << "1. Insertion Sort" << endl << "2. Shell Sort" << endl;
    cin >> ch;
    cout << "Sorted List : " << endl;
    switch(ch) {
        case 1:
            insertionSort(ar , n);
            for(int i = 1 ; i <= 5 ; i++) {
                cout << ar[n-i] << endl;
            }
            break;
        case 2 :
            shellSort(ar , n);
            for(int i = 1 ; i <= 5 ; i++) {
                cout << ar[n-i] << endl;
            }
            break;
        default :
            cout << "Incorrect choice!" << endl;
    }
    return 0;
}

