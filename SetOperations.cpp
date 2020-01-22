#include "SetOperations.h"

std::vector<char> set_union(std::vector<char> A, std::vector<char> B) {
	std::vector<char> res;
	int i = 0, j = 0,sz_a = A.size(),
		sz_b = B.size(),
		sz_max = std::max(sz_a,sz_b),
		sz_min = std::min(sz_a,sz_b);
	std::vector<char>* a, * b;
	if (sz_a >= sz_b) {
		a = &A;
		b = &B;
	}
	else {
		a = &B;
		b = &A;
	}
	while (i < sz_max) {
		if (j == sz_min) {
			res.push_back((*a)[i]);
			++i;
		}
		else if ((*b)[j] >= (*a)[i]) {
			res.push_back(A[i]);
			if ((*b)[j] != (*a)[i]) {
				res.push_back((*b)[j]);
			}
			++i;
			++j;
		}
		else {
			res.push_back((*b)[j]);
			++j;
		}
	}
	return res;
}
std::vector<char> set_intersection(std::vector<char> A, std::vector<char> B) {
	std::vector<char> res;
	int i = 0, j = 0, sz_a = A.size(),
		sz_b = B.size(),
		sz_max = std::max(sz_a, sz_b),
		sz_min = std::min(sz_a, sz_b);
	std::vector<char>* a, * b;
	if (sz_a >= sz_b) {
		a = &A;
		b = &B;
	}
	else {
		a = &B;
		b = &A;
	}
	while (i < sz_min) {
		if ((*b)[i] == (*a)[j]) {
			res.push_back((*b)[i]);
			++i;
			++j;
		}
		else if ((*b)[i] > (*a)[j]) {
			++j;
		}
		else {
			++i;
		}
	}
	return res;
}