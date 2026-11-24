#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(TuffoPauseLayer, PauseLayer) {

    void customSetup() {
        PauseLayer::customSetup();

        auto label = CCLabelBMFont::create(
            "TUFFO ANALYSER",
            "bigFont.fnt"
        );

        label->setColor({255, 65, 65});
        label->setScale(0.45f);

        auto button = CCMenuItemLabel::create(
            label,
            this,
            menu_selector(TuffoPauseLayer::openAnalyser)
        );

        auto menu = CCMenu::create();
        menu->addChild(button);

        auto size = CCDirector::sharedDirector()->getWinSize();

        menu->setPosition({
            size.width / 2,
            size.height * 0.18f
        });

        this->addChild(menu, 1000);
    }

    void openAnalyser(CCObject*) {
        FLAlertLayer::create(
            "TUFFO ANALYSER",
            "FRAME ANALYSER\n"
            "MACRO\n"
            "FRAME SKIP\n"
            "AI ANALYSER",
            "CLOSE"
        )->show();
    }
};
