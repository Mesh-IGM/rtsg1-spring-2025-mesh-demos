#pragma once

// MUST be all in the h file!

// THIS IS STILL A BAD SMART POINTER

template <class T>
class SmartPointer
{
public:
	SmartPointer(T* _ptr = nullptr)
	{
		cout << "SmartPointer()" << endl;
		ptr = _ptr;
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

