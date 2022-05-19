#include "tstoolbutton.h"
#include <QDebug>
#include <QToolTip>
QMetaEnum TsToolButton::m_sMetaButtonType = QMetaEnum::fromType<TsToolButton::ButtonType>();
TsToolButton::TsToolButton(QWidget *parent)
    : QToolButton{parent}
{
    setMinimumSize(54, 52);
    setCheckable(true);
    setToolTip("选择");
    setButtonType(TsToolButton::ButtonType::FunctionButton);
}

void TsToolButton::setButtonType(TsToolButton::ButtonType type)
{
    const QString strCalled = QString("%1Style").arg(QString(m_sMetaButtonType.valueToKey((int) type)));
    QMetaObject::invokeMethod(this, strCalled.toLatin1().constData(), Qt::DirectConnection);
}

void TsToolButton::setIconUrl(const QString nomalUrl, const QString pressedUrl)
{
    m_iconNomalUrl = nomalUrl;
    m_iconPressedUrl = pressedUrl;
}

void TsToolButton::ToolButtonStyle()
{
    const QString strStyle = QString("QToolButton {\n"
                                     "  background:url(%1) center no-repeat;\n"
                                     "  background-color: transparent;\n"
                                     "}\n"
                                     "QToolButton::checked {\n"
                                     "   background: url(%2) center no-repeat;\n"
                                     "   background-color: transparent;\n"
                                     "}\n"
                                     "QToolButton::pressed {\n"
                                     "  background:url(%2) center no-repeat;\n"
                                     "  background-color: #1C1D1D;\n"
                                     "}\n"
                                     "QToolButton::hover {\n"
                                     "  background:url(%2) center no-repeat;\n"
                                     "  background-color: transparent;\n"
                                     "}\n"
                                     "QToolTip{\n"
                                     "   border: 1px solid rgb(245,245,245);\n"
                                     "   background-color : ##f4f4f4;\n"
                                     "   color: #0b0b0b;\n"
                                     "   font-size: 20px;\n"
                                     "}\n")
                                 .arg(m_iconNomalUrl, m_iconPressedUrl);
    setStyleSheet(strStyle);
}

void TsToolButton::FunctionButtonStyle()
{
    const QString strStyle = QString("QToolButton {\n"
                                     "  background:url(%1) center no-repeat;\n"
                                     "  background-color: transparent;\n"
                                     "}\n"
                                     "QToolButton::checked {\n"
                                     "   background: url(%2) center no-repeat;\n"
                                     "   background-color: #1C1D1D;\n"
                                     "}\n"
                                     "QToolButton::pressed {\n"
                                     "  background:url(%2) center no-repeat;\n"
                                     "  background-color: #1C1D1D;\n"
                                     "}\n"
                                     "QToolTip{\n"
                                     "   border: 1px solid rgb(245,245,245);\n"
                                     "   background-color : ##f4f4f4;\n"
                                     "   color: #0b0b0b;\n"
                                     "   font-size: 20px;\n"
                                     "}\n")
                                 .arg(m_iconNomalUrl, m_iconPressedUrl);
    setStyleSheet(strStyle);
}
