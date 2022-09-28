#include "m_fun.h"


namespace mcfunc
{


	void StringSplit(const std::string input, std::vector<std::string> &ouput, const std::string &splits)
	{
		if (input == "")
		{
			std::cerr << "input string is empty, please check the string your input!!!" << std::endl;
			return;
		}
		//std::vector<std::string> res;

		//在字符串末尾也加入分隔符，方便截取最后一段
		//std::string splits = "/";
		std::string strs = input + splits;
		size_t pos = strs.find(splits);
		int step = splits.size();

		// 若找不到内容则字符串搜索函数返回 npos
		while (pos != strs.npos)
		{
			std::string temp = strs.substr(0, pos);
			ouput.push_back(temp);
			//去掉已分割的字符串,在剩下的字符串中进行分割
			strs = strs.substr(pos + step, strs.size());
			pos = strs.find(splits);
			//std::cout << "img name: " << temp << std::endl;
		}
	}


	uchar* get_color_map_list(int num_classes)
	{
		uchar *color_list = new uchar[num_classes * 3];
		num_classes += 1;
		for (int i = 1; i < num_classes; i++)
		{
			int j = 0;
			int lab = i;
			while (lab != 0)
			{
				color_list[(i - 1) * 3] |= (uchar)(((lab >> 0) & 1) << (7 - j));
				color_list[(i - 1) * 3 + 1] |= (uchar)(((lab >> 1) & 1) << (7 - j));
				color_list[(i - 1) * 3 + 2] |= (uchar)(((lab >> 2) & 1) << (7 - j));

				j += 1;
				lab >>= 3;
			}
		}
		return color_list;
	}


	std::string makelabelinfo(std::string label, int id, float score)
	{
		std::string describe_str = std::to_string(id) + ":";
		describe_str += label + "-";
		describe_str += std::to_string(score);

		return describe_str;
	}

	//根据图像的名称保存图片
	void SaveImg(const std::string& image_name, const cv::Mat& input_img, const std::string& name_suffix)
	{
		std::vector<std::string> img_name_str_;
		StringSplit(image_name, img_name_str_, "\\");

		std::vector<std::string> img_name_str_1_;
		StringSplit(img_name_str_.back(), img_name_str_1_, ".");
		
		std::cout << "img name: " << img_name_str_.back() << std::endl;
		std::cout << "img name: " << img_name_str_1_.front() << std::endl;

		std::string img_name_ = img_name_str_1_.front()+ name_suffix + ".jpg";
		std::cout << "img name: " << img_name_ << std::endl;

		std::string save_img_path_ = "D:\\images\\front(1)\\save\\" + img_name_;
		//cv::resize(img_save_,img_save_,cv::Size(800,600));
		//cv::imshow("test", img_save_);
		cv::imwrite(save_img_path_, input_img);
	}
}