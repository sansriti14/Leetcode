class FooBar {
    mutex m;
    condition_variable cv;
    bool fooWait;
    
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
        fooWait = false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock (m);
            while (fooWait == true) {
                cv.wait(lock);
            }
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            fooWait = true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock (m);
            while (fooWait == false) {
                cv.wait(lock);
            }
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            fooWait = false;
            cv.notify_all();
        }
    }
};