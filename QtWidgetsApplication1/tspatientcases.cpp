#include "tspatientcases.h"

TsPatientCases::TsPatientCases(QWidget *parent)
    : QPushButton(parent)
{
    this->setStyleSheet(QString::fromUtf8("QPushButton{"
                                          "	font-family: 'PingFang SC';"
                                          "	font-style: normal;"
                                          "	font-weight: 500;"
                                          "	font-size: 14px;"
                                          "	line-height: 20px;"
                                          "	letter-spacing: 0.1em;"
                                          "	color: #FFFFFF;"
                                          "	border: 1px solid rgba(0, 0, 0, 0.4);"
                                          "	border-top-color: rgb(113, 155, 148);"
                                          "	background: rgb(25, 140, 121);"
                                          "}"
                                          "QPushButton:pressed"
                                          "{"
                                          "	background: rgb(30, 185, 160);"
                                          "}"
                                          ""));
}

TsPatientCases::~TsPatientCases() {}

void TsPatientCases::setActive(bool is) {}
