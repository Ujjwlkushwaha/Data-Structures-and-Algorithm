#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>arr){
    for(const int& i:arr){
        cout<< i << " ";
    }
    cout<<endl;
}

int main()
{
    // insert Values to the vector
    vector<int> vr1;
    /* using push_back(ele) */
    vr1.push_back(5);
    vr1.push_back(6);

    print(vr1); // 5 6
    
    /* using insert() method */

/* There are some case of insert() method to insert value in the array */
    vr1.insert(vr1.begin() , {1,2,3,4} );
    print(vr1); // 1 2 3 4 5 6

    vr1.insert(vr1.begin()+2 , 3 , 5);
    print(vr1); // 1 2 5 5 5 3 4 5 6

// put the element at last of vector 
    vr1.emplace_back(10);
    print(vr1); // 1 2 5 5 5 3 4 5 6 10 
}