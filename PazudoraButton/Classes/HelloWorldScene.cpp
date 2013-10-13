#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    // タップイベントを取得する
    this->setTouchEnabled(true);
    this->setTouchMode(kCCTouchesOneByOne);
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    /////////////////////////////
    // 3.
    ccColor4B yellow = ccc4(0, 255, 255, 255);
    ccColor4B black  = ccc4(0, 0, 0, 255);
    CCLayerGradient* layer = CCLayerGradient::create(yellow, black, ccp(1.0f, 1.0f));
    this->addChild(layer);

    /////////////////////////////
    // 4.
    CCSprite* sprite = CCSprite::create("button.png");
    sprite->setPosition(ccp(WIN_WIDTH/2,WIN_HEIGHT/2));
    this->addChild(sprite,kTagButton,kTagButton);
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

#pragma mark - Touch

bool HelloWorld::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    // タップポイント取得
    CCPoint touchPoint = this->convertTouchToNodeSpace(pTouch);
    
    CCNode* node = this->getChildByTag(kTagButton);
    
    if (node && node->boundingBox().containsPoint(touchPoint))
    {
        CCScaleTo* scaleToExpand = CCScaleTo::create(0.1,1.2);
        CCScaleTo* scaleToShrink = CCScaleTo::create(0.1,1.0);
        CCSequence* sec = CCSequence::create(scaleToExpand,scaleToShrink,NULL);
        node->runAction(sec);
    }
    return true;
}

void HelloWorld::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    // タップポイント取得
    CCPoint touchPoint = this->convertTouchToNodeSpace(pTouch);
    
    CCNode* node = this->getChildByTag(kTagButton);
    
    if (node && node->boundingBox().containsPoint(touchPoint))
    {
        CCLog("transition");
    }
}