#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

//my common function namespace
namespace mcfunc 
{
	//���ض����ŷָ��ַ���
	void StringSplit(const std::string input, std::vector<std::string> &ouput, const std::string &splits);

	//���������Ŀ������ɫ�б�
	uchar* get_color_map_list(int num_classes);

	//���ɱ�ǩ��Ϣ
	std::string makelabelinfo(std::string label, int id, float score);

	//����ͼ�������·���Լ����Ʊ���ͼƬ
	void SaveImg(const std::string& image_name, const cv::Mat& input_img, const std::string& name_suffix = "");
}
