#include <iostream>

using namespace std;

//forward delcaration
int brutal(int *arr, int size);
int FindCrossMax(int *arr, int start, int middle, int end);
int FindMaxArray(int *arr, int start, int end);

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

int FindCrossMax(int *arr, int start, int middle, int end){
    int leftMax = arr[middle];
    int rightMax = arr[middle + 1];
    int leftSum = 0;
    int rightSum = 0;

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

int FindMaxArray(int *arr, int start, int end){
    if(start == end)
        return arr[start];
    
    int middle = (start+end)/2;
    int leftMax = FindMaxArray(arr, start, middle);
    int rightMax = FindMaxArray(arr, middle+1, end);
    int cross = FindCrossMax(arr, start, middle, end);

    return max(max(leftMax, rightMax), cross);
}
