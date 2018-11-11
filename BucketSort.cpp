/*
You have been given an array A of size N. The array contains integers. You need to divide
the elements of this array into buckets on the basis of the number of set bits in its binary 
representation. You need to then print the content of each bucket in a new line. The buckets 
should appear in the output in ascending order, i.e the bucket that stands for lesser number 
of set bits should appear before any other bucket which stands for higher number of set bits.
The elements of each bucket should appear in ascending order too. That is if 2 integers 
appear in the same bucket, the one with the lower value should appear in the bucket list 
before the one with higher value.

Input Format:
The first line contains a single integer N denoting the size of the array. The next line 
contains N space separated integers denoting the elements of the array.

Output Format:
The output should contain the number of lines equal to the number of distnict bucket. If a 
bucket remains empty, it should not appear in the output. Print the contents of each bucket 
on a new line.

Constraints:
1 <= N <= 1000
1 <= A[i] <= 1000

Note: 
It is guaranteed that each array element is unique.
*/

#include <bits/stdc++.h>
using namespace std;

void bucket_Sort(int *arr , int size) {
    vector <int> b[size];
    for(int i = 0 ; i < size ; i++) {
        int count = 0 , x = arr[i] , t;
        while(x > 0) {
            t = x % 2;
            x = x / 2;
            if(t == 1) {
                count++;
            }
        }
        b[count].push_back(arr[i]);
    }
    for(int i = 0 ; i < size ; i++) {
        sort(b[i].begin() , b[i].end());
        if(b[i].size() != 0) {
            for(int k = 0 ; k < b[i].size() ; k++) {
                cout << b[i][k] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    bucket_Sort(a , n);
    return 0;
}