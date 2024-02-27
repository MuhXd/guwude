#include <Geode/Geode.hpp>

using namespace geode::prelude;
#include <Geode/ui/GeodeUI.hpp>
#include <Geode/modify/MenuLayer.hpp>
bool sfx = true;
void updsettings() {
	sfx = Mod::get()->getSettingValue<bool>("SFX");
};
class $modify(Uwu, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}
		updsettings();
	auto geodeButton = dynamic_cast<CCMenuItemSpriteExtra*>(
		getChildByIDRecursive("geode.loader/geode-button")
	);
		geodeButton->m_pfnSelector = menu_selector(Uwu::onGeode);
		// no ids Yall
		 for(auto items : CCArrayExt<CCNode*>(this->getChildByIDRecursive("geode.loader/geode-button")->getChildren())) {
			auto g=items;
			if (auto icon = getChildOfType<CCSprite>(g, 0)) {
        	auto Spr = CCSprite::create("gwode.png"_spr);
			Spr->setScale(0.2);
			Spr->setPositionX(icon->getPositionX());
			Spr->setPositionY(icon->getPositionY());
			g->addChild(Spr);
			icon->setVisible(false);
			break;
    	};
		 }


		return true;
	}
	void onGeode(CCObject*) {
		if (sfx) {
			FMODAudioEngine::sharedEngine()->playEffect("UwU_1.mp3"_spr);
		}
		geode::openModsList();
	}
};