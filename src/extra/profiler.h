//
// Created by Artem Bobrov on 05.01.2018.
//

#ifndef COLLECTIONS_PROFILER_HPP
#define COLLECTIONS_PROFILER_HPP

#include <chrono>
#include <thread>

namespace debug {
	class profiler {
	public:
		typedef std::chrono::steady_clock clock;
		typedef clock::time_point time_point;
		typedef std::chrono::duration<double, std::ratio<1, 1>> duration_time;
	private:
		time_point _start;
		time_point _finish;

	public:
		void start();

		void finish();

		void clear();

		void sleep_for(unsigned long long seconds = 0);

		const double time() const noexcept; // seconds
	};
}

#endif //COLLECTIONS_PROFILER_HPP
