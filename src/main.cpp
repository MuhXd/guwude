#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}
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
    	};
		 }


		return true;
	}
};
