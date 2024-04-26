#include<iostream>
#include<unordered_map>
using namespace std;



int uniqueOccurence(int *arr , int size)
{
    unordered_map<int , int> mp;

    for(int i = 0 ; i<size ; i++){
        mp[arr[i]]++;
    }

    auto s = mp.begin() , e = mp.end();

        for(int i = 0 ; i<mp.size() ; i++){
        if(s == e){

        }
    }
    // return 0;
}


int main()
{
    int arr[] = {1,3,1,3,6,5,4,6,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    int i = uniqueOccurence(arr , size);

    cout <<"Your unique element is : " << i << endl;
    
}