#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    // обработчик отпускания тача
    void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    // обработчик зажатия тача (пока не отпустим)
    void ccTouchBegun(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    void ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event);


    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
    // спрайты для инструментов
    CCSprite * keySpriteBig, *ragSpriteBig, * stepladderSpriteBig;
    // графические и звуковые переменные для класса данной сцены
    CCSprite * backgroundSprite, *kimmi_go_sprite, *keySprite, *ragSprite, * stepladderSprite;

};

#endif // __HELLOWORLD_SCENE_H__
