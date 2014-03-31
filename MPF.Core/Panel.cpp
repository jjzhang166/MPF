#include "stdafx.h"
#include "../include/ui/Panel.h"

using namespace MPF;
using namespace MPF::UI;
using namespace MPF::Visual;

DEFINE_TYPE(Panel, MPF::UI::Panel)
DEFINE_UI_VALUES(Panel)
DEFINE_UI_FUNCS(Panel, UIElement)

DependencyProperty<std::vector<UIElement*>> Panel::ChildrenProperty(L"Children", std::vector<UIElement*>());

Panel::Panel()
{

}

Panel::~Panel()
{
	GetChildren().clear();
}

const std::vector<UIElement*>& Panel::GetChildren() const
{
	return GetValue(ChildrenProperty);
}

std::vector<UIElement*>& Panel::GetChildren()
{
	return GetValue(ChildrenProperty);
}

void Panel::RenderCore(MPF::Visual::RenderCoreProvider& renderer, RenderArgs&& args)
{
	auto children = GetChildren();
	for (auto child : children)
	{
		massert(child != nullptr);
		child->Render(renderer, RenderArgs{ child->MeasureBound() });
	}

	UIElement::RenderCore(renderer, std::move(args));
}

void Panel::UpdateCore(MPF::Visual::RenderCoreProvider& renderer, float elapsedTime)
{
	auto children = GetChildren();
	for (auto child : children)
	{
		massert(child != nullptr);
		child->Update(renderer, elapsedTime);
	}

	UIElement::UpdateCore(renderer, elapsedTime);
}