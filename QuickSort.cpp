/*
Write a C++ program to store first year percentage of students in an array. Write
function for sorting array of floating point numbers in ascending order using quick sort
& display top five scores.
*/

#include <bits/stdc++.h>
using namespace std;

void swap(float *a , float *b) {
	float temp = *a;
	*a = *b;
	*b = temp;
}

int partition(float *ar , int l , int h) {
	int i = (l-1);
	float pivot = ar[h];
	for(int j = l ; j < h ; j++) {
		if(ar[j] <= pivot) {
			i++;
			if(i != j) {
				swap(&ar[i] , &ar[j]);
			}
		}
	}
	swap(&ar[i+1] , &ar[h]);
	return (i+1);
}

void quickSort(float *ar , int l , int h) {
	if(l < h) {
		int index = partition(ar , l , h);
		quickSort(ar , l , index-1);
		quickSort(ar , index+1 , h);
	}
}

int main() {
	int n;
	cout << "Enter no of students : ";
	cin >> n;
	float ar[n];
	cout << "Enter percentage of students : ";
	for(int i = 0 ; i < n ; i++) {
		cin >> ar[i];
	}
	quickSort(ar , 0 , n-1);
	cout << "Scores of top 5 students are : " << endl;
	for(int x = 0 ; x < 5 ; x++) {
		cout << ar[n-1-x] << endl;
	}
	return 0;
}

