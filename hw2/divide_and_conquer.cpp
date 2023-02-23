#include <iostream>

using namespace std;

//forward delcaration
int brutal(int *arr, int size);
int GetCrossMax(int *arr, int size, int start, int middle, int end);
int divide_and_conquer(int *arr, int size, int start, int end);

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

    for(int i = middle; i>=start; i--){
        leftSum += arr[i];
        leftMax = max(leftMax, leftSum);
    }
    for(int i=middle+1; i<=end; i++){
        rightSum += arr[i];
        rightMax = max(rightMax, rightSum);
    }
    return max(max(leftMax, rightMax), leftMax+rightMax);
}

int divide_and_conquer(int *arr, int size, int start, int end){
    if(start == end)
        return arr[start];
    
    int middle = (start+end)/2;
    int leftMax = divide_and_conquer(arr, size, start, middle);
    int rightMax = divide_and_conquer(arr,size, middle+1, end);
    int cross = GetCrossMax(arr, size, start, middle, end);

    return max(max(leftMax, rightMax), cross);
}
