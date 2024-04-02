class H2O {
    mutex m;
    condition_variable cv;
    int countOfH;
    
public:
    H2O() {
        countOfH = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock (m);
        while (countOfH == 2) {
            cv.wait(lock);
        }
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++countOfH;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock (m);
        while (countOfH < 2) {
            cv.wait(lock);
        }
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        countOfH = 0;
        cv.notify_all();
    }
};