    // Copyright 2017 Kozlov Ilya

#include <gtest/gtest.h>

#include <string>
#include <algorithm>

#include "include/todo_list.h"

TEST(TODOListTest, TODOListDefaultCanBeCreated) {
    // Arrangef
    // Act
    // Assert
    ASSERT_NO_FATAL_FAILURE(TODOList ListToTest);
}

TEST(TODOListTest, TODOListCanBeCreated) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_FATAL_FAILURE(TODOList ListToTest("ListToTest"));
}

TEST(TODOListTest, NewTaskCanBeCreated) {
    // Arrange
    TODOList ListToTest;
    // Act
    // Assert
    ASSERT_NO_FATAL_FAILURE(ListToTest.NewTask());
}

TEST(TODOListTest, NewTaskCanBeCreatedWithStringArg) {
    // Arrange
    TODOList ListToTest;
    const std::string testname = "To test the constructor";
    // Act
    // Assert
    ASSERT_NO_FATAL_FAILURE(ListToTest.NewTask(testname););
}

TEST(TODOListTest, TaskCanBeDeletedInTODOList) {
    // Arrange
    TODOList ListToTest;
    // Act
    ListToTest.NewTask();
    // Assert
    ASSERT_NO_FATAL_FAILURE(ListToTest.DeleteTask(1));
}

TEST(TODOListTest, TODOListCanBeCleared) {
    // Arrange
    TODOList ListToTest;
    // Act
    ListToTest.NewTask();
    // Assert
    ASSERT_NO_FATAL_FAILURE(ListToTest.ClearList());
}

TEST(TODOListTest, TaskCanBeRenamedInTODOList) {
    // Arrange
    const std::string testname = "To test the renaming";
    TODOList ListToTest;
    // Act
    ListToTest.NewTask();
    // Assert
    ASSERT_NO_FATAL_FAILURE(ListToTest.RenameTask(1, testname););
}

TEST(TODOListTest, TODOListCanBeShownWithoutTasks) {
    // Arrange
    TODOList ListToTest;
    // Act
    // Assert
    ASSERT_NO_FATAL_FAILURE(ListToTest.ShowTODOList());
}

TEST(TODOListTest, TODOListCanBeShownWithTasks) {
    // Arrange
    TODOList ListToTest("Today's plan");
    // Act
    ListToTest.NewTask("To test the ShowTodoListMethod");
    ListToTest.NewTask("To add some tasks");
    ListToTest.NewTask("To make this one done");
    ListToTest.SetTaskDone(3);
    // Assert
    ASSERT_NO_FATAL_FAILURE(ListToTest.ShowTODOList());
}

TEST(TODOListTest, TODOListCanBeUnlimitedAndUnlimited) {
    // Arrange
    TODOList ListToTest;
    // Act
    ListToTest.LimitTasksCount(1);
    ListToTest.UnlimitTasksCount();
    // Assert
    ASSERT_NO_FATAL_FAILURE({
        ListToTest.LimitTasksCount(1);
        ListToTest.UnlimitTasksCount();
    });
}

TEST(TODOListTest, TODOListCanBeSetDoneAndUndone) {
    // Arrange
    TODOList ListToTest;
    // Act
    ListToTest.NewTask();
    // Assert
    ASSERT_NO_FATAL_FAILURE({
        ListToTest.SetTaskDone(1);
        ListToTest.SetTaskUndone(1);
    });
}

TEST(TODOListTest, TasksPosCanBeChangedInTODOList) {
    // Arrange
    TODOList ListToTest;
    // Act
    ListToTest.NewTask();
    ListToTest.NewTask();
    // Assert
    ASSERT_NO_FATAL_FAILURE(ListToTest.ChangeTasksPosition(1, 2));
}

TEST(TODOListTest, ParamsCanBeGot) {
    // Arrange
    TODOList ListToTest;
    ListToTest.NewTask();
    // Act
    // Assert
    ASSERT_NO_FATAL_FAILURE({
        ListToTest.GetCurrentTasksValue();
        ListToTest.GetMaxTaskValue();
        ListToTest.GetTaskStatus(1);
        ListToTest.GetTaskName(1);
        ListToTest.GetTODOListName();
    });
}

TEST(TODOListTest, TODOListParamConstrIsWorkingCorrectly) {
    // Arrange
    const std::string todolistname = "To test the working of constructor";
    // Act
    TODOList ListToTest(todolistname);
    // Assert
    ASSERT_EQ(todolistname, ListToTest.GetTODOListName());
}

TEST(TODOListTest, ParamNewTaskIsWorkingCorrectly) {
    // Arrange
    const std::string tasktestname = "To test the New() method";
    TODOList ListToTest;
    // Act
    ListToTest.NewTask(tasktestname);
    // Assert
    ASSERT_EQ(tasktestname, ListToTest.GetTaskName(1));
}

TEST(TODOListTest, DeleteIsWorkingCorrectly) {
    // Arrange
    const std::string taskname1 = "Task1";
    const std::string taskname2 = "Task2";
    TODOList ListToTest;
    ListToTest.NewTask(taskname1);
    ListToTest.NewTask(taskname2);
    // Act
    ListToTest.DeleteTask(1);
    // Assert
    ASSERT_EQ(taskname2, ListToTest.GetTaskName(1));
}

TEST(TODOListTest, ClearListIsWorkingCorrectly) {
    // Arrange
    const int expectedlen = 0;
    const int testlen = 42;
    TODOList ListToTest;
    // Act
    for (int i = 0; i < testlen; i++) {
        ListToTest.NewTask();
    }
    ListToTest.ClearList();
    // Assert
    ASSERT_EQ(expectedlen, ListToTest.GetCurrentTasksValue());
}

TEST(TODOListTest, TaskRenamingIsWorkingCorrectly) {
    // Arrange
    const std::string expectedname = "To test renaming's work";
    TODOList ListToTest;
    // Act
    ListToTest.NewTask();
    ListToTest.RenameTask(1, expectedname);
    // Assert
    ASSERT_EQ(expectedname, ListToTest.GetTaskName(1));
}

TEST(TODOListTest, LimitingTaskCountIsWorkingCorrectly) {
    // Arrange
    const int expectedlen = 42;
    TODOList ListToTest;
    // Act
    ListToTest.LimitTasksCount(expectedlen);
    for (int i = 0; i < expectedlen * expectedlen; i++) {
        ListToTest.NewTask();
    }
    // Assert
    ASSERT_EQ(expectedlen, ListToTest.GetMaxTaskValue());
}


TEST(TODOListTest, LimitingTaskCountToSmaller) {
    // Arrange
    const int oldlen = 10;
    TODOList ListToTest;
    // Act
    for (int i = 0; i < 10; i++) {
        ListToTest.NewTask();
    }
    ListToTest.LimitTasksCount(oldlen / 2);
    const int newlen = ListToTest.GetCurrentTasksValue();
    // Assert
    ASSERT_EQ(oldlen/2, newlen);
}

TEST(TODOListTest, UnlimitingTaskCountIsWorkingCorrectly) {
    // Arrange
    const int limitedlen = 10;
    TODOList ListToTest;
    const std::size_t expectedlen = ListToTest.GetMaxTaskValue();
    // Act
    for (int i = 0; i < 10; i++) {
        ListToTest.NewTask();
    }
    ListToTest.LimitTasksCount(limitedlen / 2);
    ListToTest.UnlimitTasksCount();
    std::size_t newlen = ListToTest.GetMaxTaskValue();
    // Assert
    ASSERT_EQ(expectedlen, newlen);
}

TEST(TODOListTest, ForbiddenParamsForMethods) {
    // Arrange
    const std::string tasknameparam = "To test the class";
    const int toolarge = 42;
    const int toolow = -42;
    TODOList ListToTest;
    ListToTest.NewTask();
    // Act
    // Assert
    ASSERT_NO_FATAL_FAILURE({
        // deleting
        ListToTest.DeleteTask(toolarge);
        ListToTest.DeleteTask(toolow);
        // renaming
        ListToTest.RenameTask(toolarge, tasknameparam);
        ListToTest.RenameTask(toolow, tasknameparam);
        // limiting
        ListToTest.LimitTasksCount(toolarge);
        ListToTest.LimitTasksCount(toolow);
        // setting done
        ListToTest.SetTaskDone(toolarge);
        ListToTest.SetTaskDone(toolow);
        // setting undone
        ListToTest.SetTaskUndone(toolarge);
        ListToTest.SetTaskUndone(toolow);
        // changing position
        ListToTest.ChangeTasksPosition(toolarge, toolow);
        ListToTest.ChangeTasksPosition(toolow, toolarge);
        ListToTest.ChangeTasksPosition(toolarge, toolarge);
        ListToTest.ChangeTasksPosition(toolow, toolow);
    });
}

TEST(TODOListTest, ChangeTaskPosIsWorkingCorrectly1) {
    // Arrange
    const std::string taskpos1 = "TaskPos1";
    const std::string taskpos2 = "TaskPos2";
    TODOList ListToTest;
    ListToTest.NewTask(taskpos1);
    ListToTest.NewTask(taskpos2);
    // Act
    ListToTest.ChangeTasksPosition(1, 2);
    // Assert
    ASSERT_EQ(taskpos2, ListToTest.GetTaskName(1));
}

TEST(TODOListTest, ChangeTaskPosIsWorkingCorrectly2) {
    // Arrange
    const std::string taskpos1 = "TaskPos1";
    const std::string taskpos2 = "TaskPos2";
    const std::string taskpos3 = "TaskPos3";
    TODOList ListToTest;
    ListToTest.NewTask(taskpos1);
    ListToTest.NewTask(taskpos2);
    ListToTest.NewTask(taskpos3);
    // Act
    ListToTest.ChangeTasksPosition(3, 2);
    // Assert
    ASSERT_EQ(taskpos3, ListToTest.GetTaskName(2));
}

TEST(TODOListTest, ThrowForWrongParamsForGetName) {
    // Arrange
    const int wrong = 42;
    TODOList ListToTest;
    // Act
    // Assert
    ASSERT_ANY_THROW(ListToTest.GetTaskName(wrong));
}

TEST(TODOListTest, ThrowForWrongParamsForGetStatus) {
    // Arrange
    const int wrong = 42;
    TODOList ListToTest;
    // Act
    // Assert
    ASSERT_ANY_THROW(ListToTest.GetTaskStatus(wrong));
}
