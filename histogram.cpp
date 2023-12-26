#include "histogram.h"

double KHisto::Mean()
{
    if(KVector::Pointer() == 0)
        return 0.0;

    double dSum = 0.0;
    double dMean = 0.0;

    for(int i=0,ii=KVector::Dim(); ii; i++,ii--)
    {
        dMean 	+= (double)(i)*_ppA[i][0];
        dSum 	+= _ppA[i][0];
    }

    return (dMean /= dSum);
}



KBINARIZATION_OUTPUT* KHisto::Otsu(const KImageGray* igpImg,KImageGray* igpOut)
{
    //histogram
    if(igpImg)
        Histogram(*igpImg);
    else
        assert(KVector::Pointer());

    //apply Ostu' thresholding
    double      dpQ1[256],dpMyu1[256],dpMyu2[256];
    double		dMyu 	= Mean();
    KVector		vP 	 	= KVector::Normalize(_UNITSUM_NORMALIZE);
    int			nThresh = 1;
    double		dMax 	= 0.0, dSigmaB;

    dpQ1[0]   	= vP[0];
    dpMyu1[0] 	= 0.0;

    for(int i=0; i<254; i++)
    {
        dpQ1[i+1] 	= dpQ1[i] + vP[i+1];
        if(_ABS(1.0-dpQ1[i+1]) < 0.000000001)
            break;

        if(dpQ1[i+1]  == 0.0)
        {
            dpMyu1[i+1] = 0.0;
            continue;
        }

        dpMyu1[i+1]	= (dpQ1[i]*dpMyu1[i] + (double)(i+1)*vP[i+1])/dpQ1[i+1];
        dpMyu2[i+1] =  (dMyu-dpQ1[i+1]*dpMyu1[i+1]) / (1.0 - dpQ1[i+1]);

        //between-class variance
        dSigmaB = dpQ1[i+1]*(1.0-dpQ1[i+1])*_SQR(dpMyu1[i+1] - dpMyu2[i+1]);

        //search the maximum
        if(dSigmaB > dMax)
        {
            dMax 	 	= dSigmaB;
            nThresh  	= i+1;
        }
    }

    //output image
    if(igpOut)
    {
        if(igpOut != igpImg)
            igpOut->Create(igpImg->Row(),igpImg->Col());
        for(int i=0,ii=igpImg->Row(); ii; i++,ii--)
            for(int j=0,jj=igpImg->Col(); jj; j++,jj--)
                (*igpOut)[i][j] = ((*igpImg)[i][j] > nThresh ? 0xFF : 0);
    }

    //return the threshold
    _oOtsuOutput.nThresh  = nThresh;
    _oOtsuOutput.dMyuG    = dMyu;
    _oOtsuOutput.dMyu1    = dpMyu1[nThresh];
    _oOtsuOutput.dMyu2    = dpMyu2[nThresh];
    _oOtsuOutput.dQ1      = dpQ1[nThresh];
    _oOtsuOutput.dQ2      = 1.0-dpQ1[nThresh];

    return &_oOtsuOutput;
}



void KHisto::Histogram(const KImageGray& igImg,const int& nType,const int& nDir,const int& nS,const int& nE)
{
    int 	nRow 	= igImg.Row();
    int 	nCol 	= igImg.Col();

    if(nType == _GRAY && nDir == -1)
    {
        //init.
        KVector::Create(256);

        //histograming according to intensities
        double* dpHisto = (double*)KVector::Pointer();

        for(int ic=nRow,i=0; ic; ic--, i++)
            for(int jc=nCol,j=0; jc; jc--, j++)
                dpHisto[igImg[i][j]] ++;
    }
    else if(nType == _GRAY && nDir == _X_AXIS)
    {
        //init.
        int	nSt = (nS ? nS : 0);
        int nEn = (nE ? nE+1 : nCol);

        KVector::Create(nEn-nSt);
        double* dpHisto = (double*)KVector::Pointer();

        //compute the mean intensities according to X coordinates
        for(int i=0,ic=this->Dim(); ic; i++,ic--)
        {
            for(int jc=nRow,j=0; jc; jc--, j++)
                dpHisto[i] += igImg[j][i];
            dpHisto[i] /= (double)(nRow);
        }
    }
    else if(nType == _BINARY && nDir == _X_AXIS)
    {
        //init.
        KVector::Create(nCol);

        //histograming according to X coordinates
        double* dpHisto = (double*)KVector::Pointer();
        int     nSt = (nS ? nS : 0);
        int     nEn = (nE ? nE+1 : nCol);

        for(int i=nSt; i<nEn; i++)
            for(int jc=nRow,j=0; jc; jc--, j++)
                if(igImg[j][i])
                    dpHisto[i] ++;
    }
    else if(nType == _BINARY && nDir == _Y_AXIS)
    {
        //init.
        KVector::Create(nRow);

        //histograming according to X coordinates
        double* dpHisto = (double*)KVector::Pointer();
        int     nSt = (nS ? nS : 0);
        int     nEn = (nE ? nE+1 : nRow);


        for(int i=nSt; i<nEn; i++)
            for(int jc=nCol,j=0; jc; jc--, j++)
                if(igImg[i][j])
                    dpHisto[i] ++;
    }
}

void KHisto::HistogramAdded(const KImageGray& igImg)
{
    if(KVector::Address() == 0)
        KVector::Create(256);

    //histograming according to intensities
    double* dpHisto = (double*)KVector::Address();

    for(int i=0; i<igImg.Row(); i++)
        for(int j=0; j<igImg.Col(); j++)
            dpHisto[igImg[i][j]] ++;
}
/*
void KHisto::Histogram(const KPtrList<KImageGray*>& plImg)
{
    //init.
    KVector::Create(256);

    //histograming according to intensities
    double* dpHisto	= (double*)KVector::Pointer();

    for(int n=0; n<plImg.Count(); n++)
    {
        KImageGray& igImg 	= *plImg[n];
        int               nRow 	= igImg.Row();
        int               nCol 	= igImg.Col();

        for(int ic=nRow,i=0; ic; ic--, i++)
            for(int jc=nCol,j=0; jc; jc--, j++)
                dpHisto[igImg[i][j]] ++;
    }
}
*/

void KHisto::HEQ(KImageGray& igImg, bool bSetHisto)
{
    //histograming according to intensities
    Histogram(igImg);

    //accumulated histogram
    double*  dpHisto = KVector::Address();

    for(int i=1, ic=KVector::Size()-1; ic; ic--, i++)
        dpHisto[i] += dpHisto[i-1];

    //Histogram Equalization
    for(int i=0, ic=KVector::Size(); ic; ic--, i++)
        dpHisto[i] = dpHisto[i] / (double)(igImg.Size());

    //transform the original image
    for(int ic=igImg.Row(),i=0; ic; ic--,i++)
        for(int jc=igImg.Col(),j=0; jc; jc--,j++)
            igImg[i][j] = (unsigned char)(dpHisto[igImg[i][j]]*255.0 + 0.5);

    //re-histograming
    if(!bSetHisto)
        return;

    memset(dpHisto,0,sizeof(double)*KVector::Size());
    for(int ic=igImg.Row(),i=0; ic; ic--,i++)
        for(int jc=igImg.Col(),j=0; jc; jc--,j++)
            dpHisto[igImg[i][j]] ++;
}
