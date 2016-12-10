#pragma once

#include <QMainWindow>
#include <QTreeWidget>
#include <QStandardItem>
#include <QStandardItemModel>
#include "TaskModel.hpp"
#include "Vizkit3dPluginRepository.hpp"
#include <vizkit3d/Vizkit3DWidget.hpp>

namespace Ui {
    class MainWindow;
}

namespace RTT {
    namespace corba {
        class TaskContextProxy;
    }
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void prepareMenu(const QPoint &pos);
    void handleOutputPort(QObject *obj);
    void queryTasks();
    void activateTask();
    void startTask();
    void stopTask();
    void configureTask();

private:
    Ui::MainWindow *ui;
    QTreeView *view;
    TaskModel *model;
    RTT::corba::TaskContextProxy *task;
    vizkit3d::Vizkit3DWidget widget3d;
    Vizkit3dPluginRepository *pluginRepo;
};
