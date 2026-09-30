#include "task.h"

//  Конструктор

Task::Task(int id, std::string title, int projectId) : id(id), projectId(projectId), title(title), description(""), status("Todo"), priority("Medium")
{
}

//  Геттеры (константные методы)

int Task::GetId() const
{
    return id;
}

int Task::GetProjectId() const
{
    return projectId;
}

std::string Task::GetTitle() const
{
    return title;
}

std::string Task::GetDescription() const
{
    return description;
}

std::string Task::GetStatus() const
{
    return status;
}

std::string Task::GetPriority() const
{
    return priority;
}

//  Сеттеры

void Task::SetProjectId(int projectId)
{
    this->projectId = projectId;
}

void Task::SetTitle(std::string title)
{
    this->title = title;
}

void Task::SetDescription(std::string description)
{
    this->description = description;
}

void Task::SetStatus(std::string status)
{
    if (status == "Todo" || status == "In Progress" || status == "Done")
    {
        this->status = status;
    }
}

void Task::SetPriority(std::string priority)
{
    if (priority == "Low" || priority == "Medium" || priority == "High")
    {
        this->priority = priority;
    }
}