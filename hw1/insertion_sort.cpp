#include <iostream>

using namespace std;

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