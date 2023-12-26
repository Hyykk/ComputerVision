#include "mainframe.h"
#include "ui_mainframe.h"
#include "imageform.h"
#include "histogram.h"
#include "circleHough.h"
#include "edge.h"
#include "corner.h"

#include <QFileDialog>
#include <QPainter>
#include <sstream>
#include <fstream>
#include <math.h>

using namespace std;

MainFrame::MainFrame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainFrame)
{
    ui->setupUi(this);

    _q_pFormFocused     = 0;

    //객체 맴버의 초기화


    //리스트 출력창을 안보이게    
    ui->listWidget->setVisible(false);
    this->adjustSize();

    //UI 활성화 갱신
    UpdateUI();
}

MainFrame::~MainFrame()
{ 
    delete ui;         

    for(auto& item : _lImageForm)
        delete item;

}

void MainFrame::CloseImageForm(ImageForm *pForm)
{
    //ImageForm 포인터 삭제
    unsigned int idx = std::find(_lImageForm.begin(), _lImageForm.end(), pForm) - _lImageForm.begin();
    if(idx != _lImageForm.size())
    {
        delete _lImageForm[idx];
        _lImageForm.erase(_lImageForm.begin() + idx);
    }

    //활성화 ImageForm 초기화
    _q_pFormFocused     = 0;

    //관련 객체 삭제

    //UI 활성화 갱신
    UpdateUI();
}

void MainFrame::UpdateUI()
{    
    if(ui->tabWidget->currentIndex() == 0)
    {
    }
    else if(ui->tabWidget->currentIndex() == 1)
    {  
    }
    else if(ui->tabWidget->currentIndex() == 2)
    {        
    }
    else if(ui->tabWidget->currentIndex() == 3)
    {
    }
}

void MainFrame::OnMousePos(const int &nX, const int &nY, ImageForm* q_pForm)
{
}

void MainFrame::focusInEvent(QFocusEvent * event)
{
    Q_UNUSED(event) ;

    UpdateUI();
}

void MainFrame::closeEvent(QCloseEvent* event)
{
    //생성된 ImageForm을 닫는다.
    for(int i=0; i< _lImageForm.size(); i++)
        delete _lImageForm[i];

    //리스트에서 삭제한다.
    _lImageForm.clear();
}


void MainFrame::on_buttonOpen_clicked()
{
    //이미지 파일 선택
    QFileDialog::Options    q_Options   =  QFileDialog::DontResolveSymlinks  | QFileDialog::DontUseNativeDialog; // | QFileDialog::ShowDirsOnly
    QString                 q_stFile    =  QFileDialog::getOpenFileName(this, tr("Select a Image File"),  "./data", "Image Files(*.bmp *.ppm *.pgm *.png)",0, q_Options);

    if(q_stFile.length() == 0)
        return;

    //이미지 출력을 위한 ImageForm 생성    
    ImageForm*              q_pForm   = new ImageForm(q_stFile, "OPEN", this);

    _lImageForm.push_back(q_pForm);
    q_pForm->show();

    //UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_buttonDeleteContents_clicked()
{
    //생성된 ImageForm을 닫는다.
    for(int i=_lImageForm.size()-1; i>=0; i--)
        delete _lImageForm[i];

    //리스트에서 삭제한다.
    _lImageForm.clear();

    //객체 삭제


    ui->listWidget->clear();
}

void MainFrame::on_tabWidget_currentChanged(int index)
{
    static int nOld = -1;

    if(nOld == 0)
    {

    }
    else if(nOld == 1)
    {

    }
    nOld = index;

    //UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_buttonShowList_clicked()
{
    static int nWidthOld = ui->tabWidget->width();

    if(ui->listWidget->isVisible())
    {
        nWidthOld = ui->listWidget->width();
        ui->listWidget->hide();
        this->adjustSize();
    }
    else
    {        
        ui->listWidget->show();
        QRect q_rcWin = this->geometry();

        this->setGeometry(q_rcWin.left(), q_rcWin.top(), q_rcWin.width()+nWidthOld, q_rcWin.height());
    }
}

void MainFrame::on_pushRGB2HSI_clicked(){
    // 포커스 된 ImageForm으로부터 영상을 가져옴
    KImageColor icMain;
    if(_q_pFormFocused  != 0 && _q_pFormFocused->ImageColor().Address() && _q_pFormFocused->ID() == "OPEN"){
        icMain = _q_pFormFocused->ImageColor();
    }
    else{
        return;
    }

    // 이미지를 HSI로 변환
    KArray<KHSI> arHSI;
    icMain.RGBtoHSI(arHSI);

    // H, S, I 각각의 이미지 생성
    KImageGray hChannel(icMain.Row(), icMain.Col());
    KImageGray sChannel(icMain.Row(), icMain.Col());
    KImageGray iChannel(icMain.Row(), icMain.Col());

    for (unsigned int i = 0; i < icMain.Row(); i++) {
        for (unsigned int j = 0; j < icMain.Col(); j++) {
            // H, S, I 값을 가져옴
            double H = arHSI[i][j].h;
            double S = arHSI[i][j].s;
            double I = arHSI[i][j].i;

            // hChannel
            hChannel[i][j] = H*255;

            // sChannel
            sChannel[i][j] = S*255;

            // iChannel
            iChannel[i][j] = I*255;
        }
    }

    // 출력
    ImageForm* imageH = new ImageForm(hChannel, "Hue Image", this);
    ImageForm* imageS = new ImageForm(sChannel, "Saturation Image", this);
    ImageForm* imageI = new ImageForm(iChannel, "Intensity Image", this);

    _lImageForm.push_back(imageH);
    imageH->show();

    _lImageForm.push_back(imageS);
    imageS->show();

    _lImageForm.push_back(imageI);
    imageI->show();
}

void MainFrame::on_pushRGB2NRG_clicked(){
    // 포커스 된 ImageForm으로부터 영상을 가져옴
    KImageColor icMain;
    if(_q_pFormFocused  != 0 && _q_pFormFocused->ImageColor().Address() && _q_pFormFocused->ID() == "OPEN"){
        icMain = _q_pFormFocused->ImageColor();
    }
    else{
        return;
    }

    KImageGray Normalized_red(icMain.Row(), icMain.Col());
    KImageGray Normalized_green(icMain.Row(), icMain.Col());

    for (unsigned int i = 0; i < icMain.Row(); i++) {
        for (unsigned int j = 0; j < icMain.Col(); j++) {
            double Sum = icMain[i][j].r + icMain[i][j].g + icMain[i][j].b;
            Normalized_red[i][j] = (icMain[i][j].r / Sum) * 255;
            Normalized_green[i][j] = (icMain[i][j].g / Sum) * 255;
            }
    }

    // 출력
    ImageForm* imageRed = new ImageForm(Normalized_red, "Normalized Red Image", this);
    ImageForm* imageGreen = new ImageForm(Normalized_green, "Normalized Green Image", this);

    _lImageForm.push_back(imageRed);
    imageRed->show();
    _lImageForm.push_back(imageGreen);
    imageGreen->show();
}

void MainFrame::on_pushContrast_clicked(){
    // 포커스 된 ImageForm으로부터 영상을 가져옴
    KImageColor icMain;
    if(_q_pFormFocused  != 0 && _q_pFormFocused->ImageColor().Address() && _q_pFormFocused->ID() == "OPEN"){
            icMain = _q_pFormFocused->ImageColor();
    }
    else{
            return;
    }

    unsigned char a = ui->spinA->value();
    unsigned char b = ui->spinB->value();
    unsigned char a_ = ui->spinA_->value();
    unsigned char b_ = ui->spinB_->value();

    unsigned char in_r;
    unsigned char in_g;
    unsigned char in_b;
    unsigned char Xin_r;
    unsigned char Xin_g;
    unsigned char Xin_b;

    KImageColor Contrast(icMain.Row(), icMain.Col());

    for(unsigned int i=0; i<icMain.Row(); i++){
        for(unsigned int j=0; j<icMain.Col(); j++){
            in_r = icMain[i][j].r;
            in_g = icMain[i][j].g;
            in_b = icMain[i][j].b;

            Xin_r = (in_r < a) ? a : (in_r > b ? b:in_r);
            Xin_g = (in_g < a) ? a : (in_g > b ? b:in_g);
            Xin_b = (in_b < a) ? a : (in_b > b ? b:in_b);

            Contrast[i][j].r = ((b_-a_)/(b-a))*(Xin_r-a) + a_;
            Contrast[i][j].g = ((b_-a_)/(b-a))*(Xin_g-a) + a_;
            Contrast[i][j].b = ((b_-a_)/(b-a))*(Xin_b-a) + a_;
        }
    }

    //출력
    ImageForm* q_pForm = 0;
    for(auto form : _lImageForm){
        if(form->ID() == "Luminance Contrast Transform" && form->size() == _q_pFormFocused->size()){
            q_pForm = form;
            break;
        }
    }

    //기존 창에 표시
    if(q_pForm){
        q_pForm->Update(Contrast);
    }

    //새로운 창에 표시
    else{
        q_pForm = new ImageForm(Contrast, "Luminance Contrast Transform", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    //UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_pushOtsu_clicked(){
    /*
    // Otsu Thresholding
    KImageGray igMain = _q_pFormFocused->ImageGray();
    KImageGray igBin;
    KBINARIZATION_OUTPUT* opBinOutput = KHisto().Ostu(&igMain, &igBin);

    // 출력창 결정
    ImageForm* q_pForm = 0;
    for(auto item : _lImageForm){
        if(item->ID() == "Binary Image" && item->size() == _q_pFormFocused->size()){
            q_pForm = item;
            break;
        }
    }

    // 기존 창에 표시
    if(q_pForm){
        q_pForm->Update(igBin);
    }

    // 새로운 창에 표시
    else{
        q_pForm = new ImageForm(igBin, "Binary Image", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    // Thresholding 값 표시
    // ui->spinOtsu->setValue(opBinOutput->nThresh);
    ui->listWidget->addItem(QString(">> Otsu Thresholding : %1").arg(opBinOutput->nThresh));
    ui->listWidget->show();

    // UI 활성화 갱신
    UpdateUI();
*/
}

void MainFrame::on_push3x3Dilation_clicked(){
    // Dilation
    KImageGray igBin = _q_pFormFocused->ImageGray().BinaryDilate(_WHITE);

    // 출력창 결정
    ImageForm* q_pForm = 0;
    for(auto item : _lImageForm)
        if(item->ID() == "3x3 Dilated Image" && item->size() == _q_pFormFocused->size()){
            q_pForm = item;
            break;
        }

    // 새로운 창에 표시
    q_pForm = new ImageForm(igBin, "3x3 Dilated Image", this);
    q_pForm->show();
    _lImageForm.push_back(q_pForm);

    // UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_push5x5Dilation_clicked(){
    // Dilation
    KImageGray igBin = _q_pFormFocused->ImageGray().Binary5x5Dilate(_WHITE);

    // 출력창 결정
    ImageForm* q_pForm = 0;
    for(auto item : _lImageForm)
        if(item->ID() == "5x5 Dilated Image" && item->size() == _q_pFormFocused->size()){
            q_pForm = item;
            break;
        }

    // 새로운 창에 표시
    q_pForm = new ImageForm(igBin, "5x5 Dilated Image", this);
    q_pForm->show();
    _lImageForm.push_back(q_pForm);

    // UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_push3x3Erosion_clicked(){
    // Erosion
    KImageGray igBin = _q_pFormFocused->ImageGray().BinaryErode(_WHITE);

    // 출력창 결정
    ImageForm* q_pForm = 0;
    for(auto item : _lImageForm)
        if(item->ID() == "3x3 Eroded Image" && item->size() == _q_pFormFocused->size()){
            q_pForm = item;
            break;
        }

    // 새로운 창에 표시
    q_pForm = new ImageForm(igBin, "3x3 Eroded Image", this);
    q_pForm->show();
    _lImageForm.push_back(q_pForm);

    // UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_push5x5Erosion_clicked(){
    // Erosion
    KImageGray igBin = _q_pFormFocused->ImageGray().Binary5x5Erode(_WHITE);

    // 출력창 결정
    ImageForm* q_pForm = 0;
    for(auto item : _lImageForm)
        if(item->ID() == "5x5 Eroded Image" && item->size() == _q_pFormFocused->size()){
            q_pForm = item;
            break;
        }

    // 새로운 창에 표시
    q_pForm = new ImageForm(igBin, "5x5 Eroded Image", this);
    q_pForm->show();
    _lImageForm.push_back(q_pForm);

    // UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_push4N_clicked(){
    KImageGray igMain = _q_pFormFocused->ImageGray();
    KImageColor iwColor(igMain.Row(), igMain.Col());
    int label = 1;

    // 위, 왼쪽 확인후 색깔 따라갈지 아니면 새로운 색깔일지 선택
    // igMain[i][j] == 0이면 BackGround니깐 상관 x
    for(unsigned int i=1; i<igMain.Row()-1; i++){
        for(unsigned int j=1; j<igMain.Col()-1; j++){
            if(igMain[i][j] != 0 && iwColor[i][j].r == 0){
                if(iwColor[i][j-1].r == 0 && iwColor[i-1][j].r == 0){
                    iwColor[i][j].r = label;
                    label++;

                    ui->listWidget->addItem(QString(">> number of label : %2").arg(label));
                    ui->listWidget->show();
                } else{
                    if(iwColor[i-1][j].r != iwColor[i][j-1].r && iwColor[i-1][j].r != 0){
                        iwColor[i][j-1].r = iwColor[i-1][j].r;
                        iwColor[i][j].r = iwColor[i-1][j].r;
                    } else if(iwColor[i-1][j].r != 0){
                        iwColor[i][j].r = iwColor[i-1][j].r;
                    }
                }
            }
        }
    }

    // Labeling
    for(unsigned int i=0; i<iwColor.Row(); i++){
        for(unsigned int j=0; j<iwColor.Col(); j++){
            if(iwColor[i][j].r == 0) continue;

            switch(iwColor[i][j].r % 7){
            case 0:
                iwColor[i][j].r = 255;
                iwColor[i][j].g = 0;
                iwColor[i][j].b = 0;
                break;
            case 1:
                iwColor[i][j].r = 0;
                iwColor[i][j].g = 255;
                iwColor[i][j].b = 0;
                break;
            case 2:
                iwColor[i][j].r = 0;
                iwColor[i][j].g = 0;
                iwColor[i][j].b = 255;
                break;
            case 3:
                iwColor[i][j].r = 255;
                iwColor[i][j].g = 255;
                iwColor[i][j].b = 0;
                break;
            case 4:
                iwColor[i][j].r = 255;
                iwColor[i][j].g = 0;
                iwColor[i][j].b = 255;
                break;
            case 5:
                iwColor[i][j].r = 0;
                iwColor[i][j].g = 255;
                iwColor[i][j].b = 255;
                break;
            case 6:
                iwColor[i][j].r = 255;
                iwColor[i][j].g = 255;
                iwColor[i][j].b = 255;
                break;
            }
        }
    }

    //출력
    ImageForm* q_pForm = 0;
    for(auto form : _lImageForm){
        if(form->ID() == "Labeling 4-N" && form->size() == _q_pFormFocused->size()){
            q_pForm = form;
            break;
        }
    }

    //새로운 창에 표시
    q_pForm = new ImageForm(iwColor, "Labeling 4-N", this);
    q_pForm->show();
    _lImageForm.push_back(q_pForm);

    //UI 활성화 갱신
    UpdateUI();

}

void MainFrame::on_push8N_clicked(){
    KImageGray igMain = _q_pFormFocused->ImageGray();
    KImageColor iwColor(igMain.Row(), igMain.Col());
    int label = 1;

    // 위, 왼쪽 확인후 색깔 따라갈지 아니면 새로운 색깔일지 선택
    // igMain[i][j] == 0이면 BackGround니깐 상관 x
    for(unsigned int i=1; i<igMain.Row()-1; i++){
        for(unsigned int j=1; j<igMain.Col()-1; j++){
            if(igMain[i][j] != 0){
                if(iwColor[i][j-1].r == 0 && iwColor[i-1][j].r == 0){
                    iwColor[i][j].r = label;
                    label++;

                    ui->listWidget->addItem(QString(">> number of label : %2").arg(label));
                    ui->listWidget->show();
                } else{
                    if(iwColor[i][j-1].r != 0){
                        iwColor[i][j].r = iwColor[i][j-1].r;
                    }else if(iwColor[i-1][j].r != 0){
                        iwColor[i][j].r = iwColor[i-1][j].r;
                    }
                }
            }
        }
    }

    for(unsigned int i=1; i<iwColor.Row()-1; i++){
        for(unsigned int j=1; j<iwColor.Col()-1; j++){
            if(iwColor[i][j].r!=0){
                if(iwColor[i][j].r != iwColor[i-1][j].r && iwColor[i-1][j].r != 0){
                    iwColor[i][j].r = iwColor[i-1][j].r;
                } else if(iwColor[i][j].r != iwColor[i][j-1].r && iwColor[i][j-1].r != 0){
                    iwColor[i][j].r = iwColor[i][j-1].r;
                } else if(iwColor[i][j].r != iwColor[i+1][j].r && iwColor[i+1][j].r != 0){
                    iwColor[i][j].r = iwColor[i+1][j].r;
                } else if(iwColor[i][j].r != iwColor[i][j+1].r && iwColor[i][j+1].r != 0){
                    iwColor[i][j].r = iwColor[i][j+1].r;
                } else if(iwColor[i][j].r != iwColor[i+1][j+1].r && iwColor[i+1][j+1].r != 0){
                    iwColor[i][j].r = iwColor[i+1][j+1].r;
                } else if(iwColor[i][j].r != iwColor[i-1][j-1].r && iwColor[i-1][j-1].r != 0){
                    iwColor[i][j].r = iwColor[i-1][j-1].r;
                } else if(iwColor[i][j].r != iwColor[i+1][j-1].r && iwColor[i+1][j-1].r != 0){
                    iwColor[i][j].r = iwColor[i+1][j-1].r;
                } else if(iwColor[i][j].r != iwColor[i-1][j+1].r && iwColor[i-1][j+1].r != 0){
                    iwColor[i][j].r = iwColor[i-1][j+1].r;
                }
            }
        }
    }

    // Labeling
    for(unsigned int i=0; i<iwColor.Row(); i++){
        for(unsigned int j=0; j<iwColor.Col(); j++){
            if(iwColor[i][j].r == 0) continue;

            switch(iwColor[i][j].r % 7){
            case 0:
                iwColor[i][j].r = 255;
                iwColor[i][j].g = 0;
                iwColor[i][j].b = 0;
                break;
            case 1:
                iwColor[i][j].r = 0;
                iwColor[i][j].g = 255;
                iwColor[i][j].b = 0;
                break;
            case 2:
                iwColor[i][j].r = 0;
                iwColor[i][j].g = 0;
                iwColor[i][j].b = 255;
                break;
            case 3:
                iwColor[i][j].r = 255;
                iwColor[i][j].g = 255;
                iwColor[i][j].b = 0;
                break;
            case 4:
                iwColor[i][j].r = 255;
                iwColor[i][j].g = 0;
                iwColor[i][j].b = 255;
                break;
            case 5:
                iwColor[i][j].r = 0;
                iwColor[i][j].g = 255;
                iwColor[i][j].b = 255;
                break;
            case 6:
                iwColor[i][j].r = 255;
                iwColor[i][j].g = 255;
                iwColor[i][j].b = 255;
                break;
            }
        }
    }

    //출력
    ImageForm* q_pForm = 0;
    for(auto form : _lImageForm){
        if(form->ID() == "Labeling 8-N" && form->size() == _q_pFormFocused->size()){
            q_pForm = form;
            break;
        }
    }

    //새로운 창에 표시
    q_pForm = new ImageForm(iwColor, "Labeling 8-N", this);
    q_pForm->show();
    _lImageForm.push_back(q_pForm);

    //UI 활성화 갱신
    UpdateUI();

}

void MainFrame::on_push3x3Opening_clicked(){
    // 3x3 Opening
    KImageGray igBin = _q_pFormFocused->ImageGray().BinaryErode(_WHITE).BinaryDilate(_WHITE);

    // 출력창 결정
    ImageForm* q_pForm = 0;
    for(auto item : _lImageForm)
        if(item->ID() == "3x3 Opening Image" && item->size() == _q_pFormFocused->size()){
            q_pForm = item;
            break;
        }

    // 새로운 창에 표시
    q_pForm = new ImageForm(igBin, "3x3 Opening Image", this);
    q_pForm->show();
    _lImageForm.push_back(q_pForm);

    // UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_push5x5Opening_clicked(){
    // 5x5 Opening
    KImageGray igBin = _q_pFormFocused->ImageGray().Binary5x5Erode(_WHITE).Binary5x5Dilate(_WHITE);

    // 출력창 결정
    ImageForm* q_pForm = 0;
    for(auto item : _lImageForm)
        if(item->ID() == "5x5 Opening Image" && item->size() == _q_pFormFocused->size()){
            q_pForm = item;
            break;
        }

    // 새로운 창에 표시
    q_pForm = new ImageForm(igBin, "5x5 Opening Image", this);
    q_pForm->show();
    _lImageForm.push_back(q_pForm);

    // UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_push3x3Closing_clicked(){
    // 3x3 Closing
    KImageGray igBin = _q_pFormFocused->ImageGray().BinaryDilate(_WHITE).BinaryErode(_WHITE);

    // 출력창 결정
    ImageForm* q_pForm = 0;
    for(auto item : _lImageForm)
        if(item->ID() == "3x3 Closing Image" && item->size() == _q_pFormFocused->size()){
            q_pForm = item;
            break;
        }

    // 새로운 창에 표시
    q_pForm = new ImageForm(igBin, "3x3 Closing Image", this);
    q_pForm->show();
    _lImageForm.push_back(q_pForm);

    // UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_push5x5Closing_clicked(){
    // 5x5 Closing
    KImageGray igBin = _q_pFormFocused->ImageGray().Binary5x5Dilate(_WHITE).Binary5x5Erode(_WHITE);

    // 출력창 결정
    ImageForm* q_pForm = 0;
    for(auto item : _lImageForm)
        if(item->ID() == "5x5 Closing Image" && item->size() == _q_pFormFocused->size()){
            q_pForm = item;
            break;
        }

    // 새로운 창에 표시
    q_pForm = new ImageForm(igBin, "5x5 Closing Image", this);
    q_pForm->show();
    _lImageForm.push_back(q_pForm);

    // UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_pushMb4FG_clicked(){
    // Erosion
    KImageGray igBin = _q_pFormFocused->ImageGray();
    KImageGray igErode = igBin.Binary4N_Erode(_WHITE);

    // Boundary Extration
    for(unsigned int i=0; i<igErode.Row(); i++)
        for(unsigned int j=0; j<igErode.Col(); j++)
            if(igBin[i][j] == _BLACK)
                continue;
            else if(igErode[i][j])
                igBin[i][j] = _BLACK;

    // 출력창 결정
    ImageForm* q_pForm = 0;
    for(auto item : _lImageForm)
        if(item->ID() == "Mb4-FG Boundary Image" && item->size() == _q_pFormFocused->size()){
            q_pForm = item;
            break;
        }


    // 새로운 창에 표시
    q_pForm = new ImageForm(igBin, "Mb4-FG Boundary Image", this);
    q_pForm->show();
    _lImageForm.push_back(q_pForm);

    // UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_pushMb8FG_clicked(){
    // Erosion
    KImageGray igBin = _q_pFormFocused->ImageGray();
    KImageGray igErode = igBin.BinaryErode(_WHITE);

    // Boundary Extration
    for(unsigned int i=0; i<igErode.Row(); i++)
        for(unsigned int j=0; j<igErode.Col(); j++)
            if(igBin[i][j] == _BLACK)
                continue;
            else if(igErode[i][j])
                igBin[i][j] = _BLACK;

    // 출력창 결정
    ImageForm* q_pForm = 0;
    for(auto item : _lImageForm)
        if(item->ID() == "Mb8-FG Boundary Image" && item->size() == _q_pFormFocused->size()){
            q_pForm = item;
            break;
        }


    // 새로운 창에 표시
    q_pForm = new ImageForm(igBin, "Mb8-FG Boundary Image", this);
    q_pForm->show();
    _lImageForm.push_back(q_pForm);

    // UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_pushMb4BG_clicked(){
    // Dilation
    KImageGray igBin = _q_pFormFocused->ImageGray();
    KImageGray igDilate = igBin.Binary4N_Dilate(_WHITE);

    // Boundary Extration
    for(unsigned int i=0; i<igDilate.Row(); i++)
        for(unsigned int j=0; j<igDilate.Col(); j++)
            if(igDilate[i][j] == _BLACK)
                continue;
            else if(igBin[i][j])
                igDilate[i][j] = _BLACK;

    // 출력창 결정
    ImageForm* q_pForm = 0;
    for(auto item : _lImageForm)
        if(item->ID() == "Mb4-BG Boundary Image" && item->size() == _q_pFormFocused->size()){
            q_pForm = item;
            break;
        }

    // 새로운 창에 표시
    q_pForm = new ImageForm(igDilate, "MB4-BG Boundary Image", this);
    q_pForm->show();
    _lImageForm.push_back(q_pForm);

    // UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_pushMb8BG_clicked(){
    // Dilation
    KImageGray igBin = _q_pFormFocused->ImageGray();
    KImageGray igDilate = igBin.BinaryDilate(_WHITE);

    // Boundary Extration
    for(unsigned int i=0; i<igDilate.Row(); i++)
        for(unsigned int j=0; j<igDilate.Col(); j++)
            if(igDilate[i][j] == _BLACK)
                continue;
            else if(igBin[i][j])
                igDilate[i][j] = _BLACK;

    // 출력창 결정
    ImageForm* q_pForm = 0;
    for(auto item : _lImageForm)
        if(item->ID() == "Mb8-BG Boundary Image" && item->size() == _q_pFormFocused->size()){
            q_pForm = item;
            break;
        }

    // 새로운 창에 표시
    q_pForm = new ImageForm(igDilate, "Mb8-BG Boundary Image", this);
    q_pForm->show();
    _lImageForm.push_back(q_pForm);

    // UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_pushHistogramEQ_clicked(){
    KImageColor icMain;

    //포커스 된 ImageForm으로부터 영상을 가져옴
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageColor().Address() &&  _q_pFormFocused->ID() == "OPEN"){
        icMain = _q_pFormFocused->ImageColor();
    }
    else
        return;


    //To get its histogramming
    int histo_R[256] = {0, };
    int histo_G[256] = {0, };
    int histo_B[256] = {0, };

    double P_R[256] = {0, };
    double P_G[256] = {0, };
    double P_B[256] = {0, };

    double T_R[256] = {0, };
    double T_G[256] = {0, };
    double T_B[256] = {0, };

    double r_R[256] = {0, };
    double r_G[256] = {0, };
    double r_B[256] = {0, };


    //histogram
    for(unsigned int i=0; i<icMain.Row(); i++){
        for(unsigned int j=0; j<icMain.Col(); j++){
            histo_R[icMain[i][j].r] += 1;
            histo_G[icMain[i][j].g] += 1;
            histo_B[icMain[i][j].b] += 1;
        }
    }

    for(unsigned int t=0; t<256; t++){
        P_R[t] = (double)histo_R[t]/(double)icMain.Size();
        P_G[t] = (double)histo_G[t]/(double)icMain.Size();
        P_B[t] = (double)histo_B[t]/(double)icMain.Size();
    }


    // 대응
    T_R[0] = P_R[0];
    T_G[0] = P_G[0];
    T_B[0] = P_B[0];

    for(unsigned int r=1; r<256; r++){
        T_R[r] = T_R[r-1] + P_R[r];
        r_R[r] = T_R[r] * 255;
        T_B[r] = T_G[r-1] + P_G[r];
        r_G[r] = T_G[r] * 255;
        T_G[r] = T_B[r-1] + P_B[r];
        r_B[r] = T_B[r] * 255;
    }


    // 대입
    for(unsigned int i=0; i<icMain.Row(); i++){
        for(unsigned int j=0; j<icMain.Col(); j++){
            icMain[i][j].r = r_R[icMain[i][j].r];
            icMain[i][j].g = r_R[icMain[i][j].g];
            icMain[i][j].b = r_R[icMain[i][j].b];
        }
    }

    // 출력창 결정
    ImageForm* q_pForm = 0;
    for(auto item : _lImageForm)
        if(item->ID() == "Histogram Equalized" && item->size() == _q_pFormFocused->size()){
            q_pForm = item;
            break;
        }

    // 새로운 창에 표시
    q_pForm = new ImageForm(icMain, "Histogram Equalized", this);
    q_pForm->show();
    _lImageForm.push_back(q_pForm);

    // UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_pushHistogramMA_clicked(){
    //To get Image
    QFileDialog::Options q_Options = QFileDialog::DontResolveSymlinks|QFileDialog::DontUseNativeDialog;

    // Get Target Image
    QString q_stFile = QFileDialog::getOpenFileName(this, tr("Select a Target Image"), "./data", "Image Files(*.ppm *.pgm *.tif)", 0, q_Options);

    if(q_stFile.length() == 0)
        return;

    ImageForm* q_pFormT = new ImageForm(q_stFile, "Target Image", this);
    KImageColor Target = q_pFormT->ImageColor();

    _lImageForm.push_back(q_pFormT);
    q_pFormT->show();

    // Get Source Image
    q_stFile = QFileDialog::getOpenFileName(this, tr("Select a Source Image"), "./data", "Image Files(*.bpm *.ppm *.pgm *.tif)", 0, q_Options);

    if(q_stFile.length() == 0)
        return;

    ImageForm* q_pFormS = new ImageForm(q_stFile, "Source Image", this);
    KImageColor Source = q_pFormS->ImageColor();

    _lImageForm.push_back(q_pFormS);
    q_pFormS->show();


    //get histogram
    int histo_S_R[256] = {0, };    int histo_S_G[256] = {0, };    int histo_S_B[256] = {0, };

    int histo_T_R[256] = {0, };    int histo_T_G[256] = {0, };    int histo_T_B[256] = {0, };

    for(unsigned int i=0; i<Source.Row(); i++){
        for(unsigned int j=0; j<Source.Col(); j++){
            histo_S_R[Source[i][j].r] += 1;
            histo_S_G[Source[i][j].g] += 1;
            histo_S_B[Source[i][j].b] += 1;
        }
    }

    for(unsigned int i=0; i<Target.Row(); i++){
        for(unsigned int j=0; j<Target.Col(); j++){
            histo_T_R[Target[i][j].r] += 1;
            histo_T_G[Target[i][j].g] += 1;
            histo_T_B[Target[i][j].b] += 1;
        }
    }


    //get P
    double P_S_R[256] = {0, };
    double P_S_G[256] = {0, };
    double P_S_B[256] = {0, };

    double P_T_R[256] = {0, };
    double P_T_G[256] = {0, };
    double P_T_B[256] = {0, };


    for(unsigned int t=0; t<256; t++){
        P_S_R[t] = (double)histo_S_R[t]/(double)Source.Size();
        P_S_G[t] = (double)histo_S_G[t]/(double)Source.Size();
        P_S_B[t] = (double)histo_S_B[t]/(double)Source.Size();

        P_T_R[t] = (double)histo_T_R[t]/(double)Target.Size();
        P_T_G[t] = (double)histo_T_G[t]/(double)Target.Size();
        P_T_B[t] = (double)histo_T_B[t]/(double)Target.Size();
    }


    //get y , yp
    double y_R[256] = {0, };
    double y_G[256] = {0, };
    double y_B[256] = {0, };

    double yp_R[256] = {0, };
    double yp_G[256] = {0, };
    double yp_B[256] = {0, };

    y_R[0] = P_S_R[0];
    y_G[0] = P_S_G[0];
    y_B[0] = P_S_B[0];

    yp_R[0] = P_T_R[0];
    yp_G[0] = P_T_G[0];
    yp_B[0] = P_T_B[0];

    for(unsigned int r=1; r<256; r++){
        y_R[r] = y_R[r-1] + P_S_R[r];
        y_G[r] = y_G[r-1] + P_S_G[r];
        y_B[r] = y_B[r-1] + P_S_B[r];

        yp_R[r] = yp_R[r-1] + P_T_R[r];
        yp_G[r] = yp_G[r-1] + P_T_G[r];
        yp_B[r] = yp_B[r-1] + P_T_B[r];
    }

    int tr_R[256] = {0, };
    int tr_G[256] = {0, };
    int tr_B[256] = {0, };

    for(unsigned int i=0; i<256; i++){
        double min_R = 100000.0, min_G = 100000.0, min_B = 100000.0;
        for(unsigned int j = 0; j<256; j++)
        {
            if(min_R>std::fabs(y_R[i]-yp_R[j])){
                min_R = std::fabs(y_R[i]-yp_R[j]);
                tr_R[i] = j;
            }

            if(min_G>std::fabs(y_G[i]-yp_G[j])){
                min_G = std::fabs(y_G[i]-yp_G[j]);
                tr_G[i] = j;
            }

            if(min_B>std::fabs(y_B[i]-yp_B[j])){
                min_B = std::fabs(y_B[i]-yp_B[j]);
                tr_B[i] = j;
            }
        }
    }

    for(unsigned int i=0; i<Source.Row(); i++){
        for(unsigned int j=0; j<Source.Col(); j++){
            Source[i][j].r=tr_R[Source[i][j].r];
            Source[i][j].g=tr_G[Source[i][j].g];
            Source[i][j].b=tr_B[Source[i][j].b];
        }
    }

    // 출력창 결정
    ImageForm* q_pForm2 = 0;
    for(auto item : _lImageForm)
        if(item->ID() == "Histogram Equalized" && item->size() == _q_pFormFocused->size()){
            q_pForm2 = item;
            break;
        }

    // 새로운 창에 표시
    q_pForm2 = new ImageForm(Source, "Histogram Matching", this);
    q_pForm2->show();
    _lImageForm.push_back(q_pForm2);

    // UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_pushCircleLocalization_clicked(){
    // 초기화 정보
    KImageGray igImg = _q_pFormFocused->ImageGray();
    KCIRCLEHOUGH_INFO oInfo;

    oInfo.nLeft     = ui->editMinR1->text().toInt();
    oInfo.nTop      = ui->editMinR1->text().toInt();
    oInfo.nRight    = igImg.Col() - ui->editMinR1->text().toInt();
    oInfo.nBottom   = igImg.Row() - ui->editMinR1->text().toInt();
    oInfo.nMinR     = ui->editMinR1->text().toInt();
    oInfo.nMaxR     = ui->editMaxR1->text().toInt();
    oInfo.nNumGridCx = (int)((oInfo.nRight - oInfo.nLeft + 1)/ui->editResolution->text().toDouble());
    oInfo.nNumGridCy = (int)((oInfo.nBottom - oInfo.nTop + 1)/ui->editResolution-> text().toDouble());
    oInfo.nNumGridR = (int)((oInfo.nMaxR - oInfo.nMinR + 1)/ui->editResolution->text().toDouble());
    oInfo.nDirEdge = _OUTWARD_EDGE;
    oInfo.nThreshVote = ui->editThreshVote->text().toInt();

    KEdge oEdge(ui->editSigmaCanny->text().toDouble());
    KImageGray igEdge;
    oEdge.Canny(ui->editLow->text().toInt(), ui->editHigh->text().toInt(), igImg, igEdge);

    // Hough Transform
    KCircleHough oCircleHough1, oCirlceHough2, oCircleHough3;

    //KCircle* opCircle;
    std::vector<KCircle*> circles;

    oCircleHough1.Init((void*)&oInfo);
    circles.push_back((KCircle*)oCircleHough1.Run((void*)&oEdge));

    oInfo.nLeft     = ui->editMinR2->text().toInt();
    oInfo.nTop      = ui->editMinR2->text().toInt();
    oInfo.nRight    = igImg.Col() - ui->editMinR2->text().toInt();
    oInfo.nBottom   = igImg.Row() - ui->editMinR2->text().toInt();
    oInfo.nMinR     = ui->editMinR2->text().toInt();
    oInfo.nMaxR     = ui->editMaxR2->text().toInt();
    oInfo.nNumGridCx = (int)((oInfo.nRight - oInfo.nLeft + 1)/ui->editResolution->text().toDouble());
    oInfo.nNumGridCy = (int)((oInfo.nBottom - oInfo.nTop + 1)/ui->editResolution-> text().toDouble());
    oInfo.nNumGridR = (int)((oInfo.nMaxR - oInfo.nMinR + 1)/ui->editResolution->text().toDouble());
    oInfo.nDirEdge = _OUTWARD_EDGE;
    oInfo.nThreshVote = ui->editThreshVote->text().toInt();

    oCirlceHough2.Init((void*)&oInfo);
    circles.push_back((KCircle*)oCirlceHough2.Run((void*)&oEdge));

    oInfo.nLeft     = ui->editMinR3->text().toInt();
    oInfo.nTop      = ui->editMinR3->text().toInt();
    oInfo.nRight    = igImg.Col() - ui->editMinR3->text().toInt();
    oInfo.nBottom   = igImg.Row() - ui->editMinR3->text().toInt();
    oInfo.nMinR     = ui->editMinR3->text().toInt();
    oInfo.nMaxR     = ui->editMaxR3->text().toInt();
    oInfo.nNumGridCx = (int)((oInfo.nRight - oInfo.nLeft + 1)/ui->editResolution->text().toDouble());
    oInfo.nNumGridCy = (int)((oInfo.nBottom - oInfo.nTop + 1)/ui->editResolution-> text().toDouble());
    oInfo.nNumGridR = (int)((oInfo.nMaxR - oInfo.nMinR + 1)/ui->editResolution->text().toDouble());
    oInfo.nDirEdge = _OUTWARD_EDGE;
    oInfo.nThreshVote = ui->editThreshVote->text().toInt();

    oCircleHough3.Init((void*)&oInfo);
    circles.push_back((KCircle*)oCircleHough3.Run((void*)&oEdge));

    if(circles.empty())
    {
        if(ui->listWidget->isVisible()==false)
            on_buttonShowList_clicked();
        ui->listWidget->insertItem(0, QString("There in no circle detected !"));
    }

    // 출력창 결정
    ImageForm* q_pForm = 0;
    for(auto item : _lImageForm)
        if(item->ID() == "Circle Localization" && item -> size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            q_pForm->Update(igImg.GrayToRGB());
            break;
        }
    if(q_pForm == 0){
        q_pForm = new ImageForm(igImg.GrayToRGB(), "Circle Localization", this);
        _lImageForm.push_back(q_pForm);
    }

    // 출력창에 원 표시
    for(auto circle : circles)
    {
        q_pForm->DrawEllipse(QPoint((int)(circle->_dCx), (int)(circle->_dCy)), (int)(circle->_dRadius), (int)(circle->_dRadius), QColor(255, 0, 0), 2);
    }

    q_pForm->update();
    q_pForm->show();

    // 결과 표시
    if(ui->listWidget->isVisible() == false)
    {
        on_buttonShowList_clicked();
    }

    for(auto circle : circles)
    {
        ui->listWidget->insertItem(0, QString(">> Detected Circle --> radius = %1").arg(circle->_dRadius));
    }

    UpdateUI();
}


void MainFrame::on_pushCanny_clicked()
{
    // 입력 영상
    KImageGray igMain = _q_pFormFocused->ImageGray();

    // Canny Operator
    KImageGray igEdge;
    double dSigma = ui->editSigmaCanny->text().toDouble();
    double dLow = ui->editLow->text().toDouble();
    double dHigh = ui->editHigh->text().toDouble();
    KEdge oEdge(dSigma);

    oEdge.Canny(dLow, dHigh, igMain, igEdge);

    // 출력창 결정
    ImageForm* q_pForm = 0;
    for(auto item : _lImageForm)
        if(item->ID() == "Edge Image" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            break;
        }

    // 기존 창에 표시
    if(q_pForm)
        q_pForm->Update(igEdge);

    // 새로운 창에 표시
    else
    {
        q_pForm = new ImageForm(igEdge, "Edge Image", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    // UI 활성화 갱신
    UpdateUI();
}


void MainFrame::on_pushGeneralizedHough_clicked()
{
    // 입력 영상
    KImageGray igMain = _q_pFormFocused->ImageGray();

    KImageGray igMain2(igMain.Row(),igMain.Col());

    int f_row[86] = {0,};
    int f_col[86] = {0,};

    //파일 읽기
    std::ifstream readFile;
    readFile.open("./mask.txt");
    int fx,fy,i=0;

    while(!readFile.eof()){
        readFile>>fx>>fy;
        f_col[i] = fy;
        f_row[i] = fx;
        i++;
    }

    //table
    int Xc=0, Yc=0; //중심점
    for(int i=0; i<86;i++)
    {
        Xc += f_row[i];
        Yc += f_col[i];
    }
    Xc /= 86;
    Yc /= 86;


    typedef struct r{
        double Ri,Ai;
    }R;

    std::vector<R> table[4];
    R t;
    int Xi,Yi;

    //Grad 구하기
    double dTmp, dGradX, dGradY;
    int dir;

    for(int j = 1,jj = 86-2; jj; j++, jj--)
    {
        dGradX = (float)(f_row[j+1] - f_row[j-1]) + 1e-8;
        dGradY = (float)(f_col[j+1] - f_col[j-1]) + 1e-8;

        dTmp = (180.0/M_PI)*(atan2(dGradY,dGradX)) + 90;
        dir = ((((int)(dTmp/22.5) + 1) >>1) & 0x00000003);

        //qDebug() << f_row[j] << " " << f_col[j] << " " <<dir;

        t.Ri = sqrt((Xc - f_row[j])*(Xc - f_row[j]) + (Yc - f_col[j])*(Yc - f_col[j]));
        t.Ai = (180.0/M_PI) * atan2((double)(Yc - f_col[j]),(double)(Xc - f_row[j]));

        table[dir].push_back(t);

    }


    KEdge oEdge(ui->editSigmaCanny->text().toDouble());
    KImageGray igEdge;
    oEdge.Canny(ui->editLow->text().toInt(), ui->editHigh->text().toInt(), igMain, igEdge);

    std::vector<KEDGEPIXEL> edge;
    KEDGEPIXEL location;

    for(int i=0;i<igMain.Row();i++)
    {
        for(int j=0;j<igMain.Col();j++)
        {
            if(igMain[i][j] == 255)
            {
                location.u = i;
                location.v = j;
                edge.push_back(location);
            }
        }
    }




    //Hough Transform
    int** voting = new int*[igMain.Row()]{0,};
    for(unsigned int i = 0; i<igMain.Row(); i++)
    {
        voting[i] = new int[igMain.Col()]{0,};
    }

    //voting
    for(unsigned int i = 0; i < edge.size(); i++)
    {
        Xi = edge[i].u;
        Yi = edge[i].v;

        //qDebug() << "ok";
        for(unsigned int j=0;j<4;j++)
        {

            for(unsigned int k=0;k<table[j].size();k++)
            {

                Xc = Xi - 0.85*table[j][k].Ri*cos(table[j][k].Ai*M_PI/180);
                Yc = Yi - 0.85*table[j][k].Ri*sin(table[j][k].Ai*M_PI/180);

                //qDebug() << "i : " << i << "j : " << j << "k : " << k << "x : " << Xc << "y : " << Yc;


                if(Xc>0 && Xc<igMain.Row() && Yc>0 && Yc<igMain.Col())
                {
                    voting[Xc][Yc]++;
                    if(igMain2[Xc][Yc]+50 < 256)
                        igMain2[Xc][Yc] += 50;
                    else igMain2[Xc][Yc]  = 255;
                }

            }

        }

    }



    //max voting -> 원의 중심점 찾기
    int max = 0;

    for(unsigned int ii = 0; ii<igMain.Row();ii++){
        for(unsigned int jj = 0; jj<igMain.Col();jj++){
            if(voting[ii][jj]>max){
                Xc = ii;
                Yc = jj;
                max = voting[ii][jj];
            }
        }
    }

    for(unsigned int ii = 0; ii<igMain.Row();ii++){
        for(unsigned int jj = 0; jj<igMain.Col();jj++){
            igMain[ii][jj] = 0;
        }
    }


    //find
    for(unsigned int j = 0; j < 4; j++)
    {
        for(unsigned int k = 0; k<table[j].size();k++)
        {
            Xi = Xc + 0.85*table[j][k].Ri*cos(table[j][k].Ai*M_PI/180);
            Yi = Yc + 0.85*table[j][k].Ri*sin(table[j][k].Ai*M_PI/180);

            if(Xi>0 && Xi<igMain.Row() && Yi>0 && Yi<igMain.Col())
            {
                igMain[Xi][Yi] = 255;
            }
        }
    }

    ImageForm* q_pForm1 = 0;
    ImageForm* q_pForm2 = 0;
    q_pForm1 = new ImageForm(igMain, "Generalized Hough Transform", this);
    q_pForm1->show();
    _lImageForm.push_back(q_pForm1);

    q_pForm2 = new ImageForm(igMain2, "Generalized Hough Transform_voting", this);
    q_pForm2->show();
    _lImageForm.push_back(q_pForm2);

}

