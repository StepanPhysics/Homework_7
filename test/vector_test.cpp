#include <gtest/gtest.h>
#include "vector.hpp"

namespace otus {

TEST(VectorTest, CanCreateContainer) {
    Vector<int> vec;
    EXPECT_EQ(vec.size(), 0); // Проверяем, что новый вектор пуст
    EXPECT_TRUE(vec.empty()); // Убеждаемся, что метод empty возвращает true
}

TEST(VectorTest, CanInsertElementToEnd) {
    Vector<int> vec;
    vec.push_back(10);
    EXPECT_EQ(vec.size(), 1); // Убедитесь, что размер равен 1 после добавления одного элемента
    EXPECT_EQ(vec.back(), 10); // Последний элемент должен быть равен 10
}

TEST(VectorTest, CanRemoveElementFromEnd) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.pop_back(); // Удаляем элемент с конца
    EXPECT_EQ(vec.size(), 1); // Размер должен быть 1
    EXPECT_EQ(vec.back(), 1); // Последний элемент должен быть равен 1
}

TEST(VectorTest, FrontBackConsistency) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    EXPECT_EQ(vec.front(), 1); // Первый элемент должен быть равен 1
    EXPECT_EQ(vec.back(), 2);  // Последний элемент должен быть равен 2
}

TEST(VectorTest, CanAccessByIndex) {
    Vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    EXPECT_EQ(vec[0], 5); // Доступ по индексу 0 должен вернуть 5
    EXPECT_EQ(vec[1], 10); // Доступ по индексу 1 должен вернуть 10
}

TEST(VectorTest, CanGetSize) {
    Vector<int> vec;
    EXPECT_EQ(vec.size(), 0);
    vec.push_back(10);
    vec.push_back(20);
    EXPECT_EQ(vec.size(), 2); // Размер должен равняться количеству добавленных элементов
}

TEST(VectorTest, CanCopyContainer) {
    // Создание и заполнение исходного контейнера
    Vector<int> original;
    original.push_back(5);
    original.push_back(10);
    original.push_back(15);

    // Копирование контейнера
    Vector<int> copy = original;

    // Проверка: размеры контейнеров должны быть одинаковы
    EXPECT_EQ(copy.size(), original.size());

    // Проверка: содержимое контейнеров должно совпадать
    for (std::size_t i = 0; i < original.size(); ++i) {
        EXPECT_EQ(copy[i], original[i]) << "Elements at index " << i << " differ.";
    }

    // Изменение копии должно не влиять на исходный контейнер
    copy[0] = 20;
    EXPECT_NE(copy[0], original[0]) << "Copy change affected original container.";
}

} 
