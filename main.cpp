#include <chrono>
#include <iostream>
#include <thread>

#include "unique_thread.h"

void doSomething() {
   const int id = rand() % 100;
   for (int i = 0; i < 4; i++) {
      std::cout << "Hello from thread id=" << id << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
   }
}

int main() {
   orange::unique_thread t;
   while (1) {
      orange::unique_thread::execute(doSomething);
   }
   return 0;
}