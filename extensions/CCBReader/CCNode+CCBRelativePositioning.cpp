#include "CCNode+CCBRelativePositioning.h"
#include "CCBReader.h"

using namespace cocos2d;

NS_CC_EXT_BEGIN

CCPoint getAbsolutePosition(const CCPoint &pt, int nType, const CCSize &containerSize, const char *pPropName)
{
    float resolutionScale = CCBReader::getResolutionScale();
    
    CCPoint absPt = ccp(0,0);
    if (nType == kCCBPositionTypeRelativeBottomLeft)
    {
        absPt.x = pt.x * resolutionScale;
        absPt.y = pt.y * resolutionScale;
    }
    else if (nType == kCCBPositionTypeRelativeTopLeft)
    {
        absPt.x = pt.x * resolutionScale;
        absPt.y = (containerSize.height - pt.y) * resolutionScale;
    }
    else if (nType == kCCBPositionTypeRelativeTopRight)
    {
        absPt.x = (containerSize.width - pt.x) * resolutionScale;
        absPt.y = (containerSize.height - pt.y) * resolutionScale;
    }
    else if (nType == kCCBPositionTypeRelativeBottomRight)
    {
        absPt.x = (containerSize.width - pt.x) * resolutionScale;
        absPt.y = pt.y * resolutionScale;
    }
    else if (nType == kCCBPositionTypePercent)
    {
        absPt.x = (int)(containerSize.width * pt.x / 100.0f);
        absPt.y = (int)(containerSize.height * pt.y / 100.0f);
    }
    else if (nType == kCCBPositionTypeMultiplyResolution)
    {
        CCSize fs = CCDirector::sharedDirector()->getOpenGLView()->getFrameSize();
        CCSize dr = CCBReader::getDesignResolution();
        
        absPt.x = fs.width / 2 - ((dr.width / 2 - pt.x) * resolutionScale);
        absPt.y = fs.height / 2 - ((dr.height / 2 -pt.y) * resolutionScale);
    }
    
    return absPt;
}

void setRelativeScale(CCNode *pNode, float fScaleX, float fScaleY, int nType, const char* pPropName)
{
    CCAssert(pNode, "pNode should not be null");
    
    if (nType == kCCBScaleTypeMultiplyResolution)
    {
        float resolutionScale = CCBReader::getResolutionScale();
        
        fScaleX *= resolutionScale;
        fScaleY *= resolutionScale;
    }
    
    pNode->setScaleX(fScaleX);
    pNode->setScaleY(fScaleY);
}

NS_CC_EXT_END
