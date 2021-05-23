#ifndef ZORK_UTIL_H
#define ZORK_UTIL_H

#include <string>
#include <algorithm>
#include <functional>
#include <list>

class Util
{
public:
	template <typename T>
	static std::list<T> filter(const std::list<T>& source, std::function<bool(const T&)> predicate)
	{
		std::list<T> filtered;
		copy_if(source.begin(), source.end(), std::back_inserter(filtered), predicate);
		return filtered;
	}

	template <typename T>
	static T* find(const std::list<T*> source, std::function<bool(const T*)> predicate)
	{
		for (auto i : source)
		{
			if (predicate(i))
			{
				return i;
			}
		}
		return nullptr;
	}

	static bool areEqualsIgnoreCase(const std::string& a, const std::string& b)
	{
		return _stricmp(a.c_str(), b.c_str()) == 0;
	}
};

#endif  //ZORK_UTIL_H
