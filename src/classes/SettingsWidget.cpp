#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>
#include "SettingsWidget.h"

SettingsWidget::SettingsWidget(QWidget* parent) : QWidget(parent) {
    ui.setupUi(this);
}

SettingsWidget::~SettingsWidget() {
    delete this;
}

void SettingsWidget::CancelButtonClicked() {
    QMessageBox msg;
    msg.setText("cancel button");
    msg.exec();
}

void SettingsWidget::UpdateButtonClicked() {
    QMessageBox msg;
    msg.setText("update button");
    msg.exec();
}

void SettingsWidget::DeleteButtonClicked() {
    QMessageBox msg;
    msg.setText("delete button");
    msg.exec();
}