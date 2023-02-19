#include <iostream>

using namespace std;

//function declaration
void Merge(int *arr, int head, int mid, int tail);
void MergeSort(int *arr, int head, int tail);

int main(){
    int a[] = {10,3,2,6,1,8,7};
    int key = 0;
    for(int j=0; j<7; j++){
        key = a[j];
        //insert a[j] into the sorted a[1,2,...]
        int i = j-1;
        while(i>=0 && a[i]>key){
            a[i+1] = a[i];
            i = i-1;
        }
        a[i+1] = key;
    }

    //print a[]
    for(int i=0; i<7; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "this is the last line!" << endl;

    return 0;
}

// below is Merge sort
void Merge(int *arr, int head, int mid, int tail){
    int llen = mid-head+1, rlen = tail-mid;
    int *leftarr = new int [llen];
    int *rightarr = new int [rlen];
    int leftind = 0, rightind = 0;
    int h = head;

    // initialize the array
    for(int i=0; i<llen; i++){
        leftarr[i] = arr[head+i];
    }
    for(int i=0; i<rlen; i++){
        rightarr[i] = arr[mid+i+1];
    }

    while(leftind<llen && rightind<rlen){
        if(leftarr[leftind] < rightarr[rightind]){
            arr[h] = leftarr[leftind];
            leftind++;
        }
        else{
            arr[h] = rightarr[rightind];
            rightind++;
        }
        h++;
    }
    while(leftind<llen){
        arr[h] = leftarr[leftind];
        leftind++;
        h++;
    }
    while(rightind<rlen){
        arr[h] = rightarr[rightind];
        rightind++;
        h++;
    }
}

void MergeSort(int *arr, int head, int tail){
    if(head<tail){
        int mid = (head+tail)/2;
        MergeSort(arr, head, mid);
        MergeSort(arr, mid+1, tail);
        Merge(arr, head, mid, tail);
    }
}