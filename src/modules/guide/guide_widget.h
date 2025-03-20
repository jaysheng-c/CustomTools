/**
  ********************************************************************************
  * @file           : guide_widget.h
  * @author         : jaysheng
  * @brief          : None
  * @attention      : None
  * @date           : 2025/03/20
  * @version        : 1.0
  ********************************************************************************
  */


#ifndef GUIDE_WIDGET_H
#define GUIDE_WIDGET_H

#include <QWidget>

class GuideWidget final : public QWidget {
Q_OBJECT
public:
    explicit GuideWidget(QWidget *parent = nullptr);
    void setTarget(const QRect &target) { m_target = target; }

protected:
    void paintEvent(QPaintEvent *event) override;

    QRect m_target;
};



#endif //GUIDE_WIDGET_H
