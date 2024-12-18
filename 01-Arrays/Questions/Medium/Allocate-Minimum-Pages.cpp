#include <bits/stdc++.h>
using namespace std;

/*
    ================✅ Problem =================

# ✅ Allocate Minimum Pages (  Difficulty: Medium  )

   Tumhare paas ek array hai, arr[], jo books ke pages represent karta hai. Har book ke pages arr[i] mein diye hain. Aur tumhare paas k students hain, jinmein tumhe ye books allocate karni hain. 
    
    Rules:

        ✔️ Har student ko kam se kam ek book milni chahiye.
        ✔️ Har student ko lagataar books ka ek sequence milna chahiye. (e.g., agar ek student ko books 1 aur 2 di gayi hain, toh wo books 3 skip nahi kar sakta).
        ✔️ Koi bhi book do students ko allocate nahi ho sakti.


    ✅ Goal: Tumhe books aise allocate karni hain ki maximum pages jo kisi bhi student ko mil rahe hain, wo minimum ho.

👋 Note: Return -1 if a valid assignment is not possible, and allotment should be in  contiguous order (see the explanation for better understanding).

Example se samjhte hai::

    arr[] = {12, 34, 67, 90}; 
    k = 2;
    Yahaan 4 books hain, aur tumhare paas 2 students hain.

Possible allocations:

        [12] aur [34, 67, 90]
        Maximum pages = 12 (student 1) + 191 (student 2) = 191

        [12, 34] aur [67, 90]
        Maximum pages = 46 (student 1) + 157 (student 2) = 157
        
        [12, 34, 67] aur [90]
        Maximum pages = 113 (student 1) + 90 (student 2) = 113
        
        Toh jo allocation me maximum pages sabse kam ho raha hai, wo answer hoga. Yahan 113 hoga.



⭐📌  Same as Book allocation Problem
*/


//==========✅ Solution===========================
class Solution
{
public:
    // Helper function to check if allocation is possible
    bool isPossible(const vector<int> &arr, int n, int k, int maxPages)
    {
        int studentsRequired = 1; // Start with one student
        int currentSum = 0;

        for (int i = 0; i < n; i++)
        {
            // If a single book has more pages than maxPages, allocation is impossible
            if (arr[i] > maxPages)
                return false;

            // Check if adding this book exceeds maxPages
            if (currentSum + arr[i] > maxPages)
            {
                studentsRequired++;  // Allocate to a new student
                currentSum = arr[i]; // Start new student's allocation with this book

                // If the number of students exceeds k, return false
                if (studentsRequired > k)
                    return false;
            }
            else
            {
                currentSum += arr[i];
            }
        }
        return true; // Allocation is possible
    }

    int findPages(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        if (k > n)
            return -1; // If students are more than books, allocation is impossible

        int low = *max_element(arr.begin(), arr.end());   // Maximum book size
        int high = accumulate(arr.begin(), arr.end(), 0); // Sum of all pages
        int result = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2; // Midpoint to test

            if (isPossible(arr, n, k, mid))
            {
                result = mid;   // Update result to the current mid
                high = mid - 1; // Try for a smaller maximum
            }
            else
            {
                low = mid + 1; // Increase the maximum
            }
        }

        return result;
    }
};

//=========✅ Driver Code =========================
int main()
{
    Solution obj;
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << obj.findPages(arr, k) << endl; // Output: 52
    return 0;
}

//===========✅ Solution Explaination=====================================================
/*

1. Key Observations
    
    ☑️ The maximum number of pages any student can receive is at least the maximum value in the array (max(arr)), as no student can receive fewer pages than the largest book.

    ☑️ The maximum number of pages any student can receive is at most the total sum of all pages (sum(arr)), which would occur if only one student reads all the books.
    
    ☑️ The goal is to minimize the maximum pages assigned among all students.


2.✅⭐  Approach: Binary Search
    
    The problem can be reduced to finding the minimum possible "maximum number of pages" using binary search:

    a. Define the search range:
            
        ✔️  low = max(arr) (minimum pages a student must read).
        ✔️  high = sum(arr) (maximum pages a student may read).
    
    b. Binary search :  to find the smallest value of mid in this range such that it is possible to allocate books with a maximum of mid pages per student.

3. Helper Function
        
    Define a helper function, isPossible(mid), to check whether it's possible to allocate books such that no student reads more than mid pages:

        ✔️ Ek-ek book ko allocate karo, aur dekho kya total pages mid se zyada ho rahe hain.
        ✔️ Keep a running sum of pages assigned to the current student.
        ✔️ Agar mid exceed ho raha hai, toh next student ko allocate karte hain.
        ✔️ Agar students ki count k se zyada ho jaye, toh allocation invalid hai.
*/