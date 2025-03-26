#pragma once

// .h file only!

// THIS IS A ***BAD*** SMART POINTER

template <class T>
class SmartPointer
{
public:
	SmartPointer(T* _ptr = nullptr)
	{
		ptr = _ptr;
		cout << "SmartPointer()" << endl;
	}

	~SmartPointer()
	{
		cout << "~SmartPointer()" << endl;
		delete ptr;
		ptr = nullptr;
	}
	
	T& operator *()
	{
		return *ptr;
	}

	T* operator ->()
	{
		return ptr;
	}

private:
	T* ptr;
};

