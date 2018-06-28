#include "opencv2/opencv.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

/* �Լ� */
void collect_trainImage(Mat& trainingData, Mat& labels, int Nimages);
void write_traindata(string fn, Mat trainingData, Mat classes);

void main() {
	Mat trainingData, labels;
	collect_trainImage(trainingData, labels, 70); // �н� ������ ����
	write_traindata("SVMDATA.xml", trainingData, labels);     // ���� ����
}

void collect_trainImage(Mat& trainingData, Mat& labels, int Nimages) {  // Nimages= 35 + 35
	for (int i = 0; i < Nimages; i++) {
		printf("�̹��� ����غ��� %d.png\n",i);
		string fname = format("C:\\Users\\wwwo3\\source\\repos\\OpenCV Test\\OpenCV Test\\trainimage\\%d.png",i);
		//"C:\\opencv-3.4\\sources\\data\\haarcascades\\haarcascade_frontalface_alt.xml"
		Mat img = imread(fname,0);
		CV_Assert(img.data);

		Mat tmp = img.reshape(1, 1);  // �н� ������ 1�� �����ͷ� �����
		int label = (i < 35) ? 1 : 0;  // 0~69�� �̹����� ���۶�, 70~139�� �̹����� ���۶� �ƴѰ�
		trainingData.push_back(tmp);
		labels.push_back(label);
	}
	trainingData.convertTo(trainingData, CV_32FC1);
}

void write_traindata(string fn, Mat trainingData, Mat classes) {
	FileStorage fs(fn, FileStorage::WRITE); // ������
	fs << "trainingData" << trainingData; // �н� ������ ��� ����
	fs << "classes" << classes; // ���̺� ��� ����
	fs.release();
}