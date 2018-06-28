#include "opencv2/opencv.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

void read_trainData(string fn, Mat& trainingData, Mat& labels) {
	FileStorage fs(fn, FileStorage::READ); // ���Ͻ��丮�� ��ü ����
	//CV_Assert(fs.isOpened()); // ����ó��
	
	fs["TrainingData"] >> trainingData; // �н������� ��ķ� �б�
	fs["classes"] >> labels; //���̺� ��ķ� �б�
	fs.release();
	trainingData.convertTo(trainingData, CV_32FC1); //float�� ��ȯ -> SVM �н��Ϸ��� ������ ����� float���̿�����
	
}

Ptr<ml::SVM> SVM_create(int type, int max_iter, double epsilon) {
	Ptr<ml::SVM> svm = ml::SVM::create(); //SVM ��ü���� -> Ptr Ŭ������ ������
	// �̰� �������� ����

	/*SVM �н��ϱ����� ���� �Ķ���� ����*/
	svm->setType(ml::SVM::C_SVC); //C-Support Vector Classification
	svm->setKernel(ml::SVM::LINEAR); // ���� SVM
	svm->setGamma(1); // Ŀ���Լ��� ������
	svm->setC(1);  // ����ȭ�� ���� C �Ķ����

	TermCriteria criteria(type, max_iter, epsilon);
	// type : �ݺ� �˰����� ��� ���� (������ �ִ� 1000�� �ݺ� �н�) 
	// -> CV_TERMCRIT_ITER : �ݺ�Ƚ���� �������� �ݺ� / CV_TERMCRIT_EPS : ��Ȯ���� �������� �ݺ�
	// max_iter : �ִ� �ݺ��� �ݺ��˰����� ���� �������� 
	// epsilon : ��Ȯ��

	svm->setTermCriteria(criteria); // �н� �ݺ����� ����
	return svm;
}

int main() {
	Mat trainingData, labels;
	read_trainData("C:\\Users\\wwwo3\\source\\repos\\OpenCV Test\\OpenCV Test\\SVMDATA.xml",trainingData,labels);
	if (trainingData.empty()) {
		printf("svmdata.xml �о���� ������\n");
	}
	
	// SVM ��ü ����
	Ptr<ml::SVM> svm = SVM_create(CV_TERMCRIT_ITER, 1000, 0); 
	svm->train(trainingData, ml::ROW_SAMPLE, labels); // �н� ����
	svm->save("C:\\Users\\wwwo3\\source\\repos\\OpenCV Test\\OpenCV Test\\SVMtrain.xml");
	return 0;
}