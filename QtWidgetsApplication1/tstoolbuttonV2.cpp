#include "tstoolbuttonV2.h"
#include <QIcon>
#include <QPalette>

class TsToolButtonV2Private
{
    TsToolButtonV2Private(TsToolButtonV2 *object);

private:
    void initButtonProperty();
private:
    TsToolButtonV2 *q_ptr;
    Q_DECLARE_PUBLIC(TsToolButtonV2);

    QSize m_iconSize;
    QString m_iconNomal;
    QString m_iconDisable;
    QString m_iconHover;
    QString m_toolTip;
    QMap<TsToolButtonV2::ButtonState, TsToolButtonV2::EventFunc> m_stateFunc;
    TsToolButtonV2::ButtonState m_currentState = TsToolButtonV2::ButtonState::Nomal;
};
TsToolButtonV2Private::TsToolButtonV2Private(TsToolButtonV2 *object)
    : q_ptr(object)
{
    initButtonProperty();
}
void TsToolButtonV2Private::initButtonProperty()
{
    m_iconNomal = nullptr;
    m_iconDisable = nullptr;
    m_iconHover = nullptr;
    m_toolTip = nullptr;
}

TsToolButtonV2::TsToolButtonV2(QWidget *parent)
    : QToolButton{parent}
    , d_ptr(new TsToolButtonV2Private(this))
{
    this->setMinimumSize(54, 52);

    installEventFilter(this);
    initStateFuncHash();
    this->setStyleSheet(
        "QToolTip{border:1px solid rgb(225, 118, 225); background-color: red; color:#484848; font-size:20px;}");
    setbackgroundColor("transparent");
}
void TsToolButtonV2::initStateFuncHash()
{
    Q_D(TsToolButtonV2);
    d->m_stateFunc.insert(TsToolButtonV2::ButtonState::ByHoverEnter, &TsToolButtonV2::hoverEnterFunc);
    d->m_stateFunc.insert(TsToolButtonV2::ButtonState::ByHoverLeave, &TsToolButtonV2::hoverLeaveFunc);
    d->m_stateFunc.insert(TsToolButtonV2::ButtonState::ByPress, &TsToolButtonV2::pressFunc);
    d->m_stateFunc.insert(TsToolButtonV2::ButtonState::ByRelease, &TsToolButtonV2::releaseFunc);
    d->m_stateFunc.insert(TsToolButtonV2::ButtonState::Nomal, &TsToolButtonV2::nomalFunc);
}
void TsToolButtonV2::setIcon(const QString icon, const int width, const int height)
{
    this->QToolButton::setIcon(QIcon(icon));
    this->QToolButton::setIconSize(QSize(width, height));
}

bool TsToolButtonV2::eventFilter(QObject *object, QEvent *event)
{
    Q_UNUSED(object);
    Q_D(TsToolButtonV2);
    if (event->type() == QEvent::MouseButtonPress) {
        (this->*(d->m_stateFunc[TsToolButtonV2::ButtonState::ByPress]))();
    } else if (event->type() == QEvent::HoverEnter) {
        (this->*(d->m_stateFunc[TsToolButtonV2::ButtonState::ByHoverEnter]))();
    } else if (event->type() == QEvent::HoverLeave) {
        (this->*(d->m_stateFunc[TsToolButtonV2::ButtonState::ByHoverLeave]))();
    } else if (event->type() == QEvent::MouseButtonRelease) {
        (this->*(d->m_stateFunc[TsToolButtonV2::ButtonState::ByRelease]))();
    }
    return QObject::eventFilter(object, event);
}

void TsToolButtonV2::setIconUrl(QString nomal, QString disable, QString hover)
{
    Q_D(TsToolButtonV2);
    d->m_iconHover = hover;
    d->m_iconNomal = nomal;
    d->m_iconDisable = disable;
}

void TsToolButtonV2::setIconSize(const QSize size)
{
    Q_D(TsToolButtonV2);
    d->m_iconSize.setWidth(size.width());
    d->m_iconSize.setHeight(size.height());
}

void TsToolButtonV2::setToolTip(const QString tooltip)
{
    
    this->QToolButton::setToolTip(tooltip);
}

void TsToolButtonV2::setState(TsToolButtonV2::ButtonState buttonState)
{
    Q_D(TsToolButtonV2);
    if (d->m_currentState != buttonState)
        d->m_currentState = buttonState;
    (this->*(d->m_stateFunc[d->m_currentState]))();
}

void TsToolButtonV2::nomalFunc()
{
    Q_D(TsToolButtonV2);
    setIcon(d->m_iconNomal, d->m_iconSize.width(), d->m_iconSize.height());
    setbackgroundColor("transparent");
}

void TsToolButtonV2::pressFunc()
{
    Q_D(TsToolButtonV2);
    setIcon(d->m_iconHover, d->m_iconSize.width(), d->m_iconSize.height());
    setbackgroundColor("#1C1D1D");
}

void TsToolButtonV2::hoverEnterFunc()
{
    Q_D(TsToolButtonV2);
    setIcon(d->m_iconHover, d->m_iconSize.width(), d->m_iconSize.height());
    setbackgroundColor("transparent");
}

void TsToolButtonV2::hoverLeaveFunc()
{
    Q_D(TsToolButtonV2);
    setIcon(d->m_iconNomal, d->m_iconSize.width(), d->m_iconSize.height());
    setbackgroundColor("transparent");
}

void TsToolButtonV2::releaseFunc()
{
    setbackgroundColor("transparent");
}
void TsToolButtonV2::setbackgroundColor(QString color)
{
    setStyleSheet(QString("QToolButton{background:%1}").arg(color));
}
TsToolButtonV2::~TsToolButtonV2() {}
