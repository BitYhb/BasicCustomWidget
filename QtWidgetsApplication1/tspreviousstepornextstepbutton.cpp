#include "tspreviousstepornextstepbutton.h"
#include "QtCore/qcoreapplication.h"
void TsPreviousStepOrNextStepButton::setTsPreviousStepOrNextStepButtonType(TsPreviousStepOrNextStepButtonType type)
{
	if (type == TsPreviousStepOrNextStepButtonType::PreviousStepm) {
		this->setStyleSheet(QString::fromUtf8("QPushButton{\n"
			"	font-family: 'PingFang SC';\n"
			"	font-style: normal;\n"
			"	font-weight: 600;\n"
			"	font-size: 22px;\n"
			"	line-height: 31px;\n"
			"	letter-spacing: 0.12em;\n"
			"	color: #000000;\n"
			"	border: 1px solid rgba(0, 0, 0, 0.4);\n"
			"	border-top-color: #959B9B;\n"
			"	background: #6B6C6C;\n"
			"}\n"
			"QPushButton:hover\n"
			"{\n"
			"	background: #A6A8A8;\n"
			"}\n"
			"QPushButton:pressed\n"
			"{\n"
			"	background: #C2C6C5;\n"
			"}\n"
			""));
		this->setText(QCoreApplication::translate("TranslateClass", "\344\270\212\344\270\200\346\255\245", nullptr));
	}
	else if (type == TsPreviousStepOrNextStepButtonType::NextStep) {
		this->setStyleSheet(QString::fromUtf8("QPushButton{\n"
			"	font-family: 'PingFang SC';\n"
			"	font-style: normal;\n"
			"	font-weight: 600;\n"
			"	font-size: 22px;\n"
			"	line-height: 31px;\n"
			"	letter-spacing: 0.12em;\n"
			"	color: #FFFFFF;\n"
			"	border: 1px solid rgba(0, 0, 0, 0.4);\n"
			"	border-top-color: rgb(166, 225, 216);\n"
			"	background: rgba(35, 229, 197, 0.4);\n"
			"}\n"
			"QPushButton:hover\n"
			"{\n"
			"	background: rgba(35, 229, 197, 0.6);\n"
			"}\n"
			"QPushButton:pressed\n"
			"{\n"
			"	background: rgba(35, 229, 197, 0.8);\n"
			"}\n"
			""));
		this->setText(QCoreApplication::translate("TranslateClass", "\344\270\213\344\270\200\346\255\245", nullptr));
	}
}

TsPreviousStepOrNextStepButton::TsPreviousStepOrNextStepButton(QWidget* parent)
	: QPushButton(parent)
{
	this->resize(140, 60);
	this->setAutoFillBackground(false);
	setTsPreviousStepOrNextStepButtonType(TsPreviousStepOrNextStepButtonType::NextStep);
}

TsPreviousStepOrNextStepButton::~TsPreviousStepOrNextStepButton()
{
}
