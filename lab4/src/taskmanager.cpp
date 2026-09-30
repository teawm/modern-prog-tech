#include "taskmanager.h"

TaskManager::TaskManager()
    : nextTaskId(1),
      nextProjectId(1)
{
}

void TaskManager::AddTask(std::string title,
                          std::string description,
                          std::string priority,
                          std::string status,
                          int projectId)
{
    Task task(nextTaskId, title, projectId);
    nextTaskId++;

    task.SetDescription(description);
    task.SetPriority(priority);
    task.SetStatus(status);

    taskRepository.Add(task);
}

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

void TaskManager::DeleteTask(int index)
{
    taskRepository.Remove(index);
}

std::vector<Task> TaskManager::GetTasks()
{
    return taskRepository.GetAll();
}

bool TaskManager::MoveTaskToProject(int taskIndex, int projectId)
{
    std::vector<Task> tasks = taskRepository.GetAll();

    if (taskIndex < 0 || taskIndex >= static_cast<int>(tasks.size()))
    {
        return false;
    }

    if (projectId != 0)
    {
        std::vector<Project> projects = projectRepository.GetAll();
        bool projectExists = false;
        for (auto& p : projects)
        {
            if (p.getId() == projectId)
            {
                projectExists = true;
                break;
            }
        }
        if (!projectExists)
        {
            return false;
        }
    }

    Task task = tasks[taskIndex];
    task.SetProjectId(projectId);
    taskRepository.Update(taskIndex, task);

    return true;
}

int TaskManager::CountTasksInProject(int projectId)
{
    std::vector<Task> tasks = taskRepository.GetAll();
    int count = 0;
    for (const auto& task : tasks)
    {
        if (task.GetProjectId() == projectId)
        {
            count++;
        }
    }
    return count;
}

int TaskManager::CountTasksInProjectByStatus(int projectId, std::string status)
{
    std::vector<Task> tasks = taskRepository.GetAll();
    int count = 0;
    for (const auto& task : tasks)
    {
        if (task.GetProjectId() == projectId && task.GetStatus() == status)
        {
            count++;
        }
    }
    return count;
}

double TaskManager::CompletionPercent(int projectId)
{
    int totalTasks = CountTasksInProject(projectId);
    if (totalTasks == 0)
    {
        return 0.0;
    }

    int doneTasks = CountTasksInProjectByStatus(projectId, "Done");
    return 100.0 * static_cast<double>(doneTasks) / static_cast<double>(totalTasks);
}

void TaskManager::AddProject(std::string name)
{
    Project project(nextProjectId, name);
    projectRepository.Add(project);
    nextProjectId++;
}

void TaskManager::DeleteProject(int index)
{
    std::vector<Project> projects = projectRepository.GetAll();

    if (index < 0 || index >= static_cast<int>(projects.size()))
    {
        return;
    }

    int projectIdToDelete = projects[index].getId();

    std::vector<Task> tasks = taskRepository.GetAll();
    for (int i = static_cast<int>(tasks.size()) - 1; i >= 0; --i)
    {
        if (tasks[i].GetProjectId() == projectIdToDelete)
        {
            taskRepository.Remove(i);
        }
    }

    projectRepository.Remove(index);
}

std::vector<Project> TaskManager::GetProjects()
{
    return projectRepository.GetAll();
}