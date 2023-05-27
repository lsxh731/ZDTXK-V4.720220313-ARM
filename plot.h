/****************************************************************************
** CopyRight(c) 2010,��������ͨ��ѧ
** All rights reserved
**
** �ļ�����: plot.h
** ժҪ: ���ߴ���
**       
**
** ��ǰ�汾: 4.0.0.0
** ����:  ������
** �������: 2017.12.09
**
** ȡ���汾:
** ����:
** ������ڣ�
**
** ��ʷ�޸ļ�¼:��
** ���ߡ��������޸�ʱ�䡡���汾�������޸İ汾
** ������      2017.12.09   V4.0      ����
**
****************************************************************************/
#pragma once
#include <QMouseEvent>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_marker.h>

#include "plotuserclass.h"

//���ߴ�����
class CPlot :public QwtPlot
{
	Q_OBJECT
public:
	CPlot(QWidget *pParent = NULL, 
			const int &nCurvesCount = 1, //���߸���
			const int & nYAxisUsedMode = CPlot::YAxis_Left,	 //Y����ʹ������
			const int & nXAxisMode = CPlot::XScale_Default,//X������ģʽ
			const QString &strTitle = "",				 //PLOT����
			const QColor &rcBackGround = QColor(Qt::black)); //������ɫ //Qt::black  //lightGray
	~CPlot(void);

public:
	//Y����ʹ��ģʽ������������ʾģʽ����������ʾģʽ������������ʾģʽ
	enum
	{
		YAxis_Left = 0,//��������ʾģʽ
		YAxis_Right,   //��������ʾģʽ
		YAxis_LeftRight//����������ʾģʽ
	};

	//X����ģʽ����Ĭ����ֵ�ࡢʱ���ࡢƵ����
	enum
	{
		XScale_Default = 3,
		XScale_Time,
		XScale_RMSTime,
		XScale_Freq
	};

public slots:
signals:

public:
	//��ʾ����
	void showCurve(const QTime &timeBegin,          //ʱ����Ļ�׼ʱ��
		           const int &nTimeInterval,        //ʱ����
				   const QString &strCurveTtile,	//��������
				   const QString &strXAxisTitle,	//X���ע
				   const QString &strYAxisTitle,	//Y���ע
				   const QList<double> &lstYValue,  //Y������ֵ
				   QColor CurveColor);	            //X��Y������ֵ
private:
	void init();
	void init_Curve();               //���������߶���
	void init_Curve(int nCurveCount);//���������߶���
	void init_XAxis();
	void initZoomer();
private:
	QwtPlotCurve *m_pNewPlotCurve;
	QwtLegend *m_pLegend;
	QwtPlotGrid *m_pPlotGrid;	
	CZoomer *m_pZoomer;//���š����١�ƽ�ơ��α�

	CTimeScaleDraw *m_pXScalDraw;

	float m_dAxisMax;
	float m_dAxisMin;
	
	int m_nCurveCount;    //���߸���
	int m_nYAxisUsedMode; //YAxisʹ��ģʽ
	int m_nXAxisMode;     //X������ģʽ

	QString m_strTitle;   //Plot Title
	QColor m_rcBackGround;//������ɫ
};
