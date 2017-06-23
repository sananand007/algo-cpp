/*
 * Insertion Sort
 * Merge Sort - You have an array, you Merge a chunk of it from position p to position r
*/

#include <iostream>
#include "math.h"
#include "limits.h"

using namespace std;

void insertionsort(int *array, int l);
void insertionsort_noninc(int *array,int l);
void merge(int array[],int p, int q, int r);
void mergesort(int array[], int p1, int r1);
void print_array(int arr[],int l);

int main(int argc, char *argv[]) {
    int array[8];
    cout<<"Enter 8 numbers:"<<endl;
    for (int i = 0; i < 8; ++i) {
        cin>>array[i];
    }
    cout<<endl;

    cout<<"Originally entered array is:"<<endl;
    for (int j = 0; j < 8; ++j) {
        cout<<array[j];
        cout<<endl;
    }
    int l = sizeof(array)/sizeof(array[0]);

    cout<<"The length of the array is:"<<endl;
    cout<<l<<endl;


    cout<<"Insertion Sort : "<<endl;
    insertionsort(array, l);

    cout<<"Insertion Sort Increasing : "<<endl;
    insertionsort_noninc(array,l);


    cout<<"Merge Sort : "<<endl;
    mergesort(array, 0, l-1);
    for (int k = 0; k < l; ++k) {
        cout<<array[k]<<endl;
    }
}

void print_array(int arr[],int l) {
    //cout<<"Size of the array"<<"="<<l<<endl;
    for (int i = 0; i <l ; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// Merge(A,p,q,r)
void merge(int array[], int p2, int q2, int r2) {

    int n1 = q2-p2+1;
    int n2 = r2-q2;

    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = array[p2+i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = array[q2+j+1];
    }

    //L[n1+1] = INT_MAX;
    //R[n1+1] = INT_MAX;


    int l=0;
    int m=0;
    int count_arr=p2;

    //print_array(L, sizeof(L)/ sizeof(L[0]));
    //print_array(R, sizeof(R)/ sizeof(R[0]));

    for (int k = p2; k <= r2; ++k) {
        //cout<<"value of k , n1,  n2, "<<k<<", "<<n1<<", "<<n2<<endl;
        //cout<<"value of l , m, "<<l<<", "<<m<<endl;
        if (l<(sizeof(L)/ sizeof(L[0])) and m<(sizeof(R)/ sizeof(R[0]))) {
            if (L[l]<R[m]) {
                //cout<<"chk-2, "<<L[l]<<endl;
                array[k] = L[l];
                ++l;

            }
            else {
                //cout<<"chk-3, "<<R[m]<<endl;
                array[k] = R[m];
                ++m;
            }
            count_arr++;
        }
    }

    // Copy the remaining elements if there are any left for both L and R
    if (l<(sizeof(L)/ sizeof(L[0]))){
        //cout<<"chk-4, array : "<<L[l]<<", "<<array[count_arr]<<", "<<count_arr<<endl;
        array[count_arr] = L[l];
    }
    if (m<(sizeof(R)/ sizeof(R[0]))){
        //cout<<"chk-5, array : "<<R[m]<<", "<<array[count_arr]<<", "<<count_arr<<endl;
        array[count_arr] = R[m];
    }

    //cout<<"array at the end"<<endl;
    int l2 = sizeof(array)/sizeof(array[0]);
    //print_array(array,l2);
}

// mergesort(A,p,r)
// p >= r , there is no merge sort possible
void mergesort(int array[], int p1, int r1) {
    if (p1<r1) {
        int q1 = static_cast<int>(floor((p1+r1)/2));
        cout<<"Values:"<<" p1="<<p1<<", q1="<<q1<<", r1="<<r1<<endl;
        mergesort(array, p1, q1);
        mergesort(array, q1+1, r1);

        merge(array,p1,q1,r1);
    }
}

void insertionsort(int *array, int l) {

    for (int k = 1; k < l; ++k) {
        int key = array[k];
        int m = k-1;
        while (m>=0 && array[m]>key) {
            array[m+1]=array[m];
            m--;
        }
        array[m+1]=key;
    }
    cout<<"Print the new array after the insertion sort"<<endl;
    for (int n = 0; n < l; ++n) {
        cout<<array[n]<<endl;
    }
}

void insertionsort_noninc(int *array, int l){

    for (int i = 1; i < l; ++i) {
        int keyval = array[i];
        int j = i-1;
        while(j>=0 && array[j]<keyval){
            array[j+1] = array[j];
            j--;
        }
        array[j+1]=keyval;
    }
    cout<<"Array in non Icreasing sort"<<endl;
    for (int k = 0; k < l; ++k) {
        cout<<array[k]<<endl;
    }
}
