#ifndef C__11TESTING__UNIQUE_THREAD_H
#define C__11TESTING__UNIQUE_THREAD_H

#include <mutex>
#include <thread>

namespace orange {
	typedef void(*func_ptr)(void);

	class unique_thread {

	public:
		unique_thread();
		~unique_thread();

		static void execute(func_ptr callback);

		static std::mutex* get_lock();

		static func_ptr get_callback();
		static void set_callback(func_ptr callback);

	private:
		static std::mutex* lock;
		static func_ptr _callback;
	};

}
#endif //C__11TESTING__UNIQUE_THREAD_H
