/*
Consider an Array a of size N
Iterate from 1 to N
In ith iteration select the ith minimum and swap it with A[i]

You are given an array a, size of the array N and an integer x. Follow the above algorithm 
and print the state of the array after x iterations have been performed.

Input Format
The first line contains two integer N and x denoting the size of the array and the steps of 
the above algorithm to be performed respectively. The next line contains N space separated 
integers denoting the elements of the array.

Output Format:
Print N space separated integers denoting the state of the array after x steps

Constraints :
1 <= N <= 100
1 <= A[i] <= 100
1 <= x <= N
*/

#include <bits/stdc++.h>
using namespace std;

void selection_Sort(int *arr , int size , int it) {
    int min , j = 0;
    for(int k = 0 ; k < it ; k++) {
        min = k;
        j = k+1;
        while(j < size) {
            if(arr[j] < arr[min]) {
                min = j;
            }
            j++;
        }
        swap(arr[min] , arr[k]);
    }
}

int main() {
    int n , x;
    cin >> n >> x;
    int a[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    selection_Sort(a , n , x);
    for(int i = 0 ; i < n ; i++) {
        cout << a[i] << " ";
    }
    return 0;
}