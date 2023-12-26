#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QDialog>

namespace Ui {
class MainFrame;

}

class ImageForm;

class MainFrame : public QDialog
{
    Q_OBJECT

private:
    Ui::MainFrame *ui;

    std::vector<ImageForm*>  _lImageForm;
    ImageForm*               _q_pFormFocused;

public:
    explicit MainFrame(QWidget *parent = 0);
    ~MainFrame();

    void    ImageFormFocused(ImageForm* q_pImageForm)
            {   _q_pFormFocused  = q_pImageForm;   //활성화된 창의 포인터를 저장함
                UpdateUI();                        //UI 활성화 갱신
            }
    void    UpdateUI();
    void    CloseImageForm(ImageForm* pForm);

public:
    void    focusInEvent(QFocusEvent *event);
    void    OnMousePos(const int& nX, const int& nY, ImageForm* q_pForm);

private slots:
    void on_buttonOpen_clicked();
    void on_buttonDeleteContents_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_buttonShowList_clicked();
    void on_pushRGB2HSI_clicked();
    void on_pushRGB2NRG_clicked();
    void on_pushContrast_clicked();
    void on_pushOtsu_clicked();
    void on_push3x3Dilation_clicked();
    void on_push5x5Dilation_clicked();
    void on_push3x3Erosion_clicked();
    void on_push5x5Erosion_clicked();
    void on_push4N_clicked();
    void on_push8N_clicked();
    void on_push3x3Opening_clicked();
    void on_push5x5Opening_clicked();
    void on_push3x3Closing_clicked();
    void on_push5x5Closing_clicked();
    void on_pushMb4FG_clicked();
    void on_pushMb8FG_clicked();
    void on_pushMb4BG_clicked();
    void on_pushMb8BG_clicked();
    void on_pushHistogramEQ_clicked();
    void on_pushHistogramMA_clicked();
    void on_pushCircleLocalization_clicked();

    void on_pushCanny_clicked();

    void on_pushGeneralizedHough_clicked();

protected:
    void closeEvent(QCloseEvent* event);
};

#endif // MAINFRAME_H
