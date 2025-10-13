class FooBar {
private:
    int n;
    binary_semaphore can_foo, can_bar;
public:
    FooBar(int n): n(n), can_foo(1), can_bar(0) {}

    void foo(function<void()> printFoo) {
        print_func(printFoo, can_foo, can_bar);
    }

    void bar(function<void()> printBar) {
        print_func(printBar, can_bar, can_foo);
    }

    void print_func(function<void()> f, binary_semaphore& self, binary_semaphore& other){
        for (int i = 0; i < n; i++) {
            self.acquire();
        	f();
            other.release();
        }
        other.release();
    }
};