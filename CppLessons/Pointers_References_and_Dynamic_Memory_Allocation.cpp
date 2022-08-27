#include <bits/stdc++.h>
using namespace std;

void squareWithPointer(int* pNumber);
void squareWithReference(int& rNumber);

int squareConst(const int);
int squareNonConst(int);
int squareConstRef(const int &);
int squareNonConstRef(int &);

int& squareRef(int&);
int* squarePtr(int*);

int* squarePtrLocal(int);
int& squareRefLocal(int);

int* squarePtrLocalDynamically(int);
int& squareRefLocalDynamically(int);

int main() {
	// https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html
	
	// --- POINTER VARIABLES ---
	
	// Pointer (variable) stores a memory address
	
	int *ptr;
	int *ptr2, *ptr3, i; // ptr2, ptr3 are pinters, i - is integer
	// Naming convention of pointers:
	// include a "p" or "ptr" as prefix or suffix, e.g., iPtr, numberPtr, pNumber, pStudent.


	// Initializing Pointers via the Address-Of Operator
	
	// When you declare a pointer variable, its content is not initialized.
	// In other words, it contains an address of "somewhere", which is of course not a valid location.
	// This is dangerous! You need to initialize a pointer by assigning it a valid address.
	// This is normally done via the address-of operator (&).

	int number = 14;
	int *numberPtr = &number;

	cout << ptr << endl; // random address
	cout << numberPtr << endl; // number variable address

	// The address-of operator (&) can only be used on the RHS (right hand side).


	// Indirection or Dereferencing Operator (*)
	
	// The indirection operator (or dereferencing operator) (*) operates on a pointer,
	// and returns the value stored in the address kept in the pointer variable.
	// For example, if pNumber is an int pointer, *pNumber returns the int value
	// "pointed to" by pNumber.

	cout << number << endl;
	cout << *numberPtr << endl;
	*numberPtr = 57;
	cout << number << endl;
	cout << *numberPtr << endl;


	// Pointer has a Type Too

	/*
	 A pointer is associated with a type (of the value it points to),
	 which is specified during declaration.
	 A pointer can only hold an address of the declared type;
	 it cannot hold an address of a different type.
	*/

	int t = 88;
	double d = 55.66;
	int *iPtr = &t;    // int pointer pointing to an int value
	double *dPtr = &d; // double pointer pointing to a double value


	// Uninitialized Pointers
	int * ptr4;
	*ptr4 = 55; // !!! DON'T DO THIS

	// The pointer iPtr was declared without initialization, i.e.,
	// it is pointing to "somewhere" which is of course an invalid memory location.
	// The *iPtr = 55 corrupts the value of "somewhere"!
	// You need to initialize a pointer by assigning it a valid address.

	cout << ptr4 << endl;
	cout << *ptr4 << endl;


	// Null Pointers
	// You can initialize a pointer to 0 or NULL, i.e., it points to nothing.
	// It is called a null pointer. 
	int *ptr5 = 0;
	int *ptr6 = NULL;
	int *ptr7 = nullptr;
	
	// cout << *ptr5 << endl;
	// Dereferencing a null pointer (*p) causes an STATUS_ACCESS_VIOLATION exception.



	// --- REFERENCE VARIABLES ---

	// References (or Aliases) (&)
	int number2 = 88;           // Declare an int variable called number
	int& refNumber2 = number2;  // Declare a reference (alias) to the variable number
                            	// Both refNumber and number refer to the same value

	cout << number2 << endl;    // Print value of variable number (88)
	cout << refNumber2 << endl; // Print value of reference (88)

	refNumber2 = 99;            // Re-assign a new value to refNumber
	cout << refNumber2 << endl;
	cout << number2 << endl;    // Value of number also changes (99)

	number2 = 55;               // Re-assign a new value to number
	cout << number2 << endl;
	cout << refNumber2 << endl; // Value of refNumber also changes (55)

	
	// Pass-By-Reference into Functions with Reference Arguments vs. Pointer Arguments

	// Pass-by-value	

	// Default way to pass arguments into functions is by value
	// (except arrays which is treated as pointers).
	// That is, a clone copy of the argument is made and passed into the function.


	// Pass-by-Reference with Pointer Arguments

	// We may wish to modify the original copy directly
	// (especially in passing huge object or array)
	// to avoid the overhead of cloning.

    int number3 = 8;
	cout << "In main(): " << &number3 << endl; // 0x22ff1c
	cout << number3 << endl; // 8
	squareWithPointer(&number3); // Explicit referencing to pass an address
	cout << number3 << endl; // 64

	
	// Pass-by-Reference with Reference Arguments
	
	// Instead of passing pointers into function,
	// you could also pass references into function,
	// to avoid the clumsy syntax of referencing and dereferencing

	int number4 = 8;
	cout <<  "In main(): " << &number4 << endl;  // 0x22ff1c
	cout << number4 << endl;  // 8
	squareWithReference(number); // Implicit referencing (without '&')
	cout << number4 << endl;  // 64

	// Again, the output shows that the called function operates on the same address,
	// and can thus modify the caller's variable.

	// Take note referencing (in the caller)
	// and dereferencing (in the function) are done implicitly.
	// The only coding difference with pass-by-value is in the function's
	// parameter declaration.

	// References are primarily used in passing reference in/out of functions
	// to allow the called function accesses variables in the caller directly.


	// "const" Function Reference/Pointer Parameters
	
	// A const function formal parameter cannot be modified
	// inside the function.
	// A const function parameter can receive both const 
	// and non-const argument.
	// On the other hand, a non-const function reference/pointer parameter can
	// only receive non-const argument.


	int number5 = 8;
	const int constNumber5 = 9;
	cout << squareConst(number5) << endl;
	cout << squareConst(constNumber5) << endl;
	cout << squareNonConst(number5) << endl;
	cout << squareNonConst(constNumber5) << endl;
	// constNumber5 is not changes since it's passed by value
	// pass-by-value makes a copy with a different address

	cout << squareConstRef(number5) << endl;
	cout << squareConstRef(constNumber5) << endl;
	cout << squareNonConstRef(number5) << endl;
	// cout << squareNonConstRef(constNumber) << endl;
	// error: invalid initialization of reference of
	// type 'int&' from expression of type 'const int'


	// Passing the Function's Return Value

	// Passing the Return-value as Reference
	int number7 = 8;
	cout << "In main() &number7: " << &number7 << endl;
	int& result = squareRef(number7);
	cout << "In main() &result:  " << &result << endl;
	cout << result << endl;   // 64
	cout << number7 << endl;  // 64

	int number8 = 9;
	cout << "In main() &number8: " << &number8 << endl;
	int* pResult = squarePtr(&number8);
	cout << "In main() pResult:  " << pResult << endl;
	cout << *pResult << endl;   // 81
	cout << number8 << endl;    // 81

	// !!! You should not pass Function's local variable
	// as return value by reference
	int number9 = 8;
	cout << number9 << endl;  // 8
	// cout << *squarePtrLocal(number9) << endl;  // ??
	// cout << squarePtrLocal(number9) << endl;   // ??

	// Local variable has local scope within the function,
	// and its value is destroyed after the function exits.
	// The GCC compiler is kind enough to issue a warning (but not error).

	// It is safe to return a reference that is passed into the function
	// as an argument. See earlier examples.


	// Passing Dynamically Allocated Memory as Return Value by Reference

	// Instead, you need to dynamically allocate a variable
	// for the return value, and return it by reference.
	int number10 = 8;
	cout << number10 << endl;  // 8
	cout << *squarePtrLocalDynamically(number10) << endl;  // 64
	cout << squareRefLocalDynamically(number10) << endl;   // 64


	// Summary

	// In pass-by-value, a clone is made and passed into the function.
	// The caller's copy cannot be modified.
	
	// In pass-by-reference, a pointer is passed into the function.
	// The caller's copy could be modified inside the function.

	// In pass-by-reference with reference arguments,
	// you use the variable name as the argument.
	
	// In pass-by-reference with pointer arguments,
	// you need to use &varName (an address) as the argument.



	// --- Dynamic Memory Allocation ---

	// new and delete Operators

	// Instead of static allocation, the storage can be dynamically allocated
	// at runtime, via a new operator.
	
	// Whenever you allocate a piece of memory dynamically via new,
	// you need to use delete to remove the storage.

	// Static allocation
	int number11 = 88;
	int* pNumber11 = &number11;  // Assign a "valid" address into pointer

	// Dynamic allocation
	cout << "Dyncamic allocation" << endl;
	int* p12;             // Not initialize, points to somewhere which is invalid
	cout << p12 << endl;  // Print address before allocation
	p12 = new int;        // Dynamically allocate an int and assign its address to pointer
	                      // The pointer gets a valid address with memory allocated
	cout << p12 << endl;  // Print address after allocation

	*p12 = 99;
	cout << *p12 << endl; // Print value point-to
	cout << p12 << endl;  // Print address after allocation
	delete p12;           // Remove the dynamically allocated storage
	cout << "delete" << endl;
	cout << p12 << endl;  // Print address after allocation
	// https://stackoverflow.com/questions/4990462/what-happens-to-an-address-after-delete-operator-has-been-applied-to-it-in-c

	// Observe that new and delete operators work on pointer.

	// To initialize the dynamically allocated memory,
	// you can use an initializer for fundamental types,
	// or invoke a constructor for an object.
	// use an initializer to initialize a fundamental type
	// (such as int, double)
	int* p13 = new int(88); // or {88}
	double* p14 = new double(1.23); // or {1.23}
	delete p13;
	delete p14;

	// invoke a constructor to initialize an object (such as Date, Time)
	// Date* date1 = new Date(1999, 1, 1);
	// Time* time1 = new Time(12, 34, 56);



	return 0;
}

void squareWithPointer(int* pNumber) { 
	cout <<  "In square(): " << pNumber << endl;  // 0x22ff1c
	*pNumber *= *pNumber;      // Explicit de-referencing to get the value pointed-to
}

void squareWithReference(int& rNumber) {
	cout <<  "In square(): " << &rNumber << endl;  // 0x22ff1c
	rNumber *= rNumber;        // Implicit de-referencing (without '*')
}



int squareConst(const int number) {
   // number *= number;  // error: assignment of read-only parameter
   return number * number;
}

int squareNonConst(int number) {  // non-const parameter
   number *= number;
   return number;
}

int squareConstRef(const int& number) {  // const reference
   return number * number;
}

int squareNonConstRef(int& number) {  // non-const reference
   return number * number;
}


int& squareRef(int& rNumber) {
   cout <<  "In squareRef():     " << &rNumber << endl;
   rNumber *= rNumber;
   return rNumber;
}
 
int* squarePtr(int* pNumber) {
   cout <<  "In squarePtr():     " << pNumber << endl;
   *pNumber *= *pNumber;
   return pNumber;
}



int* squarePtrLocal(int number) {
	int localResult = number * number;
	return &localResult;
	// warning: address of local variable 'localResult' returned
}
 
int& squareRefLocal(int number) {
	int localResult = number * number;
	return localResult;
	// warning: reference of local variable 'localResult' returned
}



int* squarePtrLocalDynamically(int number) {
   int* dynamicAllocatedResult = new int(number * number);
   return dynamicAllocatedResult;
}
 
int& squareRefLocalDynamically(int number) {
   int* dynamicAllocatedResult = new int(number * number);
   return *dynamicAllocatedResult;
}
