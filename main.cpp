#include <iostream>

using namespace std;

void insertionsort(int *array, int l);
void insertionsort_noninc(int *array,int l);
void merge(int *array,int p, int q, int r);
int main(int argc, char *argv[]) {
    int array[6];
    cout<<"Enter 6 numbers:"<<endl;
    for (int i = 0; i < 6; ++i) {
        cin>>array[i];
    }
    cout<<endl;

    cout<<"Originally entered array is:"<<endl;
    for (int j = 0; j < 6; ++j) {
        cout<<array[j];
        cout<<endl;
    }
    int l = sizeof(array)/ sizeof(array[0]);

    cout<<"The length of the array is:"<<endl;
    cout<<l<<endl;
    insertionsort(array, l);
    insertionsort_noninc(array,l);
}

// Merge(A,p,q,r)
void merge(int *array, int p, int q, int r) {

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
