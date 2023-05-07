
#ifndef GAMETILE_H
#define GAMETILE_H


#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>


class GameTile : public QWidget
{
    Q_OBJECT
public:
    explicit GameTile(QWidget *parent = nullptr);
    void setTitle(const QString &title);
    void setCover(QPixmap pixmap);

signals:
private:
    QVBoxLayout *m_mainLay;
    QPixmap m_gameCoverPixmap;
    QLabel *m_gameCoverLbl;
    QLabel *m_gameTitleLbl;
};

#endif // GAMETILE_H
