#pragma once

#include "QOPenWidget.h"
#include <QtWidgets/QDialog>
#include "ui_triangle.h"

class triangle : public QDialog
{
	Q_OBJECT

public:
	triangle(QWidget *parent = Q_NULLPTR);

private:
	Ui::triangleClass ui;
};
