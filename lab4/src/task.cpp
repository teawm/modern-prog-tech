#include "task.h"
/*
Конструктор Task(int id, string title)
Вход: идентификатор и название.
Предусловия: нет.
Процесс: присвоить id переданный идентификатор; присвоить title переданное название; установить description в пустую строку; установить status в "Todo"; установить priority в "Medium".
Выход: созданный объект Task.
Постусловия: все пять полей объекта имеют определённые значения.
*/
Task::Task(int id, std::string title) : id(id), title(title), description(""),status("Todo"), priority("Medium")
{
}

/*
Получить Идентификатор GetId()
Вход: нет.
Предусловия: объект Task существует.
Процесс: вернуть значение приватного поля id.
Выход: целое число.
Постусловия: данные объекта не изменены.
*/
int Task::GetId()
{
    return id;
}

/*
Получить Название GetTitle()
Вход: нет.
Предусловия: объект Task существует.
Процесс: вернуть значение поля title .
Выход: строка.
Постусловия: данные объекта не изменены.
*/
std::string Task::GetTitle()
{
    return title;
}

/*
Получить Описание GetDescription()
Вход: нет.
Предусловия: объект Task существует.
Процесс: вернуть значение поля description.
Выход: строка.
Постусловия: данные объекта не изменены.
*/
std::string Task::GetDescription()
{
    return description;
}

/*
Получить Статус GetStatus()
Вход: нет.
Предусловия: объект Task существует.
Процесс: вернуть значение поля status.
Выход: строка.
Постусловия: данные объекта не изменены.
*/
std::string Task::GetStatus()
{
    return status;
}

/*
Получить Приоритет GetPriority()
Вход: нет.
Предусловия: объект Task существует.
Процесс: вернуть значение поля priority .
Выход: строка.
Постусловия: данные объекта не изменены.
*/
std::string Task::GetPriority()
{
    return priority;
}

/*
Установить Название SetTitle(string title)
Вход: новое название.
Предусловия: нет.
Процесс: заменить текущее значение поля title переданным значением.
Выход: нет.
Постусловия: GetTitle() возвращает новое название.
*/
void Task::SetTitle(std::string title)
{
    this->title = title;
}

/*
Установить Описание SetDescription(string description)
Вход: новое описание.
Предусловия: нет.
Процесс: заменить текущее значение поля description переданным значением.
Выход: нет.
Постусловия: GetDescription() возвращает новое описание.
*/
void Task::SetDescription(std::string description)
{
    this->description = description;
}

/*
Установить Статус SetStatus(string status)
Вход: новый статус.
Предусловия: значение равно "Todo", "In Progress" или "Done".
Процесс: проверить допустимость значения; если оно допустимо, заменить поле status новым значением.
Выход: нет.
Постусловия: GetStatus() возвращает переданный статус.
*/
void Task::SetStatus(std::string status)
{
    if (status == "Todo" || status == "In Progress" || status == "Done")
    {
        this->status = status;
    }
}

/*
Установить Приоритет SetPriority(string priority)
Вход: новый приоритет.
Предусловия: значение равно "Low", "Medium" или "High".
Процесс: проверить допустимость значения; если оно допустимо, заменить поле priority новым значением.
Выход: нет.
Постусловия: GetPriority() возвращает переданный приоритет.
*/
void Task::SetPriority(std::string priority)
{
    if (priority == "Low" || priority == "Medium" || priority == "High")
    {
        this->priority = priority;
    }
}