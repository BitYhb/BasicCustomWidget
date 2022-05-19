#include "qpixmap.h"
#include "qbitmap.h"
#include "qpainter.h"
#include "tsstepbutton.h"

TsStepButton::TsStepButton(QWidget* parent)
    : QPushButton(parent),
	m_textY(28)
{
	setTsStepButtonType(TsStepButtonType::Middle);
}

TsStepButton::~TsStepButton()
{
}

void TsStepButton::setTextPosX(int x)
{
	m_textX = x;
}

void TsStepButton::setTextPosY(int y)
{
	m_textY = y;
}

void TsStepButton::setTsStepButtonType(TsStepButtonType type)
{
	m_qrcPath = "";
	switch (type)
	{
	case TsStepButtonType::First:
		m_qrcPath = ":/resources/svg/stephead_button";
		break;
	case TsStepButtonType::Middle:
		m_qrcPath = ":/resources/svg/stepmiddle_button";
		break;
	case TsStepButtonType::End:
		m_qrcPath = ":/resources/svg/stepend_button";
		break;
	}
	m_buttonType = type;

	QPixmap pixmap;
	pixmap.load(m_qrcPath + "_clicked.svg");
	resize(pixmap.size());
	setMask(pixmap.mask());
	this->setCheckable(true);
}

void TsStepButton::paintEvent(QPaintEvent* event)
{
	QPainter p(this);
	if (this->isChecked()) {
		p.drawPixmap(0, 0, QPixmap(m_qrcPath + "_clicked.svg"));
	}
	else {
		p.drawPixmap(0, 0, QPixmap(m_qrcPath + "_normal.svg"));
	}
	if (!this->text().isEmpty()) {
		QFont font;
		font.setFamily(QString::fromUtf8("PingFang SC"));
		font.setPointSize(14);
		
		p.setFont(font);
		p.setPen(Qt::white);
		p.drawText(m_textX, m_textY, this->text());
	}
}
