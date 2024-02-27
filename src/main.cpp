#include <Geode/Geode.hpp>

using namespace geode::prelude;
#include <Geode/ui/GeodeUI.hpp>
#include <Geode/modify/MenuLayer.hpp>
void PlaySoundEffect(auto effect){
	if (Mod::get()->getSettingValue<bool>("SFX")) {
		FMODAudioEngine::sharedEngine()->playEffect(effect);
	};
}
class $modify(Uwu, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}
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
		PlaySoundEffect("UwU_1.mp3"_spr);
		geode::openModsList();
	}
};