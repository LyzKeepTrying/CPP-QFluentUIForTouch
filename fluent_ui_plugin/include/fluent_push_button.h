#ifndef FLUENT_PUSH_BUTTON_H
#define FLUENT_PUSH_BUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>
#include <QEasingCurve>

#include "define.h"
#include "theme.h"

#if defined(FLUENTUI_PLUGIN_LIBRARY)
#define FLUENTUI_PLUGIN_EXPORT Q_DECL_EXPORT
#else
#define FLUENTUI_PLUGIN_EXPORT Q_DECL_IMPORT
#endif

class FLUENTUI_PLUGIN_EXPORT FluentPushButton : public QPushButton {
    Q_OBJECT
    DECLARE_PROPERTY(QColor, BackgroundColor, QFluentUI::ThemeColor::Light::area_color)
    DECLARE_PROPERTY(QColor, TextColor, QFluentUI::ThemeColor::Light::text_color)
    DECLARE_PROPERTY(QColor, BorderColor, QFluentUI::ThemeColor::Light::border_color)

public:
    explicit FluentPushButton(const QString& text, QWidget* parent = nullptr);
    explicit FluentPushButton(QWidget* parent = nullptr);

    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    constexpr static int k_default_width_ = 48;
    constexpr static int k_default_height_ = 24;
};

#endif // FLUENT_PUSH_BUTTON_H
