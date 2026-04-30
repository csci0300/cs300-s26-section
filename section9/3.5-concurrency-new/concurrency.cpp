#include <thread>
#include <mutex>
#include <vector>
#include <iostream>
#include <cassert>

int NUM_THREADS = 10;
int DEPOSITS_PER_THREAD = 5000;
int DEPOSIT_SIZE = 100;

int EXPECTED_TOTAL = NUM_THREADS * DEPOSITS_PER_THREAD * DEPOSIT_SIZE;

void update_account(int* balance, std::mutex* balance_mutex) {
    for (int i = 0; i < DEPOSITS_PER_THREAD; i++) {
        *balance += DEPOSIT_SIZE;
    }
}

int main() {
    int balance = 0;

    // Spawn threads to all update the account balance at once
    std::vector<std::thread> workers;
    std::mutex balance_mtx;
    for (int i = 0; i < NUM_THREADS; i++) {
        workers.push_back(std::thread(update_account, &balance, &balance_mtx));
    }

    // Join all of the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        workers.at(i).join();
    }

    // Print out the final balance and check that it's what we'd expect!
    std::cout << "Final balance = " << balance << std::endl;
    std::cout << "Expected final balance = " << EXPECTED_TOTAL << std::endl;
    assert(balance == EXPECTED_TOTAL);
}