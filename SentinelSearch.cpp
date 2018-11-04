/*
Write a C++ program to store roll numbers of students in array who attended training 
program in random order. Write function for searching whether a particular student 
attended training program or not using linear search & sentinel search.  
*/
#include <bits/stdc++.h>
using namespace std;
bool linear_Search(int *ar , int size , int rno) {
    bool f = false;
    for(int i = 0 ; i < size ; i++) {
        if(ar[i] == rno) {
            f = true;
            break;
        }
    }
    if(f) {
        return true;
    }
    else {
        return false;
    }
}
bool sentinel_Search(int *ar , int size , int rno) {
    int temp = ar[size-1];
    ar[size-1] = rno;
    int i = 0;
    while(rno != ar[i]) {
        i++;
    }
    if(i < size-1 || (rno == temp)) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    int n , rno;
    cout << "Enter no of students : ";
    cin >> n;
    int ar[n];
    cout << "Enter roll no of students who attended training program : ";
    for (int i = 0 ; i < n ; i++) {
        cin >> ar[i];
    }
    int ch = 0;
    while(ch != 3) {
        cout << "1. Linear Search" << endl;
        cout << "2. Sentinel Search" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice : ";
        cin >> ch;
        cout << "Enter roll no to be searched : ";
        cin >> rno;
        switch(ch) {
            case 1:
            {
                if(linear_Search(ar , n , rno)) {
                    cout << "Roll No " << rno << " found!" << endl;
                }
                else {
                    cout << "Roll No " << rno << " not found!" << endl;
                }
                break;
            }
            case 2:
            {
                if(sentinel_Search(ar , n , rno)) {
                    cout << "Roll No " << rno << " found!" << endl;
                }
                else {
                    cout << "Roll No " << rno << " not found!" << endl;
                }
                break;
            }
        }
    }
    return 0;
}