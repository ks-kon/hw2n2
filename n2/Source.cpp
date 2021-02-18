#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <chrono>
#include <algorithm>

class Timer
{
public:
	using clock_t = std::chrono::steady_clock;
	using time_point_t = clock_t::time_point;
	Timer() : m_begin(clock_t::now()) {};
	~Timer()
	{
		auto end = clock_t::now();
		std::cout << std::chrono::duration_cast <std::chrono::microseconds> (end - m_begin).count() <<  " microsec " << std::endl;
	}
private:
	time_point_t m_begin;
};

int main()
{
	std::array <int, 1000> a;
	std::vector <int> v;
	std::deque <int> d;
	std::list <int> l;
	std::forward_list <int> f;

	for (auto i = 1000; i > 0; --i)
	{
		a[1000 - i] = i;
		v.push_back(i);
		d.push_back(i);
		l.push_back(i);
		f.push_front(1000 - i);
	}

	std::cout << std::setw(20) << std::left << "stdsort array ";

	{
		Timer t;
		std::sort(std::begin(a), std::end(a));
	}

	std::cout << std::setw(20) << std::left << "stdsort vector ";

	{
		Timer t;
		std::sort(std::begin(v), std::end(v));
	}
	/* но иногда быстрее всех сортируется вектор*/

	std::cout << std::setw(20) << std::left << "stdsort deque ";

	{
		Timer t;
		std::sort(std::begin(d), std::end(d));
	}
	/* для очереди медленнее всего*/

	std::cout << std::setw(20) << std::left << "sort list ";

	{
		Timer t;
		l.sort();
	}
	/* сортировка для list выполняется быстрее всего*/

	std::cout << std::setw(20) << std::left << "sort forw_list ";

	{
		Timer t;
		f.sort();
	}


	return EXIT_SUCCESS;
}