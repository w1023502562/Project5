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
		cv::Mat dst1;
		cv::Mat dst2;
		cv::Size ksize;
		double scale;
		double delta;
		ksize.height = 3;
		ksize.width = 3;
		scale = 1;
		delta = 0;
		bool rSucess = cap.read(frame);
		if (!rSucess)
		{
			std::cout << "���ܴ���Ƶ�ж�ȡ֡" << std::endl;
			break;
		}
		else
		{
			//��Ե��ȡ����
			Sobel(frame, dst1, CV_16SC1, 1, 0, 3);

			Sobel(frame, dst2, CV_16SC1, 0, 1, 3);
			convertScaleAbs;

			cv::imshow("frame ", frame);
			cv::imshow("dst1 ", dst1);
			cv::imshow("dst2 ", dst2);
		}
		waitKey(30);

	}
	return 0;
}
