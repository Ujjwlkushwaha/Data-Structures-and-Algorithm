#include <iostream>
using namespace std;

// some basic operation in char Array

int length(char *arr){
	int i=0;
	int length = 0;
	
	while(arr[i++] != '\0'){
		length++;
	}
	
	return length;
}

// Reverse char array
void reverseArray(char arr[] , int len )
{
	int s = 0  , e = len-1;
	while(s <= e)
	{
		swap(arr[s] , arr[e]);
		s++ ; 
		e--;
	}
}


// check palindrom 
bool isPalindrom(char arr[] , int len)
{
	int s = 0 , e = len-1;
	
	while(s <= e){
		if(arr[s] != arr[e]){
			return false;
		}
		
		s++ ;
		e--;
	}
	
	return true;
}


// changw to upper case
void upperCase(char *arr , int len)
{
//	way -> 01 
	for(int i=0 ; i<len ; i++){
		if(arr[i] >= 97 && arr[i] <= 122){
			arr[i] = arr[i] - 'a' + 'A';
		}
	}	
	
// 	way -> 02
}

// change into lowerCase
void lowerCase(char arr[] , int len)
{
	for(int i=0 ; i<len ; i++)
	{
		if(arr[i] >= 65 && arr[i] <= 91){
			arr[i] = arr[i] - 'A' + 'a';
		}
	}	
}
int main(){
	
	char ch[100] ;
	
	cout << "Enter any random string :: " ;
	cin >> ch ;
	
//	operations 

	int len = length(ch);

	cout << "Length of string :: " << len << endl;
	
	
	// reverse of a string
	reverseArray(ch , len);
	cout << "After Reversing String :: " << ch << endl;

	// check palindrom 
	if(isPalindrom(ch , len)){
		cout << "This is palindrom " << endl ;
	}else{
		cout << "This is not palindrom "<< endl;
	}
	
	
	// change into uppercase 
	upperCase(ch , len);
	cout << "Change into upperCase :: " << ch << endl;
	
	// change into lowerCase
	lowerCase(ch , len);
	cout << "Change into lowerCase :: " << ch << endl;
}
