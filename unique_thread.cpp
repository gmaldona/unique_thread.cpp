#include "unique_thread.h"

using namespace orange;

std::mutex* unique_thread::lock = new std::mutex();
func_ptr unique_thread::_callback = nullptr;

unique_thread::unique_thread() {
	lock = new std::mutex();
	_callback = nullptr;
}

unique_thread::~unique_thread() {
	delete orange::unique_thread::lock;
}

std::mutex* unique_thread::get_lock() {
	return lock;
}

func_ptr unique_thread::get_callback() {
	return _callback;
}

void unique_thread::set_callback(orange::func_ptr callback) {
	_callback = callback;
}

void orange::unique_thread::execute(func_ptr callback)
{
	if (orange::unique_thread::get_lock()->try_lock()) {
		orange::unique_thread::set_callback(callback);
		std::thread t([]() {
		  orange::unique_thread::get_callback()();
		  orange::unique_thread::get_lock()->unlock();
		});
		t.detach();
	}
}
