#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

//forward delcaration
int brutal(int *arr, int size);
int FindCrossMax(int *arr, int start, int middle, int end);
int FindMaxArray(int *arr, int start, int end);

int main(int argc, char ** argv){
    //input file
    ifstream inputstream;
    inputstream.open(argv[1], ios::in);
    if(inputstream.fail()){
        cout << "Input file is filed." << endl;
    }

    int datanum = 0;
    string space;   //for getline space
    while(getline(inputstream, space)){
        datanum++;
    }
    inputstream.close();

    //inputfile again
    inputstream.open(argv[1], ios::in);
    if(inputstream.fail()){
        cout << "Input file is filed." << endl;
    }

    int *data = new int[datanum];
    int index;  // to store the index number
    while(inputstream >> index){
        cout << index << " ";
        inputstream >> data[0];
    }
    cout << endl;
    cout << data[0] << endl;
    
    inputstream.close();
    /*
    for(int i=0; i<datanum; i++){
        cout << data[i] <<" ";
    }
    cout << endl;
    */
    cout << datanum << endl;
    delete [] data;

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
    return max(max(leftMax, rightMax), leftMax+rightMax);   // find the Max from the three subsection 
}

int FindMaxArray(int *arr, int start, int end){
    if(start == end)            // base case: only one element
        return arr[start];
    
    int middle = (start+end)/2;
    int leftMax = FindMaxArray(arr, start, middle);      // find left Max
    int rightMax = FindMaxArray(arr, middle+1, end);     // find right Max
    int cross = FindCrossMax(arr, start, middle, end);   // find the Max from the three section 

    return max(max(leftMax, rightMax), cross);
}
