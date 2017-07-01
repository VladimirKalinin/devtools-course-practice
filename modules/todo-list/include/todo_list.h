// Copyright 2017 Kozlov Ilya

#ifndef MODULES_TODO_LIST_INCLUDE_TODO_LIST_H_
#define MODULES_TODO_LIST_INCLUDE_TODO_LIST_H_

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

enum TaskStatus { UNDONE_TASK, DONE_TASK };

class TODOList {
 public:
    TODOList();
    explicit TODOList(const std::string _users_todo_list_name);

    void NewTask();
    void NewTask(const std::string _new_task_name);
    void DeleteTask(const std::size_t _task_index);
    void ClearList();
    void RenameTask(const std::size_t _task_index,
                    const std::string _new_task_name);
    void ShowTODOList();
    void LimitTasksCount(const std::size_t _new_limit);
    void UnlimitTasksCount();
    void SetTaskDone(const std::size_t _task_index);
    void SetTaskUndone(const std::size_t _task_index);
    void ChangeTasksPosition(const std::size_t _current_postiton,
                             const std::size_t _new_position);
    const std::size_t GetMaxTaskValue();
    const std::size_t GetCurrentTasksValue();
    std::string GetTaskName(const std::size_t _task_index);
    TaskStatus GetTaskStatus(const std::size_t _task_index);
    std::string GetTODOListName();

 private:
    class TODOTask {
     public:
        TODOTask();
        explicit TODOTask(const std::string _users_task_name);
        void Rename(const std::string _new_task_name);
        void SetDone();
        void SetUndone();
        std::string GetTaskName();
        TaskStatus GetTaskStatus();
     private:
        std::string task_name_ = "New Task";
        TaskStatus task_status_ = UNDONE_TASK;
    };
    std::vector<TODOTask> data_list_ = {};
    std::size_t max_tasks_value_ = data_list_.max_size();
    std::string todo_list_name_ = "";
};
#endif  // MODULES_TODO_LIST_INCLUDE_TODO_LIST_H_
