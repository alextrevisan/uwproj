#include "object.hpp"
#include "game.hpp"

int Object::m_TotalObjects = 0;

Object::Object()
{
    Game *gptr = NULL;
    gptr = Game::getInstance();

    //assign object id
    m_ID = m_TotalObjects;

    //increase total object counter
    m_TotalObjects++;

    //set default texture to question mark
    m_TXT = gptr->getDefaultTexture();
}

Object::~Object()
{

}

//////////////////////////////////////////////////////
//  OBJECT INSTANCE
int ObjectInstance::m_InstanceCount = 0;

ObjectInstance::ObjectInstance(Object *tobj)
{
    m_InstanceID = m_InstanceCount;
    m_InstanceCount++;

    m_Ref = tobj;
    m_Billboard = NULL;

    m_Position = vector3di(0,0,0);
    m_Angle = 0;
    m_Flags = 0;
    m_Enchanted = false;
    m_DoorDir = false;
    m_Invisible = false;
    m_IsQuantity = false;
    m_Quality = 0;
    m_Next = 0;
    m_Owner = 0;
    m_Quantity = 0;

}

ObjectInstance::~ObjectInstance()
{

}

bool ObjectInstance::setBillboard(IBillboardSceneNode *tbb)
{
    if(tbb == NULL)
    {
        if(m_Billboard != NULL)
        {
            std::cout << "Setting billboard to NULL\n";
            m_Billboard->remove();
            m_Billboard = NULL;
        }
    }
    else
    {
        m_Billboard = tbb;
    }

    return true;
}

void ObjectInstance::printDebug()
{
    Game *gptr = Game::getInstance();

    std::cout << "\nObject Instance:\n";
    std::cout << "----------------\n";
    std::cout << "Desc : " << gptr->getString(3, getRefID()) << std::endl;
    std::cout << "Ref ID   : 0x" << std::hex << getRefID() << std::dec << std::endl;
    std::cout << "Instance ID : 0x" << std::hex << getInstanceID() << std::dec << std::endl;
    std::cout << "Flags : " << m_Flags << std::endl;
    std::cout << "Enchanted : " << m_Enchanted << std::endl;
    std::cout << "Door Dir  : " << m_DoorDir << std::endl;
    std::cout << "Invisible : " << m_Invisible << std::endl;
    std::cout << "IsQuantity: " << m_IsQuantity << std::endl;
    std::cout << "\nPosition  : " << m_Position.X << "," << m_Position.Y << "," << m_Position.Z << std::endl;
    std::cout << "Angle     : " << m_Angle << " - *45=" << m_Angle*45 << std::endl;
    std::cout << "\nQuality   : " << m_Quality << std::endl;
    std::cout << "Next      : 0x" << std::hex << m_Next << std::dec << std::endl;
    std::cout << "\nOwner   : 0x" << std::hex << m_Owner << " (" << std::dec << m_Owner << ")\n";
    std::cout << "Quant/Special : " << m_Quantity << " (0x" << std::hex << m_Quantity << ")\n" << std::dec;
    std::cout << "Billboard     : ";
    if(m_Billboard == NULL) std::cout << "NULL\n";
    else
    {
        vector3df bpos = m_Billboard->getPosition();
        std::cout << bpos.X << "," << bpos.Y << "," << bpos.Z << std::endl;
    }
}
