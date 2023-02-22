#include <iostream>

using namespace std;

//forward delcaration
int brutal(int *arr, int size);
int GetCrossMax(int *arr, int size, int start, int middle, int end);

int main(){
    cout << "this is the last line!" << endl;

    return 0;
}

int brutal(int *arr, int size){
    int sum; 
    int max = -size-1;
    for(int i=0; i<size; i++){
        sum = 0;
        for(int j=i; i<size; i++){
            sum += arr[j];
            if(sum > max){
                max = sum;
            }
        }
    }
    return max;
}

int GetCrossMax(int *arr, int size, int start, int middle, int end){
    int leftMax = arr[middle], leftSum = 0;
    int rightMax = arr[middle + 1], rightSum =0;

    for(int i = middle+1; i>=start; i--){
        //test
    }
}
