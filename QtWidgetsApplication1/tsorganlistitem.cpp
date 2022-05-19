#include "tsorganlistitem.h"
#include <QHBoxLayout>
#include <QSpacerItem>


class TsOrganListItemPrivate
{
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
};


TsOrganListItem::TsOrganListItem(QWidget *parent)
    : QWidget{parent}
{
    init();
    initUI();
}

void TsOrganListItem::setData(QString strName, QString strVolume, QString strColor)
{
    m_organName = strName;
    m_organVolume = strVolume;
    m_organColor = strColor;

    m_organNameButton->setStyleSheet(QString("QPushButton{background: %1;rad;border-radius:6px}").arg(m_organColor));
    m_organNameLabel->setText(m_organName);
    m_volumeLabel->setText(m_organVolume);
}

void TsOrganListItem::init()
{
    m_organNameButton = new QPushButton(this);
    m_organNameLabel = new QLabel(this);
    m_volumeLabel = new QLabel(this);
    m_delButton = new QPushButton(this);
    m_visibleButton = new QPushButton(this);
}

void TsOrganListItem::initUI()
{
    //this
    setFixedHeight(33);
    setFixedWidth(280);
    //layout
    QHBoxLayout *hboxlayout = new QHBoxLayout(this);
    hboxlayout->setSpacing(10);
    //size
    m_organNameButton->setMaximumSize(QSize(12,12));
    m_organNameButton->setMinimumSize(QSize(12,12));
    m_organNameButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    QFont font;
    font.setFamily("PingFang SC");
    font.setPixelSize(12);
    m_organNameLabel->setMinimumWidth(80);
    m_organNameLabel->setFont(font);
    m_organNameLabel->setStyleSheet("color:white");
    m_organNameLabel->setAlignment(Qt::AlignHCenter);
    m_organNameLabel->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);

    m_volumeLabel->setMinimumWidth(80);
    m_volumeLabel->setFont(font);
    m_volumeLabel->setStyleSheet("color:white");
    m_volumeLabel->setAlignment(Qt::AlignHCenter);
    m_volumeLabel->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);

    m_delButton->setMaximumSize(QSize(14,14));
    m_delButton->setStyleSheet("QPushButton{background:url(:/resources/svg/del.svg) center no-repeat;background-color:transparent;}"
                               "QPushButton::hover{background:url(:/del.svg);background-color:transparent;}");
    m_delButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);

    m_visibleButton->setMaximumSize(QSize(14,14));
    m_visibleButton->setStyleSheet("QPushButton{background:url(:/resources/svg/eyes.svg) center no-repeat;background-color:transparent;}"
                                   "QPushButton::hover{background:url(:/eyes.svg);background-color:transparent;}");
    m_visibleButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);

    hboxlayout->addWidget(m_organNameButton);
    hboxlayout->addWidget(m_organNameLabel);
    hboxlayout->addWidget(m_volumeLabel);
    hboxlayout->addWidget(m_delButton);
    hboxlayout->addWidget(m_visibleButton);

    setLayout(hboxlayout);
}
