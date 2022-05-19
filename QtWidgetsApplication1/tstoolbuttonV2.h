#pragma once
#include <iostream>
#include <QDebug>
#include <QEvent>
#include <QSize>
#include <QString>
#include <QToolButton>
#include <QToolTip>
#include <QPair>
#include <QMap>
class TsToolButtonV2Private;

class TsToolButtonV2 : public QToolButton
{
    Q_OBJECT
public:
    enum class ButtonState { Nomal = 0x01, ByPress, ByHoverEnter, ByHoverLeave, ByRelease, Disable };

public:
    explicit TsToolButtonV2(QWidget *parent = nullptr);
    ~TsToolButtonV2();
    void setIcon(const QString icon, const int width, const int height);
    bool eventFilter(QObject *object, QEvent *event) override;
    void setIconUrl(QString nomal, QString disable, QString hover);
    void setIconSize(const QSize size);
    void setToolTip(const QString tooltip);
    void setState(TsToolButtonV2::ButtonState buttonState);
private:
    void nomalFunc();
    void pressFunc();
    void hoverEnterFunc();
    void hoverLeaveFunc();
    void releaseFunc();

private:
    typedef void(TsToolButtonV2::*EventFunc)(void);
    //using EventFunc = std::function<void(void)>;
    void setbackgroundColor(QString color);
    void initStateFuncHash();

private:
    QScopedPointer<TsToolButtonV2Private> d_ptr;
    Q_DECLARE_PRIVATE(TsToolButtonV2);
};
