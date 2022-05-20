#include "QtWidgetsApplication1.h"
#include "tspreviousstepornextstepbutton.h"
#include "tsstepbutton.h"
#include "tstoolbuttonV2.h"
#include "tstoolbutton.h"
#include "tstabbutton.h"
#include "tstabiconbutton.h"
#include "tslesionsextract.h"
#include "TsOrganListItem.h"
#include <QVBoxLayout>
#include <QPalette>
#include <QDebug>
#include <QListWidget>
QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, Qt::black);
    setAutoFillBackground(true);
    setPalette(pal);
    QWidget *leftWidget = new QWidget(this);
    leftWidget->setGeometry(0,0, 55, this->height() - 2);
    QPalette palette(leftWidget->palette());
    palette.setColor(QPalette::Background,QColor(36,37,39));
    leftWidget->setAutoFillBackground(true);
    leftWidget->setPalette(palette);
    QVBoxLayout *verBoxlayout = new QVBoxLayout;
    //leftWidget->setContentsMargins(30,0,0,0);
    auto btn = new TsToolButton(this);
    auto btn1 = new TsToolButton(this);
    auto btn2 = new TsToolButton(this);
    auto btn3 = new TsToolButton(this);
    auto btn4 = new TsToolButton(this);
    
    btn->setIconUrl(":/resources/svg/toolbutton_checkIcon.svg", ":/resources/svg/toolbutton_checkIconPressed.svg");
    btn->setButtonType(TsToolButton::ButtonType::ToolButton);
    btn->setCheckable(false);

    btn1->setIconUrl(":/resources/svg/toolbutton_recover.svg", ":/resources/svg/toolbutton_recoverPressed.svg");
    btn1->setButtonType(TsToolButton::ButtonType::ToolButton);
    btn1->setCheckable(false);

    btn2->setIconUrl(":/resources/svg/toolbutton_revoke.svg", ":/resources/svg/toolbutton_revokePressed.svg");
    btn2->setButtonType(TsToolButton::ButtonType::ToolButton);
    btn2->setCheckable(false);

    btn3->setIconUrl(":/resources/svg/toolbutton_shotCut.svg", ":/resources/svg/toolbutton_shotCutPressed.svg");
    btn3->setButtonType(TsToolButton::ButtonType::ToolButton);

    btn4->setIconUrl(":/resources/svg/toolbutton_screenCap.svg", ":/resources/svg/toolbutton_screenCapPressed.svg");
    btn4->setButtonType(TsToolButton::ButtonType::ToolButton);
    
    verBoxlayout->addWidget(btn);
    verBoxlayout->addWidget(btn1);
    verBoxlayout->addWidget(btn2);
    verBoxlayout->addWidget(btn3);
    verBoxlayout->addWidget(btn4);
    verBoxlayout->setMargin(0);
    leftWidget->setLayout(verBoxlayout);


    QListWidget *listWidget = new QListWidget(this);
    listWidget->setGeometry(leftWidget->x() + leftWidget->width() + 10,leftWidget->y() + 10,400,190);
    listWidget->setStyleSheet(
                              "QListWidget\n"
                              "{\n"
                                "background:transparent;\n"
                              "}\n"
                            "QScrollBar:vertical\n"
                            "{\n"
                                "background:transparent;\n"
                                "width: 10px;"
                                "margin: 0px 0 0px 0;\n"
                            "}\n"
                            "QScrollBar::handle:vertical\n"
                            "{\n"
                                "background: #a0a0a0a0;\n"
                                "min-height: 20px;\n"
                                "margin: 0 1px 0 1px;\n"
                                "border-radius: 3px;\n"
                                "border: none;"
                            "}\n"

                            "QScrollBar::add-line:vertical\n"
                            "{\n"
                                "background:#a0a0a0a0;\n"
                                "width:3px;\n"
                                "height: 0px;\n"
                                "border-radius:3px;\n"
                                "subcontrol-position: bottom;\n"
                                "subcontrol-origin: margin;\n"
                            "}\n"

                            "QScrollBar::sub-line:vertical\n"
                            "{\n"
                                "background:#a0a0a0a0;\n"
                                "width:3px;\n"
                                "height:0px;\n"
                                "border-radius:3px;\n"
                                "subcontrol-position: top;\n"
                                "subcontrol-origin: margin;\n"
                            "}\n"

                            "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical\n"
                            "{\n"
                                "border: 1px solid grey;\n"
                                "border-radius:3px;\n"
                                "width: 3px;\n"
                                "height: 3px;\n"
                                "background: white;\n"
                            "}\n"

                            "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical\n"
                            "{\n"
                                "background: none;\n"
                                "width:3px;\n"
                            "}\n");
    //控制多选操作 设置选中
    //listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    //item->setSelected(true);
    for (int i = 0; i < 10; i++) {
        QListWidgetItem *item = new QListWidgetItem(listWidget);
        item->setSizeHint(QSize(280, 30));
        TsOrganListItem *itemD = new TsOrganListItem();
        itemD->setData("left_lung" + QString::number(i + 1),
                       QString("2001.2") + QString::number(i + 1) + "cm³",
                       "#4D6AD2");
        listWidget->addItem(item);
        listWidget->setItemWidget(item, itemD);
    }
    //verBoxlayout->setGeometry(QRect(0, 0, this->width() / 2, this->height()));
}
