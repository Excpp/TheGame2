#include "GGEngine/pch.h"
#include "GGEngine/Modules/Window/WindowModule.h"

const sf::Vector2u  Settings::windowSizes[uint8_t(WindowSize::SCount)] = { { 1280, 720 },{ 1920, 1080 } }; // "resolution" variable can be used as an index in this array

const Vec2f Settings::ViewResolution = Vec2f(1920, 1080);

const float_t Settings::WorldToViewRatio = 100.f;



void WindowModule::startUp()
{
	Settings defaultSettings;
	defaultSettings.makeWindow(window);
	window.setKeyRepeatEnabled(false);
}

sf::RenderWindow & WindowModule::getWin()
{
	return window;
}

const sf::RenderWindow & WindowModule::getWin() const
{
	return window;
}

Vec2f WindowModule::getViewToWindowRatio() const
{
	return Vec2f(VectorScaledByVector(asVec<Vec2f>(window.getView().getSize()), 1.f / asVec<Vec2f>(window.getSize())));
}