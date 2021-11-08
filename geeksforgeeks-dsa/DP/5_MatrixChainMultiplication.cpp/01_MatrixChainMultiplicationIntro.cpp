//problem statement-->
//after multiplication we have to return the min cost of multiplication
//we are given the dimension of the matrix how to put the brackets so that we can get min cost matrix
//find i ,j
//find base condition
//find k loop scheme
//calculate ans for temp ans

// UNDERSTANDING THE PROBLEM 

// Given a sequence of matrices, find the most efficient way to multiply these matrices together.
// The problem is not actually to perform the multiplications, but merely to decide in which order to perform
// the multiplications.
// We have many options to multiply a chain of matrices because matrix multiplication is associative.
// In other words, no matter how we parenthesize the product, the result will be the same.
// For example, if we had four matrices A, B, C, and D, we would have: 

// (ABC)D = (AB)(CD) = A(BCD) = ....
// However, the order in which we parenthesize the product affects the number of simple arithmetic operations
// needed to compute the product, or the efficiency. For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, 
//and C is a 5 × 60 matrix. Then,  

// (AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
// A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.
// Clearly the first parenthesization requires less number of operations.
// Given an array p[] which represents the chain of matrices such that the ith matrix Ai is of dimension p[i-1] x p[i]. We need to write a function MatrixChainOrder() that should return the minimum number of multiplications needed to multiply the chain. 

// Input: p[] = {40, 20, 30, 10, 30}   
// Output: 26000  
// There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
// Let the input 4 matrices be A, B, C and D.  The minimum number of 
// multiplications are obtained by putting parenthesis in following way
// (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30
//https://www.youtube.com/watch?v=kMK148J9qEE @12.50sec @29.0
#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int i,int j){
	if(i>=j)return 0;
	int min=INT_MAX;
	for(int k=i;k<j;k++){
		int tempAns = solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
		if(tempAns<min){
			min=tempAns;
		}
	}
	return min;
}

int main(){
	int arr[]={40,20,30,10,30};
	cout<<solve(arr,1,4)<<endl;
}