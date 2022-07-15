#include "clickergame.h"
#include <QDebug>

#define CLICK 1

ClickerGame::ClickerGame() :
    successfulClick(0),
    failedClick(0),
    clicks(0)
{
    qInfo() << "Объект данных игры загружен";
}

void ClickerGame::setSuccessCountClick(const int click)
{
    successfulClick = click;
}

void ClickerGame::addSuccessClick()
{
    successfulClick += CLICK;
}

int ClickerGame::getSuccessCountClick()
{
    return successfulClick;
}

void ClickerGame::setFailedCountClick(const int click)
{
    failedClick = click;
}

void ClickerGame::addFailedClick()
{
    failedClick += CLICK;
}

int ClickerGame::getFailedCountClick()
{
    return failedClick;
}

void ClickerGame::setOneClick()
{
    clicks += CLICK;
}

int ClickerGame::getAllClicksAndClear()
{
    unsigned int returnClicks = clicks;
    clicks = 0;
    return returnClicks;
}

void ClickerGame::allClear()
{
    successfulClick = 0;
    failedClick = 0;
    clicks = 0;
}



