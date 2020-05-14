#pragma once

#include <iostream>

using namespace std;

template<typename T>
class D_List
{
private:
	template<typename T> struct Elem
	{
		T data;
		Elem* next, * prev;
	};
	Elem<T>* Head, * Tail;
public:
	D_List();
	D_List(const D_List<T>& obj);

	void Add_begin(T el);
	void Add_end(T el);
	void deleteAll();
	void reversList();

	template<typename T>
	friend ostream& operator<<(ostream& out, const D_List<T>& obj);

	~D_List();
};

template<typename T>
inline D_List<T>::D_List()
{
	Head = Tail = NULL;
}

template<typename T>
D_List<T>::D_List(const D_List<T>& obj)
{
	Head = obj.Head;
	Tail = obj.Tail;
}

template<typename T>
inline void D_List<T>::Add_begin(T el)
{
	if (Head == NULL)
	{
		Head = Tail = new Elem<T>;
		Head->data = el;
		Head->next = Head->prev = NULL;
	}
	else
	{
		Elem<T>* nEl = new Elem<T>;
		nEl->next = Head;
		nEl->prev = NULL;
		nEl->data = el;
		Head->prev = nEl;
		Head = nEl;
	}
}

template<typename T>
void D_List<T>::Add_end(T el)
{
	if (Head == NULL)
	{
		Head = Tail = new Elem<T>;
		Head->data = el;
		Head->next = Head->prev = NULL;
	}
	else
	{
		Elem<T>* nEl = new Elem<T>;
		nEl->data = el;
		nEl->next = NULL;
		nEl->prev = Tail;
		Tail->next = nEl;
		Tail = nEl;
	}
}

template<typename T>
void D_List<T>::deleteAll()
{
	while (Head != NULL)
	{
		if (Head->next == NULL)
		{
			delete Head;
			Head = NULL;
			break;
		}
		Elem<T>* el = Head;
		Head = Head->next;
		Head->prev = NULL;
		delete el;
	}
}

template<typename T>
void D_List<T>::reversList()
{
	Elem<T>* it = Head;
	while (it != NULL)
	{
		Elem<T>* temp = it->next;
		it->next = it->prev;
		it->prev = temp;
		it = temp;
	}
	it = Tail;
	Tail = Head;
	Head = it;
}

template<typename T>
D_List<T>::~D_List()
{
	deleteAll();
}

template<typename T>
ostream& operator<<(ostream& out, const D_List<T>& obj)
{
	D_List<T> temp(obj);

	while (temp.Head != NULL)
	{
		out << temp.Head->data << " ";
		temp.Head = temp.Head->next;
	}
	temp.Head = temp.Tail = NULL;
	return out;
}
