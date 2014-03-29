#pragma once
#include "Geometry.h"

NS_MPF
NS_VSL

//ֱ��
class Line : public Geometry
{
public:
	//����һ��ֱ��
	MPF_API explicit Line(const Point& startPoint, const Point& endPoint);

	//��ȡ��������
	MPF_API virtual std::vector<Point> GetPoints() const;

	//��ȡ��ʼ��
	const Point& GetStartPoint() const mnoexcept { return startPoint; }
	//��ȡ������
	const Point& GetEndPoint() const mnoexcept { return endPoint; }

	//ͨ��Y��ֱ���ϵ�X
	uint GetX(uint y) const mnoexcept;
	//ͨ��Y��ֱ���ϵ�UV
	std::pair<float, float> GetUV(uint y) const mnoexcept;

	//��ȡ����
	DECLARE_GETTYPE(Line)
private:
	Point startPoint;
	Point endPoint;

	DECLARE_TYPE(Line)
};

NS_ED
NS_ED