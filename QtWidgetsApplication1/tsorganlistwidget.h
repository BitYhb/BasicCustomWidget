#pragma once
#include <QListWidget>
class TsOrganListWidget : public QListWidget
{
public:
    TsOrganListWidget(QWidget*parent);
    ~TsOrganListWidget(); 

    void setModel();
};
