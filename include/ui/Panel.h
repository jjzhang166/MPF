#pragma once
#include "UIElement.h"

NS_MPF
NS_UI

//���ж����Ԫ�ص� UI ����
class Panel : public UIElement
{
public:
	MPF_API Panel();
	MPF_API virtual ~Panel();

	//��ȡ��Ԫ��
	MPF_API const std::vector<UIElement*>& GetChildren() const;
	//��ȡ��Ԫ��
	MPF_API std::vector<UIElement*>& GetChildren();
	//������Ԫ��
	MPF_API void AddChild(UIElement& elem);

	//��ȡ����
	MPF_API DECLARE_GETTYPE(Panel);
	MPF_API DECLARE_GETINSTANTTYPE(Panel);
public:
protected:
	MPF_API virtual void RenderCore(MPF::Visual::RenderCoreProvider& renderer, RenderArgs&& args);
	MPF_API virtual void UpdateCore(MPF::Visual::RenderCoreProvider& renderer, float elapsedTime);
protected:
	std::vector<UIElement*> children;

	DECLARE_UI_FUNCS
private:
	DECLARE_UI_VALUES
	DECLARE_TYPE(Panel)
};

NS_ED
NS_ED