#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>

template <class T>
class Repository
{
private:
    std::vector<T> items;

public:
    void Add(T item);
    void Remove(int index);
    void Update(int index, T item);
    int Size();
    std::vector<T> GetAll();
    void Clear();
};

/*
Добавить Add(T item)
Вход: объект item типа T.
Предусловия: нет.
Процесс: добавить item в конец вектора items с помощью операции push_back.
Выход: нет.
Постусловия: новый объект находится в конце репозитория; количество объектов увеличилось на 1.
*/
template <class T>
void Repository<T>::Add(T item)
{
    items.push_back(item);
}

/*
Удалить Remove(int index)
Вход: индекс объекта index.
Предусловия: index находится в диапазоне от 0 до Size()-1.
Процесс: удалить элемент вектора items с указанным индексом. Для удаления элемента из std::vector использовать erase.
Выход: нет.
Постусловия: объект с указанным индексом удалён; количество объектов уменьшилось на 1.
*/
template <class T>
void Repository<T>::Remove(int index)
{
    if (index >= 0 && index < static_cast<int>(items.size()))
    {
        items.erase(items.begin() + index);
    }
}

/*
Изменить Update(int index, T item)
Вход: индекс index и новый объект item типа T.
Предусловия: index находится в диапазоне от 0 до Size()-1.
Процесс: заменить элемент items[index] переданным объектом item.
Выход: нет.
Постусловия: объект с индексом index заменён; количество объектов не изменилось.
*/
template <class T>
void Repository<T>::Update(int index, T item)
{
    if (index >= 0 && index < static_cast<int>(items.size()))
    {
        items[index] = item;
    }
}

/*
Получить Количество Size()
Вход: нет.
Предусловия: нет.
Процесс: получить количество элементов вектора items с помощью size() и вернуть это значение.
Выход: целое число.
Постусловия: данные репозитория не изменены.
*/
template <class T>
int Repository<T>::Size()
{
    return static_cast<int>(items.size());
}

/*
Получить Все GetAll()
Вход: нет.
Предусловия: нет.
Процесс: вернуть копию вектора items.
Выход: std::vector<T>, содержащий все объекты репозитория в текущем порядке.
Постусловия: данные репозитория не изменены.
*/
template <class T>
std::vector<T> Repository<T>::GetAll()
{
    return items;
}

/*
Очистить Clear()
Вход: нет.
Предусловия: нет.
Процесс: удалить все элементы из items с помощью clear().
Выход: нет.
Постусловия: репозиторий пуст; Size() возвращает 0.
*/
template <class T>
void Repository<T>::Clear()
{
    items.clear();
}

#endif