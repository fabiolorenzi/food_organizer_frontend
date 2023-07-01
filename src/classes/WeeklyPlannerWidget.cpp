#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>
#include "WeeklyPlannerWidget.h"

WeeklyPlannerWidget::WeeklyPlannerWidget(QWidget* parent) : QWidget(parent) {
    ui.setupUi(this);
}

WeeklyPlannerWidget::~WeeklyPlannerWidget() {
    delete this;
}

void WeeklyPlannerWidget::CancelButtonClicked() {
    QMessageBox msg;
    msg.setText("Cancel button clicked");
    msg.exec();
}

void WeeklyPlannerWidget::SaveButtonClicked() {
    QMessageBox msg;
    msg.setText("Save button clicked");
    msg.exec();
}

void WeeklyPlannerWidget::WeekSelectorButtonClicked() {
    QMessageBox msg;
    msg.setText("Week selector button clicked");
    msg.exec();
}