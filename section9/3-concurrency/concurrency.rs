use std::sync::{Arc, Mutex};
use std::thread;

fn make_large_vector() -> Vec<i32> {
    let mut v = vec![];
    for i in 0..5000 {
        v.push(i - 300);
    }
    v
}

fn update_account(balance: &Mutex<i32>) {
    for i in 0..5000 {
        let mut requests_guard = requests.lock().unwrap();
        if requests_guard.is_empty() {
            return;
        }
        let current_request = requests_guard.get(0).unwrap().clone();
        requests_guard.remove(0);
        drop(requests_guard);
        
        *balance += current_request;
    }
}

fn main() {
    let balance = Arc::new(Mutex::new(300));
    let requests = Arc::new(Mutex::new(make_large_vector()));

    let mut workers = vec![];
    for _ in 0..6 {
        let balance_ref = balance.clone();
        let requests_ref = requests.clone();
        workers.push(thread::spawn(move || update_account(&*balance_ref, &*requests_ref)));
    }

    for worker in workers {
        worker.join().unwrap();
    }

    println!("Final balance = {:?}", *balance.lock().unwrap());
}