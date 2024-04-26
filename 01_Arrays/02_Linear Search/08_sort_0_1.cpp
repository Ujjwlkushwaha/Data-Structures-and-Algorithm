#include <iostream>
#include <vector>
using namespace std;

void sortArray(vector<int>& arr){

    int s = 0 ; 
    int e = arr.size()-1;

    while(s<=e)
    {
        if(arr[s] == 0 && arr[e] == 1){
            s++;
            e--;
        }

        if(arr[s] == 1 && arr[e] == 0){
            swap(arr[s], arr[e]);
            s++;
            e--;
        }

        if(arr[s] == 0 && arr[e] ==0){
            s++;
        }
        if(arr[s] == 1 && arr[e] ==1){
            e--;
        }
    }
    
    

    for (int i = 0; i < arr.size(); i++){
        cout<< arr[i]<<" ";
    }
}
int main(){

    vector<int>arr = {0,1,1,1,0,0,1,0,1,0,1,1,1};
    sortArray(arr);

}