#include "tstabbutton.h"

TsTabButton::TsTabButton(QWidget *parent)
    : QPushButton(parent)
{
    this->resize(73, 30);
    this->setStyleSheet(QString::fromUtf8("QPushButton{"
                                          "opacity: 0.5;"
                                          "border: 1px solid rgba(255, 255, 255, 0.2);"
                                          "font-family: 'PingFang SC';"
                                          "font-style: normal;"
                                          "font-weight: 500;"
                                          "font-size: 12px;"
                                          "line-height: 17px;"
                                          "color: #979797;"
                                          "}"
                                          "QPushButton:checked"
                                          "{"
                                          "	color: #FFFFFF;"
                                          "	border: 1px solid rgba(255, 255, 255, 0.6);"
                                          "	opacity: 0.5;"
                                          "}"));
    this->setCheckable(true);
}

TsTabButton::~TsTabButton() {}
