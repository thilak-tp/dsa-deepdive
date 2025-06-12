#include <iostream>
#include <vector>
#include <thread>
#include <cmath>
#include <chrono>

void cpu_task(int thread_id, size_t iterations) {
    double result = 0.0;
    for (size_t i = 1; i < iterations; ++i) {
        result += std::sqrt(static_cast<double>(i));
    }
    // Optional: print result to prevent optimization
    std::cout << "Thread " << thread_id << " finished with result: " << result << std::endl;
}

int main() {
    // Number of threads = number of cores
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 4; // fallback

    std::cout << "Using " << num_threads << " threads.\n";

    // Workload per thread
    size_t iterations_per_thread = 100'000'000;

    // Start measuring time
    auto start_time = std::chrono::high_resolution_clock::now();

    // Launch threads
    std::vector<std::thread> threads;
    for (unsigned int i = 0; i < num_threads; ++i) {
        threads.emplace_back(cpu_task, i, iterations_per_thread);
    }

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }

    // End time
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << "Total elapsed time: " << elapsed.count() << " seconds\n";

    return 0;
}

