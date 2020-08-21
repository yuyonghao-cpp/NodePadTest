#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QtGui/QMainWindow>
#include <QKeySequence>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QPlainTextEdit>
#include <QLabel>
#include <QFileDialog>


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QPlainTextEdit mainEditor;
    QLabel statusLbl;
    QString m_filePath;
    bool m_isTextChanged;

    MainWindow();
    MainWindow(const MainWindow&);
    MainWindow& operator= (const MainWindow&);

    bool construct();
    bool initMenuBar();
    bool initToolBar();
    bool initStatusBar();
    bool initMainEditor();
    bool initFileMenu(QMenuBar* mb);
    bool initEditMenu(QMenuBar* mb);
    bool initFormatMenu(QMenuBar* mb);
    bool initViewMenu(QMenuBar* mb);
    bool initHelpMenu(QMenuBar* mb);
    bool initFileToolItem(QToolBar* tb);
    bool initEditToolItem(QToolBar* tb);
    bool initFormatToolItem(QToolBar* tb);
    bool initViewToolItem(QToolBar* tb);
    bool makeAction(QAction*& action, QWidget* parent, QString text, int key);
    bool makeAction(QAction*& action, QWidget* parent, QString tip, QString icon);

    QString showFileDialog(QFileDialog::AcceptMode mode, QString title);
    int showQueryMessage(QString message);
    void showErrorMessage(QString message);
    QString saveCurrentData(QString path = "");
    void preEditorChange();
protected:
    void closeEvent(QCloseEvent* e);
private slots:
    void onFileNew();
    void onFileOpen();
    void onFileSave();
    void onFileSaveAs();
    void onTextChanged();
public:
    static MainWindow* NewInstance();
    ~MainWindow();
};

#endif // _MAINWINDOW_H_
