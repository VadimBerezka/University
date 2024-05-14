#include "Hash.h"
#include <iostream>
#include <chrono>
using namespace std;

int HashFunction(int key, int size)    //хеш-функция
{
	double A = (sqrt(5) - 1) / 2;  // A = 0.6180339887499
	return floor(size * fmod(key * A, 1));
}

// было
//int Next_hash(int hash, int size, int p)
//{
//	return (hash + 5 * p + 3 * p * p) % size;
//}



//10
int LinearProbe(int hash, int i, int size)
{
	return (hash + i) % size;
}	




//15
//int h1(int key, int size)
//{
//	return key % size;
//}
//
//int h2(int key, int size)
//{
//	return 1 + (key % size);
//}
//
//int DoubleHash(int key, int i, int size)
//{
//	return (h1(key, size) + i * h2(key, size)) % size;
//}
//


//-------------------------------
Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}

//-------------------------------
Object::Object(int size, int(*getkey)(void*))
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];
	for (int i = 0; i < size; ++i)
		data[i] = NULL;
}

//-------------------------------
bool Object::insert(void* d)
{
	bool b = false;
	if (N != size)
		for (int i = 0, t = getKey(d), j = HashFunction(t, size);
			i != size && !b;  j = LinearProbe(j, i, size), ++i)
			if (data[j] == NULL || data[j] == DEL)
			{
				data[j] = d;
				N++;
				b = true;
			}
	return b;
}



//1
//int QuadraticProbe(int hash, int i, int size, int c1, int c2)
//{
//	return (hash + c1 * i + c2 * i * i) % size;
//}
//
//bool Object::insert(void* d)
//{
//	bool b = false;
//	if (N != size)
//		for (int i = 0, t = getKey(d), j = HashFunction(t, size);
//			i != size && !b;  j = QuadraticProbe(j, i, size, c1, c2), ++i)
//			if (data[j] == NULL || data[j] == DEL)
//			{
//				data[j] = d;
//				N++;
//				b = true;
//			}
//	return b;
//}


//-------------------------------
int Object::searchInd(int key)
{
	int t = -1;
	bool b = false;
	if (N != 0)
		for (int i = 0, j = HashFunction(key, size); data[j] != NULL && i != size && !b; j = HashFunction(key, size))
			if (data[j] != DEL)

				if (getKey(data[j]) == key)
				{
					t = j; b = true;
				}
	return t;
}

//-------------------------------
void* Object::search(int key)
{

	int t = searchInd(key);
	void* result = (t >= 0) ? (data[t]) : (NULL);

	return result;
}

//-------------------------------
void* Object::deleteByKey(int key)
{
	int i = searchInd(key);
	void* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}

//-------------------------------
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);
}

//-------------------------------
void Object::scan(void(*f)(void*))
{
	for (int i = 0; i < this->size; i++)
	{
		cout << " Элемент" << i;
		if ((this->data)[i] == NULL)
			cout << "  пусто" << endl;
		else
			if ((this->data)[i] == DEL)
				cout << "  удален" << endl;
			else
				f((this->data)[i]);
	}
}

