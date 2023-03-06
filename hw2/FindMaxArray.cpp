#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//forward delcaration
float brutal(float *arr, int size);
float FindCrossMax(float *arr, int start, int middle, int end);
float FindMaxArray(float *arr, int start, int end);

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

    float *data = new float[datanum];
    int index;  // to store the index number
    while(inputstream >> index){
        cout << index << " ";
        inputstream >> data[index-1];
    }
    cout << endl;
    
    inputstream.close();
    /*
    for(int i=0; i<datanum; i++){
        cout << data[i] <<" ";
    }
    cout << endl;
    */
    cout << datanum << endl;
    float MaxSum = 0.0;
    //float TestSum = 0.0;
    MaxSum = FindMaxArray(data, 0, datanum);
    //TestSum = brutal(data, datanum);
    cout << MaxSum << endl;
    //cout << TestSum << endl;

    delete [] data;

    cout << "this is the last line!" << endl;

    return 0;
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

float FindCrossMax(float *arr, int start, int middle, int end){
    float leftMax = arr[middle];
    float rightMax = arr[middle + 1];
    float leftSum = 0.0;
    float rightSum = 0.0;

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

float FindMaxArray(float *arr, int start, int end){
    //vector <float> returnvalue;
    if(start == end)            // base case: only one element
        //returnvalue.push_back(start);
        //returnvalue.push_back(end);
        //returnvalue.push_back(arr[start]);
        return arr[start];
    
    int middle = (start+end)/2;
    float leftMax = FindMaxArray(arr, start, middle);      // find left Max
    float rightMax = FindMaxArray(arr, middle+1, end);     // find right Max
    float cross = FindCrossMax(arr, start, middle, end);   // find the Max from the three section 

    return max(max(leftMax, rightMax), cross);
}
