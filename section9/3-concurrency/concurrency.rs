use std::sync::{Arc, Mutex};
use std::thread;

const NUM_THREADS: i32 = 10;
const DEPOSITS_PER_THREAD: i32 = 5000;
const DEPOSIT_SIZE: i32 = 100;

const EXPECTED_TOTAL: i32 = NUM_THREADS * DEPOSITS_PER_THREAD * DEPOSIT_SIZE;

fn update_account(balance: &Mutex<i32>) {
    for _ in 0..DEPOSITS_PER_THREAD {
        *balance += DEPOSIT_SIZE;
    }
}

fn main() {
    let balance = Arc::new(Mutex::new(0));

    // Spawn threads to all update the account balance at once
    let mut workers = vec![];
    for _ in 0..NUM_THREADS {
        let balance_ref = balance.clone();
        workers.push(thread::spawn(move || update_account(&*balance_ref)));
    }

    // Join all of the threads
    for worker in workers {
        worker.join().unwrap();
    }

    // Print out the final balance and check that it's what we'd expect!
    let final_balance = *balance.lock().unwrap();
    println!("Final balance = {}", final_balance);
    println!("Expected final balance = {}", EXPECTED_TOTAL);
    assert_eq!(final_balance, EXPECTED_TOTAL);
}