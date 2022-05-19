//病例条
#pragma once

#include <QPushButton>

class TsPatientCases : public QPushButton
{
    Q_OBJECT

public:
    TsPatientCases(QWidget *parent);
    ~TsPatientCases();

public:
    void setActive(bool);
};
