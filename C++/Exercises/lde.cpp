#include <iostream>
#include <memory>

template<typename T> class NodeLDE
{
    public:
        T value;
        std::weak_ptr<NodeLDE<T>> prev;
        std::shared_ptr<NodeLDE<T>> next;
        NodeLDE(T val) : value(val), prev(nullptr), next(nullptr) {}
};

template<typename T> class LDE : std::enable_shared_from_this<LDE<T>>
{
    private:
        std::shared_ptr<NodeLDE<T>> first;
    public:
        LDE() : first(nullptr) {}

        LDE(T value) : first(std::make_shared<NodeLDE<T>>(value)) {}

        void push_back(T value)
        {
            if(!first)
            {
                first = std::make_shared<NodeLDE<T>>(value);
                return;
            }

            NodeLDE<T>* current = first.get();

            while (current->next != nullptr)
                current = current->next.get();

            std::shared_ptr<NodeLDE<T>> newNode = std::make_shared<NodeLDE<T>>(value);
            current->next = newNode;

            newNode->prev = current->shared_from_this();
        }

        void push_front(T value)
        {
            std::shared_ptr<NodeLDE<T>> newPtr = std::make_shared<NodeLDE<T>>(value);

            if(!first)
            {
                first = newPtr;
                return;
            }
            
            newPtr->next = first;
            first->prev = newPtr;
            first = newPtr;
        }

        bool pop_back()
        {
            if(!first)  return false;

            if(!first->next)
            {
                first.reset();
                return true;
            }

            NodeLDE<T>* current = first.get();
            NodeLDE<T>* lastOne = current;

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
            if(!first)  return false;

            if(!first->next)
            {
                first.reset();
                return true;
            }
            else
            {
                std::shared_ptr<NodeLDE<T>> newPtr = first->next;
                first = newPtr;
                return true;
            }
        }

        bool insert_at(int index, T value) 
        {
            if (index < 0 || index > size()) return false; 

            if (index == 0)
            {
                push_front(value); 
                return true;
            }

            NodeLDE<T>* current = first.get();
            NodeLDE<T>* lastOne = nullptr; 

            for (int i = 0; i < index; i++)
            {
                lastOne = current; 
                current = current->next.get(); 
                if (current == nullptr) break;
            }

            std::shared_ptr<NodeLDE<T>> newPtr = std::make_shared<NodeLDE<T>>(value); 

            if (current == nullptr) 
            {
                lastOne->next = newPtr; 
                newPtr->prev = lastOne->shared_from_this();
            }
            else 
            {
                newPtr->prev = lastOne->shared_from_this();
                newPtr->next = current->shared_from_this(); 
                current->prev = newPtr; 
                lastOne->next = newPtr; 
            }

            return true;
        }

        bool remove_at(int index) 0 1 2 3 4 
        {
            if (index < 0 || index >= size()) return false; 

            if (index == 0)
            {
                pop_front(); 
                return true;
            }

            NodeLDE<T>* current = first.get();
            NodeLDE<T>* lastOne = nullptr; 

            for (int i = 0; i < index; i++)
            {
                lastOne = current; 
                current = current->next.get(); 
            }

            if ( current->next == nullptr)
            {
                lastOne->next.reset();
                return true;
            }
            else
            {
                lastOne->next = current->next;
                current->next->prev = lastOne->shared_from_this();
                return true;
            }
            
        }

        int find(T value) const
        {
            if(!first) return -1;

            NodeLDE<T>* current = first.get();

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
            if(!first) return 0;

            int i = 0;

            NodeLDE<T>* current = first.get();

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

            NodeLDE<T>* current = first.get();
            while (current != nullptr)
            {
                std::cout << current->value << std::endl;
                current = current->next.get();
            }
        } 
};