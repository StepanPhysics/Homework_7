#include "list.hpp"
#include <gtest/gtest.h>
#include <gtest/gtest.h>
#include "list.hpp"


namespace otus {

TEST(ListTest, CanCreateContainer) {
    List<int> list;
    EXPECT_EQ(list.size(), 0); // Проверяем, что размер нового списка равен 0
    EXPECT_TRUE(list.empty()); // И что список действительно пуст
}

TEST(ListTest, CanInsertElementToEnd) {
    List<int> list;
    list.push_back(10);
    EXPECT_EQ(list.size(), 1); // После добавления одного элемента размер должен быть 1
    EXPECT_EQ(list.back(), 10); // Последний элемент в списке должен быть 10
}

TEST(ListTest, CanInsertElementToFront) {
    List<int> list;
    list.push_front(5);
    EXPECT_EQ(list.size(), 1); // После добавления одного элемента размер должен быть 1
    EXPECT_EQ(list.front(), 5); // Первый элемент в списке должен быть 5
}

TEST(ListTest, CanRemoveElementFromEnd) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_back(); // Удаляем элемент из конца
    EXPECT_EQ(list.size(), 1); // Размер должен быть уменьшен до 1
    EXPECT_EQ(list.back(), 1); // Последний элемент теперь должен быть 1
}

TEST(ListTest, CanRemoveElementFromFront) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_front(); // Удаляем элемент из начала
    EXPECT_EQ(list.size(), 1); // Размер должен быть уменьшен до 1
    EXPECT_EQ(list.front(), 2); // Первый элемент теперь должен быть 2
}

TEST(ListTest, FrontBackConsistency) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(list.front(), 1); // Первый элемент должен быть 1
    EXPECT_EQ(list.back(), 2);  // Последний элемент должен быть 2
}

TEST(ListTest, CanGetSize) {
    List<int> list;
    EXPECT_EQ(list.size(), 0);
    list.push_back(10);
    list.push_back(20);
    EXPECT_EQ(list.size(), 2); // Размер должен быть равен количеству добавленных элементов
}

TEST(ListTest, CanCopyContainer) {
    // Создание и заполнение исходного контейнера
    List<int> original;
    original.push_back(5);
    original.push_back(10);
    original.push_back(15);

    // Копирование контейнера
    List<int> copy = original;

    // Проверка: размеры контейнеров должны быть одинаковы
    EXPECT_EQ(copy.size(), original.size());

    // Проверка: содержимое контейнеров должно совпадать
    auto originalIt = original.begin();
    auto copyIt = copy.begin();
    while (originalIt != original.end() && copyIt != copy.end()) {
        EXPECT_EQ(*copyIt, *originalIt) << "Elements in lists differ.";
        ++originalIt;
        ++copyIt;
    }

    // Изменение копии должно не влиять на исходный контейнер
    if (!copy.empty()) {
        copy.front() = 20;
        EXPECT_NE(copy.front(), original.front()) << "Copy change affected original container.";
    }


}


} 
