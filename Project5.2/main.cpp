#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
//��������ͷ
int main()
{
	VideoCapture cap;          //ʵ����һ��videocapture�࣬����Ϊcap
	cap.open(0);              //�򿪱����ĵ�һ������ͷ
	if (!cap.isOpened())     //isOpened()�����Ƶ�Ƿ�����������������1
	{
		std::cout << "���ɴ���Ƶ�ļ�" << std::endl;
		return -1;
	}
	double fps = cap.get(CAP_PROP_FPS);//ͨ��get()����ͬ�������Ի����Ƶ��fps
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		cv::Mat frame;
		cv::Mat dst;
		cv::Size ksize;
		double sigmaX;
		double sigmaY;
		ksize.height = 3;
		ksize.width = 3;
		sigmaX = 3;
		sigmaY = 3;
		bool rSucess = cap.read(frame);
		if (!rSucess)
		{
			std::cout << "���ܴ���Ƶ�ж�ȡ֡" << std::endl;
			break;
		}
		else
		{
			//��ֵ�˲�����
			blur(frame, dst, ksize);
			cv::imshow("frame ", frame);
			cv::imshow("dst ", dst);
		}
		waitKey(30);

	}
	return 0;
}
