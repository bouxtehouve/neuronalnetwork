#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    m_network.data_training();      // launch the training of the neural network
    ui->groupBox_2->setEnabled(true);      // enabled the frame which convert written digits
    ui->groupBox->setEnabled(false);      // disabled the current frame
}

void MainWindow::on_pushButton_2_clicked()
{
    ostringstream position;
    int r=m_data.rand_digit();
    m_data.output_bmp(r);
    string full_path;
    full_path=m_data.get_path()+"Output.bmp";
    QPixmap pixmapObject("Output.bmp");
    ui->label->setPixmap(pixmapObject);
    position << m_network.interpretResults(m_data.output_data("test").at(r));
    string pos_str;
    pos_str=position.str();
    ui->label_2->setText("pos_str");
}

void MainWindow::get_network(){
    Network network0(0.5,0.5,TAN);
    m_network=network0;
}

void MainWindow::get_data(){
    gestion_data data;
    m_data=data;
}
