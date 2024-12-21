#pragma once

#include <list>


namespace otus {

    template<typename T, typename Allocator = std::allocator<T>>
    struct List {
        List() = default;
        ~List() = default;

        void push_back(const T& value) {
            m_impl.push_back(value);
        }

        void push_front(const T& value) {
            m_impl.push_front(value);
        }

        void pop_back() {
            m_impl.pop_back();
        }

        void pop_front() {
            m_impl.pop_front();
        }

        std::size_t size() const noexcept {
            return m_impl.size();
        }

        bool empty() const noexcept {
            return m_impl.empty();
        }

        T& front() {
            return m_impl.front();
        }

        T& back() {
            return m_impl.back();
        }
    typename std::list<T, Allocator>::iterator begin() {
        return m_impl.begin();
    }

    typename std::list<T, Allocator>::const_iterator begin() const {
        return m_impl.begin();
    }

    typename std::list<T, Allocator>::iterator end() {
        return m_impl.end();
    }

    typename std::list<T, Allocator>::const_iterator end() const {
        return m_impl.end();
    }
    private:
        std::list<T, Allocator> m_impl;
    };

}
