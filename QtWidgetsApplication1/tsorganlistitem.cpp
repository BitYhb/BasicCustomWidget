#include "tsorganlistitem.h"
#include <QHBoxLayout>
#include <QSpacerItem>


class TsOrganListItemPrivate
{
    Q_DECLARE_PUBLIC(TsOrganListItem);
public:
    TsOrganListItemPrivate(TsOrganListItem* object);
private:
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

    TsOrganListItem* q_ptr;
};
// TsOrganListItemPrivate methods 
TsOrganListItemPrivate::TsOrganListItemPrivate(TsOrganListItem *object)
    : q_ptr(object)
    , m_organNameButton(new QPushButton(object))
    , m_organNameLabel(new QLabel(object))
    , m_volumeLabel(new QLabel(object))
    , m_delButton(new QPushButton(object))
    , m_visibleButton(new QPushButton(object))
    , m_organName("")
    , m_organVolume("")
    , m_organColor("")
{}
void TsOrganListItemPrivate::initUI()
{
    Q_Q(TsOrganListItem);

    q->setFixedHeight(33);
    q->setFixedWidth(280);
    //layout
    QHBoxLayout *hboxlayout = new QHBoxLayout(q);
    hboxlayout->setSpacing(10);
    //size
    m_organNameButton->setMaximumSize(QSize(12, 12));
    m_organNameButton->setMinimumSize(QSize(12, 12));
    m_organNameButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    QFont font;
    font.setFamily("PingFang SC");
    font.setPixelSize(12);
    m_organNameLabel->setMinimumWidth(80);
    m_organNameLabel->setFont(font);
    m_organNameLabel->setStyleSheet("color:white");
    m_organNameLabel->setAlignment(Qt::AlignHCenter);
    m_organNameLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    m_volumeLabel->setMinimumWidth(80);
    m_volumeLabel->setFont(font);
    m_volumeLabel->setStyleSheet("color:white");
    m_volumeLabel->setAlignment(Qt::AlignHCenter);
    m_volumeLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    m_delButton->setMaximumSize(QSize(14, 14));
    m_delButton->setStyleSheet(
        "QPushButton{background:url(:/resources/svg/del.svg) center no-repeat;background-color:transparent;}"
        "QPushButton::hover{background:url(:/del.svg);background-color:transparent;}");
    m_delButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    m_visibleButton->setMaximumSize(QSize(14, 14));
    m_visibleButton->setStyleSheet(
        "QPushButton{background:url(:/resources/svg/eyes.svg) center no-repeat;background-color:transparent;}"
        "QPushButton::hover{background:url(:/eyes.svg);background-color:transparent;}");
    m_visibleButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    hboxlayout->addWidget(m_organNameButton);
    hboxlayout->addWidget(m_organNameLabel);
    hboxlayout->addWidget(m_volumeLabel);
    hboxlayout->addWidget(m_delButton);
    hboxlayout->addWidget(m_visibleButton);

    q->setLayout(hboxlayout);
}

TsOrganListItem::TsOrganListItem(QWidget *parent)
    : QWidget{parent}
    , d_ptr(new TsOrganListItemPrivate(this))
{
    Q_D(TsOrganListItem);
    d->initUI();
}

void TsOrganListItem::setData(QString strName, QString strVolume, QString strColor)
{
    Q_D(TsOrganListItem);
    d->m_organName = strName;
    d->m_organVolume = strVolume;
    d->m_organColor = strColor;
    d->m_organNameButton->setStyleSheet(QString("QPushButton{background: %1;rad;border-radius:6px}").arg(d->m_organColor));
    d->m_organNameLabel->setText(d->m_organName);
    d->m_volumeLabel->setText(d->m_organVolume);
}
