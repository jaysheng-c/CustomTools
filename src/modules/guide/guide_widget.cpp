/**
********************************************************************************
  * @file           : guide_widget.cpp
  * @author         : jaysheng
  * @brief          : None
  * @attention      : None
  * @date           : 2025/03/20
  * @version        : 1.0
  ********************************************************************************
  */

#include "guide_widget.h"
#include <QPainter>

GuideWidget::GuideWidget(QWidget *parent)
{
    // setPalette(Qt::transparent); // 设置背景透明
    setAttribute(Qt::WA_TransparentForMouseEvents); // 鼠标事件穿透
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_AlwaysStackOnTop);
    setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
}

void GuideWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 填充半透明黑色背景
    painter.fillRect(this->rect(), QColor(0, 0, 0, 160));
    // painter.fillRect(this->rect(), Qt::transparent);
    qDebug() << this->rect();

    // 清除目标区域以达到突出显示效果
    painter.setCompositionMode(QPainter::CompositionMode_Clear);
    painter.eraseRect(m_target);
    // painter.fillRect(m_target, Qt::transparent);
}
