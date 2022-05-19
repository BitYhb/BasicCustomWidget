#include "tstabiconbutton.h"

void TsTabIconButton::setIconName(QString name)
{
    if (!name.isEmpty()) {
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/svg/eraser_normal.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/resources/svg/eraser_checked.svg"), QSize(), QIcon::Normal, QIcon::On);
        this->setIcon(icon);
        this->setIconSize(QSize(14, 14));
    }
}

TsTabIconButton::TsTabIconButton(QWidget *parent)
    : QPushButton(parent)
{
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
                                          "	color: #23E5C5;"
                                          "	border: 1px solid;"
                                          "	"
                                          "	border-color: rgb(48, 88, 84);"
                                          "	opacity: 0.5;"
                                          ""
                                          "}"));
}

TsTabIconButton::~TsTabIconButton() {}
