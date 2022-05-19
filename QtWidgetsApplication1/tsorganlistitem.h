#ifndef TSORGANLISTITEM_H
#define TSORGANLISTITEM_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QStringList>
class TsOrganListItemPrivate;
class TsOrganListItem : public QWidget
{
    Q_OBJECT
public:
    explicit TsOrganListItem(QWidget *parent = nullptr);
public:
    void setData(QString strName,QString strVolume,QString strColor);
signals:
private:
    void init();
    void initUI();
private:
    QPushButton *m_organNameButton;
    QLabel *m_organNameLabel;
    QLabel *m_volumeLabel;
    QPushButton *m_delButton;
    QPushButton *m_visibleButton;

    QString m_organName;
    QString m_organVolume;
    QString m_organColor;

    QScopedPointer<TsOrganListItem> d_ptr;
    Q_DECLARE_PRIVATE(TsOrganListItem)
};

#endif // TSORGANLISTITEM_H
