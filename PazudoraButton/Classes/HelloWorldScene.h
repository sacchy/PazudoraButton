#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#define WIN_WIDTH  CCDirector::sharedDirector()->getWinSize().width
#define WIN_HEIGHT CCDirector::sharedDirector()->getWinSize().height

#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayer
{
private:
    enum kTag
    {
        kTagButton=100,
    };
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(HelloWorld);
    
    virtual bool ccTouchBegan(cocos2d::CCTouch* pTouch,cocos2d::CCEvent* pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch* pTouch,cocos2d::CCEvent* pEvent);
};

#endif // __HELLOWORLD_SCENE_H__
