#include "gammeoverscreen.h"
#include "ui_gammeoverscreen.h"

GammeOverScreen::GammeOverScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GammeOverScreen)
{
    ui->setupUi(this);
}

GammeOverScreen::~GammeOverScreen()
{
    delete ui;
}
