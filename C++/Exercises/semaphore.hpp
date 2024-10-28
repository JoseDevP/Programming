#if !defined (_SEMAPHORE_HPP_)  
#define _SEMAPHORE_HPP_

#include <mutex>
#include <condition_variable>

class semaphore
{
    private:
        std::mutex mutex_;
        std::condition_variable condition_;
        int count_;
    public:
        semaphore(int count = 0) : count_{count} {}

        void notify()
        {
            std::unique_lock<std::mutex> lock(mutex_);
            ++count_;
            condition_.notify_one();
        } 

        void wait()
        {
            std::unique_lock<std::mutex> lock(mutex_);
            while (!count_)
                condition_.wait(lock);
            --count_;
        }

        bool try_wait()
        {
            std::unique_lock<std::mutex> lock(mutex_);
            if(count_)
            {
                --count_;
                return true;
            }
            return false;
        }
};

#endif