
#ifndef TOPBAR_H
#define TOPBAR_H


#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>


class TopBar : public QWidget
{
    Q_OBJECT
public:
    explicit TopBar(QWidget *parent = nullptr);

signals:

private:
    QHBoxLayout *m_mainLay;
    QLabel *m_logoLbl;
    QLineEdit *m_findTxtEdit;
    QLabel *m_profileLbl;
    QPixmap m_logoPixmap;
    QPixmap m_avatarPixmap;
};

#endif // TOPBAR_H
