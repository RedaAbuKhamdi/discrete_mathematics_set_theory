#include<iostream>

#include "SetOperations.h"

void input_function(std::vector<char>& A, int len) {
	for (int i = 0; i < len; ++i) {
		std::cin >> A[i];
	}
}

int main() {
	int n1,n2;
	std::cin >> n1>>n2;
	std::vector<char> A(n1), B(n2),res;
	input_function(A, n1);
	input_function(B, n2);
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	res = set_intersection(A, B);
	for (int i = 0; i < res.size(); ++i) {
		std::cout << res[i]<<std::endl;
	}
	return 0;
}