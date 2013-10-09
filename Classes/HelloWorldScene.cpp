#include "HelloWorldScene.h"

USING_NS_CC;

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

void HelloWorld::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCTouch* touch = (CCTouch*)( touches->anyObject());
	CCPoint location = touch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

    // ������ ������, ������� ����� ������������� (��� ������ ���� �� ��������)
	//CCSprite* kimmi_go_sprite = CCSprite::create("kimi_animations/go/000.png");
	// ����� ��������� �������
	//kimmi_go_sprite->setPosition(location);
	// ����� ����� �� ���������� �������� ������ ���� (�� ��������� ����� �� ������)
	//kimmi_go_sprite->setAnchorPoint(ccp(0, 1));
	// ��������� �� ����� � 4-� ����
	//this->addChild(kimmi_go_sprite, 4);

	/*CCAction *act = CCMoveTo::create(2,CCPoint(location.x, kimmi_go_sprite->getPositionY()));
	kimmi_go_sprite->runAction(act);*/
    keySprite->setPosition(ccp(visibleSize.width - 70, visibleSize.height - 70));

}


void HelloWorld::ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
	CCTouch* touch = (CCTouch*)( touches->anyObject());
	CCPoint location = touch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);
	keySprite->setPosition(location);

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
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    this->setTouchEnabled(true);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("It's your first app22!", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // ��������� � ������� ���
    backgroundSprite = CCSprite::create("006.png");
    // position the sprite on the center of the screen
    backgroundSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    // add the sprite as a child to this layer
    this->addChild(backgroundSprite, 0);
    // ����������, ������� ����� �������
    keySprite = CCSprite::create("kimmi_tools/key.png");
    keySprite->setPosition(ccp(visibleSize.width - 70, visibleSize.height - 70));
    keySprite->setAnchorPoint(ccp(0,1));
    this->addChild(keySprite,0);

    // �������� �����
    // ������ ������, ������� ����� ������������� (��� ������ ���� �� ��������)
    kimmi_go_sprite = CCSprite::create("kimi_animations/go/000.png");
    // ����� ��������� �������
    kimmi_go_sprite->setPosition(ccp(68,363));
    // ����� ����� �� ���������� �������� ������ ���� (�� ��������� ����� �� ������)
    kimmi_go_sprite->setAnchorPoint(ccp(0, 1));
    // ��������� �� ����� � 3-� ����
    this->addChild(kimmi_go_sprite, 3);

    // ������ ������ �������� � ������� ��������� ������������������ ������
    CCAnimation *kimmi_go = CCAnimation::create();
    for (int i = 1; i < 29; i++)
    {
        char szImageFileName[128] = {0};
        sprintf(szImageFileName, "kimi_animations/go/%03d.png", i);
        kimmi_go->addSpriteFrameWithFileName(szImageFileName);
    }
    // ����� ����� ����� �������
    kimmi_go->setDelayPerUnit(0.1f);
    // ����� ������������ � 1 ����� ����� ���� ��� ����� �� �����
    kimmi_go->setRestoreOriginalFrame(true);

    // ������ action ��������, ������� �������� � �������
    CCAnimate *kimmi_go_action = CCAnimate::create(kimmi_go);
    // ������ ���, ����� �������� ������������� ���������� � ���������
    CCAction *act = CCRepeatForever::create(kimmi_go_action);
    //��������� � ������� ���� ����� actions
    kimmi_go_sprite->runAction(act);

    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
