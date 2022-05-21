#include "tsnodulelisitem.h"

#include <QHBoxLayout>
#include <QSpacerItem>


class TsNoduleListItemPrivate
{
    Q_DECLARE_PUBLIC(TsNoduleListItem);
public:
    TsNoduleListItemPrivate(TsNoduleListItem*object);
private:
    void initUI();
private:
    QPushButton *m_organNameButton;
    QLabel *m_organNameLabel;
    QComboBox *m_typeComboBox;
    QPushButton *m_delButton;
    QPushButton *m_visibleButton;

    QString m_organName;
    QStringList m_typeList;
    QString m_organColor;
    //id,type,alias,enum_type...

    TsNoduleListItem* q_ptr;
};
TsNoduleListItemPrivate::TsNoduleListItemPrivate(TsNoduleListItem *object)
    : m_organNameButton(new QPushButton(object))
    , m_organNameLabel(new QLabel(object))
    , m_typeComboBox(new QComboBox(object))
    , m_delButton(new QPushButton(object))
    , m_visibleButton(new QPushButton(object))
    , m_organName("")
    ,m_typeList("")
    , m_organColor("")
    ,q_ptr(object)
{}
void TsNoduleListItemPrivate::initUI()
{
    Q_Q(TsNoduleListItem);
    //this
    q->setFixedHeight(33);
    q->setFixedWidth(280);
    //layout
    QHBoxLayout *hboxlayout = new QHBoxLayout(q);
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

    m_typeComboBox->setMinimumWidth(80);
    m_typeComboBox->setFont(font);
    m_typeComboBox->setStyleSheet("color:white");
    m_typeComboBox->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);
    m_typeComboBox->setStyleSheet("QComboBox {"
                                  "border: none;"
                                  "border-radius: 3px;"
                                  "padding: 1px 18px 1px 3px;"
                                  "color:white;;"
                                  "background: transparent;"
                              "}");

    m_delButton->setMaximumSize(QSize(14,14));
    m_delButton->setStyleSheet("QPushButton{background:url(:/del.svg) center no-repeat;background-color:transparent;}"
                               "QPushButton::hover{background:url(:/del.svg);background-color:transparent;}");
    m_delButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);

    m_visibleButton->setMaximumSize(QSize(14,14));
    m_visibleButton->setStyleSheet("QPushButton{background:url(:/eyes.svg) center no-repeat;background-color:transparent;}"
                                   "QPushButton::hover{background:url(:/eyes.svg);background-color:transparent;}");
    m_visibleButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);

    hboxlayout->addWidget(m_organNameButton);
    hboxlayout->addWidget(m_organNameLabel);
    hboxlayout->addWidget(m_typeComboBox);
    hboxlayout->addWidget(m_delButton);
    hboxlayout->addWidget(m_visibleButton);

    q->setLayout(hboxlayout);
}

TsNoduleListItem::TsNoduleListItem(QWidget *parent)
    : QWidget{parent}
    ,d_ptr(new TsNoduleListItemPrivate(this))
{
    Q_D(TsNoduleListItem);
    d->initUI();
}

void TsNoduleListItem::setData(QString strName, QStringList typeList, QString strColor)
{
    Q_D(TsNoduleListItem);
    d->m_organName = strName;
    d->m_typeList = typeList;
    d->m_organColor = strColor;

    d->m_organNameButton->setStyleSheet(QString("QPushButton{background: %1;rad;border-radius:6px}").arg(d->m_organColor));
    d->m_organNameLabel->setText(d->m_organName);
    d->m_typeComboBox->addItems(d->m_typeList);
}

QString TsNoduleListItem::organName() const
{
    const Q_D(TsNoduleListItem);
    return d->m_organName;
}

QStringList TsNoduleListItem::typeList() const
{
    const Q_D(TsNoduleListItem);
    return d->m_typeList;
}

QString TsNoduleListItem::organColor() const
{
    const Q_D(TsNoduleListItem);
    return d->m_organColor;
}
