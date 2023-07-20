#pragma once
#pragma once
#include <iostream>
#include <chrono>

namespace math273 {
	template <typename Units>
	class timer {
	public:
		
		void reset();
		void start();
		void stop();
		auto read() const;


	private:
		std::chrono::steady_clock::time_point start_time, stop_time;
		Units total_time = std::chrono::duration_values<Units>::zero();
		enum { RUNNING, STOPPED } state = STOPPED;
	};

	template <typename Units>
	void timer<Units>::reset() {
		if (state == RUNNING) {
			start_time = std::chrono::steady_clock::now();
			total_time = std::chrono::duration_values<Units>::zero();
			
		}
		else if (state == STOPPED) {
			stop_time = start_time; // std::chrono::system_clock::now();
			total_time = std::chrono::duration_values<Units>::zero();			
		}
	}

	template <typename Units>
	void timer<Units>::start() {
		if (state == RUNNING) { return; }
		else if( state == STOPPED) {
			start_time = std::chrono::steady_clock::now();
			state = RUNNING;
			
		}
	}

	template <typename Units>
	void timer<Units>::stop() {
		if (state == RUNNING) {
			stop_time = std::chrono::steady_clock::now();
			total_time += std::chrono::duration_cast<Units>(stop_time - start_time);
			state = STOPPED;
		}
		else if (state == STOPPED) { 
			return; 
		}
	}

	template <typename Units>
	auto timer<Units>::read() const {
		auto time_elapsed = total_time;
		if (state == RUNNING) {
			time_elapsed = total_time
				+ std::chrono::duration_cast<Units>(std::chrono::steady_clock::now() - start_time);
			return time_elapsed.count();
		}
		else if (state == STOPPED) {
			return total_time.count();
		
		}
	}
}