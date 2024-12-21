#pragma once

#include <vector>

namespace otus {

    template<typename T, typename Allocator = std::allocator<T>>
    class Vector {
    public:
        Vector() = default;
        ~Vector() = default;

        void push_back(const T& value) {
            m_impl.push_back(value);
        }

        void pop_back() {
            m_impl.pop_back();
        }

        std::size_t size() const noexcept {
            return m_impl.size();
        }

        bool empty() const noexcept {
            return m_impl.empty();
        }

        T& operator[](std::size_t index) {
            return m_impl[index];
        }

        const T& operator[](std::size_t index) const {
            return m_impl[index];
        }

        T& front() {
            return m_impl.front();
        }

        T& back() {
            return m_impl.back();
        }

    private:
        std::vector<T, Allocator> m_impl;
    };

}
