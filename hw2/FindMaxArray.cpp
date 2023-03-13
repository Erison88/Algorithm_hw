#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// forward delcaration
// 記錄最大總和subarray的起始位置和終止位置的struct
struct MaxSubarray {
    int start;
    int end;
    //float sum;
    int size;
    vector <float> sum;
};
//float brutal(float *arr, int size);
MaxSubarray FindCrossMax(float *arr, int start, int middle, int end);
MaxSubarray FindMaxArray(float *arr, int start, int end);


int main(int argc, char ** argv){
    // input file
    ifstream inputstream;
    inputstream.open(argv[1], ios::in);
    if(inputstream.fail()){
        cout << "Input file is failed." << endl;
    }

    int datanum = 0;    // to count the number of the data
    string space;   // for getline space
    while(getline(inputstream, space)){
        datanum++;
    }
    inputstream.close();

    // input file again
    inputstream.open(argv[1], ios::in);
    if(inputstream.fail()){
        cout << "Input file is failed." << endl;
    }

    float *data = new float[datanum];   // to delcare the dynamic array
    int index;  // to store the index number
    while(inputstream >> index){
        inputstream >> data[index-1];
    }
    
    inputstream.close();
    /*
    for(int i=0; i<datanum; i++){
        cout << data[i] <<" ";
    }
    cout << endl;
    */
    cout << datanum << endl;
    
    MaxSubarray max_subarray = FindMaxArray(data, 0, datanum-1);
    cout << "start:" << max_subarray.start+1 << endl;
    cout << "end:" << max_subarray.end+1 << endl;
    for(int i=0; i<max_subarray.sum.size(); i++){
        cout << "sum" << i << ":" << max_subarray.sum[i] << endl;
    }
    cout << "size:" << max_subarray.size << endl;

    delete [] data;         // to delete the dynamic array

    cout << "this is the last line!" << endl;

    return 0;
}

MaxSubarray FindCrossMax(float *arr, int start, int middle, int end){
    MaxSubarray max_subarray;
    float left_sum = arr[middle];
    float left_max = left_sum;
    float right_sum = arr[middle+1];
    float right_max = right_sum;
    max_subarray.start = middle;
    max_subarray.end = middle+1;

    // find max subarray in left side
    for(int i = middle-1; i>=start; i--){
        left_sum += arr[i];
        if(left_sum>left_max){
            left_max = left_sum;
            max_subarray.start = i;
        }
    }
    // find max subarray in right side
    for(int i=middle+2; i<=end; i++){
        right_sum += arr[i];
        if(right_sum>right_max){
            right_max = right_sum;
            max_subarray.end = i;
        }
    }
    // find the Max from the three subsection and return
    float cross_sum = left_max + right_max;

    if(left_max>=right_max && left_max>=cross_sum){
        max_subarray.sum.push_back(left_max);
        max_subarray.size = (max_subarray.end-max_subarray.start)+1;
        return max_subarray;
    }
    else if(right_max>=left_max && right_max>=cross_sum){
        max_subarray.sum.push_back(right_max);
        max_subarray.size = (max_subarray.end-max_subarray.start)+1;
        return max_subarray;
    }
    else{
        max_subarray.sum.push_back(cross_sum);
        max_subarray.size = (max_subarray.end-max_subarray.start)+1;
        return max_subarray;
    }
}

MaxSubarray FindMaxArray(float *arr, int start, int end){
    MaxSubarray max_subarray;
    if(start == end){               // base case: only one element, termination condition
        max_subarray.start = start;
        max_subarray.end = end;
        max_subarray.sum.push_back(arr[start]);
        max_subarray.size = 1;
        return max_subarray;
    }            
        
    int middle = (start+end)/2;
    MaxSubarray left_max_subarray = FindMaxArray(arr, start, middle);      // find left Max
    MaxSubarray right_max_subarray = FindMaxArray(arr, middle+1, end);     // find right Max
    MaxSubarray cross_max_subarray = FindCrossMax(arr, start, middle, end);   // find the Max from the three section 

    // To compare three section, and return the max subarray
    if(left_max_subarray.sum>=right_max_subarray.sum && left_max_subarray.sum>=cross_max_subarray.sum){
        max_subarray.size = left_max_subarray.size;
        return left_max_subarray;
    }
    else if(right_max_subarray.sum>=left_max_subarray.sum && right_max_subarray.sum>=cross_max_subarray.sum){
        max_subarray.size = right_max_subarray.size;
        return right_max_subarray;
    }
    else{
        max_subarray.size = cross_max_subarray.size;
        return cross_max_subarray;
    }
}

float brutal(float *arr, int size){
    float sum; 
    float max = -size-1;
    for(int i=0; i<size; i++){
        sum = 0.0;
        for(int j=i; j<size; j++){
            sum += arr[j];
            if(sum > max){
                max = sum;
            }
        }
    }
    return max;
}
