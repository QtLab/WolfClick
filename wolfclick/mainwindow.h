#pragma once

#include <QMainWindow>
#include <QPoint>

namespace Ui {
class MainWindow;
}
class QBytreArray;
class QTimer;
class CustomWidget;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    

    bool isRecording();
    bool isPlaying();
    void addMouseClick(int x, int y);
    void stop();

    struct MouseFrame
    {
        MouseFrame(){}
        MouseFrame(int x, int y):pos(x,y){}
        QPoint pos;
    };

public slots:
    void onMouseClicked( int x, int y );
    void on_pushButton_clicked();
    void on_actionQuit_triggered();
    void on_actionRecord_toggled(bool on);
    void on_actionPlay_toggled(bool on);
    void on_actionStop_triggered();
    void on_actionClear_triggered();
    void onTimerTimeout();

private:
    virtual void closeEvent(QCloseEvent *event);
    virtual bool nativeEvent(const QByteArray &eventType, void *message, long *result);
    Ui::MainWindow *ui;
    CustomWidget* w;
    QTimer* m_timer;
    bool m_isRecording;
    bool m_isPlaying;
    int m_mouseFrameIndex;
};
Q_DECLARE_METATYPE(MainWindow::MouseFrame)

