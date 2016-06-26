#ifndef CLASS_MOUSE
#define CLASS_MOUSE

#include "irrcommon.hpp"
#include "game.hpp"

#include "thread.hpp"


//forward declarations
class Game;

class Mouse
{
private:

    //engine references
    Game *gptr;
    IVideoDriver *m_Driver;
    IrrlichtDevice *m_Device;

public:
    Mouse(Game *tgame);
    ~Mouse();

    vector2di m_MousePos;
    line3d<f32> m_CameraMouseRay;

    ITexture *m_Texture;
    void setTexture(ITexture *ttxt);
    void draw();

    void updatePosition();
    int getMousePositionX() { return m_MousePos.X;}
    int getMousePositionY() { return m_MousePos.Y;}
    vector2di *getMousePosition() { return &m_MousePos;}
};

//mouse update thread
class MouseUpdateThread:public MyThreadClass
{
private:
    Mouse *m_Mouse;
    bool *shutdownflag;

    void InternalThreadEntry();
public:
    MouseUpdateThread(Mouse *nmouse, bool *nshutdownflag);
    ~MouseUpdateThread();
};

#endif // CLASS_MOUSE
