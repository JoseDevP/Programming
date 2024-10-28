#include <iostream>
#include <memory>

template<typename T> class NodeLSE
{
    public:
        T value; 
        std::unique_ptr<NodeLSE<T>> next;
        NodeLSE(T val = 0) : value(val), next(nullptr) {}
};

template<typename T> class LSE
{
    private:
        std::unique_ptr<NodeLSE<T>> first;
    public:
        LSE() : first(nullptr) {}
        LSE(T value) : first(std::make_unique<NodeLSE<T>>(value)) {}
        void push_back(T value)
        {
            if(!first)
            {
                first = std::make_unique<NodeLSE<T>>(value);
                return;
            }

            NodeLSE<T>* current = first.get();

            while (current->next != nullptr)
            {
                current = current->next.get();
            }
            
            current->next = std::make_unique<NodeLSE<T>>(value);
        }

        void push_front(T value)
        {
            if(!first)
            {
                first = std::make_unique<NodeLSE<T>>(value);
                return;
            }
            
            std::unique_ptr<NodeLSE<T>> newPtr = std::move(first);

            first = std::make_unique<NodeLSE<T>>(value);

            first->next = newPtr;
        }

        bool pop_back()
        {
            if(!first) return false;

            if (!first->next) 
            {
                first.reset(); 
                return true;
            }

            NodeLSE<T>* current = first.get();
            NodeLSE<T>* lastOne = current;

            while (current->next != nullptr)
            {
                lastOne = current;
                current = current->next.get();
            }

            lastOne->next.reset();
            return true;
        }

        bool pop_front()
        {
            if(!first) return false;

            if(!first->next)
            {
                first.reset();
                return true;
            }
            
            first = std::move(first->next);
            return true;
        }

        bool insert_at(int index, T value)
        {
            if (index < 0 || index > size()) return false; 

            if (index == 0)
            {
                push_front(value); 
                return true;
            }

            NodeLSE<T>* current = first.get();
            NodeLSE<T>* lastOne = nullptr;

            for (int i = 0; i < index; i++)
            {
                lastOne = current; 
                current = current->next.get(); 
            }

            std::unique_ptr<NodeLSE<T>> newPtr = std::make_unique<NodeLSE<T>>(value);
            newPtr->next = std::move(lastOne->next); 
            lastOne->next = std::move(newPtr); 

            return true; 
        }


        bool remove_at(int index)
        {
            if(index < 0 || index >= size()) return false;  

            if(index == 0)
            {
                pop_front();
                return true;
            }

            NodeLSE<T>* current = first.get();
            NodeLSE<T>* lastOne = current;

            for (int i = 0; i < index; i++)
            {
                lastOne = current;
                current = current->next.get();
            }

            lastOne->next = std::move(current->next); 
            return true;
        }
        
        int find(T value) const
        {
            if(!first) return -1;

            NodeLSE<T>* current = first.get();

            int i = 0;
            while (current != nullptr)
            {
                if(current->value == value)
                    return i;
                current = current->next.get();
            }
            return -1;
        }

        int size() const
        {
            if(is_empty()) return 0;

            int i = 0;
            NodeLSE<T>* current = first.get();

            while (current != nullptr)
            {
                i++;
                current = current->next.get();
            }

            return i;
        }

        bool is_empty() const
        {
            return !first;
        }

        void clear()
        {
            while (first) 
            {
                pop_front(); 
            }
        }

        void display() const
        {
            if(!first) return;

            NodeLSE<T>* current = first.get();
            while (current != nullptr)
            {
                std::cout << current->value << std::endl;
                current = current->next.get();
            }
        } 
};