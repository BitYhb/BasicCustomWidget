#include "tslesionsextract.h"

TsLesionsExtract::TsLesionsExtract(QWidget *parent)
    : QPushButton(parent)
{
    this->resize(328, 40);
    this->setAutoFillBackground(false);
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
                                          "	background: rgba(35, 230, 197, 0.8);"
                                          "}"
                                          "QPushButton:hover"
                                          "{"
                                          "	background: rgba(35, 229, 197, 0.6);"
                                          "}"
                                          "QPushButton:pressed"
                                          "{"
                                          "	background: rgba(35, 229, 197, 0.4);"
                                          "}"
                                          ""));
}

TsLesionsExtract::~TsLesionsExtract() {}
