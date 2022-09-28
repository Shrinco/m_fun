#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

//my common function namespace
namespace mcfunc 
{
	//以特定符号分割字符串
	void StringSplit(const std::string input, std::vector<std::string> &ouput, const std::string &splits);

	//根据类别数目生成颜色列表
	uchar* get_color_map_list(int num_classes);

	//生成标签信息
	std::string makelabelinfo(std::string label, int id, float score);

	//根据图像的输入路径以及名称保存图片
	void SaveImg(const std::string& image_name, const cv::Mat& input_img, const std::string& name_suffix = "");
}
