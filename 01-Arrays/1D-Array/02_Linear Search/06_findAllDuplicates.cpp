#include<iostream>
#include <vector>
using namespace std;

void findAllDuplicates(int * arr , int s)
{   
    vector<int> dupl;

    for(int i=0; i<s; i++){
        for(int j=i+1; j<s; j++)
        {
            if(arr[i] == arr[j]){
                dupl.push_back(arr[i]);
                break;
            }
        }
    }

    for(int i=0; i<dupl.size(); i++){
        cout << dupl[i] << " ";
    }

}
int main(){

    int arr[] = {1,5,2,3,4,4,5,6,7,1,8,8};
    int s = sizeof(arr)/sizeof(arr[0]);

    findAllDuplicates(arr, s);

}