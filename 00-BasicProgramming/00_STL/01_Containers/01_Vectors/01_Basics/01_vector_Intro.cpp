#include<iostream>

// for using vector we must to put this librery
#include<vector>

using namespace std;

void printVector(vector<int> a){
    for(int i=0 ; i<a.size() ; i++){
        cout << a[i] << " ";
    }

    cout << endl;
}

int main()
{
    // 👉 Declation of vector -> vector<Data_type> nameOfArray ;
        vector <int> vec1;

    // 👉 Initialization of vector
        // 👍 there are multiple methods for initializing a vector

            vector <int> vec2 = {4,5,6,3,7,8,2,1,6,4,3};
            printVector(vec2);
        
        // 👉 For creating n size vector with default value -> vector<int> vr(size , dValue)
            vector <int> vec3(5 , 0);
            printVector(vec3);

        //👍 Create clone of other  vector
            vector<int> vec4(vec2);
            printVector(vec4);

    // 👉 Element access
            // there are some methods for accessing elements

}