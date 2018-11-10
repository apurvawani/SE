/*
Write a C++ program to store roll numbers of students in array who attended training 
program in sorted order. Write function for searching whether a particular student 
attended training program or not using binary search & fibonacci search.  
*/
#include <bits/stdc++.h>
using namespace std;

//Binary Search using Recursive Approach
bool binary_Search(int *arr , int start , int end , int roll_no) {
    if(start <= end) {
        int mid = (start + end)/2;
        if(arr[mid] == roll_no) {
            return true;
        }
        else if(arr[mid] < roll_no) {
            return binary_Search(arr , mid+1 , end , roll_no);
        }
        else {
            return binary_Search(arr , start , mid-1 , roll_no);
        }
    }
    else {
        return false;
    }
}

bool fibonacci_Search(int *arr , int size , int roll_no) {
    bool r = false;
    int a = 0 , b = 1 , c = a+b;
    while(c < size) {
        a = b;
        b = c;
        c = a+b;
    }
    int offset = -1;
    while(c > 1) {
        int i = min(offset+a , size-1);
        if(arr[i] == roll_no) {
            r = true;
            break;
        }
        else if(arr[i] > roll_no) {
            c = a;
            b = b-c;
            a = c-b;
        }
        else {
            c = b;
            b = a;
            a = c-b;
            offset = i;
        }
        if(arr[offset+1] == roll_no) {
            return true;
        }
    }
    return r;
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
        cout << endl;
        cout << "1. Binary Search" << endl;
        cout << "2. Fibonacci Search" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice : ";
        cin >> ch;
        cout << "Enter roll no to be searched : ";
        cin >> rno;
        switch(ch) {
            case 1:
            {
                if(binary_Search(ar , 0 , n-1 , rno)) {
                    cout << "Roll No " << rno << " found!" << endl;
                }
                else {
                    cout << "Roll No " << rno << " not found!" << endl;
                }
                break;
            }
            case 2:
            {
                if(fibonacci_Search(ar , n , rno)) {
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
