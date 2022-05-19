//带有图标的中间镂空按钮
#pragma once

#include <QPushButton>

class TsTabIconButton : public QPushButton
{
    Q_OBJECT

public:
    void setIconName(QString name);

public:
    TsTabIconButton(QWidget *parent);
    ~TsTabIconButton();
};
