#pragma once
#include <string>
#include <algorithm>
#include <functional>
#include <list>

using namespace std;

class Util
{
public:
	template<typename T>
	static list<T> filter(const list<T>& source, function<bool(const T&)> predicate)
	{
		list<T> filtered;
		copy_if(source.begin(), source.end(), back_inserter(filtered), predicate);
		return filtered;
	}

	template<typename T>
	static T* find(const list<T*> source, function<bool(const T*)> predicate)
	{
		for (auto i : source)
		{
			if(predicate(i))
			{
				return i;
			}
		}
		return nullptr;
	}
};