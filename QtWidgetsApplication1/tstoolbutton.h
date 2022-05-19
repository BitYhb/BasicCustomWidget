#pragma once
#include <QMetaEnum>
#include <QObject>
#include <QToolButton>
class TsToolButton : public QToolButton
{
    Q_OBJECT
public:
    explicit TsToolButton(QWidget *parent = nullptr);
    ~TsToolButton() {}

public:
    enum class ButtonType { ToolButton = 0x01, FunctionButton };
    Q_ENUM(ButtonType)
    void setButtonType(TsToolButton::ButtonType type);
    void setIconUrl(const QString nomalUrl,const QString pressedUrl);
private:
    Q_INVOKABLE void ToolButtonStyle();
    Q_INVOKABLE void FunctionButtonStyle();
    static QMetaEnum m_sMetaButtonType;

private:
    QString m_iconNomalUrl = ":/resources/svg/toolbutton_checkIcon.svg";
    QString m_iconPressedUrl = ":/resources/svg/toolbutton_checkIconPressed.svg";
};
