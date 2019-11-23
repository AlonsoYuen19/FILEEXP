#pragma once
template<class T>
struct CNodo {
	T key;
	struct CNodo* left;
	struct CNodo* right;
	int height; //altura
	CNodo() {
		left = nullptr;
		right = nullptr;
		height = 0;
	}



};