    #pragma once

#include <QPushButton>

enum class TsPreviousStepOrNextStepButtonType {
    PreviousStepm,
    NextStep
};

class TsPreviousStepOrNextStepButton : public QPushButton
{
    Q_OBJECT

public:
    void setTsPreviousStepOrNextStepButtonType(TsPreviousStepOrNextStepButtonType);
public:
    TsPreviousStepOrNextStepButton(QWidget *parent);
    ~TsPreviousStepOrNextStepButton();
};
