#include <iostream>
#include <vector>
// #include <pair>
using namespace std;

int pairSum(vector<int> &arr , int sum)
{
    vector<pair<int , int >> finalAns;

    for(int i=0; i<arr.size(); i++)
    {  
        for (int j = i+1; j < arr.size(); j++)
        {
            if (arr[i]+arr[j] == sum)
            {
                pair<int , int> pr;
                
                pr.first = arr[i];
                pr.second = arr[j];
                finalAns.push_back(pr); 
            }
        }
    }

    for(int i = 0 ; i<finalAns.size(); i++){
        cout << finalAns[i].first << " " << finalAns[i].second << endl;
    }

}
int main(){

    vector<int> arr = {1,2,3,4,5};

    pairSum(arr , 5);

}