#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QWindow>

#include "guide/guide_widget.h"

class BackgroundDlg final : public QDialog {
public:
    explicit BackgroundDlg(QWidget *parent = nullptr) : QDialog(parent), guideWidget(new GuideWidget(this))
    {
        this->resize(800, 600);
        auto btn = new QPushButton("Show Guide", this);
        btn->setGeometry(10, 10, 100, 30);
    }

protected:
    void showEvent(QShowEvent *event) override
    {
        QDialog::showEvent(event);
        guideWidget->setFixedSize(this->size());
        guideWidget->setTarget({QPoint(10, 10), QSize(100, 30)});
        guideWidget->show();
        guideWidget->windowHandle()->setTransientParent(this->windowHandle());
    }
    void hideEvent(QHideEvent *event) override
    {
        QDialog::hideEvent(event);
        guideWidget->hide();
    }
    void closeEvent(QCloseEvent *event) override
    {
        QDialog::closeEvent(event);
        guideWidget->close();
    }
    void resizeEvent(QResizeEvent *event) override
    {
        QDialog::resizeEvent(event);
        guideWidget->setFixedSize(this->size());
        // guideWidget->windowHandle()->setTransientParent(this->windowHandle());
    }
    void moveEvent(QMoveEvent *event) override
    {
        QDialog::moveEvent(event);
        guideWidget->setGeometry(this->geometry());
        // guideWidget->windowHandle()->setTransientParent(this->windowHandle());
    }

    GuideWidget *guideWidget = nullptr;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BackgroundDlg dlg;
    dlg.show();

    return QApplication::exec();
}