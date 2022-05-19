#pragma once

#include <QPushButton>
enum class TsStepButtonType
{
    First,
    Middle,
    End
};

class TsStepButton : public QPushButton
{
    Q_OBJECT

private:
    int m_textX;
    int m_textY;
    QString m_qrcPath;
    TsStepButtonType m_buttonType;

public:
    TsStepButton(QWidget *parent);
    ~TsStepButton();

public:
    void setTextPosX(int x);
    void setTextPosY(int y);
    void setTsStepButtonType(TsStepButtonType);
protected:
    void paintEvent(QPaintEvent* event);
};
