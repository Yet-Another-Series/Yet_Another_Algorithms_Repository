/*
** Yet_Another_Algorithms_Repository
** File description:
** cpp-queue from aFranchon
*/

#ifndef CPP_QUEUE_HPP_
#define CPP_QUEUE_HPP_

#include <vector>
#include <iostream>

template<typename T>
class CppQueue
{
    public:

        CppQueue() = default;
        ~CppQueue() = default;
        
        //Utlities
        bool empty() const {return ((_queue.size() != 0) ? false : true);};
        int size() const {return _queue.size;};

        //Getting start or end of queue
        T front() const {return _queue[0];};
        T back() const {return _queue[_queue.size() - 1];};

        //manipulating queue data
        void push(const T &data) {_queue.insert(_queue.begin(), data);};
        void emplace(const T &data) {_queue.push_back(data);};
        void pop() {_queue.erase(_queue.begin());};
        void swap(CppQueue<T> &x)
        {
            std::vector<T> tmp;

            for (auto elem : _queue)
            {
                tmp.push_back(elem);
            }

            _queue.clear();
            
            for (; !x.empty();)
            {
                _queue.push_back(x.front());
                x.pop();
            }

            for (auto elem : tmp)
            {
                x.emplace(elem);
            }
        }

    private:
        std::vector<T> _queue;
};

#endif /* !CPP_QUEUE_HPP_ */
