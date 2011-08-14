#include "luainterface.h"
#include <graphics/fontmanager.h>
#include <ui/ui.h>
#include <net/protocol.h>

void LuaInterface::registerFunctions()
{
    // easy typing _1, _2, ...
    using namespace std::placeholders;

    // UIWidget
    g_lua.registerClass<UIWidget>();
    g_lua.bindClassStaticFunction<UIWidget>("create", &UIWidget::create);

    g_lua.bindClassMemberFunction("destroy", &UIWidget::destroy);
    g_lua.bindClassMemberFunction("addChild", &UIWidget::addChild);

    g_lua.bindClassMemberField<UIWidget>("id", &UIWidget::getId, &UIWidget::setId);
    g_lua.bindClassMemberField<UIWidget>("enabled", &UIWidget::isEnabled, &UIWidget::setEnabled);
    g_lua.bindClassMemberField<UIWidget>("visible", &UIWidget::isVisible, &UIWidget::setVisible);
    g_lua.bindClassMemberField<UIWidget>("width", &UIWidget::getWidth, &UIWidget::setWidth);
    g_lua.bindClassMemberField<UIWidget>("height", &UIWidget::getHeight, &UIWidget::setHeight);
    g_lua.bindClassMemberField<UIWidget>("parent", &UIWidget::getParent, &UIWidget::setParent);
    g_lua.bindClassMemberField<UIWidget>("marginTop", &UIWidget::getMarginTop, &UIWidget::setMarginTop);
    g_lua.bindClassMemberField<UIWidget>("marginBottom", &UIWidget::getMarginBottom, &UIWidget::setMarginBottom);
    g_lua.bindClassMemberField<UIWidget>("marginLeft", &UIWidget::getMarginLeft, &UIWidget::setMarginLeft);
    g_lua.bindClassMemberField<UIWidget>("marginRight", &UIWidget::getMarginRight, &UIWidget::setMarginRight);
    g_lua.bindClassMemberFunction<UIWidget>("centerIn", &UIWidget::centerIn);
    g_lua.bindClassMemberFunction<UIWidget>("addAnchor", &UIWidget::addAnchor);
    g_lua.bindClassMemberFunction<UIWidget>("getChild", &UIWidget::getChildById);
    g_lua.bindClassMemberFunction<UIWidget>("addChild", &UIWidget::addChild);
    g_lua.bindClassMemberFunction<UIWidget>("lock", &UIWidget::lock);

    // UILabel
    g_lua.registerClass<UILabel, UIWidget>();
    g_lua.bindClassStaticFunction<UILabel>("create", &UILabel::create);
    g_lua.bindClassMemberField("text", &UILabel::getText, &UILabel::setText);
    g_lua.bindClassMemberFunction("resizeToText", &UILabel::resizeToText);

    // UIButton
    g_lua.registerClass<UIButton, UIWidget>();
    g_lua.bindClassStaticFunction<UIButton>("create", &UIButton::create);
    g_lua.bindClassMemberField("text", &UIButton::getText, &UIButton::setText);

    // UILineEdit
    g_lua.registerClass<UILineEdit, UIWidget>();
    g_lua.bindClassStaticFunction<UILineEdit>("create", &UILineEdit::create);
    g_lua.bindClassMemberField("text", &UILineEdit::getText, &UILineEdit::setText);

    // UIWindow
    g_lua.registerClass<UIWindow, UIWidget>();
    g_lua.bindClassStaticFunction<UIWindow>("create", &UIWindow::create);
    g_lua.bindClassMemberField("title", &UIWindow::getTitle, &UIWindow::setTitle);

    // Protocol
    g_lua.registerClass<Protocol>();

    // global functions
    g_lua.bindGlobalFunction("importFont", std::bind(&FontManager::importFont, &g_fonts, _1));
    g_lua.bindGlobalFunction("setDefaultFont", std::bind(&FontManager::setDefaultFont, &g_fonts, _1));
    g_lua.bindGlobalFunction("importStyles", std::bind(&UIManager::importStyles, &g_ui, _1));
    g_lua.bindGlobalFunction("loadUI", std::bind(&UIManager::loadUI, &g_ui, _1));
    g_lua.bindGlobalFunction("getRootWidget", std::bind(&UIManager::getRootWidget, &g_ui));
}
