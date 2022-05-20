#ifndef TSORGANLISTITEM_H
#define TSORGANLISTITEM_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QStringList>
#include <QScopedPointer>
class TsOrganListItemPrivate;
class TsOrganListItem : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(TsOrganListItem)

public:
    explicit TsOrganListItem(QWidget *parent = nullptr);
public:
    void setData(QString strName,QString strVolume,QString strColor);
signals:
private:

    QScopedPointer<TsOrganListItemPrivate> d_ptr;
};

#endif // TSORGANLISTITEM_H
