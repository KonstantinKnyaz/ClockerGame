#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QTimer>
#include <QCloseEvent>
#include "clickergame.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    /*!
     * \brief Clicker указатель на объект хранения кликов
     */
    ClickerGame *Clicker;
    /*!
     * \brief startGame функция начала игры
     */
    void startGame();
    /*!
     * \brief stopGame функция остановки игры и сброса счётчиков
     */
    void stopGame();
    /*!
     * \brief connections функция с коннектами кнопок
     */
    void connections();
    /*!
     * \brief eventFilter ивент фильтр для остлеживания ивентов
     * \param watched в каком объекте следит
     * \param event ивент
     * \return true - если был клик мышкой, в ином случе false
     */
    bool eventFilter(QObject *watched, QEvent *event) override;
    /*!
     * \brief closeEvent ивент закрытия приложения
     * \param event ивент
     */
    void closeEvent(QCloseEvent *event);
    /*!
     * \brief gameIsStarted флаг отслеживающий начало игры
     */
    bool gameIsStarted;
    /*!
     * \brief timer указатель на таймер
     */
    QTimer *timer;
    /*!
     * \brief randomClick рандомное число кликов
     */
    unsigned int randomClick;
};

#endif // MAINWINDOW_H
