#ifndef TSNODULELISITEM_H
#define TSNODULELISITEM_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QStringList>
#include <QComboBox>
class TsNoduleListItemPrivate;
class TsNoduleListItem : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(TsNoduleListItem);
public:
    explicit TsNoduleListItem(QWidget *parent = nullptr);
public:
    void setData(QString strName, QStringList strVolume, QString strColor);
    QString organName() const;
    QStringList typeList() const;
    QString organColor() const;
signals:
private:
    QScopedPointer<TsNoduleListItemPrivate> d_ptr;
};

#endif // TSORGANLISTITEM_H
