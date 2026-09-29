#include "taskmanager.h"

/*
Конструктор TaskManager()
Вход: нет.
Предусловия: нет.
Процесс: установить nextTaskId и nextProjectId в 1. Репозитории должны быть пустыми. Если в предоставленном проекте предусмотрены начальные демонстрационные задачи и проекты, добавить их после инициализации счётчиков.
Выход: созданный объект TaskManager.
Постусловия: объект готов к добавлению задач и проектов; следующий создаваемый объект получает корректный идентификатор.
*/
TaskManager::TaskManager()
    : nextTaskId(1),
      nextProjectId(1)
{
}

/*
Добавить Задачу AddTask(string title, string description, string priority, string status)
Вход: название, описание, приоритет и статус новой задачи.
Предусловия: priority — "Low", "Medium" или "High"; status — "Todo", "In Progress" или "Done".
Процесс:
        1) взять текущее значение nextTaskId как идентификатор новой задачи;
        2) создать Task с этим идентификатором и title;
        3) установить описание, приоритет и статус;
        4) добавить задачу в taskRepository с помощью Add;
        5) увеличить nextTaskId на 1.

Выход: нет.
Постусловия: новая задача находится в taskRepository; её идентификатор равен старому значению nextTaskId; nextTaskId увеличен на 1.
*/
void TaskManager::AddTask(std::string title,
                          std::string description,
                          std::string priority,
                          std::string status)
{
    Task task(nextTaskId, title);

    nextTaskId++;

    task.SetDescription(description);
    task.SetPriority(priority);
    task.SetStatus(status);

    taskRepository.Add(task);
}

/*
Изменить Задачу UpdateTask(int index, string title, string description, string priority, string status)
Вход: индекс задачи и новые значения названия, описания, приоритета и статуса.
Предусловия: index находится в диапазоне от 0 до GetTasks().size()-1; приоритет и статус имеют допустимые значения.
Процесс:
        1) получить список задач из taskRepository;
        2) взять задачу с индексом index;
        3) изменить у этой задачи название, описание, приоритет и статус с помощью методов Task;
        4) передать изменённую задачу в taskRepository.Update(index, task).

Выход: нет.
Постусловия: задача с указанным индексом содержит новые данные; её идентификатор не изменён; количество задач не изменилось.
*/
void TaskManager::UpdateTask(int index,
                             std::string title,
                             std::string description,
                             std::string priority,
                             std::string status)
{
    std::vector<Task> tasks = taskRepository.GetAll();

    if (index < 0 || index >= static_cast<int>(tasks.size()))
    {
        return;
    }

    Task task = tasks[index];

    task.SetTitle(title);
    task.SetDescription(description);
    task.SetPriority(priority);
    task.SetStatus(status);

    taskRepository.Update(index, task);
}

/*
Удалить Задачу DeleteTask(int index)
Вход: индекс удаляемой задачи.
Предусловия: index находится в диапазоне от 0 до GetTasks().size()-1.
Процесс: вызвать Remove(index) для taskRepository.
Выход: нет.
Постусловия: задача с указанным индексом удалена; количество задач уменьшилось на 1.
*/
void TaskManager::DeleteTask(int index)
{
    taskRepository.Remove(index);
}

/*
Получить Задачи GetTasks()
Вход: нет.
Предусловия: нет.
Процесс: вызвать GetAll() у taskRepository и вернуть полученный вектор.
Выход: std::vector<Task> со всеми задачами в текущем порядке.
Постусловия: репозиторий не изменён.
*/
std::vector<Task> TaskManager::GetTasks()
{
    return taskRepository.GetAll();
}


/*
Добавить Проект AddProject(string name)
Вход: название нового проекта.
Предусловия: нет.
Процесс: 
        1) взять текущее значение nextProjectId; 
        2) создать Project с этим идентификатором и названием name; 
        3) добавить проект в projectRepository с помощью Add; 
        4) увеличить nextProjectId на 1.

Выход: нет.
Постусловия: новый проект находится в projectRepository; nextProjectId увеличен на 1.
*/
void TaskManager::AddProject(std::string name)
{
    Project project(nextProjectId, name);

    projectRepository.Add(project);

    nextProjectId++;
}

/*
Удалить Проект DeleteProject(int index)
Вход: индекс удаляемого проекта.
Предусловия: index находится в диапазоне от 0 до GetProjects().size()-1.
Процесс: вызвать Remove(index) для projectRepository.
Выход: нет.
Постусловия: проект с указанным индексом удалён; количество проектов уменьшилось на 1.
*/
void TaskManager::DeleteProject(int index)
{
    projectRepository.Remove(index);
}

/*
Получить Проекты GetProjects()
Вход: нет.
Предусловия: нет.
Процесс: вызвать GetAll() у projectRepository и вернуть полученный вектор.
Выход: std::vector<Project> со всеми проектами в текущем порядке.
Постусловия: репозиторий не изменён.
*/
std::vector<Project> TaskManager::GetProjects()
{
    return projectRepository.GetAll();
}