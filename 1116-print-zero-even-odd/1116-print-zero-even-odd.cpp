class ZeroEvenOdd {
    mutex m;
    condition_variable cv;
    int curr_value;
    bool zero_wait;
    
private:
    int n;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        curr_value = 1;
        zero_wait = false;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<mutex> lock (m);
        for (int i = 0; i < n; i++) {
            while (zero_wait == true) {
                cv.wait(lock);
            }
            
            printNumber(0);
            zero_wait = true;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex> lock (m);
        
        for (int i = 2; i <= n; i += 2) {
            while (zero_wait == false || curr_value % 2 != 0) {
                cv.wait(lock);
            }
            
            printNumber(curr_value++);
            zero_wait = false;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex> lock (m);
        
        for (int i = 1; i <= n; i += 2) {
            while (zero_wait == false || curr_value % 2 != 1) {
                cv.wait(lock);
            }
            
            printNumber(curr_value++);
            zero_wait = false;
            cv.notify_all();
        }
    }
};