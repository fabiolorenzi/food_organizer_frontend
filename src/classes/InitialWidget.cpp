#include "InitialWidget.h"

InitialWidget::InitialWidget(QWidget* parent) : QWidget(parent) {
    ui.setupUi(this);
}

InitialWidget::~InitialWidget() {
    delete this;
}