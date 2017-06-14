#include <iostream>
#include <cstdlib>

using namespace std;

void insertionsort(int *array, int l);
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
    int l = sizeof(array)/ sizeof(array[0]);

    cout<<"The length of the array is:"<<endl;
    cout<<l<<endl;

    insertionsort(array, l);

    //now we do Insertion sorting

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

