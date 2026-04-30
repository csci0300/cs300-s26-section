#include <thread>
#include <mutex>
#include <vector>
#include <iostream>

std::vector<int> make_large_vector() {
    std::vector<int> v;
    for (int i = 0; i < 5000; i++) {
        v.push_back(i - 300);
    }
    return v;
}

void update_account(int* balance, std::vector<int>* requests, std::mutex* requests_mtx) {
    while (true) {
        requests_mtx->lock();
        if (requests->empty()) {
            requests_mtx->unlock();
            return;
        }
        int current_request = requests->at(0);
        requests->erase(requests->begin());
        requests_mtx->unlock();

        *balance += current_request;
    }
}

int main() {
    int balance = 300;
    std::vector<int> requests = make_large_vector();
    std::mutex requests_mtx;

    std::vector<std::thread> workers;
    for (int i = 0; i < 6; i++) {
        workers.push_back(std::thread(update_account, &balance, &requests, &requests_mtx));
    }
    for (int i = 0; i < 6; i++) {
        workers.at(i).join();
    }

    std::cout << "Final balance = " << balance << std::endl;
    return 0;
}